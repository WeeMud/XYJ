// cracked by vikee 2/09/2002   vikee@263.net
//standroom.c used by weiqi...others may hate this format:D
//xihai.c

inherit ROOM;

string *npcs = ({
  "/d/xueshan/npc/hama",
  "/d/xueshan/npc/chongzi",
  "/d/xueshan/npc/chongzi",
  "/d/xueshan/npc/chongzi",
  "/d/xueshan/npc/chongzi",
  "/d/xueshan/npc/chongzi",
});

void create ()
{
	set ("short", "����֮��");
	set ("long", @LONG

������һ���޼ʵ�ѩԭ��Ρ����ΰ�ı�ɽ��ͻȻ��̲����꣬��
�׳����ˮ��չ������ǰ�����ʱ����һ����������ӿ����ͷ��
ɽ�������ݣ��񣬷·��ǵ�����һ�����硣
LONG);

	//set("item_desc", ([" *** " : " *** \n", ]));
	//for look something.

	set("exits", 
	([ //sizeof() == 4
		//"south" : __DIR__"xueshan4",
		//"north" : __DIR__"xueshan6",
		"east" : __DIR__"xueshan5",
		//"west" : __DIR__"eroad1",
		//"up" : __DIR__"***",
		//"down" : __DIR__"***",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		npcs[random(sizeof(npcs))] : 1,
	]));


	set("outdoors", "xueshan");

	setup();
}

//void init()
//{
	//add_action("do_jump", "jump");
//}

//int do_jump(string arg)
//{
       
//}



