// cracked by vikee 2/09/2002   vikee@263.net

//���⽣Ӱ

#include <ansi.h>
#include <combat.h>

inherit SSERVER;

int perform(object me, object target)
{
      object weapon=me->query_temp("weapon");
      int enhance,damage;

      if (!weapon) return 0;
      if( !target ) target = offensive_target(me);
      if( !target || !target->is_character()||target->is_corpse()||target==me)
          return notify_fail("��Ҫ����˭��\n");
      if (!target->is_fighting(me))
             return notify_fail("����û���ڴ�ܣ�\n");
      if (target->is_busy())
            return notify_fail("�Է������æ�����ˣ��ŵ������ɣ�\n");
      if (me->query_skill("huntian-qigong",1)<50)
          return notify_fail("����ڹ�̫��������Խ���������\n");
      if (me->query_skill("kugu-blade",1)<60) 
          return notify_fail("�㻹���ȰѾ��������ڿݹǵ����ϰɡ�\n");
    if (me->query_skill("qixiu-jian",1)<60)
        return notify_fail("������޽�����ô�ã�������˼���ڵ��������ۣ�\n");
      if (me->query("force")<100)
           return notify_fail("���������̣����Գ��С�\n");
     
    me->add("force", -100);
  seteuid(getuid());
    me->set("actions", (: call_other, SKILL_D("qixiu-jian"), "query_action" :) );
   
    message_vision(HIB"$NͻȻ�佫����"+weapon->name()+
       HIB"�������ã�ʹ�����޽�������ʱ����$n�����ֲ�����\n"NOR,me,target);
    weapon->set_temp("original/use_apply_skill",weapon->query("use_apply_skill"));
    weapon->set_temp("original/skill_type",weapon->query("apply/skill_type"));
    weapon->set("use_apply_skill",1);
    weapon->set("apply/skill_type","sword");
   enhance=me->query_skill("qixiu-jian",1);
    me->add_temp("apply/attack", enhance);  
  damage=me->query_skill("kugu-blade",1);
    damage=(damage+random(damage))/10;
    me->add_temp("apply/damage",damage);        
    COMBAT_D->do_attack(me, target, weapon);
    weapon->set("use_apply_skill",weapon->query_temp("original/use_apply_skill"));
    weapon->set("apply/skill_type",weapon->query_temp("original/skill_type"));
    me->add_temp("apply/attack",-enhance);
    me->add_temp("apply/damage",-damage);
    me->reset_action();
    me->start_busy(random(2)+1);
    return 1;
}

