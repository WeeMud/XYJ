// cracked by vikee 2/09/2002   vikee@263.net
// Room: /moon/road.c

inherit ROOM;

void create ()
{
  set ("short", "ɽ·");
  set ("long", @LONG

ֻ����ɽ����Ρ�룬��Χ�վ����Ź������̴�ǣ��ݴ����������ᡣ
LONG);

  set("outdoors", __DIR__"");
  set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"road1",
  "westup" : __DIR__"road3",
]));

  setup();
}






