// cracked by vikee 2/09/2002   vikee@263.net
// score.c

#include <ansi.h>
#include <combat.h>

inherit F_CLEAN_UP;

string *gift_ranking = ({"����֮ѡ","�µ�", "����", "�е�", "����",
"�ϵ�",
        "����֮ѡ"});

string bar_string = "��������������������������������������������������";
string blank_string ="��������������������������������������������������";
//string bar_string ="�������������������������������������������������";
//string blank_string="�񩤩���������������������������������������������";

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
        int attack_points, dodge_points, parry_points,year;
        string *husb, *wives;
        mapping hus, wiv;
        int             i;

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

        line = sprintf( BOLD "%s" NOR "%s\n\n", RANK_D->query_rank(ob),
ob->short(1) );
        line += sprintf(" ����һ%s%s���%s%s��%s����\n",
                ob->query("unit"),
                chinese_number(ob->query("age")), 
                ob->query("gender"),
                ob->query("race"),
                CHINESE_D->chinese_date(((int)ob->query("birthday") -
14*365*24*60) * 60) );
    
           year = my["combat_exp"] / 1000;
          if(year)
          line += sprintf(" ����"RED"%s��"NOR"�ĵ��С�\n\n",
                      chinese_number(year));
          else
          line += sprintf(" ��ĵ���"RED"������һ��"NOR"��\n\n");

        if( wizardp(me) || (int)ob->query("age") >= 14 ) {
                line += sprintf(
                        " ������[%s]  ��ʶ��[%s]  ���ԣ�[%s]  ���ԣ�[%s]\n"
                        " ������[%s]  ��ò��[%s]  ���ǣ�[%s]  ��Ե��[%s]\n\n",
                        display_attr(my["str"], ob->query_str()),
                        display_attr(my["cor"], ob->query_cor()),
                        display_attr(my["int"], ob->query_int()),
                        display_attr(my["spi"], ob->query_spi()),
                        display_attr(my["cps"], ob->query_cps()),
                        display_attr(my["per"], ob->query_per()),
                        display_attr(my["con"], ob->query_con()),
                        display_attr(my["kar"], ob->query_kar()));
                /*
                        my["str"], my["cor"], my["int"], my["spi"],
                        my["cps"], my["per"], my["con"], my["kar"]);

                        gift_evaluation(my["str"]),
gift_evaluation(my["cor"]),
                        gift_evaluation(my["int"]),
gift_evaluation(my["spi"]),
                        gift_evaluation(my["cps"]),
gift_evaluation(my["per"]),
                        gift_evaluation(my["con"]),
gift_evaluation(my["kar"]));*/
        }

        if( mapp(my["family"]) ) {
                if( my["family"]["master_name"] )
                        line = sprintf("%s ���ʦ����%s��\n",
                                line, my["family"]["master_name"] );
        }

        if (ob->query("married")) {
                if (ob->query("gender")=="Ů��") {
                        hus=ob->query("husband");
                        husb=keys(hus);
                        line += " ����ɷ��� " + ob->query("husband/"+husb[0])+"��\n\n";
                }
                else {
                        wiv=ob->query("wife");
                        wives=keys(wiv);
                        line += " ��������� ";
                        for (i=0;i<=(ob->query("married")-1);i++) {
                                if (i==(ob->query("married")-1))
                                        line+=ob->query("wife/"+wives[i])
+ "��\n\n";
                                else
                                        line+=ob->query("wife/"+wives[i])
+ "��"; }
        }
        }
        else {
                if (ob->query("gender")=="Ů��")
                        line += " ��Ŀǰ���ֹ��С�\n\n";
                else line+=" ��Ŀǰ�ǹ����һ����\n\n";
        }


        line += " <��>  " + tribar_graph(my["gin"], my["eff_gin"],
my["max_gin"], GRN) + "\n";
        line += " <��>  " + tribar_graph(my["kee"], my["eff_kee"],
my["max_kee"], HIR) + "\n";
        line += " <��>  " + tribar_graph(my["sen"], my["eff_sen"],
my["max_sen"], HIB) + "\n";
/*
        line += sprintf(" ���� %s%4d/ %4d %s(%3d%%)" NOR "    ������ %s%4d
/ %4d (+%d)\n" NOR,
                status_color(my["gin"], my["eff_gin"]), my["gin"],
my["eff_gin"],
                status_color(my["eff_gin"], my["max_gin"]),
my["eff_gin"] * 100 / (1+my["max_gin"]),
                status_color(my["atman"], my["max_atman"]),
my["atman"], my["max_atman"],
                my["atman_factor"] );
        line += sprintf(" ���� %s%4d/ %4d %s(%3d%%)" NOR "    ������ %s%4d
/ %4d (+%d)\n" NOR,
                status_color(my["kee"], my["eff_kee"]), my["kee"],
my["eff_kee"],
                status_color(my["eff_kee"], my["max_kee"]),
my["eff_kee"] * 100 / (1+my["max_kee"]),
                status_color(my["force"], my["max_force"]),
my["force"], my["max_force"],
                my["force_factor"] );
        line += sprintf(" �� %s%4d/ %4d %s(%3d%%)" NOR "    ������ %s%4d
/ %4d (+%d)\n" NOR,
                status_color(my["sen"], my["eff_sen"]), my["sen"],
my["eff_sen"],
                status_color(my["eff_sen"], my["max_sen"]),
my["eff_sen"] * 100 / (1+my["max_sen"]),
                status_color(my["mana"], my["max_mana"]), my["mana"],
my["max_mana"],
                my["mana_factor"] );
*/

/*
        line += sprintf(" ʳ�%d/%d����ˮ��%d/%d\n\n",
                my["food"], ob->max_food_capacity(), my["water"],
ob->max_water_capacity());
*/
        if( objectp(weapon = ob->query_temp("weapon")) )
                skill_type = weapon->query("skill_type");
        else
                skill_type = "unarmed";

        attack_points = COMBAT_D->skill_power(ob, skill_type,
SKILL_USAGE_ATTACK);
        parry_points = COMBAT_D->skill_power(ob, skill_type,
SKILL_USAGE_DEFENSE);
        dodge_points = COMBAT_D->skill_power(ob, "dodge",
SKILL_USAGE_DEFENSE);

        line += sprintf("\n ս�������� " HIW "%d (+%d)" NOR
"\t\tս�������� " HIW "%d (+%d)\n\n" NOR,
                attack_points/100 + 1, ob->query_temp("apply/damage"),
                (dodge_points + (weapon? parry_points:
(parry_points/10)))/100 + 1, ob->query_temp("apply/armor"));

        line += " ʳ�" + tribar_graph(my["food"],
ob->max_food_capacity(), ob->max_food_capacity(), YEL) + "\n";
        line += " ��ˮ��" + tribar_graph(my["water"],
ob->max_water_capacity(), ob->max_water_capacity(), CYN) + "\n";

        line += sprintf("\n �㵽ĿǰΪֹ�ܹ�ɱ�� %d ���ˣ������� %d ����������ҡ�\n\n",
                my["MKS"] + my["PKS"], my["PKS"]);

        line += sprintf(" ɱ    ���� " RED "%d\n" NOR,
ob->query("bellicosity") );
        line += sprintf(" Ǳ    �ܣ� " HIY "%d (%d%%)\n" NOR,
                (int)ob->query("potential") -
(int)ob->query("learned_points"),
                (1 + (int)ob->query("learned_points")) * 100 / (1 +
(int)ob->query("potential")) );
//      line += sprintf(" ʵս���飺 " HIM "%d\n\n" NOR,ob->query("combat_exp") );
//      line += sprintf(" �ۺ����ۣ� " HIC "%d\n\n" NOR,ob->query("score") );

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
	if(max==0) max=1;//ensure it works.
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

Ϊ�˱������Ϊ�ˡ��츳������ֵ�����������������޶�ֻ�����ۺ����۴ﵽ
100 ���ϵ���һ���ʦ�ſ��õ��츳״����

see also : hp
HELP
    );
    return 1;
}

