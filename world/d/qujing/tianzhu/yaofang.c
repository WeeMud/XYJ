// cracked by vikee 2/09/2002   vikee@263.net
// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "ҩ��");
  set ("long", @LONG

�ſ�����һ����ӭ��ҡ�Σ�ҩ��������һ����ľ����������
С����������߿��ִ���һ���ӣ����߰���һ���������Ա���
������ۿ��Ρ�

LONG);

  set("exits", ([
        "west"   : __DIR__"jiedao31",
      ]));
  set("objects", ([
        __DIR__"npc/hou"   : 1,
      ]));

  setup();
}


