// cracked by vikee 2/09/2002   vikee@263.net
// wlist.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string *list;

	write(MUD_NAME + "Ŀǰ����ʦ(��������ʦ���������)
��������������������������������������������������������������������������\n");
	list = sort_array(SECURITY_D->query_wizlist(), 1);
	for(int i=0; i<sizeof(list); i++)
		printf("%-15s%c", list[i],  (i%5==4) ? '\n' : ' ');

write("\n");
write("��������������������������������������������������������������������������\n");
	return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : wlist

��; : �г�Ŀǰ���е���ʦ����(��������ʦ)��
HELP
     );
     return 1;
}
