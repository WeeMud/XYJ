// cracked by vikee 2/09/2002   vikee@263.net
// create by snowcat jan 21 1998

inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG

������������������Ϸ�����չ��ȥ���������ʯ���̾Ͷ��ɣ���
�г�����·�����߶���һƬƬ���ֵ����ɴ����ľ���������紵
����������

LONG);

  set("exits", ([
        "northwest" : __DIR__"tieta",
        "south" : __DIR__"yuwang2",
        "east" : __DIR__"yuwang4",
      ]));

  set("outdoors", __DIR__);

  setup();
}


