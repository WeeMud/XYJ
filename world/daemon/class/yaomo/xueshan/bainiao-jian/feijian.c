// cracked by vikee 2/09/2002   vikee@263.net

#include <ansi.h>
#include <combat.h>

inherit SSERVER;

void feijian_ok(object);
void postfeijian(object,object,object,int);

int perform(object me, object target)
{
    mapping feijian= ([
       "damage": 80,
       "dodge" : -10,
       "parry" : -10,
       "damage_type" : "����",
//       "action" :  HIW"$NͻȻ��Хһ��������$w"+HIW"���ֶ���������һ�����磬ֱ��$n��$l��ȥ��"NOR,
       "action" :  HIW"$w"+HIW"�ڿ��лó��������⣬����Ͷ�ְ㣬��$n��$l��ȥ",
       "post_action" : (: postfeijian :)
    ]);

      object weapon=me->query_temp("weapon");
      if( !target ) target = offensive_target(me);
      if( !target || !target->is_character()||target->is_corpse()||target==me)
          return notify_fail("��Ҫ����˭��\n");
      if (!target->is_fighting(me))
             return notify_fail("����û���ڴ�ܣ�\n");
      if (me->query_temp("no_feijian") )
          return notify_fail("������״̬���ѣ�����ʹ�÷ɽ���\n");      
      if (me->query_skill("ningxie-force",1)<50)
          return notify_fail("����ڹ�̫����ɳ�ȥ�϶��ɲ�������\n");
      if (me->query_skill("bainiao-jian",1)<50) 
          return notify_fail("��İ��񽣷���ô�ã����İѽ����Լ����ϡ�\n");
    if (me->query_skill("throwing",1)<50)
        return notify_fail("��İ�������̫����Ұѽ��ӳ�ȥ���϶��Ҳ���Ŀ�ꡣ\n");
      if (me->query("force")<100)
           return notify_fail("���������̣����Լ����ɽ���\n");
     
      me->add("force", -100);
      me->set("actions",feijian);
    message_vision(HIW"$NͻȻ��Хһ��������"+weapon->query("name")+HIW"���ֶ���������һ�����磬ֱ��$n��ȥ��"NOR,me,target);
      COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
      me->set_temp("no_feijian",1);
      call_out("feijian_ok",2+random(2),me);
      me->reset_action();
      return 1;
}

void feijian_ok(object me) {
      if (!me) return;
      me->delete_temp("no_feijian");
}         

void postfeijian(object me,object victim,object weapon, int damage) {
      if (damage>0 || damage==RESULT_DODGE)
         message_vision(HIW""+weapon->query("name")+HIW"�ڿ��д��˸�ת���ַɻص�$N���С�\n"NOR,me);
      else {
           message_vision(HIW""+weapon->query("name")+HIW"�ı䷽�򣬡�ৡ���һ����бб���ڵ��ϡ�\n"NOR,me);
           weapon->move(environment(me));
      }
}
