// cracked by vikee 2/09/2002   vikee@263.net
// gate.c

inherit ROOM;

void create ()
{
  set ("short", "��·");
  set ("long", @LONG

·���˲��Ǻܶ࣬ż���м������ͣ�ǰ����һ��С��������
һ�������˼ң�ȴ���ⷽԲ�������ص����ˣ�������ũ����
�ǿ���߼ҵ�����գ�
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"lu2",
  "east" : "/d/changan/wroad3",
]));
  set("outdoors", 1);

  setup();
}
