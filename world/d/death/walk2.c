// cracked by vikee 2/09/2002   vikee@263.net
// zhting.c

inherit ROOM;

void create ()
{
  set ("short", "幽司");
  set ("long", @LONG

这里便是阴曹地府之中，偶尔看到几个索命鬼，勾司人牵着些套着
枷锁的人走来走去。周围是一座座的楼阁宫殿，看起来也相当的富
丽堂皇，奇怪的是都有一扇钉着金钉的红木门和一条白玉门槛。
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"walk1",
  "east" : __DIR__"room4",
  "west" : __DIR__"room3",
  "north" : __DIR__"walk3",
]));
  set("hell", 1);

  setup();
}
