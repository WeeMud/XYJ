// cracked by vikee 2/09/2002   vikee@263.net
// ajax

inherit ROOM;

void create()
{
set("short", "����ɽ��");
set("long", @LONG
    
�����ߵ���������Ѿ����Կ�������׳���Ķ���ɽ�ˣ���ɽ
����������ﲻ����ĥ����ࡣ
LONG );


set("exits", ([
  "westup"   : __DIR__"shanlu1",
  "east"   : __DIR__"guandao1",
 
]));


set("objects", ([
]));



set("outdoors", 1);

setup();
}
