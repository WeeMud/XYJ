// cracked by vikee 2/09/2002   vikee@263.net

inherit "/d/dntg/hell/wang.c";

void create()
{
  set_name("������", ({"chuguan wang", "wang", "chuguan"}));
  set("title", "����ʮ��֮");
  set("gender", "����");
  set("age", 60);
  set("class", "youling");
  set("attitude", "peaceful");
  set("shen_type", 1);
  set("per", 30);
  set("int", 30+random(5));
        set("max_kee", 1700);
        set("max_gin", 1700);
        set("max_sen", 1700);
        set("force", 1500);
        set("max_force", 1500);
        set("force_factor", 60);
        set("max_mana", 1500);
        set("mana", 1500);
        set("mana_factor", 50);
        set("combat_exp", 1500000);
        set("daoxing", 2000000);

        set("eff_dx", 600000);
        set("nkgain", 600);

        set_skill("spells", 150);
        set_skill("gouhunshu", 150);
        set_skill("unarmed", 150);
        set_skill("dodge", 150);
        set_skill("parry", 150);
        set_skill("force", 150);
        set_skill("tonsillit", 150);
        set_skill("jinghun-zhang", 150);
        set_skill("ghost-steps", 150);
        map_skill("unarmed", "jinghun-zhang");
        map_skill("dodge", "ghost-steps");
        map_skill("spells", "gouhunshu");
        map_skill("force", "tonsillit");

        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: cast_spell, "invocation" :),
                (: cast_spell, "curse" :),
                (: cast_spell, "inferno" :)
        }) );
  
  setup();
  carry_object("/d/obj/cloth/mangpao")->wear();
}


�
