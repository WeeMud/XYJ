// cracked by vikee 2/09/2002   vikee@263.net

#include <room.h>
#include <ansi.h>
inherit ROOM;



void create ()
{
  set ("short", "��ɽ");
  set ("long", @LONG

�칬��Ժ�ļ�ɽ���ļ���ʢ�����ʻ�������һ��һľ��
��¶�������緶��
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "north"      : __DIR__"beitian",

]));

  create_door("north", "������", "south", DOOR_CLOSED);

  set("objects", ([
]));


  setup();
}


