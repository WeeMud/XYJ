// cracked by vikee 2/09/2002   vikee@263.net
#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

���ֽ��ǹ��ɣ���ȥ��ľ���а���֮�䣬��֦���������Ť����
Ƥ���з�˪ż�֣�֦Ҷ�ϵ������ܡ���ľ���������ܵ����ϣ���
֮�����һ����
LONG);

  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/song" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "east": __DIR__"zhulin",
  "northwest": __DIR__"huilin",
  "northeast" : __DIR__"xinglin",
]));

  setup();
}


