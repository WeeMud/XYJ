// cracked by vikee 2/09/2002   vikee@263.net
inherit ROOM;

void create ()
{
  set ("short", "火丁洞");
  set ("long", @LONG

一个黑漆漆的小室，象是来储藏东西用的。
LONG);
  set("exits", ([ /* sizeof() == 4 */
  "southwest" : __DIR__"huoyun", 
]));
  set("objects", ([ /* sizeof() == 1*/
  __DIR__"obj/che" : 1,
]));



  setup();
}

