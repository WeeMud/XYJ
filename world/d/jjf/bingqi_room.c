// cracked by vikee 2/09/2002   vikee@263.net
// Room: /d/jjf/bingqi_room.c

inherit ROOM;

void create ()
{
  set ("short", "�ɸ���");
  set ("long", @LONG
���ź�����ǽ���Ϲ���һ��Ф�����Թ���������ǹ��һ��
Сͯ�ոմ�ɨ�����䣬����һ����Ⱦ������������ǹ�������ù��
���ˡ�
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"main_cabinet",
]));

  setup();
}
