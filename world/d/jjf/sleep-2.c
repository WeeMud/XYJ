// cracked by vikee 2/09/2002   vikee@263.net
// Room: /d/jjf/sleep-2
inherit ROOM;

void create ()
{
  set ("short", "é��");
  set ("long", @LONG

����������û��������Ȼ�м�Сé�ݡ�������տյģ�ûʲô���裬
ֻ�ǲ�֪���ﴫ���������㣬���˾���Ϊ֮һˬ��
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"sleep",
]));
  set("light_up", 1);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/baifalaoren.c" : 1,
]));

  setup();
}
