// cracked by vikee 2/09/2002   vikee@263.net
// Room: jiaoli.c
// AceP

inherit ROOM;

int do_quit();

void create()
{
	set("short", "��������");
	set("long", @LONG
���ǻ������棬�������ӳ��޵�ʱ�����ģ���ϲ��ϲ��ף���»���֣�^_^
LONG
	);

	setup();
}

void init()
{
	add_action("do_quit","quit");
}

int do_quit()
{
	tell_object(this_player(), "ʲô�����ѵ�����ӻ鲻�ɣ���");
	return 1;
}
