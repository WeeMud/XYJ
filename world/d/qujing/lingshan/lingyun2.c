// cracked by vikee 2/09/2002   vikee@263.net
// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "���ƶ�");
  set ("long", @LONG

�����У�һ��ɽ�������������˷�����ɽ���������ɷɺ磬ˮ
�����������ǧ���������ɿڰ�������������·���ߣ������
��һ����ľ�š�

LONG);

  set("exits", ([
        "north"   : __DIR__"dumuqiao",
        "southeast"   : __DIR__"yang1",
      ]));
  set("objects", ([
        __DIR__"npc/jieyin" : 1,
      ]));
  set("outdoors", __DIR__);

  setup();
}



