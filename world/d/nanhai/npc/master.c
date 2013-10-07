// cracked by vikee 2/09/2002   vikee@263.net
// master.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

string ask_for_join();

void create()
{
	set_name("���Ǻ���", ({ "master bonze", "master", "bonze" }) );

	set("gender", "����");
	set("age", 74);
	set("attitude", "peaceful");
	set("class", "bonze");
	set("apprentice_available", 10);

	set("str", 17);
	set("int", 30);
	set("spi", 30);
	set("con", 30);
	set("cps", 30);
	set("cor", 20);

	set("atman", 2000);
	set("max_atman", 2000);

	set("force", 1500);
	set("max_force", 1500);
	set("force_factor", 5);

	set("mana", 600);
	set("max_mana", 600);

	set("combat_exp", 1000000);
  set("daoxing", 1000000);

	set("score", 9000);

	set("inquiry", ([
		"���" : (: ask_for_join :),
		"����" : (: ask_for_join :),
	]) );

	set_skill("staff", 100);
	set_skill("unarmed", 80);
	set_skill("force", 100);
	set_skill("dodge", 30);
	set_skill("literate", 60);
	//set_skill("chanting", 100);
	set_skill("parry", 50);
	set_skill("magic", 100);

	//set_skill("cloudstaff", 100);
	set_skill("lotusforce", 100);
	set_skill("buddhism", 100);
	//set_skill("essencemagic", 100);

	map_skill("staff", "cloudstaff");
	map_skill("parry", "cloudstaff");
	map_skill("force", "lotusforce");
	//map_skill("magic", "essencemagic");

	create_family("ɽ����", 26, "ס��");

	setup();

	//carry_object(__DIR__"buddha_staff")->wield();
}

void init()
{
	add_action("do_kneel", "kneel");
}

string ask_for_join()
{
	object me;

	me = this_player();

	if( (string)me->query("class")=="bonze" )
		return "�����ӷ�����ͬ�ǳ����ˣ��ιʸ����Ŀ������Ц��\n";
	if( (string)me->query("gender") != "����" )
		return "�����ӷ�Ůʩ�����������������������ȥ��Ȱɡ�\n";

	me->set_temp("pending/join_bonze", 1);
	return "�����ӷ����գ����գ�ʩ������������ҷ������(kneel)�ܽ䡣\n";
}

int do_kneel()
{
	string *prename =
	 ({ "��", "��", "Բ", "��", "��", "��",
		"��", "��", "��", "��" });
	string name, new_name;

	if( !this_player()->query_temp("pending/join_bonze") ) return 0;
	message_vision(
		HIC "$N˫�ֺ�ʮ�����������ع���������\n\n"
			"$n������ƣ���$Nͷ�������Ħ���˼��£���$N��ͷ��������ȥ��\n\n" NOR,
		this_player(), this_object() );
	name = this_player()->query("name");
	new_name = prename[random(sizeof(prename))] + name[0..1];
	command("say �ӽ�������ķ�������" + new_name + "��");
	command("smile");
	this_player()->delete_temp("pending/join_bonze");
	this_player()->set("name", new_name);
	this_player()->set("class", "bonze");

	return 1;
}

void attempt_apprentice(object ob)
{
	if( query("apprentice_available") ) {
		if( find_call_out("do_recruit") != -1 )
			command("say ������һ��һ������");
		else
			call_out("do_recruit", 2, ob);
	} else {
		command("say ���ɽ����Ѿ�����ʮ�����ӣ���������ͽ�ˡ�");
	}
}

void do_recruit(object ob)
{
	if( (string)ob->query("gender") != "����" )
		command("say �����ӷ�Ůʩ����Ҫ�����ɿ���Ц��");
	else if( (string)ob->query("class") != "bonze" )
		command("say �����ӷ�ʩ��Ը����ţ����ȵ�С����ȳ��ҡ�");
	else {
		command("say �����ӷ����գ����գ�");
		command("recruit " + ob->query("id") );
	}
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) ) {
		add("apprentice_availavble", -1);
		return 1;
	}
}

int accept_fight(object me)
{
	if( (string)me->query("class")=="bonze" )
		command("say �����ӷ𣡳����˽��ǿ�񶷣����Ĳ���Υ����档");
	else
		command("say ʩ����Ȼ�����գ�����������ǣ�Ҳ���ؽ����ˡ�");
	
	return 0;
}
�