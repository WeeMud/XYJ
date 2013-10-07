// cracked by vikee 2/09/2002   vikee@263.net
// give.c

inherit F_CLEAN_UP;

int do_give(object me, object obj, object who);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string target, item;
	object obj, who, *inv, obj2;
	int i, amount, rev_val;
	mixed no_give;

    if(this_player()->is_busy())
	   return notify_fail("����æ���أ�����\n");
				 
	if(!arg) return notify_fail("��Ҫ��˭ʲô������\n");

	if( sscanf(arg, "%s to %s", item, target)==2
	|| sscanf(arg, "%s %s", target, item)==2 );
	else return notify_fail("��Ҫ��˭ʲô������\n");

	if(!objectp(who = present(target, environment(me))) || !living(who))
		return notify_fail("����û������ˡ�\n");

	if( me == who )  {
		write("Ok.\n");
		return 1;
	}


	if(sscanf(item, "%d %s", amount, item)==2) {
		if( !objectp(obj = present(item, me)) )	
			return notify_fail("������û������������\n");
		if( no_give=obj->query("no_give") )
			return notify_fail( stringp(no_give) ? no_give : "���������������ⶪ����\n");
		if( !obj->query_amount() )	
			return notify_fail( obj->name() + "���ܱ��ֿ����ˡ�\n");
		if( amount < 1 )
			return notify_fail("����������������һ����\n");
		if( amount > obj->query_amount() ) 
			return notify_fail("��û����ô���" + obj->name() + "��\n");
		else if( amount == (int)obj->query_amount() )
			return do_give(me, obj, who);
		else {
			obj2 = new(base_name(obj));
			obj2->set_amount(amount);
			rev_val = do_give(me, obj2, who);
			if( rev_val )
			   obj->set_amount( (int)obj->query_amount() - amount );
		    else
			   destruct(obj2);
			return rev_val; 
		}
	}

	if(arg=="all") {
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++) {
			if (inv[i]->query("no_get")) continue;
			do_give(me, inv[i], who);
		}
		write("Ok.\n");
		return 1;
	}

	if(!objectp(obj = present(item, me)))
		return notify_fail("������û������������\n");
	if( no_give=obj->query("no_give") )
		return notify_fail( stringp(no_give) ? no_give : "���������������ⶪ����\n");
	return do_give(me, obj, who);
}

int do_give(object me, object obj, object who)
{
	int   is_accept;
	object	*inv;
	mixed no_give;
    if(me->is_busy())
	   return notify_fail("����æ���أ�����\n");
    
    if(who->is_busy())
	   return notify_fail("�Է���æ���أ�ûʱ�����㣮����\n");

	if(no_give=obj->query("no_give") )
		return notify_fail( stringp(no_give) ? no_give : "���������������ⶪ����\n");

        // snowcat jan 23 1998
	// mon 9/29/99
	if (QUEST->quest_give (me, who, obj)) {
		message_vision("$N��$nһ"+obj->query("unit")+obj->name()+"��\n",me,who);
		if(userp(who)) {
		    if(who->query("env/no_accept") ||
			    !obj->move(who)) {
			message_vision("$Nһ��С�ģ�$n�������ϲ����ˡ�\n",
				who, obj);
			destruct(obj);
		    } else {
		        message_vision("$N���Ե���$n��л��\n",who,me);
		    }
		} else {
		    message_vision("$N���Ե���$n��л��\n",who,me);
		    destruct(obj);
		}
		return 1;
	} 

// no_accept should be in do_give Bula    
        if(who->query("env/no_accept"))
           return notify_fail("�Է�����Ը��������Ķ�����\n");

        if( !interactive(who)) {
		if( !(is_accept=who->accept_object(me, obj)) )
			return notify_fail("�Է���Ҫ��Ķ�����\n");
		if( is_accept == 2 )
			return 1;
	}

	if( !userp(who) && obj->value() ) { // give money to npc
		message_vision("$N�ó�" + obj->short() + "��$n��\n", me, who);
		destruct(obj);
		return 1;
	} else if( obj->move(who) ) {
	        string unit;
		if(obj->query_temp("d_mana")>0)
		  unit=obj->query_temp("unit");
                else
		  unit=obj->query("unit");
                if(strlen(unit)<2) unit="��";
		printf("���%sһ%s%s��\n", who->name(), unit,
			obj->name());
		message("vision", sprintf("%s����һ%s%s��\n", me->name(),
			unit, obj->name()), who );
		message("vision", sprintf("%s��%sһ%s%s��\n", me->name(), who->name(),
			unit, obj->name()), environment(me), ({me, who}) );
		if(!userp(who) && !userp(obj)) destruct(obj); // mon 4/25/98
		return 1;
	}
	else return 0;
}
int help(object me)
{
write(@HELP
ָ���ʽ : give <��Ʒ����> to <ĳ��>
      �� : give <ĳ��> <��Ʒ����>
 
���ָ��������㽫ĳ����Ʒ������, ��Ȼ, ������Ҫӵ��������Ʒ.

������ʱ : set no_accept <����ֵ>
���½��� : unset no_accept
HELP
    );
    return 1;
}
