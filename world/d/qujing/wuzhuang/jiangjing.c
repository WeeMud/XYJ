// cracked by vikee 2/09/2002   vikee@263.net
inherit ROOM;

void create ()
{
	set ("short", "������");
	set ("long", @LONG

������ƽʱ��Ԫ��������е�ʿ����ʱ���ã�������һ��������
ǰ��������ʮ��������档��������û���������裬����Ԫ����
Ϊ�����������Ϊ��
LONG);

	set("exits", 
	([ //sizeof() == 4
		"south" : __DIR__"wpiandian",
		"eastup": __DIR__"yanzhen",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		//__DIR__"npc/qingfeng" : 1,
		__DIR__"npc/zhangmen" : 1,
	]));


//	set("outdoors", "wuzhuang");

	setup();
	call_other("/obj/board/jiangjing_b", "???");
}
