// cracked by vikee 2/09/2002   vikee@263.net
// create by snowcat jan 21 1998

inherit ROOM;

void create ()
{
  set ("short", "���ͳ�");
  set ("long", @LONG

���ͳ��Ĵ�����һ����ʯ��̨����̨�϶˶������ط���һ������ǩ�У�
������Ž�ǩ����̨��������¯�������������̡����ı�����һ����
�ţ�����������ͨ�������ĳ���

LONG);

  set("exits", ([
        "north" : __DIR__"shuilu",
        "west" : __DIR__"pudu",
        "east" : __DIR__"ee",
      ]));
  set("objects", ([
        __DIR__"npc/people" :  3,
        __DIR__"npc/chen" :  1,
      ]));

  setup();
}


