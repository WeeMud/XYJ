// cracked by vikee 2/09/2002   vikee@263.net
// Room: /city/kedian2.c

inherit ROOM;

void create ()
{
  set ("short", "�Ľ�Ұ��");
  set ("long", @LONG
�������ڻĽ�Ұ���һ�����С·�ϣ�ֻ��һЩС����
�����������ȥ�� 
LONG);

  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"kedian",
  "south" : __DIR__"kedian3",
]));
        set("objects", ([ /* sizeof() == 1 */
  "/obj/money/silver" : 2,
]));

  setup();
}
