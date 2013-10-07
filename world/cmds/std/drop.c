// cracked by vikee 2/09/2002   vikee@263.net
// drop.c

inherit F_CLEAN_UP;

int do_drop(object me, object obj);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	object obj, *inv, obj2;
	int i, amount;
	string item;
	mixed no_drop;

        if(me->is_busy())
           return notify_fail("����æ���أ�����\n");
 
	if(!arg) return notify_fail("��Ҫ����ʲô������\n");

	if(sscanf(arg, "%d %s", amount, item)==2) {
		if( !objectp(obj = present(item, me)) )
			return notify_fail("������û������������\n");
		if( no_drop=obj->query("no_drop") )
                        return notify_fail( stringp(no_drop) ? 
				no_drop : "���������������ⶪ����\n");
		if( !obj->query_amount() )
			return notify_fail( obj->name() + "���ܱ��ֿ�������\n");
		if( amount < 1 )
			return notify_fail("����������������һ����\n");
		if( amount > obj->query_amount() )
			return notify_fail("��û����ô���" + obj->name() + "��\n");
		else if( amount == (int)obj->query_amount() )
			return do_drop(me, obj);
		else {
			obj2 = new(base_name(obj));
			obj2->set_amount(amount);
			if(do_drop(me, obj2)) { // succeed to drop
			    obj->set_amount( (int)obj->query_amount()-amount );
			    return 1;
			}
			return 0;
		}
	}

	if(arg=="all") {
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++) {
			if (inv[i]->query("no_drop")) continue;
			do_drop(me, inv[i]);
		}
		write("Ok.\n");
		return 1;
	}

	if(!objectp(obj = present(arg, me)))
		return notify_fail("������û������������\n");
	if( no_drop=obj->query("no_drop") )
                return notify_fail( stringp(no_drop) ? 
			no_drop : "���������������ⶪ����\n");
	return do_drop(me, obj);
}

int do_drop(object me, object obj)
{
	if(me->is_busy())
	   return notify_fail("����æ���أ�����\n");
	   
	if( obj->query("no_drop") )
		return notify_fail("���������������ⶪ����\n");

	if (obj->move(environment(me))) {
	//d_mana>0 is for "bian". mon 11/05/97
	 if((obj->query_temp("d_mana"))>0) {
	  if( obj->query_temp("is_living")==1 )
            message_vision("$N��$n�ӱ��Ϸ������������ڵ��ϡ�\n", me, obj);
	  else {
	    message_vision( sprintf("$N����һ%s$n��\n",	
	      undefinedp(obj->query_temp("unit"))?
	      "��":obj->query_temp("unit")
	      ), me, obj );
	  }
        } else {
	  if( obj->is_character() )
            message_vision("$N��$n�ӱ��Ϸ������������ڵ��ϡ�\n", me, obj);
	  else {
	    message_vision( sprintf("$N����һ%s$n��\n",	obj->query("unit")),
		me, obj );
	    if( !obj->query("value") && !obj->value() ) {
	      tell_object(me,"��Ϊ������������ֵǮ���������ǲ�����ע�⵽���Ĵ��ڡ�\n");
	      destruct(obj);
	    }
	  }
        }
       return 1;
       }
       return 0;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : drop <��Ʒ����>
 
���ָ��������㶪������Я������Ʒ.
 
HELP
    );
    return 1;
}
 
