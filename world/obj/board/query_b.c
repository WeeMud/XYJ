// cracked by vikee 2/09/2002   vikee@263.net
// query_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("�����Ӧ���԰�", ({ "board" }) );
	set("location", "/d/wiz/entrance");
	set("board_id", "query_b");
	set("long",	"����һ���������Լ��µ����԰塣\n" );
	setup();
	set("capacity", 30);
	replace_program(BULLETIN_BOARD);
}
