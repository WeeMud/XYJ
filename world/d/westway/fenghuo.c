// cracked by vikee 2/09/2002   vikee@263.net
// create by snowcat.c 4/8/1997
// room: /d/westway/fenghuo.c

inherit ROOM;

void create ()
{
  set ("short", "���̨");
  set ("long", @LONG

�߸ߵķ��̨���ӷ��̨������ȥ��һƬãã����һ���
��ã��ʲôҲ�����塣����ȥ��ԶԶ�ط��̨һ����һ��
����Ⱥɽ����һֱͨ����߼�Զ����

LONG);

  set("exits", ([
        "northdown"  : __DIR__"jiayu",
      ]));
  set("outdoors", __DIR__);

  setup();
}


