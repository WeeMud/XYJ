// cracked by vikee 2/09/2002   vikee@263.net
inherit NPC;

void create()
{
       set_name("武士", ({"wushi", "shi"}));

set("long","一个穿着盔甲的大虾米，正走来走去维护秩序．\n");
       set("gender", "男性");
       set("age", 20+random(5));
	set("per", 10);
	set("str", 22);
       set("attitude", "heroism");
       set("shen_type", 1);
        set("combat_exp", 60000);
  set("daoxing", 60000);

        set_skill("parry", 60);
        set_skill("dodge", 60);
	set_skill("unarmed", 60);
	set("force", 200);
	set("max_force", 200);
        set("force_factor", 5);
	set("max_kee", 500);
	set("max_sen", 400);
        setup();
        carry_object("/d/obj/armor/tiejia")->wear();

}

�