// cracked by vikee 2/09/2002   vikee@263.net

// score.c

#include <ansi.h>
#include <combat.h>

inherit F_CLEAN_UP;

string *gift_ranking = ({"����֮ѡ","�µ�", "����", "�е�", "����", "�ϵ�", "����֮ѡ"});

string bar_string = "��������������������������������������������������";
string blank_string ="��������������������������������������������������";

string display_attr(int gift, int value);
string status_color(int current, int max);
string date_string(int date);
string tribar_graph(int val, int eff, int max, string color);

void create() { seteuid(ROOT_UID); }

int main(object me, string arg)
{
	object ob;
	mapping my;
	string line, str, skill_type;
	object weapon;
	int attack_points, dodge_points, parry_points,year,obstacles;
	int i;

	seteuid(getuid(me));

	if(!arg)
		ob = me;
	else if (wizardp(me)) 
	{
		ob = present(arg, environment(me));
		if (!ob) ob = find_player(arg);
		if (!ob) ob = find_living(arg);
		if (!ob) return notify_fail("��Ҫ�쿴˭��״̬��\n");
	} 
	else
		return notify_fail("ֻ����ʦ�ܲ쿴���˵�״̬��\n");

	my = ob->query_entire_dbase();

	line = sprintf( BOLD "%s" NOR "%s\n\n", RANK_D->query_rank(ob), ob->short(1) );

	if( ob->query("fake_age"))
	{
		line += sprintf(" ����һ%s%s���%s%s��%s����\n\n",
		ob->query("unit"),
		chinese_number(ob->query("age")), 
		ob->query("gender"),
		ob->query("race"),
		CHINESE_D->chinese_date((int)ob->query("birthday") - 14*60*24*60) );
	}
	else
	{
		line += sprintf(" ����һ%s%s���%s%s��%s����\n\n",
		ob->query("unit"),
		chinese_number(ob->query("age")),
		ob->query("gender"),
		ob->query("race"),
		CHINESE_D->chinese_date((int)ob->query("birthday") - 14*60*24*60) );
	}

        if( wizardp(me) )
        {
		line += sprintf(
			" ������[%s]  ��ò��[%s]  ��ʶ��[%s]  ��Ե��[%s]\n"
			" ���[%s]  ���ǣ�[%s]  ���ԣ�[%s]  ���ԣ�[%s]\n\n",
		display_attr(my["cps"], ob->query_cps()),
		display_attr(my["per"], ob->query_per()),
		display_attr(my["cor"], ob->query_cor()),
		display_attr(my["kar"], ob->query_kar()),
		display_attr(my["str"], ob->query_str()),
		display_attr(my["con"], ob->query_con()),
		display_attr(my["int"], ob->query_int()),
		display_attr(my["spi"], ob->query_spi()));
        }
	else 
//if( RANK_D->grade_dx( RANK_D->describe_dx( (int)me->query("daoxing") ) ) 
//                        >= RANK_D->grade_dx(BLU "�������" NOR) ) 
	{
		line += sprintf(
			" ���[%s]  ���ǣ�[%s]  ���ԣ�[%s]  ���ԣ�[%s]\n\n",
		display_attr(my["str"], ob->query_str()),
		display_attr(my["con"], ob->query_con()),
		display_attr(my["int"], ob->query_int()),
		display_attr(my["spi"], ob->query_spi()));
	}
line += sprintf(" �����˺�����[" HIR "%d" NOR "]\t\t���ױ�������[" HIG "%d" NOR "]\n\n" NOR,
ob->query_temp("apply/damage"),ob->query_temp("apply/armor"));
        


	if( mapp(my["family"]) ) 
	{
		if( my["family"]["master_name"] )
			line = sprintf("%s ���ʦ����%s��\n", line, my["family"]["master_name"] );
	}

	if (ob->query("married")) 
	{
		if (ob->query("gender")=="Ů��") 
		{
			line += " ����ɷ���" + ob->query("couple/name")+"��\n\n";
		}
		else 
		{
			line += " ���������" + ob->query("couple/name")+"��\n\n";
		}
	}
	else 
	{
		if (ob->query("gender")=="Ů��")
			line += " ��Ŀǰ���ֹ��С�\n\n";
		else line+=" ��Ŀǰ�ǹ����һ����\n\n";
	}


	line += " <��Ѫ>  " + tribar_graph(my["kee"], my["eff_kee"],
my["max_kee"], HIR) + "\n";
	line += " <����>  " + tribar_graph(my["sen"], my["eff_sen"],
my["max_sen"], HIB) + "\n\n";

	if( objectp(weapon = ob->query_temp("weapon")) )
		skill_type = weapon->query("skill_type");
	else
		skill_type = "unarmed";

	attack_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_ATTACK);
	parry_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_DEFENSE);
	dodge_points = COMBAT_D->skill_power(ob, "dodge", SKILL_USAGE_DEFENSE);


	if(wizardp(this_player())) 
	line += sprintf(" ս�������� " HIW "%d (+%d)" NOR "\t\tս�������� " HIW "%d (+%d)\n\n" NOR,
	attack_points/100 + 1, ob->query_temp("apply/damage"),
		(dodge_points + (weapon? parry_points: 
		(parry_points/10)))/100 + 1, ob->query_temp("apply/armor"));

	line += " <ʳ��>  " + tribar_graph(my["food"], ob->max_food_capacity(), ob->max_food_capacity(), YEL) + "\n";
	line += " <��ˮ>  " + tribar_graph(my["water"], ob->max_water_capacity(), ob->max_water_capacity(), CYN) + "\n\n";


	obstacles = ob->query("qujing/number");
	if(obstacles)
		line += sprintf(" ��������ȡ�澭�ѹ���"RED"%s��"NOR"��\n", chinese_number(obstacles));
	line += sprintf(" �㵽ĿǰΪֹ�ܹ�ɱ�� %d ���ˣ������� %d ����������ҡ�\n\n", 
		my["MKS"] + my["PKS"], my["PKS"]);
        
	if(ob->query("kill/pkgain") ) 
	{ 
		line +=sprintf(" �У˵������ӣ� %s  \n", COMBAT_D->chinese_daoxing(ob->query("kill/pkgain")));
		if(!ob->query("kill/pklose") && !ob->query("kill/nkgain") ) line+="\n";
	}
	/*
	if(ob->query("kill/pklose") ) 
	{
		line +=sprintf(" �У˵��м��٣� %s\n", COMBAT_D->chinese_daoxing(ob->query("kill/pklose")));
		if(!ob->query("kill/nkgain") ) line+="\n";
	}
	*/
	if(ob->query("kill/nkgain") ) 
	{
		line +=sprintf(" �Σ˵������ӣ� %s\n\n", COMBAT_D->chinese_daoxing(ob->query("kill/nkgain")));
	}


	line += sprintf(" ���о��磺%s", RANK_D->describe_dx(ob->query("daoxing")) );
//	line += sprintf("\t\t��ѧ���磺%s\n", RANK_D->describe_exp(ob->query("combat_exp")) );
	line += sprintf("����������������ѧ���磺%s\n", 
		RANK_D->describe_exp(ob->query("combat_exp")) );
	line += sprintf(" ������Ϊ��%s", RANK_D->describe_fali(ob->query("max_mana")) );
//	line += sprintf("\t\t������Ϊ��%s\n", RANK_D->describe_neili(ob->query("max_force")) );
	line += sprintf("��������������������Ϊ��%s\n", 
		RANK_D->describe_neili(ob->query("max_force")) );

	write(line);
	return 1;
}

string display_attr(int gift, int value)
{
        if( value > gift ) return sprintf( HIY "%3d" NOR, value );
        else if( value < gift ) return sprintf( CYN "%3d" NOR, value );
        else return sprintf("%3d", value);
}

string status_color(int current, int max)
{
        int percent;

        if( max ) percent = current * 100 / max;
        else percent = 100;

        if( percent > 100 ) return HIC;
        if( percent >= 90 ) return HIG;
        if( percent >= 60 ) return HIY;
        if( percent >= 30 ) return YEL;
        if( percent >= 10 ) return HIR;
        return RED;
}

string tribar_graph(int val, int eff, int max, string color)
{
        return color + bar_string[0..(val*25/max)*2-1]
                + ((eff > val) ?
blank_string[(val*25/max)*2..(eff*25/max)*2-1] : "") + NOR;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : score
           score <��������>                   (��ʦר��)

���ָ�������ʾ���ָ������(������)�Ļ������ϡ�
�������ϵ��趨����� 'help setup'��

see also : hp
HELP
    );
    return 1;
}

