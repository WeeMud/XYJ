// cracked by vikee 2/09/2002   vikee@263.net
// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "���");
  set ("long", @LONG

�˻��˼�Ҳ�ǳ��գ����������������������Ϊ������������
һ��������������ž�����ͭ��ߣ��ݱ��м��ѿ��Σ��м�
��һС�輸��

LONG);

  set("exits", ([
        "out"   : __DIR__"chen2",
      ]));
  set("objects", ([
        __DIR__"npc/people"  : random(2),
        __DIR__"npc/kid"  : random(2),
      ]));

  setup();
}



