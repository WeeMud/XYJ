// cracked by vikee 2/09/2002   vikee@263.net
//sgzl

#include <room.h>
//inherit ROOM;
inherit "/d/dntg/lijing/starting_place.c";

void create()
{
set("short", "����ɽ�̾���");
set("long", @LONG
    
һƬ�����Ĳݵأ��������ǵ������ǵĽ̾�
����ֻ������һ�������ͨ��Գָ����һ��
�У�һ�����߹����ĺ��ӱ���
LONG );


set("exits", ([
"east"   : __DIR__"shanya",
]));


set("objects", ([
__DIR__"npc/beng" : 1,
]));



set("outdoors", 1);
setup();
}
