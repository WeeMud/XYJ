// cracked by vikee 2/09/2002   vikee@263.net
// xiudao.c

#include <skill.h>
#include <ansi.h>

inherit F_CLEAN_UP;

void finish(object me,int dx_gain, int pot_gain);

int main(object me, string arg)
{
	object where;
	int level,time,dx_gain,pot_gain,constant;

	where=environment(me);

	if (!where->query("jingzuo_room"))
		return notify_fail("�˴����˾���������\n");

	if ( (int)me->query_skill("buddhism", 1) < 20 ) 
		return notify_fail("��Ĵ�˷���Ϊ̫�ͣ������й�������\n");
	
	if( (string)me->query("class")!="bonze") 
		return notify_fail("����û�г��ң���ʲô���ģ�\n");

	if (me->is_busy() || me->query_temp("pending/exercising"))
		return notify_fail("��������æ���ء�\n");

	if( me->is_fighting() )
		return notify_fail("ս���л�Ҫ�о���\n");

	if( (int)me->query("sen") * 100 / (int)me->query("max_sen") < 50 )
		return notify_fail("���������ǲ��壬��������Ҫ�߻���ħ��\n");

	if( (int)me->query("kee") * 100 / (int)me->query("max_kee") < 50 )
		return notify_fail("����������������������Ҫ�����ˣ�\n");
	
	if( (int)me->query("water") < 10 )
		return notify_fail("�����ڿڸ��������ЪЪ�ɡ�\n");

	if( (int)me->query("mana") < 50 )
		return notify_fail("�����ڷ���̫�ͣ���������Ҫ�߻���ħ��\n");


	level=(int)me->query_skill("buddhism",1);
	time= level/2 + random(2);

	if(time > 60) time=50+random(10);

	// mon -- on average 3 hours chanting then being caught.
	if(MISC_D->random_capture(me,(3*3600/(time+1)),0)) return 1;

// time=level of chanting/2, max 60-70 seconds.
	constant= level/10 + 15;
// not the real constant, divid by 25. the constant is from 17/25-1.
//	dx_gain= (level/5)*(k/25) is the formula, dx_gain=level/4.
//	so max. 1 minutes, about 20-25 dx. that's about 1.2k-1.5k/h
//	also a little random. (that's for a player with 100 level)
//	maybe a little high?
	dx_gain= (level*constant)/100;
	dx_gain= dx_gain/2 + random(dx_gain) + random((int)me->query("spi")/5) + 1;

	if( dx_gain > 100 ) dx_gain=80+random(20);

//	pot_gain=time/10, so each hour 400-500 dx.

	pot_gain= time/10 + (int)me->query("int")/5 + 1;

	message_vision(HIY "$Nϯ�ض�����˫Ŀ΢�գ��������������˾��ġ�\n" NOR, me);
	me->start_busy(time);
	call_out("finish",time, me, dx_gain,pot_gain);
	return 1;
}

void finish(object me,int dx_gain, int pot_gain)
{
	int i;
	string *msg=({
		"����Ϊ�࣬����ƣ�ͣ���̰����������Ϊ���������ڡ�",
		"и��׹�䣬���о������Ʒ��ն񣬴ݷ���ħ������������",
		"�޳����������������ѧ���ţ������ǻۣ��ɾͱ�ţ��̻�һ�У�Ϥ�Դ��֡�",
		"ƶ���Թ������Ե��������ʩ������Թ�ף�����ɶ񣬲������ˡ�",
		"������ȼ������������������ģ��ռ�һ�С�",
		"Ը���������������࣬�����������Ͼ����֡�",
		"Ը�Դ˹��£�ׯ�Ϸ������ϱ����ض����¼���;�ࡣ",
		"���м����ߣ�Ϥ�������ģ���������������������顣",
		});
	message_vision(HIY "$N���������"+msg[random(sizeof(msg))]+"\n" NOR, me);
	message_vision(HIY "$N���������۾�������һ����վ��������\n" NOR, me);


	me->add("daoxing", dx_gain);
	tell_object(me, HIC "��ĵ���������" + chinese_number(dx_gain*3) + "ʱ����\n" NOR);
	me->add("chanting/dx", dx_gain); 
        if ((me->query("potential") - me->query("learned_points")) < 1000){
                me->add("potential", pot_gain);
		me->add("chanting/pot", pot_gain);
		tell_object(me, HIC "���Ǳ��������" + chinese_number(pot_gain) + "�㣡\n" NOR);
	}
	i=dx_gain*3+random(dx_gain*2);

if((string)me->query("family/family_name") =="�Ϻ�����ɽ"){
	me->improve_skill("buddhism", i, 1);
	tell_object(me, HIC "��Ĵ�˷�������" + chinese_number(i)+ "�㣡\n" NOR);
	me->add("chanting/bud", i);
} else {
        me->improve_skill("buddhism", i/3, 1);
        tell_object(me, HIC "��Ĵ�˷�������" + chinese_number(i/3)+ "�㣡\n" NOR);
        me->add("chanting/bud", i/3);
}

	if (me->query("water") >= pot_gain) me->add("water",-pot_gain*2);
	else me->set("water", 0);

	me->receive_damage("sen", me->query("int")*2);
	me->receive_damage("kee", me->query("int")*2);
	me->add("mana", -50);
	me->start_busy(1);
}

int help(object me)
{
        write(@HELP
ָ���ʽ : chanting

�о���������ߵ��С�
HELP
        );
        return 1;
}
