// cracked by vikee 2/09/2002   vikee@263.net

//�����ֻ�

#include <ansi.h>
 
inherit F_DBASE;
inherit SSERVER;
 
void delay_effect(object me, object target, object weapon,int power);
 
int perform(object me, object target)
{
        int delay,skill;
        object weapon=me->query_temp("weapon");
        //if (!wizardp(me)) return notify_fail("�㲻�ᡣ\n");
        if (!target) return notify_fail("��˭��\n");
        if (!me->is_fighting(target))
          return notify_fail("���ǲ��ڴ�ܡ�\n");
        skill=me->query_skill("tonsillit",1);        
        if (skill<60) return notify_fail("����������������졣\n");
        skill=me->query_skill("whip");
        if (skill<100) 
           return notify_fail("��ı޷�̫��ˡ�\n"); 
        if( (int)me->query("force") < 300 )      
                return notify_fail("�������������\n");
        if( (int)me->query_temp("lunhui_delay") )
                return notify_fail("���Ѿ���ʩչ�����ֻ��ˡ�\n");
        
        me->add("force", -200);
        delay=random(4)+1;
        message_vision(HIB"$N��������һЦ������"+weapon->name()+
             HIB"ͻȻ����������$nһ����ϲ��ץס���ᣬ��ǰ����һ�ּ�����\n"NOR, me,target);
//        tell_object(me,delay+"\n");
        me->set_temp("lunhui_delay", 1);
        me->start_busy(delay*2);
        me->start_call_out( (: call_other, __FILE__, "delay_effect", 
           me, target,weapon,delay:), delay*2);
 
         return 1;
}
 
void delay_effect(object me,object target,object weapon,int power)
{
        mapping action;
        mapping new_act=([]);
        int attack,damage;
        
        me->delete_temp("lunhui_delay");
      if (!target) return;
        if (environment(me)!=environment(target)) return;
        if (me->query_temp("weapon")!=weapon) return;

        message_vision(HIR"$N����ͻȻһ�䣬����"+weapon->name()+
            HIR"���������Ӱ����$n����·ȫ��������\n"NOR,me,target);
        message_vision(HIR"$N���������������������ܶ������ܹ�������ֻ�֮�࣬������͸��������\n"NOR,target);

        me->set("actions", (: call_other, SKILL_D("hellfire-whip"), "query_pfm_action" :) );

        attack=me->query_temp("apply/attack");
        damage=me->query_temp("apply/damage");
        me->add_temp("apply/attack",me->query_skill("hellfire-whip") *power);
        me->add_temp("apply/damage",damage*power+me->query("force_factor"));
        COMBAT_D->do_attack(me, target, weapon);
        me->set_temp("apply/attack",attack);
        me->set_temp("apply/damage",damage);
        me->reset_action();
      me->start_busy(1);target->start_busy(1);
}
