// cracked by vikee 2/09/2002   vikee@263.net
// create by snowcat.c 4/8/1997
// room: /d/westway/jincheng.c

inherit ROOM;

void create ()
{
  set ("short", "��ǿ���");
  set ("long", @LONG

��ǿ���������������Ҫ����������ȥ��ããһƬԶ������
ԼԼ��һȺɽ���������ǽ�ǿ����ţ����Ž��գ����Ŷ����
��һСʳ̯������ʲô��������һ����ٵ�����ͨ����ƹ���
�����ǡ�

LONG);

  set("exits", ([
        "west"      : __DIR__"dadao",
        "southeast" : __DIR__"west3",
        "northeast" : "/d/moon/xiaolu3",
      ]));
  set("outdoors", __DIR__);

  set("objects",([
        "/d/qujing/kusong/npc/jiruhuo" : 1,
        __DIR__"npc/tanfan" : 1,
       ]));

  setup();
}





