// cracked by vikee 2/09/2002   vikee@263.net
// Room: /city/kedian3.c

inherit ROOM;

void create ()
{
  set ("short", "·�ľ�ͷ");
  set ("long", @LONG
�������Կ������Ѿ�����·�ľ�ͷ������ֻ��һ��Сͤ��
ͤ�����Ҵ��飺���ۼ�ͤ����
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"kedian3",
  "south" : __DIR__"xiaoting",
]));

  setup();
}






