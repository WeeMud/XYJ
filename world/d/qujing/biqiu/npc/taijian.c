// cracked by vikee 2/09/2002   vikee@263.net
// by snowcat oct 22 1997

inherit NPC;

void create()
{
  set_name("̫��", ({"tai jian", "jian"}));
  set("gender", "����");
  set("combat_exp", 100000);
  set("age", 40);
  set("per", 25);
  set("attitude", "friendly");
  set("shen_type", 1);
  set("people", "people");
  set("force_factor",10);
  set("max_gin",500);
  set("max_kee",500);
  set("max_sen",500);
  set("max_force",600);
  set("max_mana",600);
  set_skill("unarmed", 40);
  set_skill("dodge", 40);
  set_skill("parry", 40);
  set_skill("force", 40);
  set_skill("spells", 40);
  setup();
  carry_object("/d/qujing/chechi/obj/gongpao")->wear();
}

