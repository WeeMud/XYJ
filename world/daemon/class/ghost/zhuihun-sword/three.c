// cracked by vikee 2/09/2002   vikee@263.net
#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        object weapon;
	int i,j;

	if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ��һ�С����ˡ�����\n");

        if(!me->is_fighting())
                return notify_fail("�����ˡ���ֻ����ս����ʹ�ã�\n");

        if((int)me->query("force") < 1000 )
                return notify_fail("�������������\n");

        if((int)me->query("kee") < 300 )
                return notify_fail("�����Ѫ���㣬û����ʩ���⹦��\n");

        if((int)me->query_skill("zhuihun-sword", 1) < 50)
                return notify_fail("���׷�꽣���𻹲�����ʹ����һ�л������ѣ�\n");

        if((int)me->query_skill("kusang-bang", 1) < 50)
                return notify_fail("��Ŀ�ɥ�����𻹲�����ʹ����һ�л������ѣ�\n");

        if((int)me->query_skill("hellfire-whip", 1) < 50)
                return notify_fail("����һ�޼��𻹲�����ʹ����һ�л������ѣ�\n");

        weapon=me->query_temp("weapon");

	if( me->query("env/brief_message") ){
		i=1;
	} else {
		i=0;
	}
	if( target->query("env/brief_message") ){
		j=1;
	} else {
		j=0;
	}	

	me->delete("env/brief_message");
	target->delete("env/brief_message");

	message_vision("\n$N˫�ֻ�һ��Բ����Ȼ������٣������������������������ˡ����ˡ������С�\n", me);

	me->set("HellZhen", 7);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

	me->set("HellZhen", 6);
//	message_vision("\n$N˫��һ��������$n��ʱ��ı�ֱ����ͬһ��������\n", me, weapon);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 

	me->set("HellZhen", 3);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

	me->delete("HellZhen");

	if( i ) me->set("env/brief_message", 1);
	if( j ) target->set("env/brief_message", 1);



	me->receive_damage("kee", 100);
	me->add("force", -100);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

	me->start_busy(3);
	return 1;
}
