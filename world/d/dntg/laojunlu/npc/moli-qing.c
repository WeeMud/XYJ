// cracked by vikee 2/09/2002   vikee@263.net
// tianwang.c

#include <ansi.h>
inherit NPC;
void create()
{
        object ob;

        set_name("ħ����", ({ "tian wang", "zengzhang tianwang", "qing", "tianwang" }) );
        set("gender", "����" );
	set("long",
		"��������Ϊ�Ĵ�����֮��, ��߶����ĳ�, ����һ�˳�ǹ, \n"
		"ǹ���Ƿ��켫, �����ܴ������Ʊ�����, ���أ�ˮ���𣬷硹\n"
		"��ʽһ��, ���޽���Ҳ���ӡ�\n"
	);
	set("age",50);
	set("title", "��������");
	set("attitude", "heroism");
	set("str",40);
	set("int",30);
	set("max_kee",3100);
	set("kee",3100);
	set("max_sen",3100);
	set("sen",3100);
	set("combat_exp",4000000);
        set("daoxing",3500000);
	set("force",2500);
	set("max_force",1500);
	set("mana",2500);
	set("max_mana",1600);
	set("force_factor", 120);
	set("mana_factor",120);
	

        set("eff_dx", 3500000);
        set("nkgain", 800);


	set_skill("unarmed",180);
	set_skill("yingzhaogong", 180);
	set_skill("parry",180);
	set_skill("dodge",180);
	set_skill("sword",180);
	set_skill("ningxie-force",180);
	set_skill("bainiao-jian",180);
	set_skill("force",180);
	set_skill("spells", 180);
	set_skill("moshenbu", 180);
	map_skill("dodge", "moshenbu");
	map_skill("force", "ningxie-force");
	map_skill("parry", "bainiao-jian");
	map_skill("sword","bainiao-jian");
	map_skill("unarmed", "yingzhaogong");

        set("chat_chance_combat", 60);
  	set("chat_msg_combat", ({
                (: perform_action, "sword", "chaofeng" :),
  	}) );

	setup();

        ob=carry_object("/d/obj/weapon/sword/qingfeng");
        ob->wield();
        ob->set_name("���Ʊ���", ({ "sword", "bao jian" }) );

	carry_object("/d/obj/armor/jinjia")->wear();
}




void die ()
{
  object me = this_object();
  message_vision (HIY"$N�ŵ����Ⱦ��ܡ�\n"NOR,me);
  destruct (this_object());
  return ;
}

