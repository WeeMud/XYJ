// cracked by vikee 2/09/2002   vikee@263.net

inherit ROOM;

void create ()
{
	set ("short", "֩������");
	set ("long", @LONG

���������������ס��������ߣ���ֻ�ܿ�������һֻ
���֩�����ž޴�İ�ֻצ������������
LONG);

	set("exits", 
	([ //sizeof() == 4
		"out" : __DIR__"no4-wn1",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		__DIR__"npc/zhizhu" : 1,
	]));
	 set("no_mieyao",1);

	setup();
}

int valid_leave(object me, string dir)
{
   if(present("wucai zhizhu", environment(me) ))
     return notify_fail("���֩���Ӵ��������ס��ȥ·��\n");
   return ::valid_leave(me,dir);
}


