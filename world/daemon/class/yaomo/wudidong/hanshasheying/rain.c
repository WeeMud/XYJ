//
//rain.c by hexiu

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
        object weapon;
        string msg;
        weapon = me->query_temp("weapon");

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ��һ�С��������꡹��\n");

     

        if((int)me->query("max_force") < 500 )
                return notify_fail("�������������\n");

        if((int)me->query("force") < 500 )
                return notify_fail("����������㣡\n");

        if((int)me->query("sen") < 500 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");

        if((int)me->query_skill("hanshasheying", 1) < 100)
                return notify_fail("��ĺ�ɳ��Ӱ���𻹲�����ʹ����һ�л������ѣ�\n");
              
        if (me->query_skill_mapped("force")!="huntian-qigong")
                return notify_fail("�������������ϻ�����������ʹ�á�\n");

        if (me->query_temp("rain_busy"))
                return notify_fail("������ʹ�Ͳ����ˣ�\n");
              
        //me->delete("env/brief_message");
        //target->delete("env/brief_message");

        message_vision(MAG"\n���������Գ�$N����Ӱ��ֻ��$Nһ����!\n"NOR,me,target);
		message_vision(HIC"\n��ö"+weapon->query("name")+"������������$n����!\n"NOR,me,target);

        
        
        
        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                         target->kill_ob(me);
                }
        }

        me->set_temp("HSSY_perform", 4);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->set_temp("HSSY_perform", 1);  
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 

        
        me->set_temp("HSSY_perform", 6);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        
        
        if((int)me->query_skill("hanshasheying",1) > 200)
		{
			me->set_temp("HSSY_perform", 5);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));  
		}

        me->delete_temp("HSSY_perform");

        me->receive_damage("sen", 100);
        me->add("force", -100);
        

       /* 
	   if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }
		*/

        me->set_temp("rain_busy",1);
		call_out("remove_rain_busy",9+random(3),me);
        //me->start_busy(2+random(1));

        return 1;
}

void remove_rain_busy(object me)
{ 
        if (!me) return;
		if (me->query_temp("rain_busy"))
        me->delete_temp("rain_busy");
}         


