// cracked by vikee 2/09/2002   vikee@263.net
// mihun.c �Ի���
#include <ansi.h>

inherit SSERVER;

void free(object target);

int cast(object me, object target)
{
	string msg;
	int success, ap, dp, ap2, ap3, ap4, dp2, dp3, dp4,howlong;
	int xk;

	if( !target ) target = offensive_target(me);

	if((int)me->query_skill("spells") < 100 || (int)me->query_skill("moonshentong",1) < 60)
		return notify_fail("�㻹ûѧ���Ի���������\n");

	if( !target
	||      !target->is_character()
	||      target->is_corpse()
	||      target==me)
		return notify_fail("������˭�Ļꣿ\n");  

	if(target->query_temp("no_move"))
	return notify_fail(target->query("name")+"�Ѿ��겻���ᣬ����ľ���ˣ�\n");  

	if((int)me->query("mana") < 200 )
		return notify_fail("��ķ���������\n");

	if((int)me->query("sen") < 10 )
		return notify_fail("���޷����о�����\n");

	me->add("mana", -200);
	me->receive_damage("sen", 10);

	msg = HIC
"$N��ͷ�������˾����ģ���̧��ͷ����$n���ĵ�һЦ��\n" 
NOR;

	success = 1;
	ap = me->query_skill("spells");
	ap = ap * ap * ap /12 ;
	ap += (int)me->query("daoxing");
	dp = target->query("daoxing");
//	if( random(ap + dp) < dp ) success = 0;
//here we compared exp and spells level. 
//note: has nothing to do with target's spells level.

	ap2 = (int)me->query_per();
	dp2 = (int)target->query_per();
//	if( random(4*ap) < ((int)target->query_cps()+dp)) success = 0;
//here we compare per and guy's ding li.


	ap3 = (int)me->query("mana");
	dp3 = (int)target->query("mana");
    ap = ap + 5000*ap2+200*ap3;
    dp = dp+5000*dp2+200*dp3;

        xk=SPELL_D->check_xiangke(me, target);
        if(xk==1) {
            dp/=5;
        } else if(xk==-1) {
            ap/=5;
        }

    if( random(ap+dp)<dp) success = 0;

//here we compare current mana. this is important. you need recover to try again.

	if(success == 1 ){
		msg +=  HIR "$n������ؿ���$N������ϧ��֮����Ȼ���𣬾�Ȼ�����Լ���ս��֮�С�\n" NOR;
		target->set_temp("no_move", 1);
	
		howlong = random((me->query_skill("spells") -100))/3+4;
		if(howlong>60) howlong=60;
		call_out("free", howlong, target);
	}	    
	else {
		msg +=  HIR "$n���ĵؿ���$Nһ�ۣ�����Ϊ������\n" NOR;	
        me->start_busy(random(2));
        	if( living(target) ) target->kill_ob(me);
	} 

	message_vision(msg, me, target);

	return 3+random(5);
}

void free(object target)
{
	if (target)
	target->delete_temp("no_move");      
	return;
}

