// cracked by vikee 2/09/2002   vikee@263.net
//jiz.

#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
	int mypot,tapot,time;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("���޾��粨��ֻ����ս���в���ʹ�á�\n");

	if( (int)me->query_skill("fengbo-cha", 1) < 50 ) 
		return notify_fail("�����Ϊ�������ʹ������һ�У�\n");

	if( target->is_busy() )
		return notify_fail(target->name()+"�Ѿ���æ�ˣ���ʹ����Ư��Ҳ����ע�⵽��\n");

	message_vision(HIC"$N��չ��������һ�棬��һ�棬�ó�������С�⻷��$n��ȥ��
�俴��������������ȴ�����ﲨ�����಻����ʵ�ǰ���ɱ����\n\n"NOR,me, target);

	me->add("sen", -100);

	mypot=(int)me->query_skill("fork");
	mypot=mypot*mypot*mypot/10 + (int)me->query("combat_exp");

	tapot=(int)target->query_skill("parry");
	tapot=tapot*tapot*tapot/10 + (int)target->query("combat_exp");

	time=(int)me->query_skill("fengbo-cha", 1) /10;
	if ( time > 10 ) time = 10;
	if ( time < 5  ) time = 5;

	if ( random( mypot + tapot ) > tapot ) {
		message_vision(HIR"$N��Ȼ����⻷��ס����ʱĿ�ɿڴ�����֪���룡\n"NOR,target);
		target->start_busy(time);
	}else {
	message_vision(HIR"����ȴ��$N���ƣ����䲻����$n�������˸����ֲ�����\n"NOR,target,
me);
		me->start_busy(3);
	}

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
                me->kill_ob(target);
        }
	return 1;
}
