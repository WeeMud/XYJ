// cracked by vikee 2/09/2002   vikee@263.net
inherit NPC;

void create()
{
        set_name("��֪��", ({"he zhizhang", "he"}));
        set("age", 52);
        set("gender", "����");
	set("int", 35);
        set("long",
"��֪���ǹ��Ӽ��ѧʿ��ͳ��ȫ�����˿��Լ�������\n");
	set("title", "���Ӽ��ѧʿ");
        set("attitude", "friendly");
	set("class", "scholar");
        set("combat_exp", 40000);
  set("daoxing", 100000);

        set("shen_type", 1);
	set("max_force", 400);
	set("force", 400);
	set("force_factor", 5);
        set_skill("unarmed", 60);
        set_skill("dodge", 60);
        set_skill("parry", 60);
	set_skill("literate", 150);
	setup();
     //   carry_object(__DIR__"obj/choupao")->wear();
}


�