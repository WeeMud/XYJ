// cracked by vikee 2/09/2002   vikee@263.net
// Room: /u/mimi/zhuziguo/stable_room.c  snowcat moved to /d/qujing/wuji
inherit ROOM;

void create ()
{
  set ("short", "���");
  set ("long", @LONG

�˼������̫�Ӿ�����ѡ�Ĵ�������������ƥ��Ϊ��������
������Ϊ����

LONG);

  set("exits", ([ /* sizeof() == 1 */
    "west" : __DIR__"garden.c",
]  ));

  setup();
}
