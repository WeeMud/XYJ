// cracked by vikee 2/09/2002   vikee@263.net
// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "ƫ��");
  set ("long", @LONG

ƫ���������ಣ���Ѩ�յ����ұ�Ȯ��������ʯ������������
�ż�С�������������Ѭ�ˡ�����ͨ�����ã���������һɽ
��ͨ���⡣

LONG);

  set("exits", ([
        "east"    : __DIR__"zhong",
        "northwest"    : __DIR__"shanmen",
      ]));
  setup();
}

