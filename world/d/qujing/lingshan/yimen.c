// cracked by vikee 2/09/2002   vikee@263.net
// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "һ��");
  set ("long", @LONG

����ſ�����һ�Ծ޴��̴��ľ�ţ��ű�����ɫ�޺�˫�׷���
��̨�������������һ���ϵ�������Ʒ𶦣������ǿ�����
ǰ��㳡������Ϊ���ϱ�����һ������š�

LONG);

  set("exits", ([
        "north"   : __DIR__"siqian",
        "south"   : __DIR__"ermen",
        "west"   : __DIR__"sidian13",
        "east"   : __DIR__"sidian15",
      ]));
  set("objects", ([
        __DIR__"npc/biqiu" : 2,
     ]));

  setup();
}

