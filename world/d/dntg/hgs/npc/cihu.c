// cracked by vikee 2/09/2002   vikee@263.net
inherit NPC;

void create()
{
  set_name("����", ({"ci hu","bird"}));
  set("race", "Ұ��");
  set("long","һֻ���������ſ�һ�Դ����ڿ������\n");
  set("age", 20);
  set("combat_exp", 50000);
  set("limbs", ({ "ͷ��", "����", "���", "���","�ҽ�", "β��" }) );
  set("verbs", ({ "bite"}));

  set_skill("dodge", 20);
  set_skill("parry", 20);
  set_skill("unarmed", 20);

  setup();
}
