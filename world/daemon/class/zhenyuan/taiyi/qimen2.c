// cracked by vikee 2/09/2002   vikee@263.net

#include <ansi.h>

inherit SSERVER;
static string old_long, old_short;
static object env;


int do_quit();
int do_finish();

int cast(object me, object target)
{
  string msg,dest,dir;  
  string sname;
  object bagua=present("bagua fu",me);
  env=environment(me);
  
  
  if (me->query_skill("taiyi",1)<60)
     return notify_fail("���̫���ɷ����������졣\n");
  if (!bagua) 
    return notify_fail("������û�а��Է�������ʩչ���Ŷݼס�\n");
  dir=bagua->query("dir");
  if (!dir) return notify_fail("��������ڰ��Է���ָ��<direct>ʩ���ķ���\n");

  dest = environment(me)->query("exits/"+dir);
  if(!dest) return notify_fail("�������û��·����\n");
  if (!env->valid_leave(me,dir))
     return notify_fail("�㲻�ܳ��������ʩչ���Ŷݼס�\n");
  if( (int)me->query("mana") < 400 )
          return notify_fail("��ķ��������ˣ�\n");

  if( (int)me->query("sen") < (int)me->query("max_sen")/2 )
      return notify_fail("������ͷ�Բ����ѣ�����ʹ�ó����Ŷݼף�\n");

  if( random(me->query("max_mana")) < 50 ) {
       write("��ʧ���ˣ�\n");
       return 1;
  }

  if (me->is_busy())
    return notify_fail("����һ��������û����ɡ�\n");
   if (me->query_temp("cast_qimen")   )
    return notify_fail("�����һ�����Ŷݼ������û��!\n");
    
  if(me->is_fighting())
    return notify_fail("����æ�Ŵ�ܣ�û�������Ŷݼס�\n");

   msg =  HIR "$Nߴ����������˼������ͻȻ����հ׹�һ��!\n" NOR;
   message_vision(msg, me);
        
   me->add("mana", -400);
     me->receive_damage("sen", 100);
  
   old_long = env->query("long");
   old_short = env->query("short");  
   
   env->set("long",   @LONG

��ͻȻ����������ת�������ǳ�ȫ����ʧ����Ҳ�ֲ��嶫���ϱ���
��ǰ�������һƬ�������������䣬����������˸������һʱ����
��ţ�һʱ������죬һ�ɾ�������������ֱ�����飬���ɼ�
�ػ���ֱ�����

LONG);
   env->set("short","���Ŷݼ���");   
   env->set("host",me);
   env->add_action("quit","do_quit");
   env->add_action("finish","do_finish");   
   
   me->set_temp("cast_qimen",1);   
   me->start_busy(random(3));
   return 1;
}

int do_quit()
{
     write("���ķ����ң���֪����β����˳���\n");
     return 1;	
}

int do_finish()
{
  object host=env->query("host");
  object me=this_player();
  if (host!=me) return 0;
 
  if (me->is_fighting()) {
    write("����æ�Ŵ�ܣ�û���й���\n");
    return 1;
  }
  if (me->is_busy()){
  	write("��æ�ĺܣ��Ķ��й�������\n");
  	return 1;
  }
  env->set("short",old_short);
  env->set("long",old_long);
  message_vision(HIB"$N��һ�ӣ����������Ŷݼ�����\n"NOR,me);
  
}
