// cracked by vikee 2/09/2002   vikee@263.net
// quit.c

#include <command.h>

inherit F_DBASE;
inherit F_CLEAN_UP;

int do_drop(object me, object obj);

void create() 
{
	seteuid(getuid());
	set("name", "����ָ��");
	set("id", "quit");
}

// if force_quit==1, then don't check whether allow quit.
// used by quit after disconnected or idled too long.
// mon 7/5/98
int main(object me, string arg, int force_quit)
{
	int i;
	object *inv, link_ob;

	link_ob = me->query_temp("link_ob");

	if(!force_quit) {
	if ( me->query_temp("no_move") )
		return notify_fail("�㱻��ס�ˣ������˵ó���Ϸ��\n");

        if(!me->query_temp("suicide_countdown")) {
	  if( me->is_busy() )
		return notify_fail("( ����һ��������û����ɣ������˳���)\n");
        } //to allow halt suicide :D by mon 9/9/97

        if( !wizardp(me) && environment(me) && 
	  environment(me)->query("no_quit") && link_ob )
                        return notify_fail("���ﲻ׼�˳���Ϸ��\n");
	}

	if( !wizardp(me) && (!link_ob || (
	    link_ob && !link_ob->is_character()) ) ) {
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++)
			if( !inv[i]->query_autoload() )
//since drop commands when quit is a little different from normal drop commands
//the do_drop is revised here. wuliao@xyj Feb 1997
				do_drop(me, inv[i]);
	}

	// We might be called on a link_dead player, so check this.
	if( link_ob ) {

		// Are we possessing in others body ?
		if( link_ob->is_character() ) {
			write("��Ļ��ǻص�" + link_ob->name(1) + "�����ϡ�\n");
			exec(link_ob, me);
			link_ob->setup();
			return 1;
		}

		link_ob->set("last_on", time());
		link_ob->set("last_from", query_ip_name(me));
		link_ob->save();
		destruct(link_ob);
	}

	write("��ӭ�´�������\n");
	if(!wizardp(me) || !me->query("env/invisibility"))
	message("system", me->name() + "�뿪��Ϸ��\n", environment(me), me);

	CHANNEL_D->do_channel(this_object(), "sys",
		me->name() + "(" + capitalize(me->query("id")) + ")" + "�뿪��Ϸ�ˡ�");

	me->save();
	destruct(me);

	return 1;
}

int do_drop(object me, object obj)
{
    	//if obj is a self-made fabao, save first...
        //if( obj->query("series_no") && obj->query("fabao") ) obj->save();
           
        if( obj->query("no_drop") ){
                destruct(obj);
                return 0;
        }
        if (obj->move(environment(me))) {
                if( obj->is_character() )
                        message_vision("$N��$n�ӱ��Ϸ������������ڵ��ϡ�\n", me, obj);
                else {
                        message_vision( sprintf("$N����һ%s$n��\n",     obj->query("unit")), me, obj );
                        if( !obj->query("value") && !obj->value() ) {
                                tell_object(me,"��Ϊ������������ֵǮ���������ǲ�����ע�⵽���Ĵ��ڡ�\n");
                                destruct(obj);
                        }
                }
                return 1;
        }
        return 0;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : quit

��������ʱ�뿪ʱ, �����ô�һָ�
HELP
    );
    return 1;
}
