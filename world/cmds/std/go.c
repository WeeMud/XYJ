// cracked by vikee 2/09/2002   vikee@263.net
// go.c

inherit F_CLEAN_UP;
#include "/cmds/std/valid_move.h";

mapping default_dirs = ([
	"north":		"��",
	"south":		"��",
	"east":			"��",
	"west":			"��",
	"northup":		"����",
	"southup":		"�ϱ�",
	"eastup":		"����",
	"westup":		"����",
	"northdown":	"����",
	"southdown":	"�ϱ�",
	"eastdown":		"����",
	"westdown":		"����",
	"northeast":	"����",
	"northwest":	"����",
	"southeast":	"����",
	"southwest":	"����",
	"up":			"��",
	"down":			"��",
	"out":			"��",
	"enter":		"��",
	"left": 		"��",
	"right":		"��",
]);

void create() { seteuid(getuid()); }

// follow will have silent=2, so as to reduce the CPU load.
int main(object me, string arg, int silent)
{
    	mixed dest;
	string ridemsg, mout, min, dir;
	object env, obj, ridee;
	mapping exit;
	int valid;

	if( !arg ) return notify_fail("��Ҫ���ĸ������ߣ�\n");

        if(!valid_move(me)) return 0;

	env = environment(me);
	if(!env) return notify_fail("������Ҳȥ���ˡ�\n");

	if( !mapp(exit = env->query("exits")) || !exit[arg] ||  undefinedp(exit[arg]) ) {
		if( query_verb()=="go")
			return notify_fail("�������û�г�·��\n");
		else
			return 0;
	}

	dest = exit[arg];

	if (dest && objectp(dest))
	    obj = dest;
	else if( !(obj = load_object(dest)) )
	        return notify_fail("��Ҫȥ������û����ͨ��\n");
	else if( !(obj = find_object(dest)) )
		return notify_fail("�޷��ƶ���\n");

	valid=(int)env->valid_leave(me, arg);
	if( !valid ) return 0;
	// valid>1 also indicates fail, but return 1 here, not 0.
	if(valid>1) return 1;

	if( !undefinedp(default_dirs[arg]) )
		dir = default_dirs[arg];
	else
		dir = arg;

        // snowcat 12/20/97
        if (ridee = me->ride())
          ridemsg = ridee->query("ride/msg")+"��"+ridee->name();
        else  
          ridemsg = "";

        if(ridee && !valid_move(ridee)) 
           return notify_fail("��������߶����ˡ�\n");

	if( me->is_fighting() ) {
		mout = ridemsg + "��" + dir + "��Ķ����ˡ�\n";
		min = ridemsg + "����ײײ�����˹�����ģ����Щ�Ǳ���\n";
	} else {
		//Jiz. 02/11
		if( ridee && ridee->query("bird") ) {
			mout = ridemsg+ "��" + dir + "��ȥ��\n";
			min = ridemsg+ "���˹�����\n";
		} else {
 		 	mout = ridemsg+ "��" + dir + "�뿪��\n";
			min = ridemsg+ "���˹�����\n";
		}
	}

	if( !wizardp(me) || !me->query("env/invisibility") )
	{
	    	if (environment(me) && environment(me)->query("no_look"))
		    	//message( "vision", "һ��ģ����Ӱ��" +  mout, environment(me), ({me}) );
		    	tell_room(environment(me),"һ��ģ����Ӱ��" +  mout, 
				({me}) );
		else
			//message( "vision", me->name() + mout, environment(me), ({me}) );
			tell_room(environment(me), me->name() + mout, 
			        ({me}) );
	}
	if( (! ridee || ridee->move(obj)) && me->move(obj, silent) ) {
		me->remove_all_enemy();
		if( !wizardp(me) || !me->query("env/invisibility") ) {
	    			if (environment(me) && environment(me)->query("no_look"))
		    			//message( "vision", "һ��ģ����Ӱ��" +  min, environment(me), ({me}) );
		    			tell_room(environment(me), 
						"һ��ģ����Ӱ��"+min,({me}) );
				else
					//message( "vision", me->name() + min, environment(me), ({me}) );
					tell_room(environment(me), me->name() 
						+ min, ({me}) );
		}
		me->set_temp("pending", 0);
		// added by snowcat, to fix the bug of recursive move of mutual follow + move to same room 
		if (env != obj)
			all_inventory(env)->follow_me(me, arg);
		if (ridee)
			tell_object (me,"��"+min);
		return 1;
	}

	return 0;
}

void do_flee(object me)
{
	mapping exits;
	string *directions;

	if( !environment(me) || !living(me) ) return;
	exits = environment(me)->query("exits");
	if( !mapp(exits) || !sizeof(exits) ) return;
	directions = keys(exits);
	if (environment(me) && environment(me)->query("no_flee")) return;
	tell_object(me, "�������һ��������ˣ�����\n");
        if( me->query_temp("no_move") ) {
          tell_object (me, "���㱻��ס�ˣ��Ӳ�����\n");
          return;
        }

	if( random(me->query_skill("dodge")/10 + me->query("kar")) < 10 ) {
	   tell_object(me, "������ʧ�ܡ�\n");
	   return;
	}

	main(me, directions[random(sizeof(directions))], 0);
}

int help(object me)
{
	write(@HELP
ָ���ʽ : go <����>
 
������ָ���ķ����ƶ���
 
HELP
    );
    return 1;
}
