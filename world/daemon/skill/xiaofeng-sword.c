// cracked by vikee 2/09/2002   vikee@263.net
// ������½���qingyu-sword.c
// created 5-13-97 pickle

/*
������½�    dodge  -10    parry  0    damage  20
�˽������������������������ĺ�ʫ�⣬��Ϊ����
������ϲ��
*/

// ��µ��գ�ˮ��й�أ������°�����������
// �ɻ����Σ�˿��������ҹ�꣬�°׷���
// �𲨵�ת

inherit SKILL;

mapping *action = ({
	([	"name":			"��µ���",
		"action":
"$N��ƮƮ������Ծ������$w����һ����ɫ�⻷����$n��$lȦȥ",
		"dodge":		-15,
		"parry":		10,
		"damage":		20,
		"damage_type":		"����"
	]),
	([	"name":			"ˮ��й��",
		"action":
"$N˫��һ�٣���ֱԾ������$w��ͣ�ز����ţ�\n"
"����ס$nȫ�����ơ�ˮ��й�ء���Ȼ����ʤ��",
		"dodge":		-5,
		"parry":		-10,
		"damage":		15,
		"damage_type":		"����"
	]),
	([	"name":			"�����°�",
		"action":
"$N����$w���������⣬ָ��$nǰ��Ѩ����$n��ר����־�ضԸ��Ž��У�\n"
"����$N������������$n��$l�����ơ������°���������ã�ʵ���ѷ�",
		"dodge":		-5,
		"parry":		-5,
		"damage":		25,
		"damage_type":		"����"
	]),
	([	"name":			"��������",
		"action":
"$N��$n�������ߣ�����$wȥ��Ʈ��������ֻ����$n�ۻ����ҡ�\n"
"�ô�������$N������������һ��$w����$n��$l����",
		"dodge":		-15,
		"parry":		5,
		"damage":		25,
		"damage_type":		"����"
	]),
	([	"name":			"�ɻ�����",
		"action":
"��ս�У�$N��$n��ǰббԾ��������$w��������һ�������$n��$l",
		"dodge":		-5,
		"parry":		0,
		"damage":		15,
		"damage_type":		"����"
	]),
	([	"name":			"˿�����",
		"action":
"$Nչ�����Σ����潣�ߣ��������಻���ز���$n��$l��\n"
"ʫ�ƣ��ޱ�˿��ϸ��$N�����н���Ȼ���ʫ����ζ",
		"dodge":		-20,
		"parry":		10,
		"damage":		20,
		"damage_type":		"����"
	]),
	([	"name":			"����ҹ��",
		"action":
"$N��������$w�����������׹⣬��ס$n���ظ���ֻ��$n��������\n"
"���С�����ҹ�꡹��Ȼ��ϸ�����ܣ�$nʵ�ڲ�֪������Ҫָ���Լ����Ϻδ�",
		"dodge":		-5,
		"parry":		-10,
		"damage":		20,
		"damage_type":		"����"
	]),
	([	"name":			"�°׷���",
		"action":
"$N����$w�й�ֱ�������ٴ���$n��ǰ�ġ�\n"
"���С��°׷��塹���˶�Ŀһ�¡�$nֻ���׹�һ���������ѵ��Ŀ�",
		"dodge":		-15,
		"parry":		15,
		"damage":		15,
		"damage_type":		"����"
	]),
	([	"name":			"�𲨵�ת",
		"action":
"$N����$w��$n�����ּ��̣�������$nҪ�м�ʱ��\n"
"$N����ת��$n�����㣡���С��𲨵�ת��ȷʵ���Ī��",
		"dodge":		-5,
		"parry":		-15,
		"damage":		25,
		"damage_type":		"����"
	]),
});
int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_force") < 100 )
		return notify_fail("���������Ϊ���������ѧ������½���\n");
	if (!(ob = me->query_temp("weapon"))
	   || (string)ob->query("skill_type") != "sword" )
		return notify_fail("���������һ������������ϰ������\n");
//	if (me->query("family/family_name") != "������")
//		return notify_fail("��������뽫�������²ſ�ѧ������½���\n");
	return 1;
}

int practice_skill(object me)
{
	int dod=(int)me->query_skill("yanxing-steps");
	int swo=(int)me->query_skill("xiaofeng-sword");

//	if (me->query("family/family_name") != "������")
//		return notify_fail("��������뽫������\n");
//	if ((string)me->query("gender") == "����")
//		if (dod<swo)
//			return
notify_fail("����������Ͻ���������ȥ�ܿ��ܻ��˵��Լ���\n");
	if ((int)me->query("kee") < 30)
		return notify_fail("������Ƿ�ѣ�ǿ��������·罣�к����档\n");
	if ((int)me->query("force") < 5)
		return notify_fail("���������㣬ǿ��������·罣���߻���ħ��Σ�ա�\n");
	me->receive_damage("kee", 30);
	me->add("force", -5);
	message_vision("$NĬĬ������һ�����Ȼ������һ��������½���\n", me);
	return 1;
}

int valid_enable(string usage)
{
	return usage=="sword"||usage=="parry";
}
string perform_action_file(string func) {
  return CLASS_D("zhenyuan") + "/xiaofeng-sword/" + func;
}
mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}
