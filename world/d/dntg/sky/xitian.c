// cracked by vikee 2/09/2002   vikee@263.net

#include <room.h>
#include <ansi.h>
inherit ROOM;



void create ()
{
  set ("short", "������");
  set ("long", @LONG

�������칬�Ķ��š����Ĵ�����֮һ��ħ�񺣸����ء�����
�������������߿ɾ�������ˡ���Ȼ��ˣ���������Ŀ�˿��
���������ʺ�Ĵ������������������ͭ�����Ե�����Ƿ���
�����춡���������һ˿������Ѳ���š�

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "east"      : __DIR__"yunluw4",
  "south"      : __DIR__"tgqw4",
  "north"      : __DIR__"tgqw5",

]));

  create_door("east", "������", "west", DOOR_CLOSED);

  set("objects", ([
  __DIR__"npc/moli-hong"   : 1,
  __DIR__"npc/tian-bing"   : 4,
]));


  setup();
}


