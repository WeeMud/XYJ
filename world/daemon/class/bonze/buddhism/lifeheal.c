// cracked by vikee 2/09/2002   vikee@263.net
// lifeheal.c

#include <ansi.h>

int cast(object me, object target)
{
	if( !target )
		return notify_fail("��Ҫ�÷���Ϊ˭���ˣ�\n");

	if( me->is_fighting() || target->is_fighting())
		return notify_fail("ս�����޷��˹����ˣ�\n");

	if( (int)me->query("mana") - (int)me->query("max_mana") < 150 )
		return notify_fail("��ķ���������\n");

	if( (int)target->query("eff_sen") < (int)target->query("max_sen") / 5 )
		return notify_fail( target->name() + "������ʧ�����ܲ�����ķ����𵴣�\n");

	message_vision(
		HIY "$N���������˶����ţ�����������$n��̨�������ؽ���������$n����....\n\n"
		"���˲��ã�$N��ͷ��ð������ĺ��飬$n�³�һ�����������������ö��ˡ�\n" NOR,
		me, target );

	target->receive_curing("sen", 10 + (int)me->query_skill("spells")/3 );
	me->add("mana", -150);
	me->set("mana_factor", 0);

	return 1;
}
