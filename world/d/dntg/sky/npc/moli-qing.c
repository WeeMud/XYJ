// cracked by vikee 2/09/2002   vikee@263.net
// tianwang.c

inherit NPC;
string send_me(object me);
void create()
{
        set_name("ħ����", ({ "moli qing", "zengzhang tianwang", "qing", "tianwang" }) );
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
	set("combat_exp",3000000);
        set("daoxing",3000000);
	set("force",2500);
	set("max_force",1500);
	set("mana",2500);
	set("max_mana",1600);
	set("force_factor", 120);
	set("mana_factor",120);
	

        set("eff_dx", 1500000);
        set("nkgain", 800);


	set_skill("unarmed",220);
	set_skill("yingzhaogong", 220);
	set_skill("parry",220);
	set_skill("dodge",220);
	set_skill("spear",220);
	set_skill("bawang-qiang",220);
	set_skill("force",220);
	set_skill("spells", 220);
	set_skill("moshenbu", 220);
	map_skill("dodge", "moshenbu");
	map_skill("parry", "bawang-qiang");
	map_skill("spear","bawang-qiang");
	map_skill("unarmed", "yingzhaogong");
	set("inquiry", ([
		"name" : "������������ħ���࣬��ʥ�Ͱ��������š�",
		"here" : "�������������, ���ھ�������ˡ�",
		"��ȥ": (: send_me :),
		"back": (: send_me:),
	]) );

	setup();
	carry_object("/d/obj/fabao/qingyun-baojian");
	carry_object("/d/obj/weapon/spear/jinqiang")->wield();
	carry_object("/d/obj/armor/jinjia")->wear();
}

string send_me(object me)
{
        me=this_player();
	        if( me->is_fighting() )
		return ("���������鷳�����Ҫ���㣡\n");
        if( me->is_busy() || me->query_temp("pending/exercising"))
		return ("æ����˵�ɡ�����\n");

	message_vision("��������������Ц����$N˵����������������ȥ��\n", me);
	message_vision("������������һ�Ű�$N������ȥ������\n", me);
        me->move("/d/changan/nbridge");
	tell_room( environment(me), "�����ˡ�һ���������ϵ��¸�������\n", ({me}));
	write("�������ˤ�����������˸��������ף�\n");
	return ("�Ϸ��������������\n");
}

int accept_fight(object me)
{
    object ob=this_object();

    if( living(ob) )
      {
/*
      ob->set("eff_kee",3100);
      ob->set("kee",3100);
      ob->set("eff_sen",3100);
      ob->set("sen",3100);
      ob->set("force",2500);
      ob->set("mana",2500);
*/
      message_vision("$N˵����ҲҪ��֪����������������\n", ob);
      }
        return 1;
}

void kill_ob (object me)
{
        object ob=this_object();

    if( living(ob) )
      {
/*
        ob->set("eff_kee",3100);
        ob->set("kee",3100);
        ob->set("eff_sen",3100);
        ob->set("sen",3100);
        ob->set("force",2500);
        ob->set("mana",2500);
*/
        message_vision("$N˵�������������죡\n", ob);
       }

	::kill_ob(me);

}

