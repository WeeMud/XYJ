// cracked by vikee 2/09/2002   vikee@263.net
// ������

inherit SKILL;

int valid_enable(string usage) { return usage=="spells"; }

int valid_learn(object me)
{
        if( (int)me->query_skill("spells", 1) < 10
        ||      (int)me->query_skill("spells", 1) <=
(int)me->query_skill("gouhunshu", 1) )
                return
notify_fail("��ķ�����Ϊ����������޷�ѧϰ��������\n");
        return 1;
}

string cast_spell_file(string spell)
{
        return CLASS_D("ghost") + "/gouhunshu/" + spell;
}
string type() { return "magic"; }