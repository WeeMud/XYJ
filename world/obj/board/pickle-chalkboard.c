// cracked by vikee 2/09/2002   vikee@263.net
// pickle's board.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("�ڰ�", ({ "chalkboard" }) );
	set("location", "/u/pickle/workroom");
	set("board_id", "chalkboard");
	set("long",	"����һ������ĺڰ壬����д�����������µ����ԡ�\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}
