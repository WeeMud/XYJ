// cracked by vikee 2/09/2002   vikee@263.net
//sgzl
inherit ROOM;

void create ()
{
	set ("short", "ѩ·");
	set ("long", @LONG

ããѩҰ�У�Զ��������һ�ˣ��ֳ����У��������ݣ�
��ű���ѩɽ�ɸ���ӭ�͵����Ŵ�ʦ���ˡ�
LONG);


	set("exits", 
	([ //sizeof() == 4
		"north" : __DIR__"xuejie",
		"west" : __DIR__"wroad1",
		"east" : __DIR__"eroad1",
                "southdown" : __DIR__"xuelu2",
	]));
	
	set("objects", 
	([
                __DIR__"npc/zhangmen" : 1,
	]));


	set("outdoors", "xueshan");

	setup();
}



