// cracked by vikee 2/09/2002   vikee@263.net

#include <ansi.h>

//inherit NPC;
inherit "/d/dntg/hell/wang.c";
inherit F_MASTER;
int send_me();
int work_me();
string expell_me(object me);
void create()
{
       set_name("������", ({"yanluo wang","wang", "master", "yanluo"}));
       set("long", "��������ۣ�ͷ���ڳ����
������ף��������룬�������������\n");
       set("title", "����ʮ��֮");
	set("class", "youling");
       set("gender", "����");
       set("age", 50);
       set("attitude", "peaceful");
       set("shen_type", 1);
       set("per", 10);
       set("max_kee", 1800);
       set("max_gin", 1800);
       set("max_sen", 1800);
       set("force", 1150);
       set("max_force", 1000);
       set("force_factor", 60);
       set("max_mana", 1500);
       set("mana", 1500);
       set("mana_factor", 50);
       set("combat_exp", 1000000);
  set("daoxing", 2000000);

        set("eff_dx", 800000);
        set("nkgain", 600);


	set_skill("jinghun-zhang", 150);
	set_skill("tonsillit", 100);
	set_skill("gouhunshu", 150);
       set_skill("unarmed", 150);
	set_skill("whip", 150);
	set_skill("hellfire-whip", 150);
	set_skill("sword", 150);
	set_skill("zhuihun-sword", 150);
       set_skill("dodge", 150);
	set_skill("ghost-steps", 150);
       set_skill("parry", 150);
        set_skill("spells", 150);
        set_skill("force", 150);
	set_skill("stick", 150);
	set_skill("kusang-bang", 150);

	map_skill("sword", "zhuihun-sword");
	map_skill("parry", "zhuihun-sword");
	map_skill("dodge", "ghost-steps");
	map_skill("unarmed", "jinghun-zhang");
	map_skill("force", "tonsillit");
	map_skill("spells", "gouhunshu");

	set("nk_gain", 500);

	set_temp("apply/armor", 50);
	set_temp("apply/dodge", 50);

        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
		(: exert_function, "sheqi" :),
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
		(: cast_spell, "gouhun" :),
		(: cast_spell, "inferno" :),
		(: cast_spell, "invocation" :),
        }) );

set("inquiry", ([
"����": (: expell_me :),
"leave": (: expell_me :),
//"watch":(:send_me:),
"ʮ�˲����":(: work_me :),
//"18": (: work_me :),
"name": "�ߣ����Ϸ򶼲��ϵã������ǻ��̫���ˣ�\n",
"here": "��������޵ظ���������һ̸���ٺ٣�û�˲��£�\n",
"����": "��˵������;����ʵ��Ȼ��������������ཻ����ȥ��ͨ��\n",
"���": "������Ҫ˵֪������ȴҲ���࣬�Ǳ����꣬�£��գ�ʱ�ͳ�����ˮ�ţ�\n",
]) );


create_family("���޵ظ�", 2, "���");
setup();

        carry_object("/d/obj/cloth/mangpao")->wear();
	carry_object("/d/obj/weapon/sword/qinghong")->wield();
}
void attempt_apprentice(object ob, object me)
{
        if ( (string)ob->query("family/family_name")=="���޵ظ�") {
        if (((int)ob->query("combat_exp") < 50000 )) {
        command("say " + RANK_D->query_rude(ob) + "��������������û�ս��㣡\n");
        return;
        }
        command("grin");
        message_vision("��������$N�ٺٵ�Ц�˼�����\n", ob);
	message_vision("����������$N�ļ��˵�����Ժ���������ù��������г�ͷ�����ӣ�\n", ob);
       command("recruit " + ob->query("id") );
        return;
        }
	message_vision("��������$N�ȵ���������������ë�������ܵ���������Ұ�����Һ��ȥ��\n", ob);
	message_vision("�ܽ�����������С���$N���˳�ȥ��\n", ob);
	ob->move("/d/diyu/walk7");
        return;
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "youling");
}


int accept_fight(object me)
{
        command("say " + "�������������У��Լ����ţ�\n");
        return 1;
}

string expell_me(object me)
{       
	me=this_player();
        if((string)me->query("family/family_name")=="���޵ظ�") {
		message_vision("���������Ӷ���������ǳ�������\n", me);
                me->set_temp("betray", 1);
		message_vision("��������$N�����ţ�С��������˵�������Ļ�(true)��\n", me);
                return ("�������ˣ��������ˣ�\n");
        }
        return ("��ʲô�ʣ��Լ���ȥ��\n");
}
void init()
{
        add_action("do_true", "true");
  ::init();
}

int do_true(string arg)
{
        if(this_player()->query_temp("betray")) {
                message_vision("$N��������ӽ������Ļ���\n\n", this_player());
		message_vision("������̾�˿�����������ˣ���㻹��ȥ�ɣ�\n", this_player());
                this_player()->set("combat_exp", this_player()->query("combat_exp")*95/100);
		this_player()->add("betray/count", 1);
		this_player()->add("betray/hell", 1);
                this_player()->delete("family");
		this_player()->delete_skill("gouhunshu");
                this_player()->delete("class");
                this_player()->set("title", "��ͨ����");
                this_player()->set_temp("betray", 0);
                this_player()->save();
		message_vision("����������ֽ�$Nһ�ƣ�$N����һ�������򶫶�ȥ������\n", this_player());
		this_player()->move("/d/city/chenghuang");
		tell_room( environment(this_player()),"�������������¼����죬���¸�������\n", ({this_player()}));
		this_player()->unconcious();		
                return 1;
                }
        return 0;
}


/*

int work_me()
{
	object ghost, me;
	me=this_player();
	if( (string)me->query("family/family_name")!="���޵ظ�" ) {
		message_vision("$Nбб��Ƴ��$nһ�ۣ���Ц�������㣬��Ц��Ц������\n", this_object(), me);
		return 1;
		}
	//for first time.
	if(!me->query("Hell_Job")) {
		call_out("start_job", 1, me);
		return 1;
	}
	if( (int)me->query("Hell_Job/time_start") + 900 > time() ) {
		if( !me->query("Hell_Job/done")) {
			command("heng " + me->query("id"));
			command("say �ϴζ�û���꣬��Ҳûץ�������������������ң�\n");
			return 1;
		}
		command("say �ϴθɵĲ�������ûʲôҪ���£���Ъ�Űɡ�\n");
		return 1;
	}
	call_out("start_job", 1, me);
	return 1;
}
int start_job(object me)
{	string* dirs;
	object ghost;

        dirs = ({"/d/4world/","/d/city/","/d/gao/", "/d/jjf/",
"/d/lingtai/", "/d/meishan/","/d/moon/", "/d/nanhai/", "/d/penglai/",
"/d/sea/","/d/sky/", "/d/xueshan/", "/d/qujing/nuerguo/", 
"/d/qujing/wudidong/", "/d/qujing/firemount/"});

        seteuid(getuid());

        ghost = new("/obj/npc/ghost");
	ghost->move("/obj/void");
        ghost->invocation(me, dirs);
//release the ghost;
//
	command("spank " + me->query("id"));
	command("whisper " + me->query("id") + "
�ݴ��й�˵�����˸����ж������ڸ���������ʮ����ְ���׽������\n");
	me->set("Hell_Job/time_start", time());

	return 1;
}
*/
int send_me()
{
	object who;
	who=this_player();
	message_vision("$N��$n���˵�ͷ�����������Լ�Ҫȥ���ز�����Թ�ҡ�\n",this_object(),who);
	who->move("/d/death/emptyroom");
	return 1;
}
int work_me()
{
	object who;
	who=this_player();

	if( (int)who->query("combat_exp") < 300000 ) {
		message_vision("$N��$nһ���֣��������в�����ǿ��������Ȼ��\n", this_object(),who);
		return 1;
	}
	if( who->query("HellZhenPass") ) {

message_vision("$N��$nһ���֣����������书��ǿ���ҵ�������ǣ��⡣�����������˰ɣ�\n",this_object(),who);
	return 1;
	}
	if( this_object()->query_temp("SomeonePassing") ) {
		message_vision("$N��$nһ���֣�������ʱ��Ե���ɣ����������ɡ�\n",this_object(),who);
		return 1;
	}


message_vision("$N��$n������Ц�˼�����˵��������·�㲻�ߣ����������㴳������\n",this_object(),who);
	this_object()->set_temp("SomeonePassing");
//add a chat here.
	command("chat "+who->query("name")+"Ҫ�����ظ�ʮ�˲�������ߣ�������ʬ�ɣ�\n");

	message_vision("$N˫������һ�£�$n����ͻȻ������ȥ������\n", this_object(),who);
	who->delete("env/brief_message");
	who->move("/d/death/emptyroom");

	command("grin");
	this_object()->move("/obj/void");
	
//	call_out("get_all",1,who);
	call_out("message",3,who);
	call_out("round_1",4, who);
	return 1;
}
/*
int get_all(object who)
{
  object me = this_object();
  object *obs = all_inventory (who);
  int i = sizeof(obs);

  message_vision ("һ���紵������ү���֣�\n",who);
  while (i--)
  {
    object ob = obs[i];

    if (ob == me)
      continue;
    if (ob->query("no_get"))
      continue;
    if (ob->query("no_drop"))
      continue;

    message_vision ("��ү��$N�����ѳ�$n��\n",who,ob);
    if (! interactive(ob))
      destruct (ob);
    else
      ob->move(environment(who));
  }  
    return 1;
}

*/
int check_status(object who)
{
	if( (int)who->query("kee") < 50 
	||	(int)who->query("eff_kee") < 50 ) {
                remove_call_out("round_2");
                remove_call_out("round_3");
                remove_call_out("round_4");
                remove_call_out("round_5");
                remove_call_out("round_6");
                remove_call_out("round_7");
                remove_call_out("round_8");
                remove_call_out("round_9");
                remove_call_out("round_10");
                remove_call_out("round_11");
                remove_call_out("round_12");
                remove_call_out("round_13");
                remove_call_out("round_14");
                remove_call_out("round_15");
                remove_call_out("round_16");
                remove_call_out("round_17");
                remove_call_out("round_18");
		remove_call_out("message");
		remove_call_out("winning");
		call_out("failed",1,who);
		return 1;
	}
}
int failed(object who)
{	
	command("chat* ��������Ц�˼�����");
	command("chat �����в������ģ���ϧ�����Ӳ������������ģ�\n");
	this_object()->delete_temp("SomeonePassing");
	who->move("obj/void");
	who->unconcious();
	this_object()->move("/d/death/zhengtang");
	call_out("remove_all", 3);
	return 1;
}
int remove_all()
{	int i;
        object *list,empty;

        if( !(empty = find_object("/d/death/emptyroom")) )
                empty = load_object("/d/death/emptyroom");
	write("���ܹ���һ�����硣����\n");
        if( empty = find_object("/d/death/emptyroom") ) {

		list=all_inventory(empty);
		i = sizeof(list);
		while (i--)
		{
			object ob=list[i];
			ob->move("/d/changan/fendui");
		}
	}
	return 1;
}

int winning(object who)
{
// add a chat here.
	command("chat "+who->query("name")+"���������ˣ��»ؿ�û��ô�����ˣ�\n");
// add reward here.
    who->add("gift_modify/kar", 5+random(6));
	who->add("potential", 1000);
//    who->add("combat_exp", 5000)
    who->add("daoxing", 5000);
	tell_object(who,"��õ���һǧ��Ǳ�ܺ�������С�\n");
	who->set("HellZhenPass",1);
	this_object()->move("/d/death/zhengtang");
	this_object()->delete_temp("SomeonePassing");
	call_out("remove_all", 3);
	return 1;
}
int message(object who)
{
	switch(random(5)) {

		case 0:
tell_room(environment(who),"\n������Լ������½�����Χ������ʵ����ɣ�����עĿ��\n");
break;
		case 1:
tell_room(environment(who),"\n������Լ������½���\n");
break;
		case 2:
tell_room(environment(who),"\n������Լ������½�������ƺ�û�˽��ޡ�����\n");
break;
                case 3:
tell_room(environment(who),"\n������Լ������½�����Χһ�ж�����ת������\n");
break;
		case 4:
tell_room(environment(who),"\n������Լ������½����½����ƺ��������޾�����Ԩ��\n");
break;
	}
	return 1;
}
int round_1(object who)
{
	object ghost;
        seteuid(getuid());
        ghost=new("/d/death/HellZhen/1");
	tell_room(environment(who),"\nͻȻ��һ������������\n\n");
	tell_room(environment(who),RED"                **************************************\n"NOR);
	tell_room(environment(who),RED"                **               ������             **\n"NOR);
	tell_room(environment(who),RED"                **************************************\n"NOR);
        ghost->move(environment(who));
        ghost->invocation(who);
	call_out("check_status",1,who);
	call_out("message",2,who);
	call_out("round_2", 3, who);
        return 1;
}

int round_2(object who)
{
        object ghost;
        seteuid(getuid());
        ghost=new("/d/death/HellZhen/2");
        tell_room(environment(who),"\nͻȻ��һ������������\n\n");
        tell_room(environment(who),GRN"                **************************************\n"NOR);
        tell_room(environment(who),GRN"                **               ������             **\n"NOR);
        tell_room(environment(who),GRN"                **************************************\n"NOR);
        ghost->move(environment(who));
        ghost->invocation(who);
        call_out("check_status",1,who);
        call_out("message",2,who);
        call_out("round_3", 3, who);
        return 1;
}
int round_3(object who)
{
        object ghost;
        seteuid(getuid());
        ghost=new("/d/death/HellZhen/3");
        tell_room(environment(who),"\nͻȻ��һ������������\n\n");
        tell_room(environment(who),YEL"                **************************************\n"NOR);
        tell_room(environment(who),YEL"                **               ����             **\n"NOR);
        tell_room(environment(who),YEL"                **************************************\n"NOR);
        ghost->move(environment(who));
        ghost->invocation(who);
        call_out("check_status",1,who);
        call_out("message",2,who);
        call_out("round_4", 3, who);  
        return 1;
}
int round_4(object who)
{
        object ghost;
        seteuid(getuid());
        ghost=new("/d/death/HellZhen/4");
        tell_room(environment(who),"\nͻȻ��һ������������\n\n");
        tell_room(environment(who),BLU"                **************************************\n"NOR);
        tell_room(environment(who),BLU"                **               ۺ����             **\n"NOR);
        tell_room(environment(who),BLU"                **************************************\n"NOR);
        ghost->move(environment(who));
        ghost->invocation(who);
        call_out("check_status",1,who);
        call_out("message",2,who);
        call_out("round_5", 3, who);  
        return 1;
}
int round_5(object who)
{
        object ghost;
        seteuid(getuid());
        ghost=new("/d/death/HellZhen/5");
        tell_room(environment(who),"\nͻȻ��һ������������\n\n");
        tell_room(environment(who),MAG"                **************************************\n"NOR);
        tell_room(environment(who),MAG"                **               ������             **\n"NOR);
        tell_room(environment(who),MAG"                **************************************\n"NOR);
        ghost->move(environment(who));
        ghost->invocation(who);
        call_out("check_status",1,who);
        call_out("message",2,who);
        call_out("round_6", 3, who);  
        return 1;
}
int round_6(object who)
{
        object ghost;
        seteuid(getuid());
        ghost=new("/d/death/HellZhen/6");
        tell_room(environment(who),"\nͻȻ��һ������������\n\n");
        tell_room(environment(who),CYN"                **************************************\n"NOR);
        tell_room(environment(who),CYN"                **               ��Ƥ��             **\n"NOR);
        tell_room(environment(who),CYN"                **************************************\n"NOR);
        ghost->move(environment(who));
        ghost->invocation(who);
        call_out("check_status",1,who);
        call_out("message",2,who);
        call_out("round_7", 3, who);  
        return 1;
}
int round_7(object who)
{
        object ghost;
        seteuid(getuid());
        ghost=new("/d/death/HellZhen/7");
        tell_room(environment(who),"\nͻȻ��һ������������\n\n");
        tell_room(environment(who),HIR"                **************************************\n"NOR);
        tell_room(environment(who),HIR"                **               ĥ����             **\n"NOR);
        tell_room(environment(who),HIR"                **************************************\n"NOR);
        ghost->move(environment(who));
        ghost->invocation(who);
        call_out("check_status",1,who);
        call_out("message",2,who);
        call_out("round_8", 3, who);  
        return 1;
}
int round_8(object who)
{
        object ghost;
        seteuid(getuid());
        ghost=new("/d/death/HellZhen/8");
        tell_room(environment(who),"\nͻȻ��һ������������\n\n");
        tell_room(environment(who),HIG"                **************************************\n"NOR);
        tell_room(environment(who),HIG"                **               ׶����             **\n"NOR);
        tell_room(environment(who),HIG"                **************************************\n"NOR);
        ghost->move(environment(who));
        ghost->invocation(who);
        call_out("check_status",1,who);
        call_out("message",2,who);
        call_out("round_9", 3, who);  
        return 1;
}
int round_9(object who)
{
        object ghost;
        seteuid(getuid());
        ghost=new("/d/death/HellZhen/9");
        tell_room(environment(who),"\nͻȻ��һ������������\n\n");
        tell_room(environment(who),HIY"                **************************************\n"NOR);
        tell_room(environment(who),HIY"                **               ������             **\n"NOR);
        tell_room(environment(who),HIY"                **************************************\n"NOR);
        ghost->move(environment(who));
        ghost->invocation(who);
        call_out("check_status",1,who);
        call_out("message",2,who);
        call_out("round_10", 3, who);  
        return 1;
}
int round_10(object who)
{
        object ghost;
        seteuid(getuid());
        ghost=new("/d/death/HellZhen/10");
        tell_room(environment(who),"\nͻȻ��һ������������\n\n");
        tell_room(environment(who),HIB"                **************************************\n"NOR);
        tell_room(environment(who),HIB"                **               ������             **\n"NOR);
        tell_room(environment(who),HIB"                **************************************\n"NOR);
        ghost->move(environment(who));
        ghost->invocation(who);
        call_out("check_status",1,who);
        call_out("message",2,who);
        call_out("round_11", 3, who);  
        return 1;
}
int round_11(object who)
{
        object ghost,ghostb;
	seteuid(getuid());
        ghostb=new("/d/death/HellZhen/15");
        seteuid(getuid());
        ghost=new("/d/death/HellZhen/11");
        tell_room(environment(who),"\nͻȻ��һ������������\n\n");
        tell_room(environment(who),HIM"                **************************************\n"NOR);
        tell_room(environment(who),HIM"                **               �ѿ���             **\n"NOR);
        tell_room(environment(who),HIM"                **************************************\n"NOR);
        ghost->move(environment(who));
        ghost->invocation(who);
	ghostb->move(environment(who));
        ghostb->invocation(who);
        call_out("check_status",1,who);
        call_out("message",2,who);
        call_out("round_12", 3, who);  
        return 1;
}
int round_12(object who)
{
        object ghost,ghostb;
        seteuid(getuid());
        ghostb=new("/d/death/HellZhen/11");
        seteuid(getuid());
        ghost=new("/d/death/HellZhen/12");
        tell_room(environment(who),"\nͻȻ��һ������������\n\n");
        tell_room(environment(who),HIC"                **************************************\n"NOR);
        tell_room(environment(who),HIC"                **               �鳦��             **\n"NOR);
        tell_room(environment(who),HIC"                **************************************\n"NOR);
        ghost->move(environment(who));
        ghost->invocation(who);
	ghostb->move(environment(who));
        ghostb->invocation(who);
        call_out("check_status",1,who);
        call_out("message",2,who);
        call_out("round_13", 3, who);  
        return 1;
}
int round_13(object who)
{
        object ghost,ghostb;
        seteuid(getuid());
        ghostb=new("/d/death/HellZhen/16");

        seteuid(getuid());
        ghost=new("/d/death/HellZhen/13");
        tell_room(environment(who),"\nͻȻ��һ������������\n\n");
        tell_room(environment(who),HIW"                **************************************\n"NOR);
        tell_room(environment(who),HIW"                **               �͹���             **\n"NOR);
        tell_room(environment(who),HIW"                **************************************\n"NOR);
        ghost->move(environment(who));
        ghost->invocation(who);
	ghostb->move(environment(who));
        ghostb->invocation(who);
        call_out("check_status",1,who);
        call_out("message",2,who);
        call_out("round_14", 3, who);  
        return 1;
}
int round_14(object who)
{
        object ghost,ghostb;
	seteuid(getuid());
        ghostb=new("/d/death/HellZhen/18");
        seteuid(getuid());
        ghost=new("/d/death/HellZhen/14");
        tell_room(environment(who),"\nͻȻ��һ������������\n\n");
        tell_room(environment(who),RED"                **************************************\n"NOR);
        tell_room(environment(who),RED"                **               �ڰ���             **\n"NOR);
        tell_room(environment(who),RED"                **************************************\n"NOR);
        ghost->move(environment(who));
        ghost->invocation(who);
	ghostb->move(environment(who));
        ghostb->invocation(who);
        call_out("check_status",1,who);
        call_out("message",2,who);
        call_out("round_15", 3, who);  
        return 1;
}
int round_15(object who)
{
        object ghost;
        seteuid(getuid());
        ghost=new("/d/death/HellZhen/15");
        tell_room(environment(who),"\nͻȻ��һ������������\n\n");
        tell_room(environment(who),GRN"                **************************************\n"NOR);
        tell_room(environment(who),GRN"                **               ��ɽ��             **\n"NOR);
        tell_room(environment(who),GRN"                **************************************\n"NOR);
        ghost->move(environment(who));
        ghost->invocation(who);
        call_out("check_status",1,who);
        call_out("message",2,who);
        call_out("round_16", 3, who);  
        return 1;
}
int round_16(object who)
{
        object ghost,ghostb;
        seteuid(getuid());
        ghostb=new("/d/death/HellZhen/15");
        seteuid(getuid());
        ghost=new("/d/death/HellZhen/16");
        tell_room(environment(who),"\nͻȻ��һ������������\n\n");
        tell_room(environment(who),YEL"                **************************************\n"NOR);
        tell_room(environment(who),YEL"                **               Ѫ����             **\n"NOR);
        tell_room(environment(who),YEL"                **************************************\n"NOR);
        ghost->move(environment(who));
        ghost->invocation(who);
	ghostb->move(environment(who));
        ghostb->invocation(who);
        call_out("check_status",1,who);
        call_out("message",2,who);
        call_out("round_17", 3, who);  
        return 1;
}
int round_17(object who)
{
        object ghost,ghostb;
	seteuid(getuid());
        ghostb=new("/d/death/HellZhen/16");
        seteuid(getuid());
        ghost=new("/d/death/HellZhen/17");
        tell_room(environment(who),"\nͻȻ��һ������������\n\n");
        tell_room(environment(who),BLU"                **************************************\n"NOR);
        tell_room(environment(who),BLU"                **               ������             **\n"NOR);
        tell_room(environment(who),BLU"                **************************************\n"NOR);
        ghost->move(environment(who));
        ghost->invocation(who);
	ghostb->move(environment(who));
        ghostb->invocation(who);
        call_out("check_status",1,who);
        call_out("message",2,who);
        call_out("round_18", 3, who);  
        return 1;
}
int round_18(object who)
{
        object ghost,ghostb;
        seteuid(getuid());
        ghost=new("/d/death/HellZhen/18");
	seteuid(getuid());
	ghostb=new("/d/death/HellZhen/17");
        tell_room(environment(who),"\nͻȻ��һ������������\n\n");
        tell_room(environment(who),CYN"                **************************************\n"NOR);
        tell_room(environment(who),CYN"                **               �Ӹ���             **\n"NOR);
        tell_room(environment(who),CYN"                **************************************\n"NOR);
        ghost->move(environment(who));
        ghost->invocation(who);
	ghostb->move(environment(who));
        ghostb->invocation(who);
        call_out("check_status",1,who);
        call_out("winning", 3, who);  
        return 1;
}

�
