// cracked by vikee 2/09/2002   vikee@263.net

//northpool.c

inherit ROOM;

void create ()
{
	set ("short", "������");
	set ("long", @LONG

�������ߡ����б�����ᣬ������������������ݺύ����˺�
����Сľ�ţ���֪��һ����ͨ���԰��ġ�
LONG);

	set("exits", 
	([ //sizeof() == 4
		"south" : __DIR__"wzgmaze5",
		"north" : __DIR__"huangguadi",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		//__DIR__"npc/qingfeng" : 1,
		//__DIR__"npc/mingyue" : 1,
	]));

	set("outdoors", "wuzhuang");

	setup();
}
