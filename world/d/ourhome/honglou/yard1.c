// cracked by vikee 2/09/2002   vikee@263.net
// Room: /u/hkgroup/yard1
inherit ROOM;

void create ()
{
  set ("short", "�����");
  set ("long", @LONG

���������������ʵ�����˴���ˡ��͸������Σ�������������
����������������ˮ�����������㡣Īҡ����Ӱ�������������

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"pavilion",
  "north" : __DIR__"village",
  "east" : __DIR__"wow",
]));

  setup();
}
