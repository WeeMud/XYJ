// cracked by vikee 2/09/2002   vikee@263.net
// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "ñ��");
  set ("long", @LONG

����һ��ר����ñ�ĵ��̣���������һ���ķ���������������
�涼���˸�ñ�ӡ�����������һˮĥͭ�����˿�������ñ��֮
����������ͭ��ǰ��ñ���վ��ӡ�

LONG);

  set("exits", ([
        "east"   : __DIR__"jiedao68",
      ]));
  set("objects", ([
        __DIR__"npc/tian"   : 1,
      ]));

  setup();
}


