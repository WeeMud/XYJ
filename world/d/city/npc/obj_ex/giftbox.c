
// renshen-guo.c �˲ι�
// suppose to be able to be given and got,
// please let me know before changing...weiqi980417

#include <ansi.h>

inherit ITEM;
inherit F_UNIQUE;

int do_open(string);

void init()
{
	check_owner();
      if(this_player()==environment())
	add_action("do_open", "open");
	return ::init();
}

void create()
{
	set_name(HIW "��Ʒ��" NOR, ({"lipin box", "lipin", "box"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ��װ�ξ�������Ʒ��,������(open)��������\n");
		set("value", 0);
		set("drug_type", "��Ʒ");
                set("no_sell",1);
		set("no_drop",1);
		set("no_get",1);
		set("no_put",1);
		set("unique",1);
		set("no_give",1);
		set("time_available", 4);

	}
  
	set("is_monitored",1);
	setup();
}

int do_open(string arg)
{
	string msg;
	object me = this_player();
  
	if (!id(arg)) return notify_fail("��Ҫ��ʲô��\n");
	if (me->query("wizgift/newbiegift") > 1)
	{  
	   tell_object(me,"��Ϊʲô��ô̰����?\n");
	   destruct(this_object()); 
	   return 1;
	}
	me->set("wizgift/newbiegift",2);
	me->save();
// me->add("combat_exp",10000);
 me->add("combat_exp",50000);
//me->add("daoxing",10000);
me->add("daoxing",20000);
me->add("potential",50000);
	me->save();
	msg=HIY"$NС������ذѺ��Ӵ�����ͻȻ�������һƬ��⣬�ε�$N"+
		"�������ۡ�\n"NOR;
        message_vision(msg,me);
        write("��ĵ��У���ѧ��Ǳ�ܶ�������!\n");
        log_file("static/NEWBIEGIFTopen","["+ctime(time())+"] "+
	sprintf("%s(%s)����%O\n",
         this_player()->query("name"),this_player()->query("id"),
         this_object()));

	destruct(this_object());
	return 1;

}

