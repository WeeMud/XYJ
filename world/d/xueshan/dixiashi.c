// cracked by vikee 2/09/2002   vikee@263.net
//standroom.c used by weiqi...others may hate this format:D
//dixiashi.c

inherit ROOM;

void create ()
{
	set ("short", "������");
	set ("long", @LONG

��ȷû�뵽Сľ�ݵ��¾�Ȼ������ôһ�䲼�þ��ɵĵ����ҡ�
����Ҳ������һ�������濿ǽ�����˴��СС�Ļ��裬������
�Ÿ�ʽ�����в������ӵĻ��ݡ���һ������һ�ſ������൱��
�ʵĴ��̣���������һλ����������ʮ��������ˡ���������
�ڵƵƹ����Ե����粻������Щ˵�����Ĺ��졣
LONG);

	//set("item_desc", ([" *** " : " *** ", ]));
	//for look something.

	set("exits", 
	([ //sizeof() == 4
		//"south" : __DIR__"xiaomuwu",
		//"north" : __DIR__"eroad2",
		//"west" : __DIR__"eroad1",
		//"east" : __DIR__"eroad3",
		//"up" : __DIR__"***",
		//"down" : __DIR__"***",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		__DIR__"npc/dapeng" : 1,
	]));


	//set("outdoors", "xuesan");

	setup();
}

void init()
{
	add_action("do_knock", "knock");
	add_action("do_knock", "qiao");
}

int do_knock(string arg)
{
	object me, uproom;
	
	me=this_player();

	if( !arg || (arg != "wall" && arg != "qiang" && arg != "ǽ" && arg != "ǽ��" ) )
		return notify_fail("��Ҫ��ʲô��\n");       

/*
	if( !(uproom = find_object(__DIR__"xiaomuwu")) )
		uproom = load_object(__DIR__"xiaomuwu");

	if( uproom = find_object(__DIR__"xiaomuwu") )
	{
		uproom->open_down();
		return 1; 
	}
	else return notify_fail("�����ӻ��س�ë���ˣ������ĵ�һ�Ȱɡ�\n");
*/
	call_out("open_up", 1);
	return 1; 
}

void open_up()
{
	object uproom; 

/*
	if( !(uproom = find_object(__DIR__"xiaomuwu")) )
		uproom = load_object(__DIR__"xiaomuwu");
*/

	if( uproom = find_object(__DIR__"xiaomuwu") ) 
	{
		set("exits/up", __DIR__"xiaomuwu");
		uproom->set("exits/down", __FILE__);
		message("vision", "���ӵ���ͻȻ����������������¶��һ�����µĶ��ڣ�������һ�����ݡ�\n", uproom );
		message("vision", "�컨���Ϻ�Ȼ����������������һ�����ݴ���������\n", this_object() );
	}

	call_out("close_up", 10);
}

void close_up()
{
	object uproom;

	if( !query("exits/up") ) return;

	message("vision", "�컨���Ϸ������������������ݱ�������ȥ��\n", this_object() );

	if( uproom = find_object(__DIR__"xiaomuwu") ) 
	{
		message("vision", "���ӵ��·��������������������ַ����ˡ�\n", uproom );
		uproom->delete("exits/down");
	}

	delete("exits/up");
}


