// cracked by vikee 2/09/2002   vikee@263.net
//���һ�ޡ�hellfire-whip.c

/*
�һ��    dodge  -10    parry  -10    damage  20
�һ���Ʋ��ƹ��У�һ���������乥����Χ�������⣬
�Ҵ˱�����ת�գ���ȥ���٣�Ҫ�мֵܵ�Ҳ��Ϊ���ס�
�ص���ɱ�˲���

Attention: �һ��ֻ��ǰ���У������ߣ��������ǿ�ɥ��
�;������У����� Perform �ģ������ƽ���������õ���
*/


inherit SKILL;

mapping *action = ({
        ([      "name":                 "�����һ�",
                "action":
"$N����һ����$w���ñ�ֱ������һ����Х�ʹ�$n$l",
                "dodge":                0,
                "parry":                -5,
                "damage":               15,
                "damage_type":  "����"
        ]),
        ([      "name":                 "�����һ�",
                "action":               
"$N���һ��������$w�����������ڰ�գ����С���ճ����������š�\n$nֻ����ȫ�����$w����֮��",
                "dodge":                -20,
                "parry":                -20,
                "damage":               30,
                "damage_type":  "����"
        ]),
        ([      "name":                 "�����һ�",
                "action":
"$N����һ����$w���ض��ɣ��ټ�����ϣ��·�����˵����е��һ𣬼�ͷ���Ե�����$n",
                "dodge":                -5,
                "parry":                -15,
                "damage":               25,
                "damage_type":  "����"
        ]),
        ([      "name":                 "�����һ�",
                "action":
"Ҳ��֪$N��ζ���һ�����������������һ����$nֻ��$w�ѻ�����$l",
                "dodge":                -15,
                "parry":                -5,
                "damage":               15,
                "damage_type":  "����"
        ]),
        ([      "name":                 "�����һ�",
                "action":
"$N������ǰ����������$w��ž������һȦ��һȦ�ؾ���$n",
                "dodge":                -5,
                "parry":                0,
                "damage":               15,
                "damage_type":  "����"
        ]),
        ([      "name":                 "�����һ�",
                "action":
"��Ц����$Nһ������������$w���ʣ�������Բ�����ɳ��ʯ�������ݺᣡ\n$n��֪��β���������������������",
                "dodge":                -15,
                "parry":                -20,
                "damage":               25,
                "damage_type":  "����"
        ]),
        ([      "name":                 "С¥ҹ��",
                "action":
"$N�����﷢���������У��߾�$w������һ�еس���$n��������$n����������\n����$wȴ������Ϣ�ش���$n��$l���������ġ�С¥ҹ�ޡ�",
                "dodge":                -15,
                "parry":                -15,
                "damage":               30,
                "damage_type":  "����"
        ]),
        ([      "name":			"������·",
		"action":		"$N����$wһ�����ó��������⣬����һ��㱼䣬$w��бб�ص�����$n��$l",
                "dodge":                -10,
                "parry":                -10,
                "damage":                30,
                "damage_type":  "����"
        ]),

});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 150 )
                return notify_fail("�������������û�а취���һ�ޡ�\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "whip" )
                return notify_fail("���������һ�����Ӳ������һ�ޡ�\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="whip" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
	int i;
	i=me->query("HellZhen");
	if( !me->query("HellZhen") ) {
        return action[random(6)];
	}else {
	return action[i];
	}
}
		

int practice_skill(object me)
{
        if( (int)me->query("kee") < 25
        ||      (int)me->query("force") < 5 )
                return notify_fail("�����������������û�а취��ϰ�һ�ޡ�\n");
        me->receive_damage("kee", 25);
        me->add("force", -5);
        write("�㰴����ѧ����һ���һ�ޡ�\n");
        return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}


string perform_action_file(string func)
{
return CLASS_D("ghost") + "/hellfire-whip/" + func;
}

