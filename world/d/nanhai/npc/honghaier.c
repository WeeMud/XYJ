// cracked by vikee 2/09/2002   vikee@263.net
// honghaier.c �캢��
// By Dream Dec. 20, 1996

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("�캢��", ({ "honghaier" }));
	set("title", "�Ϻ�����֮ͽ");   
	set("long", @LONG
������ţħ��֮�ӣ����Ժö������Ϻ������շ���Ƣ��ȴ������ʲô��ת��
��ʹ��һ�ֵĺ�ǹ��������ǹ�������е��֣�Ѱ�����ǲ��������ġ�
LONG);
	set("gender", "����");
	set("age", 15);
	set("attitude", "heroism");
	set("max_kee", 750);
	set("max_gin", 600);
	set("max_sen", 750);
	set("force", 450);
	set("max_force", 300);
	set("force_factor", 20);
	set("max_mana", 350);
	set("mana", 500);
	set("mana_factor", 50);
	set("combat_exp", 240000);
	set("daoxing", 400000);

	set_skill("literate", 80);
	set_skill("spells", 100);
	set_skill("buddhism", 100);
	set_skill("unarmed", 60);
	set_skill("jienan-zhi", 60);
	set_skill("dodge", 80);
	set_skill("lotusmove", 80);
	set_skill("parry", 80);
	set_skill("force", 80);
	set_skill("lotusforce", 70);
	set_skill("staff", 50);
	set_skill("lunhui-zhang", 40);
	set_skill("spear", 120);
	set_skill("huoyun-qiang", 150);
	map_skill("spells", "buddhism");
	map_skill("unarmed", "jienan-zhi");
	map_skill("dodge", "lotusmove");
	map_skill("force", "lotusforce");
	map_skill("parry", "huoyun-qiang");
	map_skill("staff", "lunhui-zhang");
	map_skill("spear", "huoyun-qiang");
	set("chat_chance_combat", 40);
	set("chat_msg_combat", ({
		(: cast_spell, "bighammer" :),
		(: cast_spell, "jingang" :),
	}) );

	create_family("�Ϻ�����ɽ", 2, "����");

	setup();
	carry_object("/obj/money/gold");
	carry_object("/obj/money/gold");
	carry_object("/obj/cloth")->wear();
	carry_object("/d/nanhai/obj/jingu2");
	carry_object("/d/nanhai/obj/huojianqiang")->wield();
}

void attempt_apprentice(object ob)
{
	if (((int)ob->query_skill("buddhism", 1) < 50 )) {
		command("say " + RANK_D->query_respect(ob) + "�ķ����л�������������Ŭ�����ǣ�");
		return;
	}
	command("smile");
	command("say �ܺã��Ҿ������㣬ϣ������Ŭ�������������\n");

	command("recruit " + ob->query("id") );
	return;
}

�
