// cracked by vikee 2/09/2002   vikee@263.net
// wizard_j.c

inherit "/std/jboard";

void create()
{
	set_name("��ʦ�������ȱ���", ({ "job board", "board" }) );
	set("location", "/d/wiz/jobroom");
	set("board_id", "wizard_j");
	set("long",	"����һ����������԰幩��ʦ�����Լ��Ĺ������ȡ�\n" );
	setup();
	replace_program("/std/jboard");
}
