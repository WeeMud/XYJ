// cracked by vikee 2/09/2002   vikee@263.net
// reboot.c

#include <login.h>
#include <obj.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string wiz_status;
	object npc;

	if( me != this_player(1) ) return 0;
	
	wiz_status = SECURITY_D->get_status(me);
	if( wiz_status != "(admin)" && 
		wiz_status != "(wizard)" &&
		wiz_status != "(arch)" )
		return notify_fail("ֻ�� (wizard) ���ϵ���ʦ������������" + MUD_NAME + "\n");

	seteuid(getuid());

	/* mon
	// set wiz lock during count down.
	LOGIN_D->set_wizlock(wiz_level("(elder)"));
	*/

	npc = new(NPC_DEMOGORGON);
	npc->move(START_ROOM);
	npc->start_shutdown();

	write("Ok��\n");

	return 1;
}

int help (object me)
{
        write(@HELP
ָ���ʽ: reboot
 
��������Ϸ, ϵͳ�Ὺʼ������ʱ, ʮ����Ӻ������𶯡�
 
HELP
);
        return 1;
}
 
