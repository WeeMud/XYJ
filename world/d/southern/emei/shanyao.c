// cracked by vikee 2/09/2002   vikee@263.net
// ajax

inherit ROOM;

void create()
{
set("short", "ɽ��");
set("long", @LONG
    
���������ҳ�Ϊ�����߶��졹�Ķ���ɽ�������Ÿ��������Ĵ�˵��
������ȥ����Ϳ����ҵ���˵�еľ��϶��ˡ�
LONG );


set("exits", ([
  "westup"   : __DIR__"shanlu3",
  "eastdown"   : __DIR__"shanlu2",
  "south"   : __DIR__"jiulaodong",
 
]));


set("objects", ([
]));



set("outdoors", 1);

setup();
}
