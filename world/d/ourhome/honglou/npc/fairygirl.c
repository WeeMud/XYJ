// cracked by vikee 2/09/2002   vikee@263.net
// fairygirl.c
// 1996/10/31 by none...modified:)

inherit NPC;

#include <ansi.h>

int send_back(object me);

void create()
{
	set_name("�����ɹ�", ({ "fairy girl", "fairy", "girl" }) );
	set("gender", "Ů��" );
	set("age", 18);
	set("long",
		"�������Σ���÷��ѩ��������Σ�������˪��
�侲���Σ������չȡ��������Σ�ϼӳ������
�������Σ��������ӡ��������Σ����亮����\n");
	set("combat_exp", 200000);
	set("attitude", "friendly");
	set("inquiry", ([
		"name" : "̫��þ������ɹ���Ҳ��",
		"here" : "�����֮�ϣ���֮�С�",
		"̫��þ�" : "̫�����飬�þ����ľ�",
		"��" : "ׯ���ε���������ׯ������",
		"����" : "ׯ���ε���������ׯ������",
		"��" : "ľͷ��ľͷ����������δ�ѣ�������˽��Ρ�",
		"����" : "ľͷ��ľͷ����������δ�ѣ�������˽��Ρ�",
		"��ȥ" : (: send_back :),
		"back" : (: send_back :),
		
	]) );
	set_skill("literate", 100);
	set_skill("dodge", 100);
	setup();
	carry_object("/d/obj/cloth/skirt")->wear();
	carry_object("/d/obj/cloth/shoes")->wear();
}

int send_back(object me)
{
	object home = find_object("/d/ourhome/honglou/fairyplace");
	if( !environment()
	||	environment()==home )
	{
		me=this_player();
		command("sigh " + me->query("id"));
		command("say " + "����һ��ľͷ...�ã������ȥ�ɡ�\n");
		tell_object(me,"\n�����ɹ����泤�䣬������ǰһ��...\n\n�������۾������˹�����\n\n");
		if(!me->query("dream_place")) me->move("/d/changan/pinqiting");
		else me->move((string)me->query("dream_place"));
		return 1;
	}
	else
	{
		return_home(home);
		return 1;
	}
}


