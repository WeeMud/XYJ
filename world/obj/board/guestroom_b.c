// cracked by vikee 2/09/2002   vikee@263.net
// nancheng_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("ӭ�������԰�", ({ "board" }) );
	set("board_id", "guestroom_b");
	set("long",	"����һ���������Լ��µ����԰塣\n" );
	setup();
	set("capacity", 10);
	replace_program(BULLETIN_BOARD);
}
