// cracked by vikee 2/09/2002   vikee@263.net
// create by snowcat jan 21 1998

inherit ROOM;

void create ()
{
  set ("short", "Ң����");
  set ("long", @LONG

Ң���������ڵ�˴����һ���ϱ�˫��ͨ�У���������ķ�����������
�����ֵ��������ɰس��񣬽�����������ʯ���ֱ߻��Ǻ���סլ����
��ʽ�������̵����棬������һ����¥��

LONG);

  set("exits", ([
        "southwest" : __DIR__"tieta",
        "north" : __DIR__"yao4",
        "east" : __DIR__"qili",
      ]));

  set("outdoors", __DIR__);

  setup();
}


