// cracked by vikee 2/09/2002   vikee@263.net
// vote.c
// pickle 7-17-97
// dream 7/29/97

#include <ansi.h>
#include <mudlib.h>
#define SYNTAX  "ָ���ʽ��vote < open | close > <Ƶ��> <����> \n"

mapping votes_casted=([]), 
	voted_players=([]);
void nullify_vote(string myvariable, string choice, string username);
int determine_total();
int counting(mapping players, string my);
int age_limit=16, exp_limit=2000;
int max_voter, voter_site;
object *users;

void create() {
    // the following two are defined in /include/login.h
#ifdef MAX_VOTES_PER_SITE
    max_voter=MAX_VOTES_PER_SITE;
#else
    max_voter=2;
#endif
    
    voter_site=0;
#ifdef VOTER_SITE
    if(VOTER_SITE==1)
	voter_site=1;
#endif
}

int main(object me, string arg)
{
    string chan, *channels, choice, choicename;
    string myid, playerid, myname, playername;
    string myvariable;
    object player;
    int nullify_vote_time=1800, diff, i, chansize, chanmatch;
    int total_votes_required;
    mapping voted_player;
    string ip;
    int votes_count;
    int zige;
    
    zige = ( (int)me->query("daoxing") + (int)me->query("combat_exp") )/2;

    if( !arg || sscanf(arg, "%s %s %s", choice, chan, playerid)!=3 ) return notify_fail(SYNTAX);

    // conditions for voting: exp > exp_limit and age > age_limit
    if (me->query("age") < age_limit || zige < exp_limit) {
	if (me->query("age") < age_limit) return notify_fail("�����䲻��"+chinese_number(age_limit)+"��û��ͶƱȨ��\n");
	if (zige < exp_limit) return notify_fail("���ʸ񲻹���û��ͶƱȨ��\n");
	}

    // sytax errors.
    if (choice != "open" && choice != "close") return notify_fail(SYNTAX);
    choicename = (choice == "open"? "��":"�ر�");
    // channels available: chat (made this option for future ease, if we open
    // more chat channels, such as channels for each menpai, ...)
    channels=({"chat"});
    chansize=sizeof(channels);
    while (chansize--)
    {
        if (chan == channels[chansize])
        {
            chanmatch = 1; break;
        }
        continue;
    }
    if (!chanmatch) return notify_fail("����"+choicename+" "+chan+" ���Ƶ��������� help��\n");
    if (!player = find_player(playerid) ) 
	return notify_fail("Ŀǰ�Ҳ��� "+playerid+" ����ˡ�\n");

    if (!me->visible(player) ) 
	return notify_fail("Ŀǰ�Ҳ��� "+playerid+" ����ˡ�\n");

//    if (wizardp(player)) return notify_fail("Can't accuse wizard.\n");

    myvariable=choice+"_"+chan+"_"+playerid; // for checking double votes.
    myid=me->query("id");
    myname=me->query("name");
    playername=player->query("name");
    users=users();

    if( choice=="close" ) {
	if (player->query("channel/chat_block")>time())
		return notify_fail(playername+"�Ľ�̸Ƶ���Ѿ����ر��ˡ�\n");
	}
    else {
	if (player->query("channel/chat_block")<time())
		return notify_fail(playername+"�Ľ�̸Ƶ���Ѿ������ˡ�\n");
	}

    if (!undefinedp(voted_players[myvariable]))
	voted_player = (mapping)voted_players[myvariable];
    else
	voted_player = ([]);

    if (!undefinedp(voted_player[myid])) 
	return notify_fail("���Ѿ�Ͷ����ͬ��Ʊ�ˡ�\n");
    else {
	ip=query_ip_number(me);
	if(ip && voter_site==0)
	    ip=ip[0..strsrch(ip, ".", -1)];
	voted_player += ([myid: (["obj":me, 
		                  "ip":ip]) ]);
    }

    voted_players[myvariable] = voted_player;
    
    total_votes_required = determine_total();
    votes_count = counting(voted_player, myvariable);

        // remove vote in 5 min if not enough people respond
        if(undefinedp(votes_casted[myvariable]))
        {
            votes_casted+=([myvariable:1]);
	    call_out("nullify_vote", nullify_vote_time, 
		    myvariable, choicename, playername);
        }

        diff=total_votes_required-votes_count;

        // announce to mu
        if (diff>0)
	    message("vote", HIW"�������"+myname+"ͶƱ"+choicename+playername+
		    "������Ƶ������Ҫ" + chinese_number(total_votes_required)
		    + "Ʊͨ��������" + chinese_number(diff) +"Ʊ��\n"NOR, users);
        else
        {
	    if (choice=="open") player->set("channel/chat_block", time());
	    else player->set("channel/chat_block", time()+86400);
	    // block for 1 day.
	    map_delete(voted_players, myvariable);
	    map_delete(votes_casted, myvariable);
	    message("vote", HIW"�������"+myname+"ͶƱ"+choicename+playername+
		    "������Ƶ����"+playername+"�Ľ�̸Ƶ����"+choicename+"�ˣ�\n"NOR, users);
	}
    return 1;
}

int counting(mapping players, string myvariable) {
    int i=sizeof(players);
    int count=0;
    string *key;
    mapping site=([]);
    string ip;
    
    if(!i) return 0;
    key=keys(players);
    
    while(i--) {
	if(!players[key[i]]["obj"]) { // this player has logged out.
	    map_delete(players, key[i]);
	    continue;
	}
	
	if(!ip=players[key[i]]["ip"]) continue;
	
	if(undefinedp(site[ip])) {
	    site[ip]=1;
	} else {
	    site[ip]+=1;
	}

	// each site can count to max_voter.
	if(site[ip]<=max_voter) count++;
    }
    
    if(players)
      voted_players[myvariable] = players;
    else
      voted_players[myvariable] = ([]);

    return count;
}


int determine_total()
{
    int i, total_required;
    mapping site=([]);
    object *user=users();
    string ip;

    // to determine how many votes necessary to block channel

    i = sizeof(user);
    while (i--)
    {
        if (user[i]->query("age") > age_limit && 
		(user[i]->query("combat_exp")+user[i]->query("daoxing"))/2 > exp_limit ) {

	    if(!ip=query_ip_number(user[i])) continue;

	    if(ip && voter_site==0)
	      ip=ip[0..strsrch(ip, ".", -1)];

	    if(undefinedp(site[ip])) {
	      site[ip]=1;
	    } else {
	      site[ip]+=1;
	    }

	    if(site[ip]<=max_voter) total_required++;
	}
    }

    total_required=total_required/3;
    if (total_required < 3) total_required=3;
    if (total_required > 20) total_required=20;
    return total_required;
}

void nullify_vote(string myvariable, string choice, string username)
{
    if (!undefinedp(voted_players[myvariable])) {
        message("vote", HIW"���������Ϊû���㹻������Ӧ"+choice+username+
	  "�Ľ�̸Ƶ����ͶƱȡ���ˣ�\n"NOR, users);
        map_delete(voted_players, myvariable);
        map_delete(votes_casted, myvariable);
    }
}

int help()
{
    write(SYNTAX + @TEXT

ͶƱ�رջ��һ���˵Ľ�̸Ƶ����ֻ��ʮ�������ϵĳ��˹�����Ч��
�����������Ȩ�������⵷�ҵ��˻ᱻ����ʮ�˲������

�ر��Լ��򿪶���Ҫ��������Ʊ��������֮һ���ϵ�Ʊ����

ĿǰƵ�������� chat��

����vote close chat joeschmoe

TEXT
    );
    return 1;
}
