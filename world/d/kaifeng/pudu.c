// cracked by vikee 2/09/2002   vikee@263.net
// create by snowcat jan 21 1998

inherit ROOM;

void create ()
{
  set ("short", "�նɳ�");
  set ("long", @LONG

�նɳ����������ƣ�������һ����ľ�㰸�����߸���һ���޽�ͭ����
����ľ�����������ţ�������Ҳ����˷����նɳ��Ķ��������ǳ�
�ڣ�������һ��ͨ�����ͳ���

LONG);

  set("exits", ([
        "northeast" : __DIR__"shuilu",
        "east" : __DIR__"jixian",
      ]));
  set("objects", ([
        __DIR__"npc/people" :  3,
        __DIR__"npc/yin" :  1,
      ]));

  setup();
}


