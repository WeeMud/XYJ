#include <room.h>
inherit ROOM;

void create()
{
set("short", "����");
set("long", @LONG
    
�������̫���Ͼ����������ڡ�����������һֻһ�˶�ߵ�
��ɫ��¯������������ʲô�������ġ�¯���һ����ܣ�Ȼ��
��ȴ���ܲ���һ˿���ȡ�ǽ�Ƿ���һ¯̴�㣬һ˿��������
�������������ơ�

LONG );


set("exits", ([
  "east"   : "/d/dntg/laojun/hall",
]));
set("objects",([
        "/d/dntg/laojunlu/npc/taishanglaojun.c": 1,
  ]));

setup();
}
