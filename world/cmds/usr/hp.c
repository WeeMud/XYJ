// cracked by vikee 2/09/2002   vikee@263.net
// hp cmds (Mon  09-04-95)
 
#include <ansi.h>
 
inherit F_CLEAN_UP;
 
string status_color(int current, int max);
 
int main(object me, string arg)
{
	object ob;
	mapping my;
	int  year, day, hour;
 
	seteuid(getuid(me));
 
	if(!arg)
		ob = me;
	else if (wizardp(me)) {
		ob = present(arg, environment(me));
		if (!ob) ob = find_player(arg);
		if (!ob) ob = find_living(arg);
        if (!ob) return notify_fail("��Ҫ�쿴˭��״̬��\n");
	} else
		return notify_fail("ֻ����ʦ�ܲ쿴���˵�״̬��\n");
 
	my = ob->query_entire_dbase();
 
	printf(" ��Ѫ�� %s%4d/ %4d %s(%3d%%)" NOR 
		"    ������ %s%4d / %4d (%3d%%) (+%d)\n" NOR,
		status_color(my["kee"], my["eff_kee"]),my["kee"],my["eff_kee"],
		status_color(my["eff_kee"], my["max_kee"]),	
		my["eff_kee"] * 100 / my["max_kee"],
		status_color(my["force"], my["max_force"]),	
		my["force"], my["max_force"],
		my["maximum_force"] ?
		  my["max_force"] * 100 / my["maximum_force"] : 100,
		my["force_factor"] );

	printf(" ���� %s%4d/ %4d %s(%3d%%)" NOR 
		"    ������ %s%4d / %4d (%3d%%) (+%d)\n" NOR,
		status_color(my["sen"], my["eff_sen"]),my["sen"],my["eff_sen"],
		status_color(my["eff_sen"], my["max_sen"]),	
		my["eff_sen"] * 100 / my["max_sen"],
		status_color(my["mana"], my["max_mana"]), 
		my["mana"], my["max_mana"],
		my["maximum_mana"] ?
		  my["max_mana"] * 100 / my["maximum_mana"] : 100,
		my["mana_factor"] );
    
	printf(" ʳ� %s%4d/ %4d      " NOR "     ��ѧ�� %s%d\n" NOR,
		status_color(my["food"], ob->max_food_capacity()),
		my["food"], ob->max_food_capacity(),
		HIY,
		my["combat_exp"]);
	
	year = my["daoxing"] / 1000; 
	day = (my["daoxing"] - year * 1000) / 4;
	hour = (my["daoxing"] - year * 1000 - day * 4) * 3; 
    
	printf(" ��ˮ�� %s%4d/ %4d      " NOR "     ���У� %s",
		status_color(my["water"], ob->max_water_capacity()),
		my["water"], ob->max_water_capacity(), HIM );
    
	if(year) printf("%s��", chinese_number(year));
	if(day) printf("%s��", chinese_number(day));
	if(hour) printf("%sʱ��", chinese_number(hour));
	if(!year && !day && !hour)  printf("û�е���");
	printf("\n"NOR);

	printf(" Ǳ�ܣ� %s%-8d        " NOR "     ɱ���� %s%d\n "NOR,
		YEL,
		(int)ob->query("potential") - (int)ob->query("learned_points"),
		RED,
		my["bellicosity"]);		

	return 1;
}
 
string status_color(int current, int max)
{
	int percent;
 
	if( max>0 ) percent = current * 100 / max;
	else percent = 100;
	if( percent > 100 ) return HIC;
	if( percent >= 90 ) return HIG;
	if( percent >= 60 ) return HIY;
	if( percent >= 30 ) return YEL;
	if( percent >= 10 ) return HIR;
	return RED;
}
 
int help(object me)
{
	write(@HELP
ָ���ʽ : hp
           hp <��������>                   (��ʦר��)
 
���ָ�������ʾ���ָ������(������)�ľ�, ��, ����ֵ��
 
see also : score
HELP
    );
    return 1;
}
