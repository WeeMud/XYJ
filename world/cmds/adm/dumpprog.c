// cracked by vikee 2/09/2002   vikee@263.net
// dump.c (should be admin cmd?)

inherit F_CLEAN_UP;

int main(object me,string arg)
{
    object obj;

    seteuid(geteuid(me));

    obj=new(arg);
    if(!obj) return 0;
    dump_prog(obj,1,"dump1");
    dump_prog(obj,2,"dump2");
    destruct (obj);

	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : dump
 
dump the stats of all objects to a file in root dir 
named OBJ_DUMP.

HELP
    );
    return 1;
}
 
