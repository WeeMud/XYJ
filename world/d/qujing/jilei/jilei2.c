// cracked by vikee 2/09/2002   vikee@263.net
// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "����ɽ");
  set ("long", @LONG

����ɽ���絶��һ�㣬Ⱥ�������ι�״��Ȯ��������ɽ������
����һ�ɹ�Ũ�ҵ���������������Х���չȻ�����Ұ�޵ĺ�
�����Ѿ��ܽ��ˡ�

LONG);

  set("exits", ([
        "northeast"   : __DIR__"jilei1",
        "south"   : __DIR__"shidong",
      ]));
  set("outdoors", __DIR__);

  setup();
}


