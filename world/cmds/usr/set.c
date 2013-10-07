// cracked by vikee 2/09/2002   vikee@263.net
// set.c
 
#define MAX_ENV_VARS	20
 
inherit F_CLEAN_UP;
 
int help();
 
int main(object me, string arg)
{
    int i;
    string term, *terms, *wiz_only, *allowed;
    mixed data;
    mapping env;
 
    wiz_only = ({"invisibility", "immortal"});
    allowed=({  "block_tell", "brief", "brief_message", "brief_all",
		"no_accept", "no_teach", "wimpy", "public",
		"fengbo-cha", "destination"});
 
	if( me != this_player(1) ) return 0;
 
	env = me->query("env");
 
	if( !arg || arg=="" ) {
		write("��Ŀǰ�趨�Ļ��������У�\n");
		if( !mapp(env) || !sizeof(env) )
			write("\tû���趨�κλ���������\n");
		else {
			terms = keys(env);
			for(i=0; i<sizeof(terms); i++)
				printf("%-20s  %O\n", terms[i], env[terms[i]]);
		}
		return 1;
	}
 
	if( sscanf(arg, "%s %s", term, data)!=2 ) {
		term = arg;
		data = "YES";
	}
 
	if( term && term!="" ) {
		if( mapp(env) && undefinedp(env[term]) && sizeof(env) >= MAX_ENV_VARS )
			return notify_fail("����Ļ�������̫���ˣ������� unset ɾ�������ɡ�\n");
		sscanf(data, "%d", data);

	// added by pickle to prevent people from taking advantage of
	// LPC, for instance, set invisibility/ and become invisible.
	// 9-27-97.
	if(!wizardp(me)
	&& (member_array(term, allowed) == -1))
		return notify_fail("��ֻ���趨 help settings �ж�����Ļ���������\n");
        if((wiz_level(me) == 0) && (member_array(term, wiz_only) != -1))
            return notify_fail("ֻ����ʦ��������趨��\n");

	if(term == "wimpy" && (intp(data) < 0 || intp(data) > 80))  {
	   return COMMAND_DIR"usr/wimpy"->help(me);
		}
        me->set("env/" + term, data);
		printf("�趨����������%s = %O\n", term, data);
	return 1;
	}
	return help();
}
 
int help()
{
	write(@TEXT
ָ���ʽ��set <������> [<����ֵ>]
 
���ָ�������趨һЩ�������������Ӳ���ʱ����ʾ��Ŀǰ�趨�Ļ�����������ָ��
����ֵ�����ڶ�ֵΪ "YES"��
 
ȡ�������趨���� unset ָ�
 
��������Щ�������������趨����� help settings��
TEXT
	);
	return 1;
}
