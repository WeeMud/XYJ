// cracked by vikee 2/09/2002   vikee@263.net
//qinping.c
//created 5-10-97 pickle

inherit F_MASTER;
inherit NPC;
string try_me(object me);

void create()
{
  set_name("�ظ�", ({"qin fu", "qin", "fu", "master"}));
  set("title", "�������ܼ�");
  set("gender", "����");
  set("age", 38);
  set("str", 30);
  set("int", 25);
  set_skill("spear", 60);
  set_skill("force", 75);
  set_skill("dodge", 60);
  set_skill("parry", 60);
  set_skill("yanxing-steps", 60);
  set_skill("bawang-qiang", 60);
  set_skill("lengquan-force", 75);
  set_skill("unarmed", 75);
  set_skill("changquan", 75);
  map_skill("force", "lengquan-force");
  map_skill("unarmed", "changquan");
  map_skill("spear", "bawang-qiang");
  map_skill("parry", "bawang-qiang");
  map_skill("dodge", "yanxing-steps");
  set("max_sen", 200);
  set("max_kee", 700);
  set("force", 550);
  set("max_force", 500);
  set("force_factor", 30);
  set("combat_exp", 75000);

  setup();
  
  create_family("������", 3, "��");
  carry_object("/d/obj/armor/tenjia")->wear();
  carry_object("/d/obj/weapon/spear/tieqiang")->wield();
}

int attempt_apprentice(object me)
{
  string myname=RANK_D->query_respect(me);
  command("pat "+me->query("id"));
  command("say �ܺã�ʱ����������֮��"+myname+"���Ŭ�������ձض��гɡ�");
  command("recruit " + me->query("id") );
  return 1;
}
int recruit_apprentice(object ob)
{
  if( ::recruit_apprentice(ob) )
    ob->set("class", "fighter");
}


