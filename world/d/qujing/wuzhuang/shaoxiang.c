// cracked by vikee 2/09/2002   vikee@263.net
inherit ROOM;

void create ()
{
	set ("short", "���㷻");
	set ("long", @LONG

���㷻��������ɽ��ׯ��֮�⣬һ�����͵������㣬��ͷ��Ը
���Ҫ��ת�ˡ���ǰ��һ�����㰸���������򵭵���ȼ��������
��ի�����׿ͷ����������Ϣ��ի��
LONG);

	set("exits", 
	([ //sizeof() == 4
		"southdown" : __DIR__"gate",
		"northup" : __DIR__"secondgate",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		//__DIR__"npc/***" : 1,
	]));


	set("outdoors", "wuzhuang");

	setup();
}
