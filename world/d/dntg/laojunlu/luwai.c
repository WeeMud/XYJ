// cracked by vikee 2/09/2002   vikee@263.net
#include <room.h>
inherit ROOM;

void create()
{
set("short", "�Ͼ�¯");
set("long", @LONG
    
�������̫���Ͼ����������ڡ�����������һֻһ�˶�ߵ�
��ɫ��¯������������ʲô�������ġ�¯���һ����ܣ�Ȼ��
��ȴ���ܲ���һ˿���ȡ�ǽ�Ƿ���һ¯̴�㣬һ˿��������
�������������ơ�

LONG );


set("exits", ([
]));

     set("objects", ([ /* sizeof() == 4 */
       __DIR__"npc/taishanglaojun" : 1,
]));

setup();
}


