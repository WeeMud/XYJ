// cracked by vikee 2/09/2002   vikee@263.net
// /clone/board/bonze_b.c

#include "ansi.h"

inherit BBS_BOARD;

void create()
{
	set_name("���μǷ�չ���۰�", ({ "board" }) );
	set("location", "/d/wiz/entrance");
	set("board_id", "query_bbs");
	set("long", "����һ������ʦ��������۷�չ�����õ����۰塣\n" );
	setup();
	set("capacity", 300);
	replace_program(BBS_BOARD);
}

