// cracked by vikee 2/09/2002   vikee@263.net
// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "���");
  set ("long", @LONG

����ר��Զ����������׼���ķ��꣬ǰ���ǿ�����Ϣϴˢ��
���ĳ�����������һ�������ͣ�Ŵ�С��ͬ�����������
ˮ�Բ���Ϣ��

LONG);

  set("exits", ([
        "east"   : __DIR__"jiedao41",
      ]));
  set("objects", ([
        __DIR__"npc/ma"   : 1,
      ]));

  setup();
}


