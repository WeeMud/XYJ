// cracked by vikee 2/09/2002   vikee@263.net
#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "��������");
  set ("long", @LONG

�����а����˸�������Ʒ���ѵĵ������ǣ������޷��½š�����
С�������һ�Ա���������ϰ��ȥ��֣�����Щ͵��������
�����ﻹ�Ǹ�����������˻�ͦ�ࡣ
LONG);

  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/huoji" : 1,
]));
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"eastmarket",
]));

  setup();
}

