// cracked by vikee 2/09/2002   vikee@263.net
//sgzl
#include <room.h>
inherit ROOM;
 
void create()
{
        set("short", "������");
        set("long", @LONG

һ��С�ݣ��ڼ�ٳ��ڴ˰��ž�ϯ�������𻰡�
LONG );
 
        set("exits", ([
                "north" : __DIR__"zhengting",
        ]));
 
        set("objects", ([
        ]));
 


        setup();
}
