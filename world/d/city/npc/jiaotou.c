// cracked by vikee 2/09/2002   vikee@263.net
inherit NPC;

void create()
{
        set_name("��«ƽ", ({"fan luping", "fan"}));
        set("age", 32);
        set("gender", "����");
        set("long",
"һ���������ݵ�С���ӣ�����һ��ȭ��\n");
	set("title", "��ݽ�ͷ");
        set("attitude", "peaceful");

        set("combat_exp", 20000);
  set("daoxing", 5000);

        set("shen_type", 1);
	set("max_force", 200);
	set("force", 200);
	set("force_factor", 5);
        set_skill("unarmed", 30);
        set_skill("dodge", 30);
	set_skill("force", 30);
        set_skill("parry", 30);
	setup();
        carry_object("/d/obj/cloth/linen")->wear();
}

int recognize_apprentice(object ob)
{
	return 1;
}

�