// cracked by vikee 2/09/2002   vikee@263.net
//standroom.c used by weiqi...others may hate this format:D
//girlroom.c

#include <ansi.h>

inherit ROOM;
inherit "/d/wiz/no_get";

void create ()
{
	set ("short", "Ů�����Է�");
	set ("long", @LONG

ѩɽ�ɵ�Ů�����Է��������൱�ؾ�����ǽ���ż��Ŵ���(bed)��
LONG);

	set("item_desc", (["bed" : "һ�ž��µĴ���(gosleep, gobed, bed)��\n", ]));
	//for look something.

	set("exits", 
	([ //sizeof() == 4
		//"south" : __DIR__"binggu",
		"north" : __DIR__"restroom",
		//"west" : __DIR__"restroom",
		//"east" : __DIR__"chufang",
		//"up" : __DIR__"***",
		//"down" : __DIR__"***",
	]));
  set("no_magic",1);
	
	set("objects", 
	([ //sizeof() == 1
		//__DIR__"npc/xunshi" : 2,
		__DIR__"npc/huanhua" : 1,
	]));


	//set("outdoors", "xueshan");

	setup();
}

void init()
{
	add_action("do_bed", "gosleep");
	add_action("do_bed", "gobed", );
	add_action("do_bed", "bed");
}

int do_bed()
{       
	object me;
	me=this_player();

	message_vision(HIY "$N�ƿ�ɴ�ʣ�׼���ϴ��ˡ�\n\n" NOR, me);
	me->move(__DIR__"girlbed");
	message_vision(HIY "\nɳ������һ����$N���˽�����\n" NOR, me);
	return 1;
}

