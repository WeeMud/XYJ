// cracked by vikee 2/09/2002   vikee@263.net
// Room: /d/nanhai/guangchan
inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG

�����Ϻ�����ɽ��һ��Ƚ�ƽ�������أ�����ɽ���˵����Ǿ�
���������д����գ������𷨣������ĵá�
LONG);

  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/huian" : 1,
  __DIR__"npc/zhangmen" : 1,
]));
  set("outdoors", "/d/nanhai");
  set("valid_startroom", 1);
  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"xiaoyuan",
  "west" : __DIR__"road11",
  "east" : __DIR__"road1",
  "enter" : __DIR__"chaoyindong",
]));

  setup();
}

//object zhangmen = 0;
/*
void init ()
{

  if (! zhangmen)
  {
// zhangmen = present("zhang men",this_object());

zhangmen = new ("/d/npc/zhangmen");

    zhangmen->create_identity(__DIR__"npc/guanyin",this_object());
  }
}
*/
