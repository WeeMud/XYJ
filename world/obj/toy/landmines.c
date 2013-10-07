#include <ansi.h>
//inherit /obj/toy/bomb.c
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
        set_name(HIG"����<������>"NOR, ({"land mines", "landmines","mines"}));
        set_weight(10000);
        if(clonep())
                set_default_object(__FILE__);
        else {
	set("long", "һ�ų����ĵ��ף������и����أ��ƺ�����������ĳ��(sethere)��\n
����һ�����ؿ����趨��λ��(turnoff:"HIG"������"NOR"/turnon:"HIR"����"NOR")\n");
        set("unit", "��");
        set("value", 0);
        set("no_put",1);
        set("no_sell",1);
		set("dead",0);
		set("sethere",0);
		set("set_down",0);
		

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
tell_object(env,"һ�����죬���ױ�ը�ˣ�\n");

if (this_object()->query("dead")==0)  
{
      for(i=0; i<sizeof(ob); i++) 
		{
			if( !living(ob[i]) || ob[i]==this_object() || wizardp(ob[i])) continue;
	

                damage = 1;
                
                        ob[i]->receive_damage("sen", damage,this_object());
                        
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
			if(userp(ob[i])) ob[i]->set_temp("death_msg", "������ը���ˡ�\n");
			ob[i]->die();
	  
	  }

        }

 destruct(this_object());
 return 1;
}



void init( )
{       
	

	
    object ob=this_player();
	//::init();
//	if ( living(ob) && !wizardp(ob) && query("setb")==1 ) bomb(); 
	if ( living(ob) && query("sethere")==1 )  bomb(); 
	
	 add_action("do_sethere", "sethere");
   // add_action("do_block","",1);
	add_action("do_turnon", "turnon");
	add_action("do_turnoff", "turnoff");         
		// remove_call_out("greeting");
	                //call_out("greeting", 1, ob);
	
}


int do_turnon()
{   if (this_object()->query("set_done") == 1 )
         return notify_fail("�������ܣ�����\n");
	if (!wizardp(this_player()) )
         return notify_fail("������ֻ����ʦ�������ã�\n");
	message_vision(HIW"$N�ѵ��׵ĵ�λ����"HIR"����"HIW"�ϡ�\n"NOR,this_player());
        this_object()->set("no_give",1);
	this_object()->set("dead",1);
	this_object()->set("name",HIR"����<����>"NOR);
	return 1;
}

int do_turnoff()
{
	if (this_object()->query("set_done") == 1 )
         return notify_fail("�������ܣ�����\n");
	message_vision(HIW"$N�ѵ��׵ĵ�λ����"HIG"������"HIW"�ϡ�\n"NOR,this_player());
	this_object()->set("dead",0);
	this_object()->set("name",HIG"����<������>"NOR);
	return 1;
}

int do_sethere()
{
	if (this_object()->query("set_done") == 1 )
         return notify_fail("�������ܣ�����\n");
	if (this_object()->move(environment( this_player() )))
	{	
		this_object()->set("no_get",1);
		this_object()->set("set_done",1);

	tell_object(environment(this_player()),HIW"���׷�����ϣ�����ʮ�����뿪��\n"NOR);
	call_out("set_doing",10,1);
	}
	return 1;
}


void set_doing()
{
	if(this_object())  this_object()->set("sethere",1);
	return;
	
}



/*
int do_block(string arg)
{
  object me=this_object();
    object who=this_player();
    string verb=query_verb();
    int t;
    
    if(wizardp(who)) return 0;
   // if(me->is_fighting()) return 0;
if (me->query("setb")==1)
{
    if(verb!="go" &&
	    verb!="fly" &&
	    !(environment() && environment()->query("exits/" + verb)))
	return 0;

    if(who->query_temp("mieyao/allow_to_go")) {
	who->delete_temp("mieyao/allow_to_go");
	who->delete_temp("mieyao/leave_time");
	return 0;
    }
    t=who->query_temp("mieyao/leave_time");
    if(t>0 && time()>t) {
	who->delete_temp("mieyao/leave_time");
	//message_vision("$n��$Nһ����ע�⣬��æ���˹�ȥ��\n",me,who);
	return 0;
    }

    if(t==0) {
        t=time()+30+random(90);
        who->set_temp("mieyao/leave_time",t);
	//message_vision("$N�͵�����������$n��ǰ�������е���\n"+
	//	"          ��ɽ���ҿ������������ԣ�\n"+
	//	"          Ҫ���·����������·�ƣ�\n\n",me,who);
    } 
    
    tell_object(who,me->name()+"��������ˣ�\n");

    return 1;}
	
}
*/
