// cracked by vikee 2/09/2002   vikee@263.net
// exercise.c

#include <skill.h>

inherit F_CLEAN_UP;
int finishb(object me);

int main(object me, string arg)
{
	int kee_cost, busy_time,ex_max;
	object where = environment(me);
	string m;
	
	seteuid(getuid());
	ex_max=0;
	
	if(environment(me)->query("no_fight")  ||
	   environment(me)->query("no_magic") )
	      return notify_fail("��ȫ���ڽ�ֹ������\n");
	

        if( !arg)
           return notify_fail("��Ҫ��������������\n");

        if( !sscanf(arg, "%d", kee_cost) )
		{
        if(sscanf(arg,"%s",m) && m=="max")
			{	

            if( (int)me->query("max_force") < 500  )
				return notify_fail("��Ĺ��������������ã�\n");


			if((int)me->query("force") > (int)me->query("max_force") * 2-120)
			    return notify_fail("���������ӯ��\n");
			else    
					{ 
			          kee_cost=me->query("kee")-20;
			          ex_max=1;
					}
			//	tell_object(me,"ok\n");
			}
        else
           return notify_fail("��Ҫ��������������\n");
		}
          

        if( kee_cost <= 0 && me->query_temp("pending/exercising") ){
//                remove_call_out("exec_int");
                call_out("finish", 1, me);
                return 1;
        }
	      
        if (me->is_busy() || me->query_temp("pending/exercising"))
                return notify_fail("��������æ���ء�\n");

	if( me->is_fighting() )
		return notify_fail("ս���в������ڹ������߻���ħ��\n");

	if( !stringp(me->query_skill_mapped("force")) )
		return notify_fail("��������� enable ѡ����Ҫ�õ��ڹ��ķ���\n");

	if( kee_cost < 20 ) return notify_fail("������Ҫ�� 20 �㡸��������������\n");

	if( (int)me->query("kee") < kee_cost )
		return notify_fail("�����ڵ���̫���ˣ��޷�������Ϣ����ȫ��������\n");

	write("�������������ù���һ����Ϣ��ʼ������������\n");

	busy_time=kee_cost/20;
	me->start_busy(busy_time*2 + 1);
	me->set_temp("pending/exercising", 1);
	
	call_out("exec_int", 1, me, where, busy_time,ex_max);	
	return 1;
}


int exec_int(object me, object where, int busy_time,int ex_max)
{
	object wherenow;
	int force_gain,p_max;
	wherenow = environment(me);
	

	if(!me) return 1;
	
	if( wherenow!=where ){
//		remove_call_out("exec_int");
		finishb(me);
		return 1;
	}

	if(!me->query_temp("pending/exercising")) return 1;
	
	if(!living(me)) return finishb(me);

	force_gain = (int)me->query_skill("force",1)/10
		+(int)me->query_con()/2 + random(3);

	if (force_gain < 5) force_gain = 5;
	if (force_gain > 60) force_gain = 60;

	force_gain*=2;

	me->receive_damage("kee", 20);
	me->add("force", force_gain);
//	tell_object(me,"��Ŀǰ��max"+chinese_number(ex_max)+"\n");

if( ex_max==1 && (int)me->query("force") > (int)me->query("max_force") * 2-force_gain )
	{
	//tell_object(me,"��������Ѵ�����\n");
	call_out("finish", 1, me);
	return 1;
	}

        if( (int)me->query("force") > (int)me->query("max_force") * 2) 
		{
                if( (int)me->query("max_force") >=
              (int)me->query_max_force() ) {
                        tell_object(me,"�������Ϣ�鲼ȫ������ʱȴû�й��������ļ����ƺ�������Ϊ�Ѿ�������ƿ����\n");
		}else{
                        tell_object(me, "���������ǿ�ˣ�\n");
                        me->add("max_force", 1);

if ( (int)me->query("max_force") > (int)me->query("maximum_force"))
me->set("maximum_force", (int)me->query("max_force"));

		}
                me->set("force", me->query("max_force"));
//                remove_call_out("exec_int");
                call_out("finish", 1, me);
                return 1;
	}

	if (busy_time>1){
		busy_time--;
		call_out("exec_int", 1, me, where, busy_time,ex_max);
	} else {
		call_out("finish", 1, me);
	}
	return 1;
}


int finishb(object me)
{
	me->delete_temp("pending/exercising");
	me->start_busy(1);
	return 1;
}
int finish(object me)
{
	me->delete_temp("pending/exercising");
	me->start_busy(1);
	tell_object(me, "���й���ϣ���һ����������վ��������\n");
	return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : exercise|dazuo [<�ķѡ���������>]
	   exercise|dazuo 0 ��ֹͣ����

�����������������ڵ����ڸ�����������������ѵ�����弡���������
��������������������������ʽ����������������

��ο� help stats
HELP
        );
        return 1;
}