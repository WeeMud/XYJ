// cracked by vikee 2/09/2002   vikee@263.net
// Room: /d/4world/northgate.c
inherit ROOM;

void create ()
{
  set ("short", "������������");
  set ("long", @LONG

һ���ߴ�ĳ�ǽ������ǰ�ߣ����ϲ������سǵĹٱ��߹�������
�����������˺ܶ࣬�������˷紾�ӣ��񸻶�֪�㣬����Ҳ����
һ��ϲ������ľ�ɫ��
LONG);

  set("light_up", 1);
  set("no_magic", 1);
  set("outdoors", __DIR__"");
  set("objects", ([
                __DIR__"npc/wushi": 2]) );

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"north2.c",
  "north" : __DIR__"aolai",
  "east"  : __DIR__"aolaifighting",
]));
  set("no_fight", 1);

  setup();
}
int valid_leave(object me, string dir)
{
// This line caused a bug. Modified by Dream on 08/27/97
//	me=this_player();

    if (dir == "south" ) {
        if ((int)me->query("combat_exp") < 15000
	&& (int)me->query("PKS") < 2 ) 
		return ::valid_leave(me, dir);
	return notify_fail("��ʿ�����г���һ�ᣬ�ȵ���������ü���۵����ӣ��������\n");
	}

return 1;
}

