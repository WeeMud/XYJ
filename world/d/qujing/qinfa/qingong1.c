// cracked by vikee 2/09/2002   vikee@263.net
// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "�޹�");
  set ("long", @LONG

�޹�������Ű����廨ͼ�������ǳ������ܡ������ˮ������
��������翣����ż�ֻ������ɫ��ľ�����м���˫��������
�칬����

LONG);

  set("exits", ([
        "south"    : __DIR__"fenggong",
        "southwest"    : __DIR__"longgong",
      ]));
  set("objects", ([
        __DIR__"npc/girl"    : 1,
      ]));
  set("sleep_room",1);
  set("if_bed",1);
  setup();
}

