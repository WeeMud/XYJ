// cracked by vikee 2/09/2002   vikee@263.net
// steal.c

#include <ansi.h>
#include "valid_kill.h";

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string what, who;
	object ob, victim;
	int sp, dp;

	if( !wizardp(me) && environment(me)->query("no_fight") )
		return notify_fail("�����ֹ���ԡ�\n");

	if( me->query_temp("stealing") )
		return notify_fail("���Ѿ����һ��������ˣ�\n");

	if( !arg || sscanf(arg, "%s from %s", what, who)!=2 ) return
		notify_fail("ָ���ʽ��steal <��Ʒ> from <����>\n");

	victim = present(who, environment(me));
	if( !victim || victim==me) return notify_fail("�������ԵĶ��������\n");
        if(!valid_kill(me,victim,0)) return 0;

	if( !wizardp(me) && wizardp(victim) )
		return notify_fail("��Ҳ���͵��ʦ���ϵĶ�����\n");

	if( !ob = present(what, victim) ) {
		object *inv;
		inv = all_inventory(victim);
		if( !sizeof(inv) )
			return notify_fail( victim->name() + "���Ͽ�����û��ʲôֵǮ�Ķ�����͵��\n");
		ob = inv[random(sizeof(inv))];
	}
	sp = (int)me->query_skill("stealing",1) * 5 +((int)me->query("kar")+(int)me->query("age"))*2
		- (int)me->query("thief") * 20;
	if( sp < 1 ) sp = 1;
	if( me->is_fighting() ) {
		sp /= 2;
		me->start_busy(3);
	}
	dp = ((int)victim->query("sen")+(int)victim->query("age")+(int)victim->query_kar())*2+(int)ob->weight()/25;
	if( victim->is_fighting() ) dp *= 10;
	if( ob->query("equipped") ) dp *= 10;

	write("�㲻����ɫ����������" + victim->name() + "���ȴ��������� ...\n\n");

	me->set_temp("stealing", 1);
	call_out( "complete_steal", 3, me, victim, ob, sp, dp);

	return 1;
}

private void complete_steal(object me, object victim, object ob, int sp, int dp)
{
    int no_steal;

        if(!me || !victim) return;
	me->delete_temp("stealing");

	if( environment(victim) != environment(me) ) {
		tell_object(me, "̫��ϧ�ˣ������ֵ�Ŀ���Ѿ����ˡ�\n");
		return;
	}

        if(!ob) {
	  tell_object(me, "��Ҫ͵�Ķ��������ˡ�\n");
	  return;
        }   // mon 8/31/97

	no_steal=(ob->query("no_give")) ||
	         (ob->query("no_drop")) ||
		 (ob->query("no_get")); // can't steal these stuffs.
	// mon 9/8/98

	if( (!living(victim) || (random(sp+dp) > dp)) &&
	 !no_steal ) {
		if( !ob->move(me) ) {
			tell_object(me, "������һ" + ob->query("unit") + ob->name() 
				+ "�����Ƕ������̫���ˣ����ò�������\n");
			return;
		}
		tell_object(me, HIW "�����ˣ�\n\n" NOR);
		tell_object(me, "��ɹ���͵��һ" + ob->query("unit") + ob->name() + "��\n");
		if( living(victim) )
			me->improve_skill("stealing", random(me->query("int")));
		if( random(sp) < dp/2 )
			message("vision", "�㿴��" + me->name() + "�������ش�"
				+ victim->name() + "����͵����һ" + ob->query("unit")
				+ ob->name() + "��\n", environment(me), ({ me, victim }) );
	} else {
		if( random(sp) > dp/2 || no_steal ) {
			tell_object(me, victim->name() + "�������һתͷ���㼱æ�������˻�ȥ��\n"
				"���ã�û�б����֡�\n");
			return;
		}
		tell_object(me, HIR "��⣡��ʧ���ˣ�\n\n" NOR);
		message_vision("$Nһ��ͷ�����÷���$n������ץ��$P���ϵ�" + ob->name() + "��\n\n"
			+ "$N�ȵ�������ʲô����\n\n", victim, me);
		me->improve_skill("stealing", 1, 1);
		if( userp(victim) ) victim->fight_ob(me);
		else victim->kill_ob(me);
		me->fight_ob(victim);
		me->start_busy(5);
		me->add("thief", 1);
	}
}

int help(object me)
{
write(@HELP
ָ���ʽ : steal <ĳ��> from <ĳ��>

���ָ�������л���͵���������ϵĶ������ɹ���, ��Ȼ����ܻ��
������Ʒ������, ����ʧ��, ������ʧ���ʱ��, ����ʧ��ʱ��Ȼ��
�ø�������, ������ʲô����......�����Լ�ȥ�����ޡ�
HELP
    );
    return 1;
}
