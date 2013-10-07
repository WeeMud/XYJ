// cracked by vikee 2/09/2002   vikee@263.net
// abandon.c

inherit F_CLEAN_UP;

// mon@xyj 10/15/98
void do_abandon(string yn, object me, string arg);

int main(object me, string arg)
{
    mapping skills;

	if( !arg || arg=="" ) return notify_fail("��Ҫ������һ��ܣ�\n");

	skills=me->query_skills();
	if( !skills || undefinedp(skills[arg]) )
	    return notify_fail("�㲢û��ѧ������ܡ�\n");

	if((int)skills[arg]>=10) {
	    write("��ȷ��Ҫ����"+to_chinese(arg)+
		    "��(y/n)");
	    input_to("do_abandon",me,arg);
	} else
	    do_abandon("yes",me,arg);
	
	return 1;
}

void do_abandon(string yn, object me, string arg)
{
     if(!me) return;

     if(!yn) {
	 write("ʲô��\n");
	 return;
     }

     if(yn[0]=='y' || yn[0]=='Y' ) {
	if( !me->delete_skill(arg) ) {
		write("��û��ѧ������ܡ�\n");
		return;
	}

	write("�������������ѧϰ" + to_chinese(arg) + "��\n");
	
	if(MISC_D->random_capture(me,8000,0)) return;

	return;
     } else {
	 write("�������������ܡ�\n");
	 return;
     }
}

int help()
{
	write(@TEXT
ָ���ʽ��abandon|fangqi <��������>

����һ������ѧ�ļ��ܣ�ע��������˵�ġ���������ָ������ܴ��������������
ɾ����������Ժ�Ҫ��������� 0 ��ʼ����������ؿ��������

���ָ��ʹ�õĳ���ͨ��������ɾ��һЩ����С�ġ��������ļ��ܣ�������Ǽ�����
��������ʱ������������ĸ��ֶ�����ս����ѧϰ�������Щ���ܻ���Ϊ�㾭����ʹ
�ö���������ļ����б��У��������ͱ��뻨��һЩ����ȥ����ס����ѧ����һ��
��Ȼ�����˵����ʸ��в�ͬ�����Ըߵ����ܹ�ѧϰ��༼�ܶ���Ϊ��Ŷ��յĲ��ӣ�
���Խϲ���˾�ֻ��ר����ض�����ܣ������ѧ�ļ�������̫�࣬�����������
����ᷢ�������ѧϰ�ٶȽ���ֻѧ���ּ��ܵ�����������Խ�࣬ѧϰЧ���������
��Խ���أ��������ξ�����һ��ѧ��ͬʱѡ��̫��ѧ�֣���Ȼ����Ȼ����ƾ�����˵�
��־������ȥ�������⽫��໨������౦���ʱ�䡣
TEXT
	);
	return 1;
}
