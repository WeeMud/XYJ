// cracked by vikee 2/09/2002   vikee@263.net
// Room: /d/nanhai/shanglu
inherit ROOM;

void create ()
{
  set ("short", "ɽ·");
  set ("long", @LONG

�������۵�ɽ·�����Ͼ�������ɽ��ɽ�š�
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"shanglu2",
  "northup" : __DIR__"gate",
]));
  set("outdoors", "/d/nanhai");

  setup();
}
