// cracked by vikee 2/09/2002   vikee@263.net
inherit ROOM;

void create ()
{
	set ("short", "����¥");
	set ("long", @LONG

����¥��������Ԫ���ɵ�˽�ӡ�����һ��̨������һ��ɫ�߲�˿
�Ľ��ʡ�̨����ŷ����ã�����һ���������֡�С¥������ǵ�
���ȴ�������Χ���¿������������
LONG);

	set("exits", 
	([ //sizeof() == 4
		"eastdown": __DIR__"shuofa",
		"up" : __DIR__"chengyun",
		"westdown": __DIR__"jiangjing",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		//__DIR__"npc/qingfeng" : 1,
		//__DIR__"npc/mingyue" : 1,
	]));


//	set("outdoors", "wuzhuang");

	setup();
}
