// cracked by vikee 2/09/2002   vikee@263.net

#include <ansi.h>

inherit SKILL;

mapping *action = ({
        ([      "name":                 "Ⱥħ����",
                "action":
"$N����$wһ�����γ�������Ӱ�������������$n��$l��������",
		"parry":		0,
                "dodge":                -10,
                "damage":               25,
                "damage_type":  "����"
        ]),
        ([      "name":                 "�������",
                "action":               "$N����һת������һ��������$w��һ�����߰����$n��$l",
		"parry":		-10,
                "dodge":                -10,
                "damage":               25,
                "damage_type":  "����"
        ]),
        ([      "name":                 "�ٹ�ҹ��",
                "action":
"$N�趯$w��ͻȻһ�����壬$wЮ�������������$n��$l",
		"parry":		0,
                "dodge":                -15,
                "damage":               20,
                "damage_type":  "����"
        ]),
        ([      "name":                 "������·",
                "action":
"$N����$wһ�����ó��������⣬����һ��㱼䣬$w��бб�ص�����$n��$l",
		"parry":		-20,
                "dodge":                -20,
                "damage":               35,
                "damage_type":  "����"
        ]),
        ([      "name":                 "��Ӱ����",
                "action":
"$N����$w���Ⱪ�����ּ��ֿ����$n$l��ȥ",
		"parry":		-10,
                "dodge":                -20,
                "damage":               25,
                "damage_type":  "����"
        ]),
        ([      "name":                 "��ع�",
                "action":
"$N��Ȼ������һչ������$wͻ�����߽�â��৵ش�����$n��$l",
		"parry":		-10,
                "dodge":                -10,
                "damage":               30,
                "damage_type":  "����"
        ]),
        ([      "name":                 "�����һ�",
                "action":               
"$N���һ��������$w�����������ڰ�գ����С���ճ����������š�\n$nֻ����ȫ�����$w����֮��",
                "dodge":                -15,
                "parry":                -15,
                "damage":               30,
                "damage_type":  "����"
        ]),
        ([      "name":                 "С¥ҹ��",
                "action":
"$N�����﷢���������У��߾�$w������һ�еس���$n��������$n����������\n����$wȴ������Ϣ�ش���$n��$l���������ġ�С¥ҹ�ޡ�",
                "dodge":                -10,
                "parry":                -10,
                "damage":               30,
                "damage_type":  "����"
        ]),


});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 100 )
                return notify_fail("�������������û�а취��׷�꽣��\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return notify_fail("���������һ�ѽ�������������\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="sword" || usage=="parry";
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
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 5 )
                return notify_fail("�����������������û�а취��ϰ׷�꽣��\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        write("�㰴����ѧ����һ��׷�꽣����\n");
        return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

void skill_improved(object me)
{
        if( (int)me->query_skill("six-chaos-sword", 1)  % 10 == 0 ) {
                tell_object(me,
                        RED "\n��ͻȻ����һ�ɶ���������ͷ��ֻ������ɱ��....\n\n" NOR);
                me->add("bellicosity", 100);
        } else
                me->add("bellicosity", 10);
}

string perform_action_file(string func)
{
return CLASS_D("ghost") + "/zhuihun-sword/" + func;
}


