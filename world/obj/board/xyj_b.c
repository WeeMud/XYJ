// cracked by vikee 2/09/2002   vikee@263.net
#include "ansi.h"

inherit BBS_BOARD;

void create()
{
        set_name("����"+HIG+" BBS "+NOR+"�������ð�", ({ "board" }) );
        set("location", "/d/wiz/jobroom");
        set("board_id", "xyj_b");
        set("long", "����һ������λ�������۵�"+HIG+" BBS "+NOR+"�塣\n" );
        setup();
        set("capacity", 500);
        replace_program(BBS_BOARD);
}

