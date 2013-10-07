
//���Ͳ by hexiu

#include <ansi.h>
#include <weapon.h>

//inherit ITEM;

inherit MACE;

mapping default_dirs = ([
        "north":        "��",
        "south":        "��",
        "east":         "��",
        "west":         "��",
        "northup":      "����",
        "southup":      "�ϱ�",
        "eastup":       "����",
        "westup":       "����",
        "northdown":    "����",
        "southdown":    "�ϱ�",
        "eastdown":     "����",
        "westdown":     "����",
        "northeast":    "����",
        "northwest":    "����",
        "southeast":    "����",
        "southwest":    "����",
        "up":           "��",
        "down":         "��",
        "out":          "��",
        "enter":        "��",
]);

void create()
{
        set_name(HIC"���Ͳ"NOR, ({"rocket launcher","mace","launcher"}));
        set_weight(8000);
        if(clonep())
                set_default_object(__FILE__);
        else {
	set("long", "һ�߻��Ͳ���ƺ����Է���(fire)��\n�����Ѿ�װ��һö�����"+HIG"<������>��"NOR);
	set("orilong", "һ�߻��Ͳ���ƺ����Է���(fire)��");

        set("unit", "��");
        set("value", 100000);
        set("no_put",1);
        set("no_sell",1);
		set("rocket_in",1);
		set("dead",0);
		

        }
        init_mace(100);
        setup();
}


int query_autoload() { return 1; }


void init()
{                                             
	
	add_action("do_fire", "fire");
	add_action("do_install","install");
	//add_action("do_turnon", "turnon");
	//add_action("do_turnoff", "turnoff");
	//add_action("do_uninstall", "uninstall");

}



int do_fire(string arg)
{
	
	
    //mixed dest;
	string dir;
		string dest;
	object env, obj,srocket;
	mapping exit;

	if ( this_object()->query("rocket_in") == 0 )
         return notify_fail("��û��װ����\n");
	if (this_player()->query_temp("weapon") != this_object())
		return notify_fail("��û��װ�����������\n");


	if( !arg ) return notify_fail("��Ҫ���ĸ����򿪻�\n");
	env = environment(this_player());
	//if(!env) return notify_fail("������Ҳ�Ӳ���ȥ��\n");

	if( !mapp(exit = env->query("exits")) || !exit[arg] ||  undefinedp(exit[arg]) )
		return notify_fail("��������䲻��ȥ��\n");
     dest = exit[arg];

	//if (dest && objectp(dest))
	  //  obj = dest;
	//else if( !(obj = load_object(dest)) )
	  if( !(obj = load_object(dest)) )
	        return notify_fail("��Ҫ���������û����ͨ��\n");

	if( !undefinedp(default_dirs[arg]) )
		dir = default_dirs[arg];
	else
		dir = arg;
	srocket = new("/obj/toy/rocket");
    if (this_object()->query("dead")) srocket->set("dead",1);
	
	message_vision("$Nһ�۰����һö�������"+dir+"���˹�ȥ��\n",this_player());

	//this_object()->set("set_done",1);
	//srocket->set("no_get",1);
	srocket->move(obj);
	tell_object(environment(srocket),HIW"һö��������˹�����\n"NOR);
    srocket->bomb();
	this_object()->set("rocket_in",0);
    this_object()->set("long",this_object()->query("orilong"));
	//call_out("bomb",5,1);
	return 1;


}


int do_install(string arg)
{
   object me=this_object();
   object who=this_player();
   object crocket;
   string dead_arg;
   

   if( !arg)  return notify_fail("����װʲô��\n");

   crocket=present(arg, who);
   if (! present(arg, who)) 
		return notify_fail("������û���ⶫ����\n");
   if (crocket->query("name") == me->query("name") ) 
                return notify_fail("װ�Լ���\n");
   if (! crocket->query("is_rocket")) 
        	return notify_fail("������װ����ȥ��\n");
   if (who->is_busy()) return notify_fail("����æ���ء�\n");
   
   if (me->query("rocket_in"))
        	return notify_fail(me->query("name")+"�Ѿ�װ���ˡ�\n");
   
   //if (me->query("anqi/now") >0 && me->query("anqi/type") != aq->query("name") )
   //    	return notify_fail(me->query("name")+"����װ��ͬ����İ�����\n");
   //else  
     
     message_vision( "$N��һ"
		+crocket->query("unit")+crocket->query("name")+"װ��"+me->query("name")+"�\n",who);
     
     
	 if (crocket->query("dead")) me->set("dead",1);//dead_arg=HIR"<����>"NOR;
	 //else {dead_arg=HIG"<������>"NOR;}
     
        me->set("long",me->query("orilong")+"\n�����Ѿ�װ��һ" 
		
		+crocket->query("unit")+crocket->query("name")+"��\n");
		
		me->set("rocket_in",1);
     //who->start_busy(3);
     destruct(crocket);
       
     return 1;
     
  }


