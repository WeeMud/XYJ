// cracked by vikee 2/09/2002   vikee@263.net
// reclaim.c

int main(object me, string arg)
{
	int mem;

	write("������������� " + reclaim_objects() + " ��������\n");
	return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : reclaim

�ô� : �������ڼ����������õı��������, �Լ��ټ������ʹ�á�
HELP
     );
     return 1;
}
