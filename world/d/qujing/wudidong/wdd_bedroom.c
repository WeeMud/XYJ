// cracked by vikee 2/09/2002   vikee@263.net
// Room: /d/qujing/wudidong/wdd_bedroom.c

inherit ROOM;
inherit "/d/wiz/no_get";

void create()
{
	set("short", "�Է�");
	set("long", @LONG

�������޵׶����Է����������˯�ż������󾫡�����ɢ����һ����
����Ż����������֪���ĸ�С���������������ˡ�
LONG
	);
	set("sleep_room", "1");
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"dong2",
]));
	set("no_clean_up", 0);
	set("no_magic", "1");
	set("no_fight", "1");

	setup();
}
