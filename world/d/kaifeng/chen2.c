// cracked by vikee 2/09/2002   vikee@263.net
// create by snowcat jan 21 1998

inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG

�����ĳ�������ڿ�����ڶ��������죬��·������ʯ���̳ɣ�����
���������де���ľ������ԶԶ�ɼ����⸮�ĳ��ţ�������һ���ߴ�
���������ϱ���һ����

LONG);

  set("exits", ([
        "west" : __DIR__"chen1",
        "east" : __DIR__"tieta",
        "south" : __DIR__"machang",
      ]));

  set("outdoors", __DIR__);

  setup();
}


