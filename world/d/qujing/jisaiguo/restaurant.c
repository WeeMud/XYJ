// cracked by vikee 2/09/2002   vikee@263.net
#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "�����");
  set ("long", @LONG

�������Ʈ�Ź�ŨŨ�Ŀ�����ζ�������������������˶���ϯ��
��������ǰ�Ŀ�¯�Ϸ��Ų�ͬ���࣬�������������ʳ�����е�
���˶��Ǵ�ںȾƣ���ڳ��⣬�Ե����ֵ����ӡ�
LONG);

  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/samui" : 1,
]));
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"centermarket",
]));

  setup();
}

