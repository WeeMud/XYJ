// cracked by vikee 2/09/2002   vikee@263.net
// cat.c

#include "/doc/help.h"
#include "/net/daemons.h"

inherit F_CLEAN_UP;
int help(object me);

int main(object me, string arg)
{
	string file;

	seteuid(geteuid(me));
	if(arg && arg="on") {
	  DNS_MASTER->set_monitor(me);
	  write("ok.\n");
        } else {
	  DNS_MASTER->set_monitor(0);
	  write("closed.\n");
        }
	return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : dns <on>

to set debug mode for the dns_master.
HELP
    );
    return 1;
}
