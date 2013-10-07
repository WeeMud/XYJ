// cracked by vikee 2/09/2002   vikee@263.net
// describe.c

#include "ansi.h"

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string *txt;

	if( !arg ) return notify_fail("ָ���ʽ��describe <����>\n");

	if( arg=="none" ) {
	        me->delete("long");
		tell_object(me, "Ok!\n");
        	return 1;
	}


	txt = explode(arg, "\n");
	if( (wizardp(me) && sizeof(txt) > 20) || sizeof(txt) > 8 )
		return notify_fail("�뽫�����Լ������������ڰ������ڡ�\n");

	arg = implode(txt, "\n") + "\n";

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

	me->set("long", arg + NOR);
	write("Ok.\n");
	return 1;
}

int help()
{
	write(@TEXT
ָ���ʽ��describe <����>

���ָ�������趨�������� look ָ���ʱ�������������ͨ������
����������һ��ʱ������ to describe �ķ�ʽ�����롣

ȡ����describe none

TEXT
	);
	return 1;
}
