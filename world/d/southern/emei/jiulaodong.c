// cracked by vikee 2/09/2002   vikee@263.net
// ajax

inherit ROOM;

void create()
{
set("short", "���϶�");
set("long", @LONG
    
������˵�Ƶ�Ϊ��������ˣ���������ɽ�����ɷ��²��һ
ɽ�������ڶ����һ���ߣ��ʵ���������һ�˺��������ߴ�
�����ϾӴˡ���������ǰѴ˶���Ϊ���϶���
LONG );


set("exits", ([
  "north"   : __DIR__"shanyao",
 
]));


set("objects", ([
]));



set("outdoors", 1);

setup();
}
