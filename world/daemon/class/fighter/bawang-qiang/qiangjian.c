// add by hexiu
// ǹ����

#include <ansi.h>
#include <weapon.h>

inherit SSERVER;

int perform(object me, object target)
{
	int skill, skill1, skill2;
	object weapon1, weapon2,sweapon,ob;

	if(!target) target = offensive_target(me);

	if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ��һ�С�ǹ���ﵡ���\n");

	if(!me->is_fighting())
                return notify_fail("��ǹ���ﵡ�ֻ����ս����ʹ�ã�\n");

	if((int)me->query("max_force") < 500)
		return notify_fail("�������������\n");

        if((int)me->query("force") < 500 )
                return notify_fail("����������㣡\n");

	if((int)me->query("sen") < 250)
		return notify_fail("��ľ����㣬û����ʩ���⹦��\n");

	if((int)me->query_skill("bawang-qiang",1) < 100)
		return notify_fail("��İ���ǹ���𻹲�����ʹ����һ�л�������!\n");

	if((int)me->query_skill("wusi-mace",1) < 100)
		return notify_fail("�����˽ﵼ��𻹲�����ʹ����һ�л�������!\n");
     
	if(me->query_temp("QJ_perform"))
        return notify_fail("���в�����̫��!\n");

    ob=target->query_temp("weapon");
	weapon1=me->query_temp("weapon");
    if(me->query_temp("secondary_weapon")) sweapon=me->query_temp("secondary_weapon");
	weapon2=present("mace", me);
	
	if(!objectp(weapon2)) 
		return notify_fail("û���ôǹ����?\n");

	message_vision(HIC"\n$N���㾫�񣬶��ִ̳�һǹ!\n"NOR, me, target);
	
    me->set_temp("BWQ_perform", 7);
	COMBAT_D->do_attack(me, target, weapon1);
    me->delete_temp("BWQ_perform");
	
    if((int)me->query_skill("bawang-qiang",1) > 200 && me->query("family/family_name") == "������" )
	{  
		if(target->query_temp("no_parry")==0 && ob !=0)
		{message_vision(HIC"\n$Nһ���֣�˦ǹ������$n���е�"+ob->query("name")+"!\n"NOR, me, target);
	target->set_temp("no_parry",1);
	call_out("remove_no_parry",me->query_skill("bawang-qiang",1)/20+random(3),target);}
		else {write("�Է����²����мܣ�\n");}
	
	}

        message_vision(HIC"\n����$n��æ���ң�$N���"+weapon2->query("name")+HIC"��������"NOR, me, target);

	weapon1->unequip();
	if(sweapon) sweapon->unequip();
	weapon2->wield();

	me->set_temp("WSJ_perform", 4);
	COMBAT_D->do_attack(me, target, weapon2);

	me->set_temp("WSJ_perform", 5);
	COMBAT_D->do_attack(me, target, weapon2);

	if((int)me->query_skill("wusi-mace",1) > 200)
	{me->set_temp("WSJ_perform", 7);
	COMBAT_D->do_attack(me, target, weapon2);}

	me->delete_temp("WSJ_perform");

	me->receive_damage("sen", 100);
	me->add("force", -100);

	if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

	weapon2->unequip();
	weapon1->wield();
	//if(sweapon) sweapon->wield();

       me->set_temp("QJ_perform",1);
        me->set_temp("no_move",1);
		call_out("remove_no_move",3,me);
        call_out("remove_effect",3+random(3),me);

        return 1;
}

void remove_effect(object me) {
  if (!me) return;
  me->delete_temp("QJ_perform");
}

void remove_no_move(object me) {
  if (me) me->delete_temp("no_move");
}

void remove_no_parry(object target)
{
	if (!target) return;
	target->delete_temp("no_parry");
	message_vision(HIY"\n$N���һ�·��������\n"NOR,target);
	return;
}
