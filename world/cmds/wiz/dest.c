// cracked by vikee 2/09/2002   vikee@263.net
// dest.c

#include "/doc/help.h"

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string option, target, msg;
	object obj,*body,ob;
	int i;

	if (!arg) return notify_fail("ָ���ʽ : dest <���֮���ƻ���>\n" );

	if( sscanf(arg, "%s %s", option, target)!=2 ) target = arg;
if ( option != "-r" && option != "-p" ) target = arg;

// added by mon. 3/12/97
        if(arg=="-p") {
	  body=children(USER_OB);
	  for (i=0;i<sizeof(body);i++){
	    ob=body[i];
	    if(clonep(ob)&&ob->query("max_gin")==0)
	      write(getuid(ob)+" "+ob->short()+"\n");
          }
          return 1;
        }

        if( option == "-r" && (string)SECURITY_D->get_status(me)=="(admin)" )
		seteuid(ROOT_UID);
	else
		seteuid(geteuid(me));

	obj = find_object(target);
	if (!obj) obj = present(target, me);
	if (!obj) obj = present(target, environment(me));
	if (!obj) obj = find_object( resolve_path(me->query("cwd"), target) );
	if (!obj) return notify_fail("û�����������\n");

	if( environment(me)==environment(obj) )
	if( !stringp(msg = me->query("env/msg_dest")) )
		msg = "$N�ٻ���һ���ڶ�����$n��û�ˡ�\n";
        else 
	  message_vision(msg + "\n", me, obj);

	destruct(obj);
	if(obj) write("���޷����������ݻ١�\n");
	else write("Ok.\n");

	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : dest [-r] <���֮���ƻ���>
           dest [-p] show damaged player objects.

���ô�һָ��ɽ�һ�����(object)���������(class)�Ӽ�������������������
������(����ָ�������������)����һ�βο�����������ʱ������½������롣

���� (admin) ��ֵ���ʦ������ -r ѡ���� ROOT_UID ���������������������
ʹ���ߡ�

�ο����ϣ� destruct()
HELP
    );
    return 1;
}
