//�������������� by hexiu

#include <ansi.h>
#include <combat.h>

inherit SSERVER;

int exert(object me, object target)
{
       object where;
        int i, skill, damage, force;
    

	if( !target
	||      !target->is_character()
	||      target->is_corpse()
	||      target==me)
		return notify_fail("��Ҫ��˭��\n");

	if ( me->query_temp("fjdh_busy") == 1)
        return notify_fail("Ъ���ٷ���\n");

	where=environment(me);
	if( where->query("no_fight") )
		return notify_fail("��ȫ���ڲ����ҽУ�\n");

        if( !me->is_fighting() )
                return notify_fail("��������ֻ����ս����ʹ�á�\n");
	
		if( me->query_skill("dragonforce",1) < 200 )
                return notify_fail("��Ĺ�������������������\n");


        if( (int)me->query("force") < 200 )
                return notify_fail("�������������\n");
	if( (int)me->query("kee") < 100)
		return notify_fail("������������ˡ�\n");


        skill = me->query_skill("force");
	force = me->query("max_force");
        me->add("force", -150);
        me->receive_damage("kee", 50);

       // me->start_busy(5);
		me->set_temp("fjdh_busy",1);
        me->set_temp("no_move",1);
		call_out("remove_no_move",3,me);
        call_out("remove_effect",6+random(3),me);
	message_vision(HIR "\n$N�˺��������������һ��������Ȼ��������������������\n\n"
NOR, me);
      

	if( skill/2 + random(skill/2) > (int)target->query("cps") * 2 ) 
	{

                damage = skill + force/10 - ((int)target->query("max_force") / 10);
                if( damage > 0 ) 
				{
                        target->receive_damage("sen", damage/2, me);
                        if( (int)target->query("force") < skill * 2 )
                                target->receive_wound("sen", damage/10, me);
						if (target->query_temp("no_dodge") == 1) 
    //                    message_vision(HIY"\n$N���ڵ���ſ���أ�\n"NOR,target);
write("�Է����»���ſ�ţ�\n");
						else{
                              target->set_temp("no_dodge",1);
							  message_vision(HIW"\nһ�����Ϯ����ֱ�ӽ�$N�����ڵأ�\n"NOR,target);
                     //   tell_object(target, "�����һ�����Ϯ����ֱ�ӽ���嵹�ڵأ�\n");
             call_out("no_dodge_end", me->query_skill("dragonforce",1)/20+random(3), target);
							}
				}
				else tell_object(me,HIW "\n��������������\n"NOR);
	}
	else 
		tell_object(me,HIW "\n��⣡����������\n"NOR);

		COMBAT_D->report_sen_status(target);		
        if( living(target) ) target->kill_ob(me);

        

        return 1;
}


void remove_effect(object me) {
  if (!me) return;
  me->delete_temp("fjdh_busy");
}

void remove_no_move(object me) {
  if (me) me->delete_temp("no_move");
}
void no_dodge_end(object target)
{
	if (!target) return;
	target->delete_temp("no_dodge");
	message_vision(HIY"\n$N���������������������\n"NOR,target);
	return;
}
