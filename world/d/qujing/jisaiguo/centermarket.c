// cracked by vikee 2/09/2002   vikee@263.net
#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

�������зǳ��ķ�����·�ܵ�¥̨���ʣ������ͷס�ֻ��������
���У���ֳͨ�ƣ������˵��¹�¡�أ������񸻺�����·����һ
�Ҵ��¥��Ʈ���������ζ��
LONG);

  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/xiaofan" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"westmarket",
  "east" : __DIR__"eastmarket",
  "south" : __DIR__"restaurant",
  "northup" : __DIR__"yunqi",
]));

  setup();
}

