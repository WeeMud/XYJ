// cracked by vikee 2/09/2002   vikee@263.net
// who.c

#include <net/dns.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

object *order_list (object *list);

mixed main(object me, string arg, int remote)
{
	string str, *option;
	object *list;
	int i, j, ppl_cnt;
	int opt_long, opt_id, opt_wiz, opt_pk;

	if( arg ) {
		option = explode(arg, " ");
		i = sizeof(option);
		while( i-- )
			switch(option[i]) {
				case "-l": opt_long = 1;	break;
				case "-i": opt_id = 1;		break;
				case "-w": opt_wiz = 1;		break;
				case "-k": {
				   opt_pk = 1;opt_id=1;
				   if(wizardp(me)||me->query("kill")) break;
				   else write("�㲻��ʹ�����ѡ�\n");

				   }
				default:
					if( wizardp(me)
					&&	option[i][0]=='@' ) {
						RWHO_Q->send_rwho_q(option[i][1..sizeof(option[i])],
							me, opt_long);
						write("��·ѶϢ���ͳ������Ժ�\n");
						return 1;
					}
					return notify_fail("ָ���ʽ��who [-l|-i|-w]\n");
			}
	}

	if( opt_long ) {
		if( (int)me->query("sen") < 20 )
			return notify_fail("��ľ���̫���ˣ�û�а취��֪������ҵ���ϸ���ϡ�\n");
		me->receive_damage("sen", 15);
	}

	str = "�� " + MUD_NAME + "\n";
	str += "��������������������������������������������������������������������������\n";
	
        if(opt_pk == 1) {
	   list = sort_array(users(), "sort_user", this_object());
        } else {
	   list = users();
        }

	list = order_list (list);

	ppl_cnt = 0;
	if( opt_long || opt_wiz ) {
		j = sizeof(list);
		while( j-- ) {
			// Skip those users in login limbo.
			if( !environment(list[j]) ) continue;
			if( !me->visible(list[j]) ) continue;
			if( opt_wiz && !wizardp(list[j]) ) continue;
			str = sprintf("%s%12s %s%s\n",
				str,
				RANK_D->query_rank(list[j]),
				list[j]->query("env/invisibility")?"(H)":"",
				list[j]->short(1)
			);
			ppl_cnt++;
		}
	} else {
		j = sizeof(list);
		while( j-- ) {
			// Skip those users in login limbo.
			if( !environment(list[j]) ) continue;
			if( me && !me->visible(list[j]) ) continue;

			//added by mon for who -k
			if(opt_pk && !list[j]->query("kill")) continue;
			
			str = sprintf("%s%-15s%s",
				str,
				opt_id ? capitalize(list[j]->query("id")): list[j]->name(1),
				(ppl_cnt%5==4? "\n": "")
			);
			ppl_cnt++;
		}
		if( ppl_cnt%5 ) str += "\n";
	}
		
	str += "��������������������������������������������������������������������������\n";
	str = sprintf("%s���� %d λʹ���������У�ϵͳ������%s\n", str, ppl_cnt,
		query_load_average() + "\n");

	if( remote ) return str;

	me->start_more(str);
	return 1;
}

//added by snowcat
object *order_list (object *list)
{
	int i, j;
	int size = sizeof(list);
	int *table = allocate(size);
	
	for (i = 0; i < size; i++)
	  	table[i] = (int)list[i]->query("combat_exp");
	for (i = size-2; i >= 0; i--) {
		for (j = 0; j <= i; j++) {
			if (table[j] < table[j+1]) {
			    	int k = table[j];
			    	object ob = list[j];
			    	table[j] = table[j+1];
			    	list[j] = list[j+1];
			    	table[j+1] = k;
			    	list[j+1] = ob;
			}
		}
	}
	return list;
}

int sort_user(object ob1, object ob2)
{
	if( wizardp(ob1) && !wizardp(ob2) ) return -1;
	
	if( wizardp(ob2) && !wizardp(ob1) ) return 1;

	if( wizardp(ob1) && wizardp(ob2) )
		return (int)SECURITY_D->get_wiz_level(ob2) 
			- (int)SECURITY_D->get_wiz_level(ob1);
	
	return (int)ob2->query("combat_exp") - (int)ob1->query("combat_exp");
}

int help(object me)
{
write(@HELP
ָ���ʽ : who [-l|-i|-w]

���ָ������г����������ϵ���Ҽ���ȼ���

-l ѡ���г��ϳ���ѶϢ��
-i ֻ�г���ҵ�Ӣ�Ĵ��š�
-w ֻ�г��������е���ʦ��

���ָ� finger
HELP
    );
    return 1;
}
