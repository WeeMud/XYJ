
//��ʱը�� by hexiu

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
        set_name(HIG"��ʱը��<������>"NOR, ({"time bomb", "bomb"}));
        set_weight(10000);
        if(clonep())
                set_default_object(__FILE__);
        else {
	set("long", "һ��ը���������и���ʱ�����ƺ����Զ�ʱ��(settime)��\n
����һ�����ؿ����趨��λ��(turnoff:"HIG"������"NOR"/turnon:"HIR"����"NOR")\n");
        set("unit", "��");
        set("value", 0);
        set("no_put",1);
        set("no_sell",1);
		set("dead",0);
		set("set_done",0);
		

        }

        setup();
}



void bomb()
{
int damage,i,n,j,success;
string msg;
object *ob;
object env,obj;
mapping exit;
   string *dirs, target_dir, dest;



 env=environment( this_object() );
 ob = all_inventory( env );

if(!this_object()) return ;
tell_object(env,"һ�����죬ը����ը�ˣ�\n");

if (this_object()->query("dead")==0)  
{
      for(i=0; i<sizeof(ob); i++) 
		{
			if( !living(ob[i]) || ob[i]==this_object() || wizardp(ob[i])) continue;
	

                damage = 1;
                
                        ob[i]->receive_damage("sen", damage, this_object());
                        
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

					tell_object(environment(ob[i]),HIR"\nֻ��"+ob[i]->name()+"�������ݰ�ķ��˹�����\n" NOR);}

										}

					}

}
	  else{
		  for(i=0; i<sizeof(ob); i++) 
		{
			if( !living(ob[i]) || ob[i]==this_object() || wizardp(ob[i])) continue;
			if(userp(ob[i])) ob[i]->set_temp("death_msg", "��ը��ը���ˡ�\n");
			ob[i]->die();
	  
	  }

        }

 destruct(this_object());
 return ;
}



void init()
{                                             
	
	add_action("do_settime", "settime");
	add_action("do_turnon", "turnon");
	add_action("do_turnoff", "turnoff");
	//add_action("do_block","",1);

}



int do_settime(string arg)
{
	int timea,k,d;
	if ( this_object()->query("set_done")==1 )
         return notify_fail("�������ܣ�����\n");
	if( !arg
        ||      !sscanf(arg, "%d", timea) )
                return notify_fail("��Ҫ��ʱ���٣�\n");

	if( timea < 5)
		return notify_fail("����Լ������㹻��·��ʱ�䣡\n");
	if( timea > 60)
		return notify_fail("ը����������ô��ʱ�䣡\n");

	if (this_object()->move(environment( this_player() )))
	{	
		this_object()->set("no_get",1);
		this_object()->set("set_done",1);
	    tell_object(environment(this_player()),HIW"ĳ�˶���һ���ε���Ķ�����\n"NOR);

        for(k=timea-1;k>=1;k--)
		{
	    d=timea-k;
		call_out("show_time",k,d);
		}
		call_out("bomb",timea,1);
		return 1;
	}
//	destruct(this_object());}
}

int do_turnon()
{   if (!wizardp(this_player()) )
         return notify_fail("������ֻ����ʦ�������ã�\n");
    if ( this_object()->query("set_done")==1 )
         return notify_fail("�������ܣ�����\n");

	message_vision(HIW"$N��ը���ĵ�λ����"HIR"����"HIW"�ϡ�\n"NOR,this_player());
        this_object()->set("no_give",1);
	this_object()->set("dead",1);
	this_object()->set("name",HIR"��ʱը��<����>"NOR);
	return 1;
}

int do_turnoff()
{
	if ( this_object()->query("set_done")==1 )
         return notify_fail("�������ܣ�����\n");
	message_vision(HIW"$N��ը���ĵ�λ����"HIG"������"HIW"�ϡ�\n"NOR,this_player());
	this_object()->set("dead",0);
	this_object()->set("name",HIG"��ʱը��<������>"NOR);
	return 1;
}



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







