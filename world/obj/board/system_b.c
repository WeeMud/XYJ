// cracked by vikee 2/09/2002   vikee@263.net
// wizard_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("ϵͳ�����", ({ "board" }) );
	set("location", "/d/wiz/system");
	set("board_id", "system_b");
	set("long",
		"����һ��ר�Ź���ϵͳ��Ѷ�İ��ӣ�ֻ����ʦ�� post��\n" );
	setup();
	set("capacity", 150);
	replace_program(BULLETIN_BOARD);
}
