// cracked by vikee 2/09/2002   vikee@263.net
// tell.c

#include <ansi.h>
#include <net/dns.h>
#include "/cmds/std/block_tell.h";

inherit F_CLEAN_UP;

int help(object me);

	void create() {seteuid(getuid());}

int main(object me, string arg)
{
	string target, msg, mud, filename;
	object obj;

	if( !arg || sscanf(arg, "%s %s", target, filename)!=2 )
	   return help(me);

	msg = "\n";
	msg += read_file(filename);

	if( sscanf(target, "%s@%s", target, mud)==2 ) {
		GTELL->send_gtell(mud, target, me, msg);
		write("��·ѶϢ���ͳ�������Ҫ�Ժ���ܵõ���Ӧ��\n");
		return 1;
	}

        if(!block_tell(me)) return 1;

	obj = find_player(target);
	if(!obj || !me->visible(obj)) return notify_fail("û������ˡ�\n");

	if( !wizardp(me) && obj->query("env/block_tell") )
	   return notify_fail(obj->name(1) + "���²�����κ���˵����\n");

        if(!living(obj) || !interactive(obj)) 
	  return notify_fail(obj->name(1)+"������������˵�Ļ���\n");
	  
	write(GRN "�����" + obj->name(1) + "��" + msg + "\n" NOR);
	tell_object(obj, sprintf( GRN "%s�����㣺%s\n" NOR,
		me->name(1)+"("+me->query("id")+")", msg));

	obj->set_temp("reply", me->query("id"));
	return 1;
}

string remote_tell(string cname, string from, string mud, string to, string msg)
{
	object ob;

	if( ob = find_player(to) ) {
	        if(wizardp(ob) && ob->query("env/invisibility"))
		  return "�����Ҳ�������ˡ�"; //respond no such user.

	        if( ob->query("env/block_tell") ) return
		  ob->query("name")+"���ڲ�����κ���˵����";

        if(!living(ob) || !interactive(ob)) 
	          return ob->query("name")+"������������˵�Ļ���\n";

		if( cname )
			tell_object(ob, sprintf(HIG "%s(%s@%s)�����㣺%s\n" NOR,
				cname, capitalize(from), mud, msg ));
		else
			tell_object(ob, sprintf(HIG "%s@%s �����㣺%s\n" NOR,
				capitalize(from), mud, msg ));
		ob->set_temp("reply", from + "@" + mud);
		return ob->query("name")+"�յ��������Ϣ��";  
		// if succeed, return target's name.
	} else
		return "�����Ҳ�������ˡ�";
}

int help(object me)
{
	write(@HELP
ָ���ʽ��tell <ĳ��> <ѶϢ>

����������ָ��������ط���ʹ����˵����

�������ָ�reply
HELP
	);
	return 1;
}
