// cracked by vikee 2/09/2002   vikee@263.net
// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "��ɽ");
  set ("long", @LONG

��ɽ���У����µ��շ����ƺ���¶��ɣ�ɽ��֮���������Ʋ�
����衣ɭ��֮��ʱʱ�����޵�ŭ��֮����ɽ�ȣ�ʹ�˲���
���ɵط����Ų���

LONG);

  set("exits", ([
        "eastdown"   : __DIR__"shanlu8",
        "southwest"   : __DIR__"jindou4",
      ]));
  set("objects", ([
        __DIR__"npc/yao"   : 2,
      ]));
  set("outdoors", __DIR__);

  setup();
}


