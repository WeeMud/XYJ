
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIW"����ĸ��<������>"NOR, ({ "carrier","aircraft carrier" }) );
        set_weight(1500000);
        set_max_encumbrance(1000000);
		set("no_get",1);
		set("value", 1000000);
        if( clonep() ) {
                object a,b,c,d,e;
                  seteuid(getuid());
                if(a=new("/obj/toy/fighter"))
                  a->move(this_object());

                  seteuid(getuid());
                if(d=new("/obj/toy/fighter"))
                  d->move(this_object());

                  seteuid(getuid());
		if(b=new("/obj/toy/fighter"))
		  b->move(this_object());

                  seteuid(getuid());
                if(e=new("/obj/toy/fighter"))
                  e->move(this_object());

                  seteuid(getuid());
		if(c=new("/obj/toy/fighter"))
		  c->move(this_object());
                set_default_object(__FILE__);
        } else {
                set("unit", "��");
                set("long", "����һ�Ҿ޴�ĺ���ĸ��������ͣ���˺ܶ�ɻ�������Գ�������Э��(xiezhu)\n");
					         
                set("value", 10000000);
        }
}

int is_container() { return 1; }

void init()
{                                             
	
	add_action("do_helpfire", "assist");
	add_action("do_helpfire", "xiezhu");

	
	//add_action("do_block","",1);

}

int do_helpfire()
{   
	object guai,me,obj,fighter;
    obj=this_object();
    me=this_player();

    if(me->query("mieyao/helpkill")==0)
		return notify_fail("����δ�ӵ�Э���㹥�������\n");

	guai = find_living(me->query("mieyao/ygid"));

	if(!living(guai) || me->query("mieyao/done"))
		return notify_fail("�����޷��������Ŀ�꣡\n");

	if(me->query("mieyao/helpkill") > 0 && living(guai))
	{
		message_vision("һ�������һ��ս�����Ӻ�ĸ������ˣ�\n",me);
		fighter=new("/obj/toy/fighter");
	   if(fighter->move(environment(guai)))
	   {
		tell_object(environment(guai),"һ�������һ��ս�������ƶ˸�����£�\n");
		tell_object(environment(guai),HIR"ս����һ�����ɨ�䣡\n"NOR);
		guai->die();
		me->add("mieyao/helpkill",-1);
		tell_object(environment(fighter),"ս����ҡ��ҡ��򣬷����ˣ�\n");
		destruct(fighter);
		return 1;

	   }
	   else
	   {
		   destruct(fighter);
		   return notify_fail("�����޷���ɹ�������\n");

	   
	   }

	}

	else return notify_fail("����Ŀǰ�޷���ɹ�������\n");

}