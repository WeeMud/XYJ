// cracked by vikee 2/09/2002   vikee@263.net
inherit ROOM;

void create ()
{
	set ("short", "��С��");
	set ("long", @LONG

���Ǵ����һ�����ȣ���������Ժ��С������ľ���̵أ�
��ɨ�ļ�Ϊ�ɾ����������淢��֨֨�����������������ľ����
����һЩɽˮ��������ǹ��е�ի����
LONG);

	set("exits", 
	([ //sizeof() == 4
		"south" : __DIR__"eastway4",
		"north" : __DIR__"eastway6",
		"west" : __DIR__"zaifang",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		//__DIR__"npc/qingfeng" : 1,
		//__DIR__"npc/mingyue" : 1,
	]));


//	set("outdoors", "wuzhuang");

	setup();
}
