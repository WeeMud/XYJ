// cracked by vikee 2/09/2002   vikee@263.net
// gao.c

inherit NPC;
void create()
{
       set_name("��Ա��", ({"gao yuanwai", "gao"}));

set("long","�߼�ׯ�����ˣ��Ե��ֺ����ģ�\n��˵�����Ӧ���ֺǺǵأ���ȴ��ü����������������ʲô���£�\n");
       set("gender", "����");
       set("age", 46);
       set("title", "ׯ��");
       set("attitude", "peaceful");
       set("shen_type", 1);
	set("combat_exp", 5000);
        set_skill("unarmed", 15);
	set_skill("dodge", 30);
	set_skill("parry", 15);
set("inquiry", ([
"name": "�Ϸ��ոߣ����Ǽ��е����ˣ�\n",
"here": "����ׯ��Ҳ��\n",
]) );

	setup();
       add_money("silver", 3+random(5));
	carry_object("/d/ourhome/obj/choupao")->wear();
}
int accept_object(object who,object ob)
{
        object m;
        if (ob->query("id")=="mmmmmm") {
                say("��ׯ��Ц������л"  + RANK_D->query_respect(who) +
"���Ϸ����������ˣ�\n��ׯ��˵����������ǰһ����ʿ���µģ�Ҳ��������ã�\n");
	m=new("/d/gao/obj/pa_book");
        m->move(who);
	call_out("destroy", 1, ob);
	return 1;
        }
	else return 0;
}
void destroy(object ob)
{
        destruct(ob);
        return;
}

