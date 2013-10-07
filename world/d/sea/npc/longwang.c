// cracked by vikee 2/09/2002   vikee@263.net
//modified by sgzl for dntg/donghai quest
#include <skill.h>

inherit NPC;
inherit F_MASTER;

string expell_me(object me);
int donghai_quest(object who);

void create()
{
       	set_name("����", ({"ao guang", "ao","guang","longwang","wang"}));

	set("long","�����Ƕ��������������ֱֵܷ��ƹܶ��������ϣ����ĺ���
������ˮ���ڶ࣬���ƺƴ�ٲȻ����һ����\n");
       	set("gender", "����");
       	set("age", 66);
	set("title", "��������");
	set("class","dragon");
       	set("attitude", "peaceful");
       	set("shen_type", 1);
        set("combat_exp", 1260000);
        set("daoxing", 1500000);

        set("rank_info/respect", "����");
       	set("per", 20);
       	set("str", 30);
       	set("max_kee", 3000);
       	set("max_gin", 400);
       	set("max_sen", 1500);
       	set("force", 3000);
       	set("max_force", 1500);
       	set("force_factor", 120);
       	set("max_mana", 800);
       	set("mana", 1600);
       	set("mana_factor", 40);
       	set("combat_exp", 1200000);
        set("daoxing", 1500000);

	set_skill("huntian-hammer", 180);
	set_skill("hammer", 180);
	set_skill("literate", 100);
       	set_skill("unarmed", 200);
       	set_skill("dodge", 180);
       	set_skill("force", 180);
       	set_skill("parry", 180);
       	set_skill("fork", 180);
       	set_skill("spells", 170);
	set_skill("seashentong", 170);
	set_skill("dragonfight", 200);
	set_skill("dragonforce", 180);
	set_skill("fengbo-cha", 180);
	set_skill("dragonstep", 180);
	map_skill("hammer", "huntian-hammer");
	map_skill("spells", "seashentong");
	map_skill("unarmed", "dragonfight");
	map_skill("force", "dragonforce");
	map_skill("fork", "fengbo-cha");
	map_skill("parry", "fengbo-cha");
	map_skill("dodge", "dragonstep");

        set("inquiry", ([ 
           "�빬": (: expell_me :),
	   "leave": (: expell_me :), 
           "����": (: donghai_quest :),
           "weapon": (: donghai_quest :), 
        ]) );

        create_family("��������", 1, "ˮ��");
	set_temp("apply/armor",50);
	set_temp("apply/damage",25);
	setup();

        carry_object("/d/sea/obj/longpao")->wear();
}
void init()
{
	::init();
	add_action("do_agree", "agree");
	add_action("do_learn", "xuexi");
}


void destroy(object ob)
{
        destruct(ob);
        return;
}

void unsetlearn(object ob)
{
	if (find_player(ob->query("id"))) {
		ob->set_temp("temp/learn", 0);
		ob->save();
		}
}


string *reject_msg = ({
	"˵������̫�����ˣ�����ô�ҵ���\n",
	"�����ܳ�����һ����˵������̣�����ô�ҵ���\n",
	"Ц��˵��������Ц�ˣ��������С�������ʸ�ָ�㡹��ʲô��\n",
});

int do_learn(string arg)
{
	string skill, teacher, master;
	object me= this_player(), ob;
	int master_skill, my_skill, sen_cost;

	if(!arg || sscanf(arg, "%s from %s", skill, teacher)!=2 )
		return notify_fail("ָ���ʽ��xuexi <����> from <ĳ��>\n");

	if( me->is_fighting() )
		return notify_fail("����ĥǹ������������\n");

	if( !(ob = present(teacher, environment(me))) || !ob->is_character())
		return notify_fail("��Ҫ��˭��̣�\n");

	if( !living(ob) )
		return notify_fail("�ţ���������Ȱ�" + ob->name() + "Ū����˵��\n");

	if( !master_skill = ob->query_skill(skill, 1) )
		return notify_fail("���������±����ұ���ѧ�ˡ�\n");

	if (skill != "unarmed" || !me->query_temp("temp/learn") ) 
		return notify_fail( ob ->name() + reject_msg[random(sizeof(reject_msg))] );

	notify_fail(ob->name() + "��Ը���������ܡ�\n");
	if( ob->prevent_learn(me, skill) )
		return 0;

	my_skill = me->query_skill(skill, 1);
	if( my_skill >= master_skill )
		return notify_fail("�������ĳ̶��Ѿ�������ʦ���ˡ�\n");

	notify_fail("����Ŀǰ��������û�а취ѧϰ���ּ��ܡ�\n");
	if( !SKILL_D(skill)->valid_learn(me) ) return 0;

	sen_cost = 250 / (int)me->query_int();

	if( !my_skill ) {
		sen_cost *= 2;
		me->set_skill(skill,0);
	}

	if( (int)me->query("learned_points") >= (int)me->query("potential") )
		return notify_fail("���Ǳ���Ѿ����ӵ������ˣ�û�а취�ٳɳ��ˡ�\n");
	printf("����%s���йء�%s������ʡ�\n", ob->name(),
		to_chinese(skill));

	if( ob->query("env/no_teach") )
		return notify_fail("����" + ob->name() + "���ڲ���׼���ش�������⡣\n");

	tell_object(ob, sprintf("%s�������йء�%s������⡣\n",
		me->name(), to_chinese(skill)));

	if( (int)ob->query("sen") > sen_cost/5 + 1 ) {
		if( userp(ob) ) ob->receive_damage("sen", sen_cost/5 + 1);
	} else {
		write("����" + ob->name() + "��Ȼ̫���ˣ�û�а취����ʲô��\n");
		tell_object(ob, "������̫���ˣ�û�а취��" + me->name() + "��\n");
		return 1;
	}
		

	if( (int)me->query("sen") > sen_cost ) {
		if( (string)SKILL_D(skill)->type()=="martial"
		&&	my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp") ) {
			printf("Ҳ���ǵ��в��������%sĻش������޷���ᡣ\n", ob->name() );
		} else {
			printf("������%s�ָ�����ƺ���Щ�ĵá�\n", ob->name());
			me->add("learned_points", 1);
			me->improve_skill(skill, random(me->query_int()));
		}
	} else {
		sen_cost = me->query("sen");
		write("�����̫���ˣ����ʲôҲû��ѧ����\n");
	}

	me->receive_damage("sen", sen_cost );

	return 1;
}

void attempt_apprentice(object ob)
{	
	if( (int)ob->query_skill("dragonforce",1) < 50
	|| (int)ob->query_skill("seashentong", 1) < 50) {
	command("say " + RANK_D->query_respect(ob) +
		"�����ȵ��󽫾���СŮ���ѻ������������������ɡ�\n");
	return;
	}	
        command("smile");
        command("say �ѵ�" + RANK_D->query_respect(ob) +
		"�д���־�������պ���Ŭ����Ϊ�Ҷ����������⡣\n");
        command("recruit " + ob->query("id") );
	return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "dragon");
}

string expell_me(object me)
{
  me=this_player();
  if((string)me->query("family/family_name")=="��������")
    {
      me->set_temp("betray", 1);
      command("sigh");
      return ("��Ҫ�뿪��Ҳ����ǿ����ֻ�ǰ��Ҷ�����أ�ȴ���ܷ���
���¼���������࣬�������ķ��벩����������ǰ����ת�����Ը��(agree)?\n");
    }
  return ("ȥ����Ԭ�����ɣ�������֪����\n");
}

int do_agree(string arg)
{
  object me;
  me = this_player();
  if(me->query_temp("betray"))
    {
      message_vision("$N���������Ը�⡣\n\n", me);
      command("say �˸���־������" + RANK_D->query_respect(me) +
        "��Ը���ڶ������������ȥ�ɡ�ֻ�ǽ����ն�" + RANK_D->query_respect(me) +
	"������Ϊ֮������\n");
      me->set_skill("dragonforce", (int)me->query_skill("dragonforce",1)/2);
      me->set_skill("dragonfight", (int)me->query_skill("dragonfight",1)/3);
      me->set("combat_exp", me->query("combat_exp")*80/100);
      me->set("daoxing", me->query("daoxing")*80/100);
      me->delete("family");
      me->delete("class");
      me->set("title", "��ͨ����");
      me->set_temp("betray", 0);
      me->add("betray/count", 1);
      me->add("betray/longgong", 1);
      me->save();
      return 1;
    }
  return 0;
}

int donghai_quest(object who)
{
  object me=this_object();
  object fighter;
  string weapon_name,weapon_id,weapon_unit,temp_flag;

  who=this_player();
  if (who->query("dntg/donghai")=="done") {
    message_vision("$N��ɫ�ҵ�������Ը��˵��������������ϵط���������������\n",this_object());
    call_out("sendto_maze",2,who);
    return 1;
  }

  if (
      who->query("dntg/donghai") == "begin"
      || who->query("dntg/donghai") == "da kan dao"
      || who->query("dntg/donghai") == "jiu gu cha"
      || who->query("dntg/donghai") == "mei hua chui"
     )

    {
        if (who->query("dntg/donghai") == "begin")
           {weapon_name="�󿳵�"; weapon_id="da kan dao";weapon_unit="��";temp_flag="try_dao";}
        if (who->query("dntg/donghai") == "da kan dao")
           {weapon_name="�Źɲ�"; weapon_id="jiu gu cha";weapon_unit="֧";temp_flag="try_cha";}
        if (who->query("dntg/donghai") == "jiu gu cha")
           {weapon_name="÷����"; weapon_id="mei hua chui";weapon_unit="��";temp_flag="try_chui";}
        if (who->query("dntg/donghai") == "mei hua chui")
           {weapon_name="�����"; weapon_id="hua gan ji";weapon_unit="��";temp_flag="try_ji";}

        
        if (present(weapon_id, this_player()) && present("ye cha", environment()))
          message_vision("����������������"+weapon_name+"��ҹ�������ɣ�\n",me);
        else if (present(weapon_id, environment()) && present("ye cha", environment()))
          message_vision("����������������"+weapon_name+"��ҹ�������ɣ�\n",me);
        else if (present(weapon_id, this_player()) || present(weapon_id, environment()))
          {
          message_vision("��������˵���������Ҹ���������������\n",me);
          message_vision("��������һ���֣�һ��ҹ�����˹�����\n",me);
          fighter = new ("/d/dntg/donghai/npc/fighter");
          fighter->move(environment(me));
          } 
        else if (present("ye cha", environment()))
          message_vision("����������֪��"+weapon_name+"��˭��ȥ�ˣ�\n",me);
        else
          {
          message_vision("$N��æ����˵����"+RANK_D->query_respect(who)+"�Ժ�������룿\n",me,who);
          message_vision("������������"+weapon_unit+weapon_name+"���պ�����ʹ��"+RANK_D->query_respect(who)+"����������������"+RANK_D->query_respect(who)+"�ðɣ�\n",who);
          who->set_temp("dntg/donghai",temp_flag);
          call_out ("fight_quest",2,who);
          }
        return 1;
    } 

  else if (who->query("dntg/donghai") == "hua gan ji" )
    {
    me->command("consider");
    message_vision("�Ӻ�����һ�����ţ�����������С��˵�˼��仰��\n",me);
    call_out ("sendto_maze",3,who);
    return 1;
    }
   command("nod");
  message_vision("$N�������˵����Ҫ���������������е��ǣ�ȥ����ŪЩ�ɡ���\n",me);
  message_vision("$N���˶٣���˵�����������ı�������������Щ��������Ҳʹ���ˡ���\n",me);
  command("wave");
  return 1;
}

void fight_quest (object who)
{
  object me=this_object();
  object fighter,fa_bao;
  string weapon_name,weapon_id,weapon_unit;


  if (who->query("dntg/donghai") == "begin")
    {weapon_name="�󿳵�"; fa_bao = new ("/d/dntg/donghai/obj/dakandao");weapon_unit="��";}
  if (who->query("dntg/donghai") == "da kan dao")
    {weapon_name="�Źɲ�"; fa_bao = new ("/d/dntg/donghai/obj/jiugucha");weapon_unit="֧";}
  if (who->query("dntg/donghai") == "jiu gu cha")
    {weapon_name="÷����"; fa_bao = new ("/d/dntg/donghai/obj/meihuachui");weapon_unit="��";}
  if (who->query("dntg/donghai") == "mei hua chui")
    {weapon_name="�����"; fa_bao = new ("/d/dntg/donghai/obj/huaganji");weapon_unit="��";}

  message_vision("��������һ���֣�һ��ҹ��̧��һ"+weapon_unit+weapon_name+"��\n",me);
  fighter = new ("/d/dntg/donghai/npc/fighter");
  fighter->move(environment(me));
  fa_bao->move(environment(me));
  message_vision("��������˵������Ҫ��Ҫ���ҵ���������������\n",me);
}

void sendto_maze (object who)
{
  object me=this_object();
  message_vision("$N˵����"+RANK_D->query_respect(who)+"�书�������ɵ�����ĺ�������һ�Զ�����������\n",me,who);
  call_out ("send_maze",3,who);
}

void send_maze (object who)
{
  object me=this_object();
  message_vision("˵�ţ�����������$N�͵���һ���ط���\n",who);
  who->move("/d/dntg/donghai/haidimigong");
  message_vision("$Nһ���ֵ���"+RANK_D->query_respect(who)+"��ǰ�߼��ɿ�����������ˡ�Ϸ򲻷����ˡ�\n",me,who);
  message_vision("˵�գ�����ת��ع��ˡ�\n",me);
}

