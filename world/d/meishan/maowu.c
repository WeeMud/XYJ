// cracked by vikee 2/09/2002   vikee@263.net

#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

���й��߲��Ǻܺã���Լ��������һ�Ű��������������Ρ���
�Ϸ���һ��������������롣���ﲢ�޺������裬�������˲�
���Ǻܸ��С�
LONG);


  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/zhangsun" : 1,
]));
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"xiaoyuan",
]));

  setup();
}

