// cracked by vikee 2/09/2002   vikee@263.net
// summon command..

inherit F_CLEAN_UP;

int main(object me, string str)
{
	object ob;
	int i;
	if (!str) return notify_fail("<Syntax>: Summon <player id>\n");
	ob = LOGIN_D->find_body(str);
	if (!ob) return notify_fail("�ף����� ���������\n");

//    if(wizardp(ob) && wiz_level(me) < wiz_level(ob))
//      return notify_fail("�㲻��ץ�ȼ�����ߵ���ʦ��\n");
				  
	// moving
	tell_room(environment(ob),"��������һֻ���ְ�"+
	(string)ob->query("name")+"ץ��������Ȼ�󲻼��ˡ�\n", ob);
	tell_object(ob,"һֻ�ְ���ץ������������ǰһ��ڣ�����\n");
	ob->move(environment(me));
        tell_object(me, "���"+(string)ob->query("name")+"ץ�������ǰ��\n");
	tell_object(ob,"������ ����ʱ������"+(string)me->query("name")+
	"����Ū�����ġ�\n");
	tell_room(environment(ob),(string)ob->query("name")+"ͻȻ����"+
	"������ǰ��\n",({me,ob}));
	// ok ..
	return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : summon <ĳ��>

��ָ������㽫ĳ��ץ������ǰ��
HELP
    );
    return 1;
}
