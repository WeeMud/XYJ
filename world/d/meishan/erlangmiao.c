// cracked by vikee 2/09/2002   vikee@263.net

#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG

�����Ƕ������������뵱�������ʥ��������������
�ڴ�һ���񶷣����������ڣ�ֻ����������ࡣ�������
��������ǰ����Ц��Ц�ؿ����㡣
LONG);


  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/miaozhu" : 1,
]));
  set("exits", ([ /* sizeof() == 2 */
  "south" : "/d/meishan/erlangwai",
]));

  setup();
}

