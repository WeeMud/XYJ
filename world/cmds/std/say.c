// cracked by vikee 2/09/2002   vikee@263.net
// say.c

#include <ansi.h>
#include "/cmds/std/block_tell.h";

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        if(!block_tell(me)) return 1;

	if (!arg) {
		write("���������ﲻ֪����˵Щʲô��\n");
		tell_room(environment(me), me->name() + "�������ﲻ֪����˵Щʲô��\n",
	          	  me);
		return 1;
	}
	if( (int)me->query("kee") < (int)me->query("max_kee") / 5 ) {
		arg = replace_string(arg, " ", " ... ") + " ...";
	}

	write( CYN "��˵����" + arg + "\n" NOR);
	tell_room(environment(me), CYN + me->name() + "˵����" +  arg + "\n" NOR,
	          me);

	// The mudlib interface of say
	all_inventory(environment(me))->relay_say(me, arg);

	return 1;
}

int help (object me)
{
	write(@HELP
ָ���ʽ: say <ѶϢ>
 
˵�������и�����ͬһ��������˶���������˵�Ļ���
 
ע: ��ָ����� ' ȡ��.
 
HELP
	);
	return 1;
}
