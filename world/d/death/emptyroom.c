// cracked by vikee 2/09/2002   vikee@263.net
// zhting.c

inherit ROOM;

void create ()
{
  set ("short", "����ɽ��");
  set ("long", @LONG

��������˾����ɽ�£���ΧһƬ������������ľ��һƬ�ž���
ֻ����������ع��š�ɽ���µ��������棬��˵�е���˾ʮ
�˲�������������û���˴�������ų�ȥ��


LONG);


  setup();
}
void init()
{
	add_action("do_get","eat");
	add_action("do_get","drink");
	add_action("do_get","kill");
        add_action("do_get","fight");
        add_action("do_get","cast");
        add_action("do_get","bian");
        add_action("do_get","fly");
        add_action("do_get","perform");
        add_action("do_get","steal");
	add_action("do_look", "look");
	add_action("do_exert", "exert");
}
int do_look(string arg)
{
	if( !arg ) {
		tell_object(this_player(),
"\n����������޵��µ�ʮ�˲�����ˣ����������ܴ�������ų�ȥ��\n\n");
		return 1;
	}
	command("look");
}
int do_exert(string arg)
{
	if( !arg )
		return notify_fail("��Ҫ���ڹ���ʲô��\n");
	if( arg!="heal"){
		command("exert");
		return 0;
	}
	tell_object(this_player(),"���ﲻ�����ˡ�\n");
	return 1;
}
int do_get(string arg)
{
	return 1;
}
