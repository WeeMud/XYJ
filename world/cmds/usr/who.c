// cracked by vikee 2/09/2002   vikee@263.net
// who.c

#include <net/dns.h>
#include <mudlib.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

mixed main(object me, string arg, int remote)
{
        string str, *option;
        object *list;
        int i, j, t_ppl_cnt;
        int opt_long, opt_id, opt_wiz;
	string load, cmds, comp;

        if( arg ) {
                string verbose="", rwho="";

                option = explode(arg, " ");
                i = sizeof(option);
                while( i-- )
                        switch(option[i]) {
                                case "-l": opt_long = 1;verbose+="-l ";continue;
                                case "-i": opt_id = 1;verbose+="-i ";continue;
                                case "-w": opt_wiz = 1;verbose+="-w ";continue;
                                default:
                                   if(option[i][0]=='@' ) {
                                       rwho=option[i][1..sizeof(option[i])];
                                   } else return notify_fail("ָ���ʽ��who [-l|-i|-w]\n");
                        }
                if(strlen(rwho)>0) {
                   RWHO_Q->send_rwho_q(rwho, me, verbose);
                   write("��·ѶϢ���ͳ������Ժ�\n");
                   return 1;
                }
        }

        if( opt_long && !remote ) {
                if( (int)me->query("sen") < 50 )
                        return notify_fail("��ľ���̫���ˣ�û�а취��֪������ҵ���ϸ���ϡ�\n");
                me->receive_damage("sen", 10);
        }

        if(remote) {
            opt_long=0; // disable -l for remote because too long.
#ifdef INTERMUD_NAME
            str  = "�� " + INTERMUD_NAME + "\n";
#else
            str = "�� " + MUD_NAME + "\n";
#endif
        } else {
            str = "�� " + MUD_NAME + "\n";
	}

        str += "��������������������������������������������������������������������������\n";

                         
        t_ppl_cnt = 0;
	list = users();

        if( opt_long || opt_wiz ) {
	        string menpai, *whokey;
		mapping wholist=([]);

		j = sizeof(list);

                while( j-- ) {
                // Skip those users in login limbo.
                  if( !environment(list[j]) ) continue;
		  if( me && !me->visible(list[j]) ) continue;
		  if( remote && list[j]->query("env/invisibility")  ) continue;
                  if( opt_wiz && 
			  (!wizardp(list[j])||(string)wizhood(list[j])
			   =="(elder)"))continue;
//here won't show "elder" as wiz, added by weiqi.

                  menpai=(string)list[j]->query("family/family_name");
		  if(undefinedp(wholist[menpai])) {
			  wholist[menpai]=
                              sprintf("%12s %s\n",
			      RANK_D->query_rank(list[j]),list[j]->short(1));
		  } else {
		      wholist[menpai]+=sprintf("%12s %s\n",
			      RANK_D->query_rank(list[j]),list[j]->short(1));
		  }
                  t_ppl_cnt++;
                }
		j=sizeof(wholist);
		if(j) whokey=keys(wholist);
		while(j--) {
		    str+=wholist[whokey[j]];
		}
        } else {
                j = sizeof(list);
                while( j-- ) {
                        // Skip those users in login limbo.
                        if( !environment(list[j]) ) continue;
                        if( me && !me->visible(list[j]) ) continue;
                        if( remote &&
                        list[j]->query("env/invisibility"))
                                continue;

                        str = sprintf("%s%-15s%s",
                                str,
                                opt_id ? capitalize(list[j]->query("id")): list[j]->name(1),
                                (t_ppl_cnt%5==4? "\n": "")
                        );
                        t_ppl_cnt++;
                }
                if(t_ppl_cnt%5 ) str += "\n";
        }
                                
//      if(!remote || strlen(str)<1024) {
        //don't add last two lines for remote who if it is too long.
        //small packets maybe arrived to remote machine out of order.
          str += "��������������������������������������������������������������������������\n";
//          str = sprintf("%s���� %d λ��������У�ϵͳ������%s\n", str, t_ppl_cnt,
//               query_load_average() + "\n");
	  load=query_load_average();
	  if(sscanf(load,"%s cmds/s, %s comp lines/s",
		      cmds,comp)!=2) {
              str = sprintf("%s���� %d λ��������У�ϵͳ������%s\n", 
			str, t_ppl_cnt,
                        query_load_average() + "\n");
	  } else {
	      str = sprintf("%s���� %d λ��������У�"+
		      "ƽ��ÿ��ִ�� %s ��ָ��"+
		      ((!remote&&wizardp(me))?"������ %s ��Դ����":"")+
		      "��\n",
		      str, t_ppl_cnt, cmds, comp);
	  }
//        }

        if( remote ) return str;
                         
        me->start_more(str);
        return 1;
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
ָ���ʽ : who [-l|-i|-w] ��
           who [-l|-i|-w] @mud_name

���ָ������г����������ϵ���Ҽ���ȼ���

-l        ѡ���г��ϳ���ѶϢ��
-i        ֻ�г���ҵ�Ӣ�Ĵ��š�
-w        ֻ�г��������е���ʦ��
@mud_name �г�����վ������ѶϢ������mudlist�鿴����վ�㡣
                          
���ָ� finger, mudlist
HELP
    );
    return 1;
}
                                
                     
