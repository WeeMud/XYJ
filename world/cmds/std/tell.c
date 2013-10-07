// cracked by vikee 2/09/2002   vikee@263.net
// tell.c

#include <ansi.h>
#include <net/dns.h>
#include "/cmds/std/block_tell.h";

inherit F_CLEAN_UP;

int help(object me);
void add_id(object me, string id);

void create() {seteuid(getuid());}

int main(object me, string arg)
{
	string target, msg, mud;
	object obj;
	string *allow;

	if( !arg || sscanf(arg, "%s %s", target, msg)!=2 ) return help(me);

	if( sscanf(target, "%s@%s", target, mud)==2 ) {
		GTELL->send_gtell(mud, target, me, msg);
		write("��·ѶϢ���ͳ�������Ҫ�Ժ���ܵõ���Ӧ��\n");
		
	        // mon 7/29/98
	        add_id(me, target+"@"+mud);

		return 1;
	}

        if(!block_tell(me)) return 1;

	obj = find_player(target);
	if(!obj || !me->visible(obj)) return notify_fail("û������ˡ�\n");

	// mon 7/29/98
	// when a player set no_tell, if he once initiate to tell
	// others, then his target is allowed to use tell to tell him.

	allow=obj->query_temp("allow_tell");
	if(!allow || member_array(me->query("id"), allow)==-1)
	  if( !wizardp(me) && obj->query("env/block_tell") )
	    return notify_fail(obj->name(1) + "���²�����κ���˵����\n");

        if(!living(obj) || !interactive(obj)) 
	  return notify_fail(obj->name(1)+"������������˵�Ļ���\n");
	  
	write(GRN "�����" + obj->name(1) + "��" + msg + "\n" NOR);
	tell_object(obj, sprintf( HIG "%s�����㣺%s\n" NOR,
		me->name(1)+"("+me->query("id")+")", msg));

	obj->set_temp("reply", me->query("id"));
	
	// mon 7/29/98
	add_id(me, target);
	return 1;
}

string remote_tell(string cname, string from, string mud, string to, string msg)
{
	object ob;
	string *allow;

	if( ob = find_player(to) ) {
	        if(wizardp(ob) && ob->query("env/invisibility"))
		  return "�����Ҳ�������ˡ�"; //respond no such user.

		// mon 7/29/98
	    allow=ob->query_temp("allow_tell");
	    if(!allow || member_array(lower_case(from+"@"+mud), allow)==-1)
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
		ob->set_temp("reply", from+"@"+mud);

		return ob->query("name")+"�յ��������Ϣ��";  
		// if succeed, return target's name.
	} else
		return "�����Ҳ�������ˡ�";
}

// mon 7/29/98
void add_id(object me, string id)
{
    string *allow;

    // temp array of players we allow to talk to.
    allow=me->query_temp("allow_tell");
    if(!allow) allow=({id});
    else if(sizeof(allow)<50 && member_array(id,allow)==-1)
        allow+=({id});
    me->set_temp("allow_tell", allow);
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
