// cracked by vikee 2/09/2002   vikee@263.net
// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "大路");
  set ("long", @LONG

一条烟尘漫漫的大路，其路遥遥，其雾茫茫，前不见古人后不
见来者。时而有远方兽吼，时而又有近处鸟鸣。两边荒山野林
交替出现，你不由自主地加快步伐。

LONG);

  set("exits", ([
        "east"    : __DIR__"dalu12",
        "west"    : __DIR__"dalu10",
      ]));
  set("outdoors",__DIR__"");
  setup();
}

