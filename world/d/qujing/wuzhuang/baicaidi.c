// cracked by vikee 2/09/2002   vikee@263.net
//baicaidi.c

inherit ROOM;

void create ()
{
	set ("short", "�ײ˵�");
	set ("long", @LONG

��ׯ�����µĶ࣬�Է���Ҳ���٣����Թ��ڹ��˸�����һЩũ��
�����߲˹Ϲ��������ǰײ˵ء�
LONG);

	set("exits", 
	([ //sizeof() == 4
		"south" : __DIR__"qiezidi",
		"northwest" : __DIR__"xiguadi",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		"/d/obj/food/dbc" : 2,
		"/d/obj/food/xbc" : 2,
	]));

	//create_door("south", "�滨��", "north", DOOR_CLOSED);
	set("outdoors", "wuzhuang");

	setup();
}
