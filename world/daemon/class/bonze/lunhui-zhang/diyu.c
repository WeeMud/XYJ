// cracked by vikee 2/09/2002   vikee@263.net

//�������

#include <ansi.h>
#include <combat.h>

inherit SSERVER;
void postdiyu(object,object,object,int);
void remove_effect(object);

int perform(object me, object target)
{
      int enhance,damage;
      object weapon=me->query_temp("weapon");
      mapping action;

      if( !target ) target = offensive_target(me);
      if( !target || !target->is_character()||target->is_corpse()||target==me)
          return notify_fail("��Ҫ����˭��\n");
      if (!target->is_fighting(me))
             return notify_fail("����û���ڴ�ܣ�\n");
      if (me->query_skill("force")<100)
          return notify_fail("����ڹ�̫�\n");
      if (me->query_skill("buddhism",1)<60)
         return notify_fail("��𷨲�������û��������Ĵȱ��ĳ���\n");
      if (damage=me->query_skill("staff")<100) 
          return notify_fail("����ȷ���Ƿ���\n");
      if (me->query("force")<500)
           return notify_fail("���������̣����Գ��С�\n");
     
    if (me->query_temp("pfm_diyu_delay")) return notify_fail("����ù����У������ȵ���һ�°ɡ�\n");
  me->add("force",-200);
    message_vision(HIY"$N���з�ţ���ȫ����ע������"+weapon->name()+
       HIY"��ʱ��ϼ�����䣬�յ�$n�������ۣ�\n"NOR,me,target);
    enhance=me->query_skill("lotusforce",1)/2;
    me->add_temp("apply/attack", enhance);  
    damage=me->query_skill("buddhism",1);
    if (damage>200) damage=200;
    action=copy(me->query("actions"));
    damage=action["damage"]*damage/20;
  if (wizardp(me)) write (damage+"\n");
    action["post_action"] = (: postdiyu :);
    me->add_temp("apply/damage",damage);
    me->set_temp("putuo_diyu",1);
    me->set("actions",action);
    COMBAT_D->do_attack(me, target, weapon);
    me->add_temp("apply/attack",-enhance);
    me->add_temp("apply/damage",-damage);
    me->reset_action();
    return 1;
}

void postdiyu(object me,object target,object weapon,int damage) {
   int howlong=damage/100+1;

   me->start_busy(1);
   if (!me->query_temp("putuo_diyu")) return;
   me->delete_temp("putuo_diyu");
   if (damage<100) return;
   message_vision(HIR"$N�������ȣ�ֻ���û������ѣ��������á�\n"NOR,me);
   damage=random(damage);
   if (me->query("kee")-damage<10) damage=me->query("kee")-10;
  if (damage<0) damage=0;
   me->receive_damage("kee",damage);
   COMBAT_D->report_status(me); 
  me->set_temp("pfm_diyu_delay",1);
  call_out("remove_effect",howlong,me);

  // write("hi\n");
}
void remove_effect(object me){
  me->delete_temp("pfm_diyu_delay");
}
