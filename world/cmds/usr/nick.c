// cracked by vikee 2/09/2002   vikee@263.net
// nick.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int i;
	string newarg, str1, str2;
	
	if( !arg ) return notify_fail("��Ҫ���Լ�ȡʲô�ºţ�\n");
	
if ( me->query("nickname")=="���˷绯�ѱ���ֹ"NOR )
return notify_fail("����ʱ�������ôº�!\n");
	if( arg=="none" ) {
	me->delete("nickname");
	return 1;
	}

	while(i--) {
               	if( arg[i]<' ' ) {
                       	return notify_fail("�Բ������ͷ�β����ÿ�����Ԫ��\n");
               	}
       	}

	arg = replace_string(arg, "$BLK$", BLK);
	arg = replace_string(arg, "$RED$", RED);
	arg = replace_string(arg, "$GRN$", GRN);
	arg = replace_string(arg, "$YEL$", YEL);
	arg = replace_string(arg, "$BLU$", BLU);
	arg = replace_string(arg, "$MAG$", MAG);
	arg = replace_string(arg, "$CYN$", CYN);
	arg = replace_string(arg, "$WHT$", WHT);
	arg = replace_string(arg, "$HIR$", HIR);
	arg = replace_string(arg, "$HIG$", HIG);
	arg = replace_string(arg, "$HIY$", HIY);
	arg = replace_string(arg, "$HIB$", HIB);
	arg = replace_string(arg, "$HIM$", HIM);
	arg = replace_string(arg, "$HIC$", HIC);
	arg = replace_string(arg, "$HIW$", HIW);
	arg = replace_string(arg, "$NOR$", NOR);

	newarg=arg; // strip away ansi color code, then count length
	// mon 8/20/98
	while(sscanf(newarg,"%s%*sm%s",str1,str2)==3)
	            newarg=str1+str2;

if ( (i = strlen(newarg)) > 30 )
		return notify_fail
		    ("��Ĵº�̫���ˣ���һ����һ��ġ�����һ��ġ�\n");

	me->set("nickname", arg + NOR);
	write("Ok.\n");
	return 1;
}
int help(object me)
{
        write(@HELP
ָ���ʽ : nick <���, �º�>
	   nick none	ȡ��
 
���ָ���������Ϊ�Լ�ȡһ�����������Ż�ͷ�Σ������ϣ���ڴº���
ʹ�� ANSI �Ŀ�����Ԫ�ı���ɫ�����������µĿ����ִ���

HELP +
"$BLK$ - "BLK"��ɫ"NOR"		$NOR$ - �ָ�������ɫ\n"+
"$RED$ - "RED"��ɫ"NOR"		$HIR$ - "HIR"����ɫ"NOR"\n"+
"$GRN$ - "GRN"��ɫ"NOR"		$HIG$ - "HIG"����ɫ"NOR"\n"+
"$YEL$ - "YEL"����ɫ"NOR"		$HIY$ - "HIY"��ɫ"NOR"\n"+
"$BLU$ - "BLU"����ɫ"NOR"		$HIB$ - "HIB"��ɫ"NOR"\n"+
"$MAG$ - "MAG"ǳ��ɫ"NOR"		$HIM$ - "HIM"�ۺ�ɫ"NOR"\n"+
"$CYN$ - "CYN"����ɫ"NOR"		$HIC$ - "HIC"����ɫ"NOR"\n"+
"$WHT$ - "WHT"ǳ��ɫ"NOR"		$HIW$ - "HIW"��ɫ"NOR"\n"+
@HELP
 
����ϵͳ�Զ������ִ�β�˼�һ�� $NOR$��

HELP
        );
        return 1;
}
