// cracked by vikee 2/09/2002   vikee@263.net
// yahuan1.c

inherit NPC;

void create()
{
       set_name("Ѿ��", ({"yahuan"}));
       set("long","һ��СѾ�������ź���ţ�\n");
       set("gender", "Ů��");
       set("age", 16);
       set("attitude", "friendly");
       set("shen_type", 1);
	set("combat_exp", 500);
	setup();
        carry_object("/d/gao/obj/pink_cloth")->wear();
}

