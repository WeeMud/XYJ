// cracked by vikee 2/09/2002   vikee@263.net
//created 8-8-97 pickle
//�޴�
 

inherit F_MASTER;
inherit NPC;
string try_me(object me);

void create()
{
  set_name("�޴�", ({"luo chun", "luo", "chun", "luochun"}));
  set ("long", @LONG
�޴����޸����ĸ��ҽ����������ǵ�������˵�������յ�˽���ӣ�
���޳ɵ��׸�硣�޴���һ�ְ���ǹʹ�ô����ޱȣ���ս��������
����ս����
LONG);

  set("title", "�޸��ҽ�");
  set("gender", "����");
  set("age", 40);
  set("str", 50);
  set("cor", 50);
  set("cps", 50);
  set("spi", 15);
  set("per", 25);
  set("con", 50);
  set("int", 25);
  set("kar", 10);
  set("combat_exp", 1000000);
  set_skill("force", 100);
  set_skill("lengquan-force", 100);
  set_skill("parry", 100);
  set_skill("dodge", 100);
  set_skill("yanxing-steps", 100);
  set_skill("unarmed", 100);
  set_skill("changquan", 100);
  set_skill("spear", 200);
  set_skill("bawang-qiang", 200);
  map_skill("force", "lengquan-force");
  map_skill("unarmed", "changquan");
  map_skill("spear", "bawang-qiang");
  map_skill("parry", "bawang-qiang");
  map_skill("dodge", "yanxing-steps");
  set("max_sen", 600);
  set("max_kee", 1200);
  set("force", 2000);
  set("max_force", 1500);
  set("force_factor", 20);
 
  create_family("������", 2, "��");
  setup();
 
  carry_object("/d/obj/weapon/spear/tieqiang")->wield();
  carry_object("/d/obj/armor/tiejia")->wear();
}

int accept_fight(object me)
{
  command("say �������ܣ����¾�����¥�ϵĹ��ˣ�\n");
  return 0;
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