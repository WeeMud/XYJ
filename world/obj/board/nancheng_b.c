// cracked by vikee 2/09/2002   vikee@263.net
// nancheng_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("�ϳǿ�ջ���԰�", ({ "board" }) );
	set("location", "/d/city/kezhan");
	set("board_id", "nancheng_b");
	set("long",	"����һ���������Լ��µ����԰塣\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}
