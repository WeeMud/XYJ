// cracked by vikee 2/09/2002   vikee@263.net
// heal.c

#include <ansi.h>

int exert(object me, object target)
{
        if( me->is_fighting() )
                return notify_fail("ս�������ˣ�������\n");

        if( (int)me->query("force") < 50 )
                return notify_fail("�������������\n");

        if( (int)me->query("eff_kee") < (int)me->query("max_kee") / 2 )

                return notify_fail("���Ѿ����˹��أ�ֻ��һ��������������Σ�գ�\n");
	message_vision("$N���ȶ�����ȫ������һ����棬�˿�Ҳ���������ˡ�\n", me);

        me->receive_curing("kee", 20 + (int)me->query_skill("force")/5 );
        me->add("force", -40);

        return 1;
}

