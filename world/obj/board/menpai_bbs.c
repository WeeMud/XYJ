// cracked by vikee 2/09/2002   vikee@263.net
// /clone/board/bonze_b.c

#include "ansi.h"

inherit BBS_BOARD;

void create()
{
	set_name("���μ�"+HIG+"����"+NOR+"���۰�", ({ "board" }) );
	set("location", "/d/wiz/menpai_room");
	set("board_id", "menpai_bbs");
	set("long", "����һ������ʦ���������ɷ�չ�����õ����Ű塣\n" );
	setup();
	set("capacity", 30);
	replace_program(BBS_BOARD);
}
