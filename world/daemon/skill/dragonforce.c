// cracked by vikee 2/09/2002   vikee@263.net
inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me) { return 1; }

string exert_function_file(string func)
{
        return CLASS_D("dragon") + "/dragonforce/" + func;
}

int practice_skill(object me)
{
        if( (string)me->query("family/family_name")!="��������")
                return notify_fail("������壬�����к����档\n");

        if( !environment(me)->query("dragonforce_practice") )
                return notify_fail("�����ķ�ֻ��������ķ�̨�ϲſ�����\n");
/*
	if( (int)me->query_skill("dragonforce",1) >= 200 )
		return notify_fail("��������ķ���������ˣ���������ʦ�������̰ɣ�\n");
*/
	if( (int)me->query_temp("dragonforce_practice") < 1 )
		return notify_fail("�������������ɺ��޽�չ����Ҫѱ������ĺ��������������ķ���\n");

        if( (int)me->query("kee") < 60 )
                return notify_fail("�����������\n");
	if( (int)me->query("kee") < 60 )
                return notify_fail("����񲻹���\n");
        if( (int)me->query("force") < 30 )
                return notify_fail("�����������");

if( (int)me->query_skill("dragonforce", 1) >= 200 ) {
        me->receive_damage("kee", 60);
        me->receive_damage("sen", 60);
        me->add("force", -30);
        me->add_temp("dragonforce_practice",-1);
} else {
      	me->receive_damage("kee", 30);
	me->receive_damage("sen", 30);
        me->add("force", -10);
	me->add_temp("dragonforce_practice",-1);
}
	return 1;
}

