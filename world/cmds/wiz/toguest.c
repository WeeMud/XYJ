// cracked by vikee 2/09/2002   vikee@263.net
// mon 8/3/99

#include "/doc/help.h"

inherit F_CLEAN_UP;

string JAIL="/d/wiz/guest";
int help(object me);

int main(object me, string arg)
{
        int online, howlong;
	object who, env;
	string id;

	seteuid(geteuid(me));

        if (!arg) return notify_fail("����Ҫ��˭����ӭ������\n");
	arg=replace_string(arg,"#"," ");
	arg=replace_string(arg,"."," ");

	if(sscanf(arg, "%s for %d", id, howlong)==2) {
	    if(howlong<1) return notify_fail("����Ӧ������Ϊһ�졣\n");
	} else {
	    id=arg;
	    howlong=2;
	}

	who=find_player(id);
	if(who) { //player online now.
	    online=1;
	    if(env=environment(who))
		message_vision("�����̽��һֻ���ֽ�$Nץ���������ˡ�\n",
			who);
	} else {
	    who=new(USER_OB);
	    who->set("id",id);
	    if(!who->restore()) {
		write("û��"+id+"�����һ��ļ�����\n");
		if(who) destruct(who);
		return 1;
	    }
	    online=0;
	}
	
	who->set("banned_approved",time()+24*3600*howlong);
	if(online) {
	    who->move(JAIL);
	}
	who->set("startroom",JAIL);
	who->save(1);
	log_file("to_jail","["+ctime(time())+"]"+
		this_player()->query("id")+" send "+who->query("id")+
		" to guestroom for "+howlong+" day(s).\n");
	write("�㽫"+who->query("name")+"("+id+")�ͽ���ӭ������"+
		chinese_number(howlong)+"����ͷš�\n");

	if(!online) {
	    destruct(who);
	} 

	return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ��toguest id               -- send to guest for 2 days.
          toguest id for <number>  -- send to guest for <number> days.
	  
	  e.g.: toguest id for 7 

Send <id> to xyj guest room.
HELP
    );
    return 1;
}
