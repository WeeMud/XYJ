// cracked by vikee 2/09/2002   vikee@263.net
inherit NPC;

void create()
{
	set_name("�ϴ���", ({ "lao daniang", "woman", "daniang" }) );
        set("gender", "Ů��" );
	set("age", 60);
	set("long", "һ�����ݺͰ����ϴ��\n");
        set("per", 26);
	set("combat_exp", 100);
	set("attitude", "friendly");

	set("chat_chance",30);
	setup();
	
	carry_object("/d/obj/cloth/linen.c")->wear();
	add_money("coin", 60);
}
