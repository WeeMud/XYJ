//by hexiu
// ��ɳ��Ӱ


// Ϭţ���£��������ǣ��ٲ������������
// �������գ����ĸ����������ʯ

#include <ansi.h>
inherit SKILL;
//void throw_weapon(object,object,object,int);

mapping *action = ({
  ([
    "action":
"$N��Ȼ������Х����Ծ�ڿա�\n"
"ֻ��һ����Х��$w�ѵ�$n��磬�ۿ���Ҫ�Դ�������\n"
"���С������ʯ����Ȼ�д�ʯ֮��",
    "damage":      25,
    "dodge":      -20,
    "parry":	   10,
    "damage_type": "����",
   // "post_action": (: throw_weapon :),
    "name":	   "�����ʯ",
    ]),
  ([
    "action":
"$N�ֲر��󣬸���һ�С����ĸ�������$w�Ѵ���Х����$nǰ�ط�ȥ",
    "damage":	35,
    "dodge":	20,
    "parry":	20,
    "damage_type":	"����",
    //"post_action":	(: throw_weapon :),
    "name":		"���ĸ���",
    ]),
  ([
    "action":
"ͻȻ�䣬$N�����������ȥ������$n����֮�⡣\n"
"$n����׷����$N��Ȼת������һ�����ٲ������\n"
"$w�Ѵ����ƿ�֮����ֱ��$n����",
    "damage":	20,
    "dodge":       -10,
    "parry":       -10,
    "damage_type":	"����",
    //"post_action":	(: throw_weapon :),
    "name":		"�ٲ�����",
    ]),
  ([
    "action":
"$N��׼$n��������һ�С�\n"
"$n�������ܣ�ͻȻ���ֲ��ް��������������޴���ȥʱ��\n"
"$Nһ˦�֣�ֻ��һ֧$w��$n��$l���ɶ���",
    "damage":	25,
    "dodge":       -20,
    "parry":	10,
    "damage_type":	"����",
    //"post_action":	(: throw_weapon :),
    "name":		"��������",
    ]),
  ([
    "action":
"$N��ָ΢����$nֻ������ಡ���һ����$w�ѵ�$lǰ���硣\n"
"$nû�ŵ����С��������ա��������֮�죬���������޴�",
    "damage":	35,
    "dodge":	10,
    "parry":       -10,
    "damage_type":	"����",
    //"post_action":	(: throw_weapon :),
    "name":		"��������",
    ]),
  ([
    "action":
"$N����վ�ȣ�����͸��������$w��һ�����$n��$l",
    "damage":	40,
    "dodge":	20,
    "parry":	20,
    "damage_type":	"����",
    //"post_action":	(: throw_weapon :),
    "name":		"���Ǹ���",
    ]),
  ([
    "action":
"$n���������������һ����$N������Ҫ���ܣ�ͻȻŤ��������\n"
"һ�С�Ϭţ���¡�������$w��ͬ����һ�㣬ֱ����$n��$l",
    "damage":	    30,
    "dodge":       -10,
    "parry":       -10,
    "damage_type":  "����",
    //"post_action":  (: throw_weapon :),
    "name":	    "Ϭţ����",
    ]),
});
 
int valid_learn(object me)
{
  object ob;
  
  if(me->query_skill("throwing",1) < 20)
    return notify_fail("��İ������ܲ�����죡\n");
  if( (int)me->query("max_force") < 50 )
    return notify_fail("�������������\n");
  if( !(ob=me->query_temp("weapon")) || (string)ob->query("skill_type") != "throwing" )
    return notify_fail("�����ް�����������ʦ�����̣�\n");
  return 1;
}

/*
mapping query_action(object me)
{
  int max=me->query_skill("archery") / 15;
  
  if (max>sizeof(action)) max=sizeof(action);
  return action[random(max)];
  //return action[random(sizeof(action))];
}
*/

mapping query_action(object me, object weapon)
{
	int i;
	i=me->query_temp("HSSY_perform");
	if( !me->query_temp("HSSY_perform")) {
		return action[random(7)];
	}else {
		return action[i];
	}
//        return action[random(sizeof(action))];
}

/*
string learning_message(int level)
{
  if (level / 15 >= sizeof(action) ) return "";
  else return "�ԡ�" + action[level/15]["name"] + "��������������";
}
*/

int valid_enable(string usage)
{
  return (usage=="throwing");
}

int practice_skill(object me)
{
  object weapon;

  if( !objectp(weapon = me->query_temp("weapon"))
     ||      (string)weapon->query("skill_type") != "throwing" )
    return notify_fail("û�а��������ϰ��\n");

  if( (int)me->query("kee") < 40 || (int)me->query("force") < 10)
    return notify_fail("����������㣡\n");
  me->receive_damage("kee", 30);
  me->add("force", -5);
  message_vision("$NĬĬ������һ�����Ȼ������һ�麬ɳ��Ӱ��");
 // (: throw_weapon :);
  return 1;
}

/*
void throw_weapon(object me, object victim, object weapon, int damage)
{
  if( objectp(weapon) ) {
    if( (int)weapon->query_amount()==1 ) {
      weapon->unequip();
      tell_object(me, "\n���" + weapon->query("name") + "�����ˣ�\n");
    }
	if(weapon->query("never_tear") != 1) 
    weapon->add_amount(-1);
  }
}
*/

string perform_action_file(string func)
{
	return CLASS_D("yaomo") + "/wudidong/hanshasheying/"+func;
}