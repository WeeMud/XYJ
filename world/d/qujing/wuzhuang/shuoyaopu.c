// cracked by vikee 2/09/2002   vikee@263.net
//shuoyaopu.c

inherit ROOM;

void create ()
{
	set ("short", "��ҩ��");
	set ("long", @LONG

��ǳ��ʢ�������ڵ����̿���һ�Ż��ĵ�̺����λ���Ż�����
��Ů�ڴ˴�����Ϸ�������������Ʈ�㣬�㲻�ɵ����������
һ������
LONG);

	set("exits", 
	([ //sizeof() == 4
		"southeast" : __DIR__"juyuan",
		"north" : __DIR__"southpool",
		//"south" : __DIR__"houyuan",
		//"west" : __DIR__"westway6",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		__DIR__"npc/hexiangu" : 1,
		__DIR__"npc/girl" : 3,
	]));

	//create_door("south", "�滨��", "north", DOOR_CLOSED);
	set("outdoors", "wuzhuang");

	setup();
}
