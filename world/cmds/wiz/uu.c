// cracked by vikee 2/09/2002   vikee@263.net
// user list

inherit F_CLEAN_UP;

int main(string str)
{
        object *ob;
        int i;
        ob=users();
        i = sizeof(ob);
        while (i--) {
        write(sprintf("%15s : %30s\n",ob[i]->query("id"),
        file_name(ob[i])));
        }
        return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : ulist

������������ҵ�/obj/user number ��ʾ������
HELP
    );
    return 1;
}
