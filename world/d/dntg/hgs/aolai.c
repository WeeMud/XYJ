// cracked by vikee 2/09/2002   vikee@263.net
//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "������");
set("long", @LONG
    
��ʤ���޺���һС�������������ٴ󺣣���������ɽ��ֻ��
�����һ����խ��ƽԭ�ش��Ͻ���һ���ǳء�һ����·ֱͨ
�Ϸ���·������Ҳ�ǴҴҶ�����
LONG );


set("exits", ([
  "west"   : "/d/changan/aolaiws",
  "east"   : __DIR__"flowerfruit",
  "south"   : __DIR__"northgate",
]));


set("objects", ([
]));



set("outdoors", 1);

setup();
}
