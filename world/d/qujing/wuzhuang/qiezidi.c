// cracked by vikee 2/09/2002   vikee@263.net
//qiezidi.c

inherit ROOM;

void create ()
{
	set ("short", "���ӵ�");
	set ("long", @LONG

��ׯ�����µĶ࣬�Է���Ҳ���٣����Թ��ڹ��˸�����һЩũ��
�����߲˹Ϲ������������ӵء�
LONG);

	set("exits", 
	([ //sizeof() == 4
		"southwest" : __DIR__"huangguadi",
		"north" : __DIR__"baicaidi",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		//"/d/obj/food/dbc" : 2,
		//"/d/obj/food/xbc" : 2,
	]));

	//create_door("south", "�滨��", "north", DOOR_CLOSED);
	set("outdoors", "wuzhuang");

	setup();
}
