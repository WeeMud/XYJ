// cracked by vikee 2/09/2002   vikee@263.net

#include <room.h>
#include <ansi.h>
inherit ROOM;



void create ()
{
  set ("short", "������");
  set ("long", @LONG

�������칬�ı��š����Ĵ�����֮һ��ħ���ٸ����ء�����
�������������߿ɾ�������ˡ���Ȼ��ˣ���������Ŀ�˿��
���������ʺ�Ĵ������������������ͭ�����Ե�����Ƿ���
�����춡���������һ˿������Ѳ���š�

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south"      : __DIR__"jiashan",
  "east"      : __DIR__"tgqn5",
  "west"      : __DIR__"tgqn4",

]));

  create_door("south", "������", "north", DOOR_CLOSED);

  set("objects", ([
  __DIR__"npc/moli-hai"   : 1,
  __DIR__"npc/tian-bing"   : 4,
]));


  setup();
}


