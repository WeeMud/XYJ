// cracked by vikee 2/09/2002   vikee@263.net
inherit ROOM;

void create ()
{
	set ("short", "Ѱ��̨");
	set ("long", @LONG

Ѱ��̨����������ʯ�̾ͣ������������̫��֮�⡣̨�з�
һ�߸�ͭ¯��¯��С���е������̡�̨���г߸߻������Ե�����
�Զ��ɽ�£�����ɽ�����ޣ�ˮ������������г���֮�⡣��
���ƺ���������(play)��
LONG);

	set("exits", 
	([ //sizeof() == 4
		"northdown" : __DIR__"eastway1",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		//__DIR__"npc/qingfeng" : 1,
		__DIR__"npc/hanxiangzi" : 1,
	]));


	set("outdoors", "wuzhuang");

	setup();
}

void init()
{
        add_action("do_play", "play");//add by hexiu
}

int do_play(string arg)
{	
	
	int sen_cost, kee_cost, force_cost, sk, gain;
	object me=this_player();
	object weapon = me->query_temp("weapon");
	
	sk=(int)me->query_skill("zouxiao", 1);
	


	if( !arg || (arg != "xiao"))
		return notify_fail("��Ҫ����ʲô��\n");
	if( me->is_busy() )
		return notify_fail("��æ�ĺܣ����й���ȥ���࣡\n");
	if (!weapon || weapon->query("music/type") != "xiao")
                return notify_fail("������ļһﴵ�������ӡ�\n");
	if( me->is_fighting() )
		return notify_fail("��ѧ�������������ˣ�\n");
	if( (int)me->query_skill("literate", 1) < 100)
          return notify_fail("��äҲ�����ɣ�\n");
	if (me->query_skill_mapped("force")!="zhenyuan-force")
                return notify_fail("ֻ������Ԫ�񹦲����������\n");
	if( (int)me->query("max_force") < 1000)
		return notify_fail("��������㣬�Ѿ�������ȫ�ˡ�\n");
	
	if( sk < 199)
		return notify_fail("�㴵�˰��죬ȴһֱû�н�չ��\n");
	
	//if( sk >= 300)
	//	return notify_fail("��������һ���ƺ���������\n");
	
	sen_cost = 80 - (int)me->query_int();
	if( (int)me->query("sen") < sen_cost )
		return notify_fail("������ͷ�����ͣ�����Ϣ��Ϣ�ˡ�\n");

	kee_cost = 80 - (int)me->query_con();
	if( (int)me->query("kee") < kee_cost )
		return notify_fail("�����ڻ�������������Ϣ��Ϣ�ˡ�\n");

	force_cost = 20;
	if( (int)me->query("force") < force_cost )
		return notify_fail("���������᲻�����ˣ�����Ϣ��Ϣ�ˡ�\n");

	me->receive_damage("sen", sen_cost);
	me->receive_damage("kee", kee_cost);
	me->add("force", - force_cost);
	me->start_busy((int)(sk/100)+random(3));

	
    gain = sk/2+random(10);
    
	me->improve_skill("zouxiao", gain);

	write("��������һ���������渣���ԡ�����֮�����������˽⡣\n");

	tell_room( environment(me), me->name() + "������һ���������渣�ɪɪ������\n", ({me}));

	return 1;
}