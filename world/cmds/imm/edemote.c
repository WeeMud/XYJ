// cracked by vikee 2/09/2002   vikee@263.net
// edemote.c
// modified by none 96/12/1
// modified by yyzz 96/12/11

inherit F_CLEAN_UP;

int in_use;
string *emindex=
    ({"myself","others","myself_self","others_self",
    "myself_target","target","others_target"}); 
string *emexplain=
    ({
       "��ָ������ʹ����� emote ʱ�����Լ�������ѶϢ��",
       "��ָ������ʹ����� emote ʱ�������˿�����ѶϢ��",
       "���Լ�ʹ����� emote ʱ���Լ�������ѶϢ��",
       "���Լ�ʹ����� emote ʱ�������˿�����ѶϢ��",
       "�Ա���ʹ����� emote ʱ���Լ�������ѶϢ��",
       "�Ա���ʹ����� emote ʱ��ʹ�ö��󿴵���ѶϢ��",
       "�Ա���ʹ����� emote ʱ�������Լ���ʹ�ö����⣬�����˿��� ��ѶϢ��"
    });
int main(object me, string arg)
{
  mapping emote;
  mapping emote2;

  if( !arg ) 
    return notify_fail("��Ҫ�༭ʲô emote��\n");

  if( sscanf(arg, "-d %s", arg) ) 
  {
    log_file("FILES", sprintf("%s(%s) delete emote %s on %s.\n", 
        me->name(1), geteuid(me), arg, ctime(time()) ) );
    write("ɾ�� emote��" + arg + "\n");
    EMOTE_D->delete_emote(arg);
    return 1;
  }

  if( sscanf(arg, "-e %s", arg) ) 
  {
     int i;
     log_file("FILES", sprintf("%s(%s) modify emote %s on %s.\n", 
         me->name(1), geteuid(me), arg, ctime(time()) ) );
     emote = EMOTE_D->query_emote(arg);
     emote = (["updated":geteuid(me)]);

     write("�༭ emote��" + arg + "\n");
     write("ѶϢ�����кü��У��� . ��ʾ������\n");
     write("�� s ��ʾ�������롣\n");
     write("�� a ��ʾ������ emote �����n");
     write("ѶϢ�п�ʹ�õĲ��������¼��֣�\n");
     write("  $N  �Լ������֡�\n");
     write("  $n  ʹ�ö�������֡�\n");
     write("  $P  �Լ����˳ƴ����ʣ����㡢��������������������\n");
     write("  $p  ʹ�ö�����˳ƴ����ʣ����㡢��������������������\n");
     write("  $S  ���Լ��ĳƺ���\n");
     write("  $s  ���Լ��Ĵ�³�ƺ���\n");
     write("  $C  ���˶��Լ�����ơ�\n");
     write("  $c  ���˶��Լ��Ĵ�³�ƺ���\n");
     write("  $R  �Ա��˵���ơ�\n");
     write("  $r  �Ա��˵Ĵ�³�ƺ���\n");
     write("������������������������������������������������������������������������\n");
     i=0;
     emote2 = EMOTE_D->query_emote(arg);
     write(emexplain[0]+"\n");
     printf("�ϴ��޸�: %s->",emote2[emindex[i]]);
     input_to("get_msg",emote,arg,i);
     return 1;
  }
  emote = EMOTE_D->query_emote(arg);
  printf("�ϴ��޸ģ�%s\n", emote["updated"]);
  printf("��������������������������\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n",
  emote["myself"], emote["others"], emote["myself_self"],
     emote["others_self"], emote["myself_target"], emote["target"],
     emote["others_target"] );
  return 1;
}


int get_msg(string msg,mapping emote, string pattern,int i)
{
   mapping emote2;
   emote2 = EMOTE_D->query_emote(pattern);
   if (msg==".")
   {
     if( !undefinedp(emote[emindex[i]]) ) 
        emote[emindex[i]] += "\n";
     if(i==6)
     {
       EMOTE_D->set_emote(pattern, emote);
       write("Emote �༭������\n");
       return 1;
     }
     write(emexplain[i+1]+"\n");
     printf("�ϴ��޸�: %s->",emote2[emindex[i+1]]);
     input_to("get_msg", emote, pattern,i+1);
     return 1;
   }
   if (msg=="s")
   {
        emote[emindex[i]] =emote2[emindex[i]];
     if(i==6)
     {
       EMOTE_D->set_emote(pattern, emote);
       write("Emote �༭������\n");
       return 1;
     }
     write(emexplain[i+1]+"\n");
     printf("�ϴ��޸�: %s->",emote2[emindex[i+1]]);
     input_to("get_msg", emote, pattern,i+1);
     return 1;
   }
   if (msg=="a")
   {
     return 1;
   }
   if( !undefinedp(emote[emindex[i]]) )
     emote[emindex[i]] += msg + "\n";
   else 
     emote[emindex[i]] = msg;
   write("->");
   input_to("get_msg",emote,pattern,i);
   return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : edemote [-e|-d] <emote>
 
���ָ������޸�, ɾ�� emote ���г�������. ���� -d ������ɾ��
ָ���� emote, -e�����༭ָ���� emote.  �޲�������г�ָ�� emote ������,
�г���˳����༭ emote ʱ��ͬ.
 
���� emote ѶϢʱ��������Ŀ: û��Ŀ��, ָ��Ŀ����Ƕ��Լ�. ��
������ĳ��ѶϢ, ��ֱ���ڿհ������� '.' ����.
 
һ�� emote ѶϢ�����кܶ���, �ڿհ������� '.' ����������� emote.
�ڿհ������� 's' ����������� emote.
�ڿհ������� 'a' ����������� emote.
 
�༭ emote ʱ���������µķ�������ʾ:
 
$N : �Լ�������.
$n : Ŀ�������.
$P : �Լ����˳ƴ�����.
$p : Ŀ����˳ƴ�����.
$S : ���Լ��ĳƺ���
$s : ���Լ��Ĵ�³�ƺ���
$C : ���˶��Լ�����ơ�
$c : ���˶��Լ��Ĵ�³�ƺ���
$R : �Ա��˵���ơ�
$r : �Ա��˵Ĵ�³�ƺ���
 
HELP
    );
    return 1;
}
