// cracked by vikee 2/09/2002   vikee@263.net
// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

������һ�������˱ǣ��ؽֵ��ſ�����һЩ�ʻ���������ǽͷ
����������ɫ�ĸɻ��ݣ���̨���������Ư���Ļ�ƿ��ƿ�ڲ�
�Ÿ�ʽ�������ʻ���

LONG);

  set("exits", ([
        "south"   : __DIR__"jiedao13",
      ]));
  set("objects", ([
        __DIR__"npc/dai"   : 1,
      ]));

  setup();
}


