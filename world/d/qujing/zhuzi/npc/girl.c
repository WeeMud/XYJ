// cracked by vikee 2/09/2002   vikee@263.net
// by snowcat oct 15 1997

inherit NPC;

void create()
{
  set_name("����", ({"gong fei","girl"}));
  set("gender", "Ů��");
  set("combat_exp", 10000);
  set("age", 15);
  set("per", 30);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 10);

  setup();
  set("chat_chance", 5);
  set("chat_msg", ({ (: random_move :) }));
  carry_object("/d/obj/cloth/gongpao")->wear();
}

