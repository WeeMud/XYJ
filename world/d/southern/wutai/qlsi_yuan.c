// cracked by vikee 2/09/2002   vikee@263.net
// ajax

#include <room.h>
inherit ROOM;

void create()
{
set("short", "Ժ��");
set("long", @LONG
    
     ��������������ɽ֮�ۣ�����;����������ȣ�Ҳ��
������κ�ΰ��ɽ���ƾɣ��������ʧ�ޡ�
LONG );


set("exits", ([
  "out"   : __DIR__"qlsi_gate",
  "enter"   : __DIR__"qlsi_tang",
 
]));


set("objects", ([
]));


create_door("out", "����", "enter", DOOR_CLOSED);
set("no_clean_up", 0);


setup();
}
