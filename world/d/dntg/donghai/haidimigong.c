// cracked by vikee 2/09/2002   vikee@263.net
//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "�����Թ�");
set("long", @LONG
    
����ˮɫ��Ļ�����������Χ�ѿ���������ˡ�ż�а���Ϯ������
��������������Ĵ�����Щ�߸ߵĺ��ݣ����������ͷ���ڵ�һ˿
��âҲû���ˡ�
LONG );


set("exits", ([
  "north"   : __DIR__"maze1",
]));


set("objects", ([
]));



setup();
}
