
//���� by hexiu

#include <ansi.h>
inherit ITEM;

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
        set_name(HIG"�����<������>"NOR, ({"rocket", "huojian dan","dan"}));
        set_weight(2000);
        if(clonep())
                set_default_object(__FILE__);
        else {
	set("long", "һ�Ż������
����һ�����ؿ����趨��λ��(turnoff:"HIG"������"NOR"/turnon:"HIR"����"NOR")\n");
        set("unit", "ö");
        set("value", 0);
        set("no_put",1);
        set("no_sell",1);
		set("is_rocket",1);
		set("dead",0);
		//set("set_done",0);
		

        }

        setup();
}



int bomb()
{
int damage,i,n,j,success;
string msg;
object *ob;
object env,obj;
mapping exit;
   string *dirs, target_dir, dest;



 env=environment( this_object() );
 ob = all_inventory( env );

if(!this_object()) return 1;


tell_object(env,"һ�����죬�������ը�ˣ�\n");

if (this_object()->query("dead")==0)  
{
      for(i=0; i<sizeof(ob); i++) 
		{
			if( !living(ob[i]) || ob[i]==this_object() || wizardp(ob[i])) continue;
	

                damage = 1;
                
                       ob[i]->receive_damage("sen", damage ,this_object());
                        
                        tell_object(ob[i], "�������ǰһ�������ð������ʹ������Ҫ�ѿ�һ����\n");
						COMBAT_D->report_sen_status(ob[i]);
			  
						msg = HIC "�޴�ĳ������"+ob[i]->name()+"ը��" NOR;
                        exit=env->query("exits");


 if( mapp(exit) && sizeof(env->query("exits")) != 0) {
				dirs=keys(exit);
				n=sizeof(exit);
				j=random(n);
				dest=exit[dirs[j]];
				if(!undefinedp(default_dirs[dirs[j]]))
					target_dir=default_dirs[dirs[j]];
				else
					target_dir=dirs[j]; 

				if( obj=load_object(dest)) {
					success=1;
					msg+= HIC "��" +target_dir+ NOR;
				}
msg += HIC "���˳�ȥ��\n\n" NOR;
			}

  
  if( success == 1){
    tell_object(env,msg);

				if( ob[i]->move(obj) ) {

					//tell_object(environment(ob[i]),HIR"\nֻ��"+ob[i]->name()+"�������ݰ�ķ��˹�����\n" NOR);}
				message_vision(HIR"\nֻ��$N�������ݰ�ķ��˹�����\n" NOR,ob[i]);}

										}

					}

}
	  else{
		  for(i=0; i<sizeof(ob); i++) 
		{
			if( !living(ob[i]) || ob[i]==this_object() || wizardp(ob[i])) continue;
			if(userp(ob[i])) ob[i]->set_temp("death_msg", "�������ը���ˡ�\n");
			ob[i]->die();
	  
	  }

        }

 destruct(this_object());
 return 1;
}



void init()
{                                             
	
	//add_action("do_throw", "throw");
	add_action("do_turnon", "turnon");
	add_action("do_turnoff", "turnoff");
	//add_action("do_block","",1);

}


/*
int do_throw(string arg)
{
	
	
    //mixed dest;
	string dir;
		string dest;
	object env, obj;
	mapping exit;

	if ( this_object()->query("set_done")==1 )
         return notify_fail("�������ܣ�����\n");

	if( !arg ) return notify_fail("��Ҫ���ĸ������ӣ�\n");
	env = environment(this_player());
	//if(!env) return notify_fail("������Ҳ�Ӳ���ȥ��\n");

	if( !mapp(exit = env->query("exits")) || !exit[arg] ||  undefinedp(exit[arg]) )
		return notify_fail("��������Ӳ���ȥ��\n");
     dest = exit[arg];

	//if (dest && objectp(dest))
	  //  obj = dest;
	//else if( !(obj = load_object(dest)) )
	  if( !(obj = load_object(dest)) )
	        return notify_fail("��Ҫ�ӵ�����û����ͨ��\n");

	if( !undefinedp(default_dirs[arg]) )
		dir = default_dirs[arg];
	else
		dir = arg;

	message_vision("$N�ͳ�һ����������������"+dir+"���˹�ȥ��\n",this_player());
	this_object()->set("set_done",1);
	this_object()->set("no_get",1);
	this_object()->move(obj);
	tell_object(environment(this_object()),HIW"һ��ð�̵Ķ��������˹�����\n"NOR);
	call_out("bomb",5,1);
	return 1;


}
*/
int do_turnon()
{   if (!wizardp(this_player()) )
         return notify_fail("������ֻ����ʦ�������ã�\n");
    //if ( this_object()->query("set_done")==1 )
      //   return notify_fail("�������ܣ�����\n");
		 

	message_vision(HIW"$N�ѻ�����ĵ�λ����"HIR"����"HIW"�ϡ�\n"NOR,this_player());
        this_object()->set("no_give",1);
	this_object()->set("dead",1);
	this_object()->set("name",HIR"�����<����>"NOR);
	return 1;
}

int do_turnoff()
{
	//if ( this_object()->query("set_done")==1 )
      //   return notify_fail("�������ܣ�����\n");

	message_vision(HIW"$N�ѻ�����ĵ�λ����"HIG"������"HIW"�ϡ�\n"NOR,this_player());
	this_object()->set("dead",0);
	this_object()->set("name",HIG"�����<������>"NOR);
	return 1;
}


/*
void show_time(int d)
{
	if(!this_object()) return ;
	if( d<=3 ) 
	{
		tell_object(environment( this_object() ),HIR"\n"+chinese_number(d)+"\n�εεΣ�����\n"NOR);
		return;}
	else
	{

    tell_object(environment( this_object() ),HIY"\n"+chinese_number(d)+"\n"NOR);
	return;}
}

*/





