// trace.c

int main(object me, string arg)
{
	if(arg == "on")
	{
		me->set_temp("debug_ex/trace", 1);
		message_vision("ϵͳ trace ��Ϣ�Ѵ򿪡�\n", me);
	}
	else
	{
		me->set_temp("debug_ex/trace", 0);
		tell_object(me, "ϵͳ trace ��Ϣ�ѹرա�\n");
	}
	return 1;
}

int help (object me)
{
write(@HELP
ָ���ʽ : trace <on|off>

��/�ر� trace ��Ϣ

HELP
     );
    return 1;
}
