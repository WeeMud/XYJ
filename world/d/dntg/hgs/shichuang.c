// cracked by vikee 2/09/2002   vikee@263.net
//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "ʯ��");
set("long", @LONG
    
һ�ų�����ʯ����
LONG );


set("exits", ([
"out"   : __DIR__"shifang",
]));


set("objects", ([
]));



set("sleep_room", 1);
setup();
}
