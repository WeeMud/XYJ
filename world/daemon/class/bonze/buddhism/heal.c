// cracked by vikee 2/09/2002   vikee@263.net
// heal.c

#include <ansi.h>

int cast(object me, object target)
{
	if( me->is_fighting() )
		return notify_fail("ս�����˹����ˣ�������\n");

	if( (int)me->query("mana") < 50 )
		return notify_fail("��ķ���������\n");

	if( (int)me->query("eff_sen") < (int)me->query("max_sen") / 2 )
		return notify_fail("�㾫��ʵ�ڲ��ã�ֻ��һ�˷�����������Σ�գ�\n");

	write( HIW "��ȫ����ɣ����ȶ�������ʼ�������⡣\n" NOR);
	message("vision",
		HIW + me->name() + "���ȶ�������ʼ�������⡣�����³�һ�����������������ö��ˡ�\n"NOR,
		environment(me), me);

	me->receive_curing("sen", 10 + (int)me->query_skill("spells")/5 );
	me->add("mana", -50);
	me->set("mana_factor", 0);

	return 1;
}
