// cracked by vikee 2/09/2002   vikee@263.net
//mugu.c

inherit NPC;
string ask_for_leave();

void create()
{
        set_name("���", ({"magu"}));
        set("gender", "Ů��" );
        set("age", 35);
        set("title","�¹��ܼ�");
        set("long", "������¹�������������һ���֡�\n");
        set("combat_exp", 100);
  set("daoxing", 5000);

        set("attitude", "peaceful");
        set("per", 15);
        set("max_kee", 200);
        set("max_gin", 100);
        set("max_sen", 100);
        set("inquiry", ([
		"����" : (: ask_for_leave :),
		"leave" : (: ask_for_leave :),
		]) );
	setup();
        carry_object("/d/ourhome/obj/pink_cloth")->wear();
        carry_object("/d/ourhome/obj/shoes")->wear();
}

void init()
{
        add_action("do_agree", "agree");
}

string ask_for_leave()
{
	object me=this_player();

	if (me->query("family/family_name") == "�¹�" ) {
		command("say �����ִ����ɽ������ȴ�м��仰˵��");
		me->set_temp("betray", 1);
		return ("����ʦ��Ҫ��Ҫ��һ���ͷ������Ը��(agree)��");
	}

	return ("����֪��\n");
}

int do_agree(string arg)
{
	if(this_player()->query_temp("betray")) {
		message_vision("$N���������Ը�⡣\n\n", this_player());
		command("say ���������¹���Ե�������ɽȥ�ɣ�");
		this_player()->add("betray/count", 1);
		this_player()->add("betray/moon", 1);
		this_player()->set("combat_exp", this_player()->query("combat_exp")*80/100);
		this_player()->set("daoxing", this_player()->query("daoxing")*80/100);
		if( this_player()->query_skill("moonshentong") )
		    this_player()->delete_skill("moonshentong");
		if( this_player()->query_skill("snowsword") )
	            this_player()->delete_skill("snowsword");

		
		this_player()->delete("family");
		this_player()->delete("class");
		this_player()->set("title", "��ͨ����");
		this_player()->set_temp("betray", 0);
		this_player()->save();
		command("say �����粨���ƶ����Σ�����Ϊ֮������\n");
		return 1;
	}
}

�
