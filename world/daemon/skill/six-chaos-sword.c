// cracked by vikee 2/09/2002   vikee@263.net
// six-chaos-sword.c
//not used, set to default first.

#include <ansi.h>

inherit SKILL;

mapping *action = ({
        ([      "name":                 "Ⱥħ����",
                "action":
"$Nʹһ�С�Ⱥħ���衹������$w�����������$n��$l��������",
                "dodge":                0,
                "damage":               20,
                "damage_type":  "����"
        ]),
        ([      "name":                 "�������",
                "action":               "$N����һת��һ�С��������$wն��$n��$l",
                "dodge":                0,
                "damage":               20,
                "damage_type":  "����"
        ]),
        ([      "name":                 "�ٹ�ҹ��",
                "action":
"$N�趯$w��һ�С��ٹ�ҹ�С�Ю�������������$n��$l",
                "dodge":                0,
                "damage":               20,
                "damage_type":  "����"
        ]),
        ([      "name":                 "������·",
                "action":
"$N����$wһ����ʹ����������·����$n��$l�̳�һ��",
                "dodge":                0,
                "damage":               20,
                "damage_type":  "����"
        ]),
        ([      "name":                 "��Ӱ����",
                "action":
"$N����$w���Ⱪ����һ�С���Ӱ��������$n$l��ȥ",
                "dodge":                0,
                "damage":               20,
                "damage_type":  "����"
        ]),
        ([      "name":                 "��ع�",
                "action":
"$N����$wֱָ$n$l��һ�С���ع����������˽�����ȥ",
                "dodge":                0,
                "damage":               20,
                "damage_type":  "����"
        ]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 100 )
                return notify_fail("�������������û�а취������׷�꽣��\n");

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
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 5 )
                return notify_fail("�����������������û�а취��ϰ����׷�꽣��\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        write("�㰴����ѧ����һ������׷�꽣����\n");
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
                me->add("bellicosity", 300);
        } else
                me->add("bellicosity", 50);
}

