// cracked by vikee 2/09/2002   vikee@263.net
// Room: /changan/nanyue.c
//cglaem...12/12/96.

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

һ·�������ѵ���ɽ�ؽ硣��ɽ�ų��������۾����죬���ư��硣���Ի�
���Ϊ�ף�������´ɽΪ�㣬��С��ʮ�����������ư˰����Ȼ��˵�
�Թ�����⺷�������洦���У��ڴ����߿ɵ�С��Ϊ�ǡ�
LONG);

  set("outdoors", 2);
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"broadway2",
  "south" : __DIR__"broadway3",
  "northwest" : "/d/southern/emei/guandao3",
  "southeast" : "/d/meishan/guanjiang1",
]));

  setup();
}






