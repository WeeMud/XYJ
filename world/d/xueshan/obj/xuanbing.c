// cracked by vikee 2/09/2002   vikee@263.net
inherit ITEM;

#include <ansi.h>

int do_make(string);

void create() 
  {
	seteuid(getuid());
   set_name("����",({"xuan bing"}));
        set ("long", @LONG
һ��������ð��˿˿��������֪�����ж��䡣
LONG);
   set_weight(10);
   set("unit","��");
   set("cook/allow",1);
   set("cook/value",5);
   set("cook/type","shui");
   setup();
  }

void init()
{                                             
      //  remove_call_out("do_melt");
    //    call_out("do_melt", 1);
	add_action("do_make", "make");
	add_action("do_make", "zuo");
//	add_action("do_chi", "chi");
//	add_action("do_chi", "eat");
//	add_action("do_add", "add");
//	add_action("do_add", "put");
}

int do_make(string arg)
{
	object ob, me;

	me = this_player();

	if( !arg || (arg != "blade" && arg != "dao" && arg != "sword" && arg != "jian" ) )
		return notify_fail("��Ҫ��ʲô��\n");
	if( arg == "sword" || arg =="jian" )
		return notify_fail("��Ƭ������ģ������˽���\n");

	if( (int)me->query("force") < 200 || (int)me->query_skill("ningxie-force", 1) < 20 )
	{
		message_vision("$N�������������ȥ���������ܿ�ͻ����ˡ�\n", me);
		destruct(this_object());
		return 1;
	}	

	ob=new("/d/obj/weapon/blade/xiceblade");
	ob->move(me);
	me->add("force", -100);
	message_vision("$N�������������ȥ����Ȼ������һ���������������\n", me);
	destruct(this_object());

	return 1;
}


