// cracked by vikee 2/09/2002   vikee@263.net
//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "��·");
set("long", @LONG
    
̤�����������칬��·������Ʈ�������ƣ������˼�ũ��
��Ʈ����������̣����˱����Ŀ�������
LONG );


set("exits", ([
  "east"   : __DIR__"baoguangdian",
  "west"   : __DIR__"yunluw2",
]));


set("objects", ([
]));



set("outdoors", 1);

setup();
}
