// cracked by vikee 2/09/2002   vikee@263.net
// natured.c

#define TIME_TICK (time()*60)

static int current_day_phase;
mapping *day_phase;

void auto_save(object *user, int size, int i);
mapping *query_day_phase() { return day_phase; }

int query_current_day_phase() { return current_day_phase; }

string *weather_msg = ({
	"�������������",
	"���䵭�����Ʋ�ױ�������ʵ����",
	"�����������Ʈ��Ʈȥ",
	"�����Ʋ�ѻ������",
	"����������ܲ�",
});

mapping *read_table(string file);
void init_day_phase();

void create()
{
	day_phase = read_table("/adm/etc/nature/day_phase");
	init_day_phase();
}

void init_day_phase()
{
	mixed *local;
	int i, t;

	// Get minutes of today.
//	local = localtime(TIME_TICK);
//	t = local[2] * 60 + local[1];		// hour * 60 + minutes

	t=time()%1440; // mon 7/22/99
	               // note currently a whole day is 24 min in real time
	               // 24*60=1440. change this number may break the
	               // syncronization between the day phase description
	               // and the "time" command.

	// Find the day phase for now.
	for( i=0; i < sizeof(day_phase); i++)
		if( t >= day_phase[i]["length"] )
			t -= (int)day_phase[i]["length"];
		else
			break;

	current_day_phase = (i==0? sizeof(day_phase)-1: i - 1);

	// Since in our time scale, 1 minute == 1 second in RL, so we don't need
	// any conversion before using this number as call_out dalay, if you 
	// changed the time scale, be sure to convert it.

	call_out("update_day_phase",
		(int)day_phase[(current_day_phase+1) % sizeof(day_phase)]["length"] - t);
}

void update_day_phase()
{
        int i=0;

	remove_call_out("update_day_phase");

	current_day_phase = (++current_day_phase) % sizeof(day_phase);
	
	// to re-syncronize with the local time.
	// mon 5/5/98
	if(current_day_phase==0) {
	    init_day_phase();
	    i=1;
	}
	
	if(current_day_phase==5) {
	    object *user=users();
	    remove_call_out("auto_save");
	    call_out("auto_save", 10, user, sizeof(user), 0);
	}

	message("outdoor:vision", day_phase[current_day_phase]["time_msg"] + "\n", users());
	if( !undefinedp(day_phase[current_day_phase]["event_fun"]) )
		call_other(this_object(), day_phase[current_day_phase]["event_fun"]);

	if(i==0)
	    call_out("update_day_phase", 
		    day_phase[current_day_phase]["length"]);
}

// mon 5/19/98
void auto_save(object *user, int size, int i)
{
    int j;
    
    for(j=i;j<i+5;j++) {
	if(j>=size) return;
	if(!user[j]) continue;
	if(!environment(user[j])) continue; // skip those still in login.
	if(user[j]->save())
	    tell_object(user[j], "�Զ��洢��ϡ�\n");
    }
    
    call_out("auto_save", 10, user, size, i+5);
}

// This is called everyday noon by update_day_phase, defined in the
// "event_fun" field in /adm/etc/nature/day_phase
void event_noon()
{
	object *ob;
	int i, skill;

	ob = users();
	for(i=0; i<sizeof(ob); i++) {
		if( !environment(ob[i]) ) continue;
		if( !environment(ob[i])->query("outdoors") ) continue;
		if( !ob[i]->query("mana") ) continue;
		if( !(skill = ob[i]->query_skill("spells", 1) )) {
			tell_object(ob[i], "�����һ����ѣ��������һ�����������ϱ��������ˡ�\n");
			ob[i]->set("mana", 0);
			ob[i]->receive_damage("sen", 0);
		} else if( skill < 25 ) {
			tell_object(ob[i], "����̫��������յ������룬�������ķ�����ʼ��ʧ�ˡ�\n");
			ob[i]->set("mana", (int)ob[i]->query("mana") * skill / 25 );
		}
	}
}

string outdoor_room_description()
{
	return "    " + day_phase[current_day_phase]["desc_msg"] + "��\n";
}

string game_time()
{
	return CHINESE_D->chinese_date(time());
	//return CHINESE_D->xyj_date();
}

// This function is to read a regular type of data table for day_phase and
// etc.
mapping *read_table(string file)
{
	string *line, *field, *format;
	mapping *data;
	int i, rn, fn;

	line = explode(read_file(file), "\n");
	data = ({});
	for(i=0; i<sizeof(line); i++) {
		if( line[i]=="" || line[i][0]=='#' ) continue;
		if( !pointerp(field) ) {
			field = explode( line[i], ":" );
			continue;
		}
		if( !pointerp(format) ) {
			format = explode( line[i], ":" );
			continue;
		}
		break;
	}

	for( rn = 0, fn = 0; i<sizeof(line); i++) {
		if( line[i]=="" || line[i][0]=='#' ) continue;
		if( !fn ) data += ({ allocate_mapping(sizeof(field)) });
		sscanf( line[i], format[fn], data[rn][field[fn]] );
		fn = (++fn) % sizeof(field);
		if( !fn ) ++rn;
	}
	return data;
}


