// cracked by vikee 2/09/2002   vikee@263.net
// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "���");
  set ("long", @LONG

һ�����Ҷ���Ȼ�γɵĶ�Ѩ��������Щ����������������Ƥ��
�ݣ�����һЩ�������Ĺ�ͷ�����ڿ���һ�����ӣ����в���
�������ӡ�

LONG);

  set("exits", ([
        "northwest"    : __DIR__"bopiting",
      ]));
  set("objects", ([
        __DIR__"obj/rou" : 8,
      ]));
  setup();
}

