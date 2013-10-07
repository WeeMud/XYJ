// cracked by vikee 2/09/2002   vikee@263.net
// move.c

// 4/24/98 mon adds max_items related stuff.

#pragma optimize

#include <dbase.h>
#include <room.h>
#include <ansi.h>

static int weight = 0;
static int encumb = 0, max_encumb = 0;

varargs int _move(mixed dest, int silently);
void dest_obj(object obj);

// max_items is the maximum number of items an object can hold.
// note this is for non-character items.
// there is no limitations on # of characters. (limited by encumb)
// this is to prevent some rooms that full of items and
// players and npcs can't even enter. :P
static int max_items=10; // default max_items.
nomask void set_max_items(int e) {max_items=e;}
nomask int query_max_items() {return max_items;}

nomask int query_encumbrance() { return encumb; }
nomask int over_encumbranced() { return encumb > max_encumb; }

nomask int query_max_encumbrance() { return max_encumb; }
nomask void set_max_encumbrance(int e) { max_encumb = e; }
nomask void add_encumbrance(int w)
{
	encumb += w;
	if( encumb < 0 )
		log_file("move.bug", file_name(this_object())+
		this_object()->query("id")+
		" encumbrance underflow. env:"+file_name(environment())
		+" w:"+w+"\n");
//		log_file("move.bug", sprintf("%O encumbrance underflow.\n", this_object()));
	if( encumb > max_encumb ) this_object()->over_encumbrance();
	if( environment() ) environment()->add_encumbrance(w);
}

void over_encumbrance()
{
	if( !userp(this_object()) ) return;
	tell_object(this_object(), "��ĸ��ɹ����ˣ�\n");
}

nomask int query_weight() { return weight; }
nomask void set_weight(int w)
{
	if( !environment() ) {
		weight = w;
		return;
	}
	if( w!=weight ) environment()->add_encumbrance( w - weight );
	weight = w;
}


// This is the "current" weight of an object, which is used on weight
// checking in move().
nomask int weight() { return weight + encumb; }

string ride_suffix (object me)
{
  string ridemsg = 0;
  object ridee = 0;

  ridee = me->ride();
  if (ridee)
    ridemsg = ridee->query("ride/msg")+"��"+ridee->name()+"��";
  return ridemsg;
}

// silently=1: after move, no look.
// silently=2: when look, only show room name. (for follow command)
// silently=0: full look.
// mon 4/20/98
varargs int move(mixed dest, int silently)
{
    if(_move(dest, silently)) return 1;
    
    call_out("dest_obj", 2, this_object());
    return 0;
}

// destruct obj if it failed to move and has no environment.
void dest_obj(object obj)
{
    if(obj && !environment(obj))
	destruct(obj);
}

varargs int _move(mixed dest, int silently)
{
	object ob, env, *inv, me;
	int i;
	mapping exits;
	string str="", str1="", *dirs;
	string ridemsg="";
	me=this_object();

	// If we are equipped, unequip first.
	if( query("equipped") && !this_object()->unequip() )
		return notify_fail("��û�а취ȡ������������\n");

	// Find the destination ob for moving.
	if(dest && objectp(dest) )
		ob = dest;
	else if( stringp(dest) ) {
//		call_other(dest, "???");
// by mon 10/29/97. remove call_other, use load_object to find and load.
		ob=load_object(dest);
		if(!ob) 
		  return notify_fail("move: destination unavailable.\n");
	} else
		return notify_fail(sprintf("move: invalid destination %O.\n", dest));

	// check for max_items.
	if(!(me->is_character()) &&
		sizeof(all_inventory(ob))>=ob->query_max_items()) {
	    if(ob==this_player())
		return notify_fail("������װ���¸��ණ���ˡ�\n");
	    else if(userp(ob))
		return notify_fail(ob->name()+"����װ���¸��ණ���ˡ�\n");
	    else  { // for rooms and container.
		string name=ob->name();
		if(!name) name=ob->query("short");
		if(!name) name=ob->short();
		return notify_fail(name+"�Ѿ�̫ӵ���ˡ�\n");
	    }
	}

	// recursive check can't move sth into itself's belonging's
	// mon 9/1/98
	env = ob;
        if(env==this_object()) //mon 8/25/97
	    return notify_fail("�㲻�ܰ���Ʒ��������֮�С�\n");
	while(env=environment(env)) {
	    if(env==this_object()) 
		return notify_fail("�㲻�ܰ���Ʒ��������֮�С�\n");
	}

	// Check if the destination ob can hold this object.
	// Beforce checking it, we check if the destination is environment of
	// this_object() (or environment of its environment). If it is, then
	// this could be like get something from a bag carried by the player.
	// Since the player can carry the bag, we assume he can carry the this
	// object in the bag and encumbrance checking is unessessary.

	env = this_object();
	while(env = environment(env)) if( env==ob ) break;

	if( !env && (int)ob->query_encumbrance() + weight()
		> (int)ob->query_max_encumbrance() ) {
		if( ob==this_player() )
			return notify_fail( this_object()->name() + 
				"�������̫���ˡ�\n");
		else
			return notify_fail( this_object()->name() + 
				"��" + ob->name() + "����̫���ˡ�\n");
	}

	// Move the object and update encumbrance
	// by snowcat 3/10/1998
	if( env=environment() ) 
	{
	    // check whether env allow to move out.
	    // mon 8/9/99
	    mixed str2;
	    if(str2=(env->no_leave(this_object(),ob))) {
		if(base_name(ob)!=VOID_OB) { // allow move to void.
		  if(stringp(str2)) return notify_fail(str2);
		  else return 
		    notify_fail("һ�����ص����������赲ס�ˡ�\n");
		}
	    }

		env->add_encumbrance( - weight());
		if (userp(env) &&
    		    this_object()->value() >= 10000)
    		    	env->save();
	}
	ob->add_encumbrance(weight());

	//added by snowcat
	if (userp(ob) && this_object()->value() >= 1000000)
	{
	        object where1, where2;
	        string place_me = "ĳ";
	        string place_ob = "ĳ";

		where1 = environment();
	        if (where1)
	        	place_me = (where1->short()?where1->short():where1->query("short"))+"["+file_name(where1)+"]";
		where2 = environment(ob);
	        if (where2)
	        	place_ob = (where2->short()?where2->short():where2->query("short"))+"["+file_name(where2)+"]";
	        if (where1 != ob)
	        	MONITOR_D->report_system_object_msg (ob,"����"+place_ob+"����"+
	                   place_me+"���õ��˼�ֵΪ"+to_chinese(this_object()->value()/10000)+"gold�ľ޿");
	}

	move_object(ob);
        if(!this_object()) return 0;  //mon 8/24/97

	// If we are players, try look where we are.
	if( interactive(this_object())		// are we linkdead?
	&&	living(this_object())			// are we still concious?
	&&	silently!=1 ) 
	if (silently==2 || this_object() -> query("env/brief_all"))
		tell_object(this_object(), environment()->query("short") ? environment()->query("short")+"\n": "\n");
	else {
		str = sprintf( "%s - %s\n    %s%s",
			environment()->query("short") ? environment()->query("short"): "",
			wizardp(me)? file_name(environment()): "",
			( (!this_object() -> query("env/brief")) && (environment()->query("long")) ) ? environment()->query("long"): "",
			( (!this_object() -> query("env/brief")) && (environment()->query("outdoors")) ) ? NATURE_D->outdoor_room_description(): "");

        	if(! environment()->query("no_look") && mapp(exits = environment()->query("exits")) ) {
       	        	dirs = keys(exits);
               		for(i=0; i<sizeof(dirs); i++)
                        	if( (int)environment()->query_door(dirs[i], "status") & DOOR_CLOSED )
                                	dirs[i] = 0;
       			dirs -= ({ 0 });
               		if( sizeof(dirs)==0 )
                       		str += "    ����û���κ����Եĳ�·��\n";
               		else if( sizeof(dirs)==1 )
                       		str += "    ����Ψһ�ĳ����� " + BOLD + dirs[0] + NOR + "��\n";
               		else
                       		str += sprintf("    �������Եĳ����� " + BOLD + "%s" + NOR + " �� " + BOLD + "%s" + NOR + "��\n",
               		implode(dirs[0..sizeof(dirs)-2], "��"), dirs[sizeof(dirs)-1]);
       		}
       		inv = all_inventory(environment());
       		i=sizeof(inv);
		if (environment()->query("no_look"))
		    	i=0;
       		while(i--) {
               		if( !me->visible(inv[i]) ) continue;
               		if( inv[i]==me ) continue;
               		if (ridemsg = ride_suffix(inv[i]))
                       		str1 = "  " + inv[i]->short() + " <"+ridemsg +">\n"+str1;
               		else
                       		str1 = "  " + inv[i]->short() + "\n"+str1;
       		}
		tell_object(this_object(), str+str1);
	}

        // the following is made by snowcat on 6/20/1997
	// modified by mon 8/29/97
        if ((this_object()->query("is_monitored") ||
	     file_name(this_object())[0..2]=="/u/") 
	     && userp(ob))
        	MONITOR_D->report_system_object_msg (ob,"�õ���"+
        	  this_object()->query("name")
		  +"("+file_name(this_object())+")��");
	return 1;
}

void remove(string euid)
{
	object default_ob;

	if( !previous_object()
	||	base_name(previous_object()) != SIMUL_EFUN_OB )
		error("move: remove() can only be called by destruct() simul efun.\n");

	if( userp(this_object()) && euid!=ROOT_UID ) {
		log_file("destruct", sprintf("%s attempt to destruct user object %s (%s)\n",
			euid, this_object()->query("id"), ctime(time())));
		error("��(" + euid + ")���ܴݻ�������ʹ���ߡ�\n");
	} else if( this_object()->query("equipped")) {
		if(	!this_object()->unequip() )
			log_file("destruct", sprintf("Failed to unequip %s when destructed.\n",file_name(this_object())));
	}

	// We only care about our own weight here, since remove() is called once
	// on each destruct(), so our inventory (encumbrance) will be counted as
	// well.
	if( environment() )	environment()->add_encumbrance( - weight );
	if( default_ob = this_object()->query_default_object() )
		default_ob->add("no_clean_up", -1);
}

int move_or_destruct( object dest )
{
	if( userp(this_object()) ) {
		tell_object(this_object(), 
			"һ��ʱ�յ�Ť�����㴫�͵���һ���ط�������\n");
		move(VOID_OB);
	}
}

object ride ()
{
  object me = this_object();
  string ridemsg = "";
  object ridee;

  if (ridee = me->query_temp("ridee")) { 
    if ((environment(ridee) != environment(me) &&
         environment(ridee) != me) ||
        (ridee->is_character() && ! living(ridee))) {
      me->set_temp("ridee",0);
      ridee->set_temp("rider",0);
      ridee = 0;
    }
  }
  if (! ridee) {
    me->add_temp("apply/dodge",-me->query_temp("ride/dodge"));
    me->set_temp("ride/dodge",0);
  }
  return ridee;
}
