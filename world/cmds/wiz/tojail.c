// cracked by vikee 2/09/2002   vikee@263.net
// mon 8/3/99

#include "/doc/help.h"

inherit F_CLEAN_UP;

string JAIL="/d/wiz/punish";
int help(object me);

int main(object me, string arg)
{
        int online;
	object who, env;

	seteuid(geteuid(me));

        if (!arg) return notify_fail("����Ҫ��˭������Σ�\n");
	arg=replace_string(arg,"#"," ");
	arg=replace_string(arg,"."," ");

	who=find_player(arg);
	if(who) { //player online now.
	    online=1;
	    if(env=environment(who))
		message_vision("�����̽��һֻ���ֽ�$Nץ���������ˡ�\n",
			who);
	    who->move(JAIL);
	} else {
	    who=new(USER_OB);
	    who->set("id",arg);
	    if(!who->restore()) {
		write("û��"+arg+"�����һ��ļ�����\n");
		if(who) destruct(who);
		return 1;
	    }
	    online=0;
	}
	
	who->set("startroom",JAIL);
	who->save(1);
	log_file("to_jail","["+ctime(time())+"]"+
		this_player()->query("id")+" send "+who->query("id")+
		" to jail.\n");
	write("�㽫"+who->query("name")+"("+arg+")�ͽ��˼��Ρ�\n");

	if(!online) {
	    destruct(who);
	} 

	return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ��tojail id 

Send <id> to xyj jail.
HELP
    );
    return 1;
}
