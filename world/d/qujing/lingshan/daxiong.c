// cracked by vikee 2/09/2002   vikee@263.net
// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "���۱���");
  set ("long", @LONG

���۱������̻Ի��������𣬸������������룬��ǽ�
���ܣ�������ǽ���ԧ��˫˫�Զԣ�������һ�����������
̨���ϱ���һ����ͨ���������߸���һƫ�š�

LONG);

  set("exits", ([
        "north"   : __DIR__"sanmen",
        "south"   : __DIR__"houdian",
        "west"   : __DIR__"zhenlou1",
        "east"   : __DIR__"baoge1",
      ]));
  set("objects", ([
        __DIR__"npc/rulai" : 1,
        __DIR__"npc/xiantong" : 2,
     ]));

  setup();
}

