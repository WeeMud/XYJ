// cracked by vikee 2/09/2002   vikee@263.net
//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "�����");
set("long", @LONG
�������������ܻ��������ߴ���ΰ����
������������߰��������ûʡ�    
LONG );


set("exits", ([
  "north"   : __DIR__"weiyuegong",
  "south"   : __DIR__"xuanyuantang",
]));


set("objects", ([
]));



setup();
}
