#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
	//string msg,start;
	//int ap, dp, success;
	//target = offensive_target(me);
	//always use the one who is fighting me as target.
	int t;
    t=me->query("no_dead_time");

	if( me->is_busy())
		return notify_fail("����æ���أ���Ӧ����ǰ���°ɡ�\n");

	if( (int)me->query("mana") < 300 )
		return notify_fail("��ķ��������ˣ�\n");

	if( (int)me->query("sen") < (int)me->query("max_sen")/5 )
		return notify_fail("�㾫��̫����Լ��о������䡣\n");

	if( (int)me->query_skill("dao", 1) < 200)
		return notify_fail("��δ��ѧ������\n");

    if(me->query_temp("no_dead"))
           return notify_fail("������������\n");

	if(t<time()&&time()<t+1800)
		return notify_fail("���������ʱ����δ����\n");

	

     
	message_vision(HIC"$N�૵����˼�������,���˼�������\n"NOR,me);
	me->add("mana", -300);
	
	if(time()>t+1800)
	{
	me->set("no_dead_time",time());
	me->set_temp("no_dead",1);
	message_vision(HIC"$N��������������ˣ�\n"NOR,me);
	call_out("remove_no_dead",1800,me);
	}
	return 5;
	
}



void remove_no_dead(object me) 
{ if (!me) return;
  if (!me->query_temp("no_dead")) return;
  if (me) me->delete_temp("no_dead");
message_vision(HIC"$N�о�������������ɢ�ˣ�\n"NOR,me);
return;

}