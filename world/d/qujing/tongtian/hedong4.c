// cracked by vikee 2/09/2002   vikee@263.net
// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "�Ӷ�");
  set ("long", @LONG

һ���ܿ�Ĵ�Ӻ�����ǰ��һ����ȥ��ԶԶ���Լ�����Լ�Ķ�
�����ӵ̵ı�����ǳ¼�ׯ�������ѽ��˺���һ�����żȻ
����һЩ�������ڱ��ϡ�

LONG);

  set("exits", ([
        "north"   : __DIR__"hedong3",
        "east"   : __DIR__"xiaolu4",
        "south"   : __DIR__"hedong5",
      ]));
  set("outdoors", __DIR__);

  setup();
}



