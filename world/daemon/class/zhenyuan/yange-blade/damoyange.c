#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
object weapon;
 string msg;
if( !target ) target = offensive_target(me);
if( !target
||      !target->is_character()
||      target->is_corpse()
||      target==me)
return notify_fail("��Ҫ��˭ʩչ��һ�С���Į��衹��\n");
if(!me->is_fighting())
return notify_fail("����Į��衹ֻ����ս����ʹ�ã�\n");
if((int)me->query("max_force") < 500 )
return notify_fail("�������������\n");
if((int)me->query("force") < 500 )
return notify_fail("����������㣡\n");
if((int)me->query("sen") < 500 )
return notify_fail("��ľ����㣬û����ʩ���⹦��\n");
if((int)me->query_skill("yange-blade", 1) < 80)
return notify_fail("�����赶�����𻹲�����ʹ����һ�л������ѣ�\n");
if (me->query_skill_mapped("force")!="zhenyuan-force")
return notify_fail("��Į�����������Ԫ�񹦲���ʹ�á�\n");

me->delete("env/brief_message");
target->delete("env/brief_message");

message_vision(HIR"\n$N���һ��,ֻ����ɳ��ʯ,��������,����Į��衹һ��һ���ǳ�!!!\n"NOR,me,target);

// message_vision( HIY  "�³����գ�\n" NOR,me,target);
me->set_temp("yange_perform", 1);
COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
// message_vision( HIC  "��Į���\n" NOR,me,target);
me->set_temp("yange_perform", 2);
COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
// message_vision( HIG  "�߷�Ʈҡ��\n" NOR,me,target);
me->set_temp("yange_perform", 4);
COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
// message_vision( HIW  "�����Ϸɣ�\n" NOR,me,target);
me->set_temp("yange_perform", 6);
COMBAT_D->do_attack(me, target, me->query_temp("weapon"));       
me->delete_temp("yange_perform");      
me->receive_damage("sen", 100);   
me->add("force", -100);

if( !target->is_fighting(me) ) {
if( living(target) ) {
if( userp(target) ) target->fight_ob(me);
else target->kill_ob(me);
}
}
me->start_busy(2+random(1));
return 1;
}
