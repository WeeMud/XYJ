// cracked by vikee 2/09/2002   vikee@263.net
// create by snowcat jan 21 1998

inherit ROOM;

void create ()
{
  set ("short", "Ң����");
  set ("long", @LONG

Ң���������ڵ�˴����һ���ϱ�˫��ͨ�У���������ķ�����������
�����ֵ��������ɰس��񣬽�����������ʯ���ֱ߻��Ǻ���סլ����
��ʽ�������̵����档

LONG);

  set("exits", ([
        "north" : __DIR__"yao1",
        "south" : __DIR__"yao3",
      ]));

  set("outdoors", __DIR__);

  setup();
}


