// cracked by vikee 2/09/2002   vikee@263.net
// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "�쾮");
  set ("long", @LONG

������쾮�����ľͷ���ż��ӣ������ϴ���һЩ��Ƥ����
����һЩ������Ĵ�ʯ�飬����ɹ������ӡ��쾮��һ�Ƕ���
һЩ��ͷ��

LONG);

  set("exits", ([
        "west"    : __DIR__"bopiting",
      ]));
  set("objects", ([
        __DIR__"npc/xiaoyao" : 4,
      ]));
  set("outdoors",__DIR__"");
  setup();
}

