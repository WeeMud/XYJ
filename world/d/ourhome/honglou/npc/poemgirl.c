// cracked by vikee 2/09/2002   vikee@263.net
// poemgirl.c

inherit NPC;

#include <ansi.h>

int send_back(object me);

void create()
{
	set_name("̽��", ({ "tan chun", "chun", "girl" }) );
	set("gender", "Ů��" );
	set("age", 16);
	set("combat_exp", 200000);
	set("attitude", "friendly");
	set_skill("literate", 100);
	set_skill("dodge", 100);
	setup();
	carry_object("/d/obj/cloth/skirt")->wear();
	carry_object("/d/obj/cloth/shoes")->wear();
}
