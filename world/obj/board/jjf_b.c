// cracked by vikee 2/09/2002   vikee@263.net
// jjf_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("���Ͳ�", ({ "board" }) );
        set("location", "/d/jjf/keting.c");
        set("board_id", "jjf_b");
        set("long", "����һ�������Ĺ��Ͳ���������������ؼ��Ž���������������ս����\n" );
        setup();
        set("capacity", 100);
        replace_program(BULLETIN_BOARD);
}
