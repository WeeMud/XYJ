// cracked by vikee 2/09/2002   vikee@263.net
#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "����������");
  set ("long", @LONG

����͵��˼����������ţ���·�ǳ��Ŀ��㣬����ݵ���ʮ����
�ۡ���ֱ����·ֱͨ����У�������ͽ����·����������������
������֮������
LONG);

  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/guard" : 2,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"pingxi",
  "east" : __DIR__"crosswest",
]));

  setup();
}
