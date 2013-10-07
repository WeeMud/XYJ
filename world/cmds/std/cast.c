// cracked by vikee 2/09/2002   vikee@263.net
// cast.c

#include <skill.h>
#include "/cmds/std/valid_kill.h";

inherit F_CLEAN_UP;

void destruct_flag(object me);

int main(object me, string arg)
{
	string spells, spl, trg;
	object target;
	
	seteuid(getuid());

        if((int)me->query_temp("no_cast")==1)
	        return notify_fail("�����ڲ�����ħ����\n");

	if( me->is_busy() )
		return notify_fail("( ����һ��������û����ɣ����������ġ�)\n");

	if( (int)me->query_temp("silence")==1 )
		return notify_fail("( ��ʲô���������)\n");

	if( me->is_ghost() )
		return notify_fail("�����ڲ�����ħ����\n");

	if( !wizardp(me) && environment(me)->query("no_magic") )
		return notify_fail("���ﲻ׼�����ġ�\n");

	if( !arg ) return notify_fail("ָ���ʽ��cast <����> [on <Ŀ��>]\n");
	if( sscanf(arg, "%s on %s", spl, trg)==2 ) {
		target = present(trg, environment(me));
		if( !target ) target = present(trg, me);
		if( !target ) return notify_fail("����û�� " + trg + "��\n");
		
		if(!valid_kill(me,target,0)) return 0;

		if( userp(me) && userp(target) && 
		    target->query_temp("netdead") )
		   return notify_fail("�Է����ڶ����У����ܶ���ʩ����\n");
	} else {
		spl = arg;
		target = 0;
	}

	spl = replace_string( spl, " ", "_");

	if( stringp(spells = me->query_skill_mapped("spells")) ) {
	        int nocast;
		notify_fail("����ѧ�ķ�����û�����ֹ��ܡ�\n");
		nocast=(int)SKILL_D(spells)->cast_spell(me, spl, target);
		//cast_spell should return an integer as the no_cast time.
		if (!nocast) 
		  nocast=(int)SKILL_D("spells")->cast_spell(me, spl, target);
                if (nocast) {
                  me->set_temp("no_cast", 1);
		  //each cast should return an integer which is
		  //the no_cast time fot this cast.
		  //also, in each cast, can set busy or no_move
		  //time individually.   --mon 8/24/97
		  call_out("destruct_flag", nocast, me);
		  return 1;
		}
		return 0;
		}
		
	return notify_fail("�������� enable ָ��ѡ����Ҫʹ�õ�����ϵ��\n");
}

void destruct_flag(object me)
{
     if (me)
     	me->delete_temp("no_cast");
}

int help (object me)
{
        write(@HELP
ָ���ʽ��cast <��������> [on <ʩ�����>]
 
ʩ���������Ҫָ��<��������>��<ʩ�����>����п��ޡ�
����ʹ��ĳһ������֮ǰ����������� enable ָ����ָ����Ҫʹ�õ�����ϵ��
 
ע�������ı��Լ�������ϵ����ԭ������ķ���������ֱ��ת����ȥ������
    �� 0 ��ʼ��
 
HELP
        );
        return 1;
}
