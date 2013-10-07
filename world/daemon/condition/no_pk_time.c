// cracked by vikee 2/09/2002   vikee@263.net
// pk_counter.c
// by mon. 9/22/97

#include <ansi.h>
#include <condition.h>
#include <login.h>

inherit F_CLEAN_UP;

string *msgs= ({
"\n���������һ�����磬���һ��������ͷ�ϣ�\n",
"��·�������������������˵�������������ң�������������������",
"��ͻȻ���ñ����Ϸ���һ�����⣺����",
"��������ǰ�ɹ�����ô�����캦��֮�£����ɲ����ú���䤱���",
"��̧ͷ�����죬�����ֹ����Ҹ�����ô�໵�£�������������ɣ�",
"����¶�׹⣬�����Ƶش󺰣���ɱ��ɱ��ɱ�����۵���������������",
});

int update_condition(object me, int duration)
{

        object env=environment(me);
	
	if(env) {
	    if(!env->query("no_fight") && !env->query("no_magic")) {
	       me->apply_condition("no_pk_time", duration - 1);
	       me->delete_temp("no_heal_up/no_pk_time");
	    }
	    // can't hide in safe room to count hours.
	    else { // in a safe place.
		// no heal_up when in safe room.
		me->set_temp("no_heal_up/no_pk_time",1);
		if(living(me) && duration>100) {
		    seteuid(getuid());
                  if(env!=load_object(DEATH_ROOM) ||
			 !me->is_ghost()) {
		    me->receive_damage("kee",me->query("max_kee")/20);
		    me->receive_damage("sen",me->query("max_sen")/20);
//     if (me->query("sen")<0) me->set("sen",0);
//     if (me->query("kee")<0) me->set("kee",0);
		    write(msgs[random(sizeof(msgs))]+"\n");
		  }
		}
	    }
	}

	if( duration < 1 ) {
	    me->delete_temp("no_heal_up/no_pk_time");
	    return 0;
	}

	return CND_CONTINUE;
}

// mon 8/1/98
// this condition can't be cleared.
int no_clear_condition() {return 1;}

