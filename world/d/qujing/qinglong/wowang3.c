// cracked by vikee 2/09/2002   vikee@263.net
// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG

�����ſڷ���һ��ͭ�󶦣�����ɢ���������͵Ĵ���ζ������
��һ��ߺ���ľ�������������յ�����͵ƣ��������յ�һƬ
ͨ����

LONG);

  set("exits", ([
        "northwest"   : __DIR__"tongdao2",
      ]));
  set("objects", ([
        __DIR__"npc/pi3"  : 1,
      ]));

  setup();
}



