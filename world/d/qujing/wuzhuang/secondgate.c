// cracked by vikee 2/09/2002   vikee@263.net
inherit ROOM;

void create ()
{
	set ("short", "��ɽ��");
	set ("long", @LONG

��ɽ��Զ�����Ǹߴ���¥�������������ơ�����ʯ���Ͽ̿�һ
�Դ��������ǡ������������ɸ�������ͬ�ٵ��˼ҡ�ʮ�ĸ�����
����Ĵ��֡�
LONG);

	set("exits", 
	([ //sizeof() == 4
		"southdown" : __DIR__"shaoxiang",
		"north" : __DIR__"linkway",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		//__DIR__"npc/***" : 1,
	]));


	set("outdoors", "wuzhuang");

	setup();
}
