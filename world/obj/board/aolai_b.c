// cracked by vikee 2/09/2002   vikee@263.net
// nancheng_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("�����ջ���԰�", ({ "board" }) );
	set("location", "/d/dntg/hgs/cuixiang");
	set("board_id", "aolai_b");
	set("long",	"����һ���������Լ��µ����԰塣\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}
