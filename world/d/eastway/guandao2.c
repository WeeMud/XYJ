// cracked by vikee 2/09/2002   vikee@263.net
// create by snowcat.c 4/20/1997
// room: /d/eastway/guandao2.c

inherit ROOM;

void create ()
{
  set ("short", "�ٵ�");
  set ("long", @LONG

����һ�������Ĺٵ����ٵ��������У������������ٵ�������Զ
Զͨ���ʿ�������ߺ��ϱ߸���һ��������������ͨ���Զ����
LONG);

  set("exits", ([
        "northwest"      : __DIR__"wangnan3",
        "northeast" : __DIR__"guandao3",
      ]));
  set("outdoors", __DIR__);

  setup();
}






