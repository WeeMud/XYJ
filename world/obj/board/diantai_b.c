// cracked by vikee 2/09/2002   vikee@263.net
inherit BULLETIN_BOARD;

void create()
{
	set_name("�ʼǱ�", ({"board"}) );
set("location", "/u/bula/diantai");
set("board_id", "diantai_b");
set("capacity", 100);
set("long", "
������������������������������������������������������������\n");
        setup();
        replace_program(BULLETIN_BOARD);
}

