// cracked by vikee 2/09/2002   vikee@263.net
#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "·��");
  set ("long", @LONG

�������зǳ��ķ�����·�ܵ�¥̨���ʣ������ͷס�ֻ��������
���У���ֳͨ�ƣ������˵��¹�¡�أ������񸻺�����
LONG);

  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/laoban" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"eastmarket",
  "east" : __DIR__"eastgate",
  "south" : __DIR__"east1",
]));

  setup();
}

