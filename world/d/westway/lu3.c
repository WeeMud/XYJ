// cracked by vikee 2/09/2002   vikee@263.net
inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

����֮�ϻ��Ƿǳ�������Χǽ�ϵ��Ŵִ���͵ƣ��Ѵ�����
��ͨ�������и�̨�Ϸ�������̫ʦ�Σ�����С�������߶���
LONG);

  set("exits", ([
        "south" : __DIR__"lu2",
      ]));
//  set("outdoors", __DIR__);
  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/yin" : 1,
  __DIR__"npc/xiong" : 1,
  __DIR__"npc/niu" : 1,
]));

  setup();
}





