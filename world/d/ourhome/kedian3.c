// cracked by vikee 2/09/2002   vikee@263.net
// Room: /city/kedian3.c

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
  "north" : __DIR__"kedian2",
  "south" : __DIR__"kedian4",
]));

        set("objects", ([ /* sizeof() == 1 */
  "/obj/money/coin" : 50+random(50),
]));
  setup();
}






