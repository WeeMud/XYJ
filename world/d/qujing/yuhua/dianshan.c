// cracked by vikee 2/09/2002   vikee@263.net
// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG

���ȶԿ���ľ���Ž�������װ�εļ�Ϊ���������˾���������
�ǳ����ܹ����ĵط����ٽֵ��������·���һ�����������ѿ�
���η����������ࡣ

LONG);

  set("exits", ([
        "north"   : __DIR__"xiaojie8",
      ]));
  set("objects", ([
        __DIR__"npc/chaiguan"  : 1,
      ]));

  setup();
}



