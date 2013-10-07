// cracked by vikee 2/09/2002   vikee@263.net
// powerup.c

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill;


        skill = me->query_skill("tonsillit",1);

	if( skill > 250 ) {
		skill=250;
	}

        if( target != me ) 
		return notify_fail("��ֻ���÷����������������Լ���ս������\n");

        if( (int)me->query("force") < skill*2 )     
		return notify_fail("�������������\n");
        if( (int)me->query_temp("powerup") ) 
		return notify_fail("���Ѿ����˹����ˡ�\n");

        me->add("force", -skill);
        me->receive_damage("kee", 50);

        message_vision(
                HIR "$N΢һ��������������������ͷ��ð��һ�������������ֳ�һ�����Ρ�����\n" NOR, me);

        me->add_temp("apply/attack", skill/5);
	me->add_temp("apply/strength", skill/5);
        me->set_temp("powerup", 1);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/5 :), skill);

        if( me->is_fighting() ) me->start_busy(3);

        return 1;
}

void remove_effect(object me, int amount)
{
        if(!me) return;
        me->add_temp("apply/attack", - amount);
	me->add_temp("apply/strength", - amount);
        me->delete_temp("powerup");
        me->add("bellicosity", amount*2 );
	// mon 3/1/98. move this to after powerup is done.
        tell_object(me, "��ķ���������������һ������ϣ��������ջص��\n");
}

