// cracked by vikee 2/09/2002   vikee@263.net
// Room: /d/jjf/stone_road.c

inherit ROOM;

void create ()
{
  set ("short", "ʯ��·");
  set ("long", @LONG
С·��������ͷ׵�ʯ���̳ɵġ�ʯ������˸��ֻ��ƣ�����
�ÿ���·�߳�����ɻ�ͤͤ�����ѷ�����ȥ��ֻ��ż�������ļ���
�������������ܵ�������
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"keting",
  "southwest" : __DIR__"pavillion",
]));

  setup();
}
