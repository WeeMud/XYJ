// cracked by vikee 2/09/2002   vikee@263.net
// lao ren, 9-28-97 pickle

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

string kick_back();

void create()
{
  set_name("�׷�����", ({ "lao ren", "lao", "laoren","ren", "baifa", "immortal", "master", "shifu" }));

  set("gender", "����");
  set("age", 100);

  set("str", 20);
  set("per", 130);
  set("cor", 30);
  set("cps", 75);
  set("kar", 100);
  set("int", 40);
  set("con", 40);
  set("spi", 40);

  set("long","
����һλ�׷�ͯ�յ����ˡ����������ƺ����ϵ����ӣ�
��ƫ���Ǻ�����档�������������������Ͱ���Ц��
һЦ��

");
  set("title", "����");
  set("combat_exp", 2000000);
  set("daoxing", 2000000);


  set_skill("literate", 150);
  set_skill("unarmed", 150);
set_skill("force", 180);
  set_skill("lengquan-force", 180);
  set_skill("axe", 180);
  set_skill("spear", 180);
  set_skill("dodge", 200);
  set_skill("parry", 180);
  set_skill("sanban-axe", 180);
  set_skill("mace", 180);
  set_skill("spells", 160);
  set_skill("baguazhou", 160);
  set_skill("yanxing-steps", 180);
  map_skill("force", "lengquan-force");
  map_skill("spells", "baguazhou");
  map_skill("axe", "sanban-axe");
  map_skill("parry", "sanban-axe");
  map_skill("dodge", "yanxing-steps");
  map_skill("sword", "xiaofeng-sword");

  set("max_sen", 4500);
  set("max_kee", 3500);
  set("force", 1500); 
  set("max_force", 1500);
  set("force_factor", 40);
  set("max_mana", 3000);
  set("mana", 3000);
  set("mana_factor", 50);

  set("inquiry", ([
	"name"    : "����˭����Ҳ���ǵ��ˡ�",
	"here"    : "����һ���Ρ�",
	"rumors"  : "��Ϣ���㲻ר��ѧ�գ���������ʲô��Ϣ��",
	"��ȥ"    : (: kick_back :),
	"return"  : (: kick_back :),
]) );

  create_family("������", 1, "��");

  setup();
  carry_object("/d/obj/weapon/axe/huafu")->wield();
  carry_object("/d/obj/cloth/linen")->wear();
}

string kick_back()
{
    object me=this_player();

    message_vision(CYN"$ņ�ֳ�$N��ǰ���͵�һ�ģ�������ȥ����\n"NOR, me, this_object());
    message_vision(CYN"$N����Ӱ������ȥ�ˣ�����\n"NOR, me);
    me->move("/d/jjf/guest_bedroom");
    message_vision("$NͻȻ��������ԭ�����Ͽ�һ�Σ�����\n", me);
    return "";
}
int accept_fight(object me)
{
  command("say ���������ˣ��������Ǵ󡣱𶯴ֱ𶯴֣�");
  return 0;
}

void attempt_apprentice(object me)
{
  int effstr=(int)(me->query("str")+me->query_skill("unarmed",1)/10-2);
  string myrespect=RANK_D->query_respect(me);

  if (wizardp(me) && me->query("env/override"))
  {
	command("recruit "+me->query("id"));
	return;
  }
  if (me->query("family/master_id") != "cheng yaojin"
   || !me->query_temp("jjf/�׷���Ե"))
  {
	command("say �⡣�����Ϸ�����������Ե֮�ˣ�"+myrespect+"���ǻ�ȥ�ɡ�");
	return;
  }
  if (effstr<30)
  {
      command("say "+myrespect+"�ı�������Щ����������ѧ����");
      return;
  }
  command("nod");
  command("say ����"+myrespect+"������Ե���Ϸ��������ɣ�\n");
  command("recruit " + me->query("id") );
  return;
}
int recruit_apprentice(object ob)
{
  if( ::recruit_apprentice(ob) )
    ob->set("class", "fighter");
}
�
