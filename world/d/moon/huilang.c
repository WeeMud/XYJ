// cracked by vikee 2/09/2002   vikee@263.net
// Room: /moon/road.c

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

�������ȣ�����ʯ�������·����ǧ�ٴ�����ӳ��
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"ghg_zhengdian.c",
  "north" : __DIR__"huilang1.c",
  "west" : __DIR__"change_room.c",
]));

  setup();
}






