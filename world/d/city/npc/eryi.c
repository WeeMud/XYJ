// cracked by vikee 2/09/2002   vikee@263.net
inherit NPC;

void create()
{
        set_name("����̫", ({"er yitai", "yitai"}));
        set("age", 22);
        set("gender", "Ů��");
        set("long",
"��ҵĶ���̫̫�����㿴�����������˸����ۣ�\n");
        set("attitude", "friendly");
	set("per", 22);
        set("combat_exp", 1000);
        set("shen_type", 1);
        set_skill("unarmed", 10);
        set_skill("dodge", 40);
	setup();

        carry_object("/d/obj/cloth/nichang")->wear();
	carry_object("/d/obj/cloth/yuanxiang")->wear();
}
