// cracked by vikee 2/09/2002   vikee@263.net
// Room: /u/hkgroup/cottage
inherit ROOM;

void create ()
{
  set ("short", "��Ȼ");
  set ("long", @LONG

������������������𴦣������㻤�ɽ��ˡ�

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"village",
]));
//  set("objects", ([
//           __DIR__"npc/niu": 1,
//]));

  setup();
}
