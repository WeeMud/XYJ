// cracked by vikee 2/09/2002   vikee@263.net
// create by snowcat jan 21 1998

inherit ROOM;

void create ()
{
  set ("short", "����·");
  set ("long", @LONG

������һ��С·���������������ƣ���ˮ�峺͸������������������
���񡣷紵��ʱ����ˮ��������ϸ֦΢��������ɽӰ��ӡ�����߰���
������������

LONG);

  set("exits", ([
        "northwest" : __DIR__"donghu5",
        "southwest" : __DIR__"donghu8",
      ]));

  set("outdoors", __DIR__);

  setup();
}


