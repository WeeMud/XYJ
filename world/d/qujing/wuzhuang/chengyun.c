// cracked by vikee 2/09/2002   vikee@263.net
inherit ROOM;

void create ()
{
	set ("short", "���Ƹ�");
	set ("long", @LONG

���Ƹ�ӹ��е���ߴ������ϻ�����������麿������������˺�
��Ĺ�����Χ����������ƾ��������Զ�����¾�����ǰ��ɽ��
�巿¥�ᣬɽ����ʯ����������Ŀ��
LONG);

	set("exits", 
	([ //sizeof() == 4
		"down": __DIR__"yanzhen",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		//__DIR__"npc/qingfeng" : 1,
		__DIR__"npc/zhenyuan" : 1,
	]));


	set("outdoors", "wuzhuang");

	setup();
}
