// cracked by vikee 2/09/2002   vikee@263.net
// Room: /u/hkgroup/main
inherit ROOM;

void create ()
{
  set ("short", "���¥");
  set ("long", @LONG

�������Ρ�룬��¥���������չ��ϱ��������������С�
���ɷ��ܣ�����������������棬�ʻ��ͷ��

LONG);

  set("exits", ([ /* sizeof() == 5 */
  "up" : __DIR__"fairyplace",
  "west" : __DIR__"mainwest",
  "north" : __DIR__"bridge",
  "south" : __DIR__"yard2",
  "east" : __DIR__"maineast",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/leng" : 1,
]));
  set("light_up", 1);

  setup();
  "obj/board/honglou_b"->foo();
}
