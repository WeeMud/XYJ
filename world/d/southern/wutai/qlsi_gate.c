// cracked by vikee 2/09/2002   vikee@263.net
// ajax

#include <room.h>
inherit ROOM;

void create()
{
set("short", "��������");
set("long", @LONG
    
     ��������������ɽ֮�ۣ�����;����������ȣ�Ҳ��
������κ�ΰ��ɽ���ƾɣ��������ʧ�ޡ�
LONG );


set("exits", ([
  "enter"   : __DIR__"qlsi_yuan",
  "south"   : __DIR__"qlsi_shanlu1",
 
]));


set("objects", ([
]));


create_door("enter", "����", "out", DOOR_CLOSED);
set("no_clean_up", 0);


setup();
}
