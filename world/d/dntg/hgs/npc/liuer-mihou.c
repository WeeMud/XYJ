// cracked by vikee 2/09/2002   vikee@263.net
//liuer-mihou.c weiqi...98/05/13

#include <ansi.h>
#define MAX_TRY 20
#define MAX_TRY1 200
inherit NPC;

void set_skills();
void finished();
void killed_enemy(object victim);
string do_accuse(string tar);

void create()
{
	set_name("����⨺�", ({"liuer mihou", "liuer", "mihou"}));
	set("title", "��ͨ��");
	set("gender", "����" );
	set("age", 35);
	set("per", 14);
	set("str", 30);
	set("long", "����⨺����������Ԫ�������£�ѧ��һ��ñ��졣\n�������Ծ�����Ԫ���ɲ���ˣ��㿪ʼ������������\n��Ȼȥ��԰͵���˲ι�������ǹ���û���ŷ�������Ԫ���ɴ�ס��\nʹ�ӳ�����������ǽ��\n");
	set("class", "xian");
	set("attitude", "peaceful");
	//create_family("��ׯ��", 2, "����");
	set("rank_info/respect", "��ү");

	set_skills();

	set("spell_qiankun_on", 1); //to use cast qiankun, must set this.
	
	set("chat_chance", 2);
	set("chat_msg", ({ 
		(: random_move :)
		}));

	set("chat_chance_combat", 60);
	set("chat_msg_combat", 
	({
		(: cast_spell, "zhenhuo" :),
	}) );

	set("inquiry", ([
		"name": "�����ʥ�������Ҳ��\n",
		"here": "������\n",
		"�˲ι�": "��ү����ϲ���ľ����˲ι���\n",
		"ɱ��": "ɱ�ˣ�ֻҪ�����˲ι���ʲô����������\n",
		"�ؾ�": "�ؾ���ֻҪ�����˲ι���ʲô����������\n",
		"⨺��ּ�": "�ּǣ�ֻҪ�����˲ι���ʲô����������\n",
	]) );

	setup();
	carry_object("/d/obj/cloth/xianpao")->wear();
	carry_object("/d/obj/weapon/hammer/tongchui")->wield();
}

void set_skills()
{
	set("combat_exp", 1800000);
  set("daoxing", 4000000);

	set_skill("unarmed", 260);
	set_skill("wuxing-quan", 260);
	set_skill("dodge", 260);
	set_skill("baguazhen", 260);
	set_skill("parry", 260);
	set_skill("hammer", 260);
	set_skill("kaishan-chui", 260);
	set_skill("force", 260);   
	set_skill("zhenyuan-force", 260);
	set_skill("literate", 260);
	set_skill("spells", 260);
	set_skill("taiyi", 260);
	map_skill("spells", "taiyi");
	map_skill("force", "zhenyuan-force");
	map_skill("unarmed", "wuxing-quan");
	map_skill("dodge", "baguazhen");
	map_skill("hammer", "kaishan-chui");

	set("max_kee", 3500);
	set("max_sen", 3500);
	set("force", 5000);
	set("max_force", 2500);
	set("mana", 6000);
	set("max_mana", 3000);	
	set("force_factor", 200);
	set("mana_factor", 250);
}

void init()
{
    if(this_player()==query_leader()) kill_ob(this_player());

//    remove_call_out("to_say");
//    call_out("to_say", 1);
    
    add_action("do_get","get");
}

int do_get(string arg)
{
    object who=this_player();
    object tar=query_leader();
    object obj;
    
    if(!tar || !who) return 0;
    if(!(obj=present(arg, environment(this_object())))) return 0;
    
    if(obj==tar) {
	message_vision("$N��$nһ���ۣ���ү��Ƥ����Ҳ�Ҿ��ˣ�\n",
		this_object(), who);
	return 1;
    }
    return 0;
}

void to_say()
{

    if(is_fighting() || this_object()->is_busy()) return;

        if(random(10)==0) { message_vision(
	 "$N����˵������λ���ɱ��Խ�������ɸ���˵��(whisper liuer PKer_id)��"
	   + "\n���������򱨲�ƽ��\n",this_object());
	}
}

// this function is called from combatd.c
// after this_object() killed a victim.
void killed_enemy(object victim)
{
    if (victim!=query_leader()) return;
    
    // ok, now killed the target.
    finished();
}

void finished()
{
		command("bian");
		delete_temp("I_am_busy");
		delete_temp("kill_count");
		delete_temp("kill_count1");
		remove_call_out ("try_kill");
		remove_call_out ("check_finish");
		
		set_skills(); // set back skills.
		this_object()->move("/d/4world/houshan3");
}

string do_accuse(string tar)
{
    object me=this_object();
    object target;
    object env;
    int no_pk;

    if(!tar) return 0;
    target=find_player(tar);

    if((int)this_player()->query_condition("no_pk_time")>0)
        return "�ߣ���Ҳ�䣿��\n";
    if(!target || !interactive(target) ||wizardp(target))
        return "�Ҳ�������ˡ�\n";
//    if(wizardp(target)) return 0;
    
    no_pk=(int)target->query_condition("no_pk_time");
    if(!no_pk) return "�����������޹��أ���\n";
    if(no_pk<250)
        return "������δ�����ӯ���ҷ���ȥ�ɣ�\n";
    env=environment(target);
    if(!env || env->query("no_fight"))
        return target->name()+"���ڶ������ˣ���Ҳ�˲���������\n";

    set_temp("kill_count", 1);
    set_temp("kill_count1", MAX_TRY1);
	    
    remove_call_out ("try_kill");
    call_out ("try_kill", 2, tar);
    call_out ("check_finish", 3, tar);

    return "�ã���;�������ɣ�\n";
}

// mon 8/8/98
// If someone else trying to help to kill mihou, and he is stronger,
// then mihou will become stronger too.
void kill_ob(object ob)
{
    object me=this_object();
    int dx;
    
    if(!ob) return;
    dx=ob->query("combat_exp");
    
    if(dx>(me->query("combat_exp"))) me->set("combat_exp", dx*2);
    
    ::kill_ob(ob);
}

int accept_object(object me, object ob)
{
	object book;

	if ( (string)ob->query("id") != "renshen guo" ) {
		message_vision("����⨺�����е���ȥ��ȥ��ȥ����Һ�үû�����㣡\n", me);
		command("kick " + me->query("id"));
		//call_out("do_drop", 2, ob);
		return 1;
	}

	else {
		command("jump ");
		command("say ��λ" + RANK_D->query_respect(me) + "��Ȼ��ʹ���ˣ�\n");
		//first give a book...
		book = new("/d/obj/book/mihou-book");
		book->move(me);
		message_vision("$N��$n�����Ǻ�ү��Ҳ����С����˵�յݸ�$nһ��С���ӡ�\n", this_object(), me);

		//then promise a kill...
		command("whisper " + me->query("id")+
			" �����Ȿ���⣬����Ұﲻ�ϣ���ɱ������û����ġ�"+
			"\n��Ҫɱ�˵Ļ������ɸ���˵��"+
			"(whisper liuer enemy_id)��\n");
		me->set_temp("rsg_given", 1);
       		return 1;
	}
}

void do_drop(object ob)
{
	command("drop "+ob->query("id"));
}

void relay_whisper(object me, string msg)
{
	object target, where;

	if( query_temp("I_am_busy") == 1 )
	{
		message_vision((string)this_object()->query("name") 
			+ "��$N������������æ�ţ���Ȼ������ɡ�\n", me);
		return;
	}

	if (me->query_temp("rsg_given") != 1)
	{
//	    string result=do_accuse(msg);
	    
//	    if(result) write(result);
//	    else
		message_vision((string)this_object()->query("name") + 
			"����$N����ؿ���һ�ۡ�\n", me);
	    return;
	}
	
	target = find_player(msg);
	if( !target )
	{ 
		message_vision((string)this_object()->query("name") 
			+ "��$N˵���������Ҳ�������ˡ�\n", me);
		return;
	}

	where = environment(target);
	if( !where )
	{ 
		message_vision((string)this_object()->query("name") 
			+ "��$N˵������������У����Ƕ������ˡ�\n", me);
		return;
	}

	//now got the target player...
	message_vision((string)this_object()->query("name") 
		+ "��$N˵�����ã���;�������ɣ�\n", me);

	me->delete_temp("rsg_given");
	set_temp("I_am_busy", 1);
	set_temp("kill_count", MAX_TRY);
        set_temp("kill_count1", MAX_TRY1);

	remove_call_out ("try_kill");
	call_out ("try_kill", 2, msg);
	call_out ("check_finish", 3, msg);
	//note, here we still use target id for future trying...
}

void check_finish(string target_id)
{
	object target;

	//here alway set fali back, since liuer mihou is in a "bian" status...
	if( (int)this_object()->query("mana") < (int)this_object()->query("max_mana") )
		this_object()->set("mana", 2*(int)this_object()->query("max_mana"));
	
	add_temp("kill_count1",-1);
	if(query_temp("kill_count1")<0) {
	    finished();
	    return;
	}

	target = find_player(target_id);
	if( !target )
	{
	    command("bian");
		remove_call_out ("check_finish");
		call_out ("check_finish", 3, target_id);//try every 3 second.
		return; 
	}

	if( target->is_ghost() )
	{//means the target is dead.
	    finished();
	    return;
	}
	else
	{
	    object env1, env=environment(target);
	    
	    if(env!=environment() &&
		    !env->query("no_fight")) {
		if(env->is_character()) { //someone picked up.
		    env1=environment(env);
		    if(env1!=environment()) {
		       this_object()->move(env1);
		       message_vision("$N���˹�����\n", this_object());
		    }
		    kill_ob(env);
		} else {
		  this_object()->move(env);
		  message_vision("$N���˹�����\n", this_object());
		  kill_ob(target);
		}
	    } 

		remove_call_out ("check_finish");
		call_out ("check_finish", 3, target_id);//try every 3 second.
		return; 
	}
}

void  try_kill(string target_id)
{
	object target, where;

	if( (int)query_temp("kill_count") <= 0 )
	{//tried too long
	    finished();
	    return;
	}

	target = find_player(target_id);
	if( !target )
	{
		remove_call_out ("try_kill");
		call_out ("try_kill", 930, target_id);//try every 15 minutes.
		return; 
	}

	where = environment(target);
	if( !where ||
		where->query("no_fight")) // mon added check no_fight
	{
		remove_call_out ("try_kill");
		call_out ("try_kill", 890, target_id);//try every 15 minutes.
		return; 
	}

	//now kill...
	command("bian");
	if( where != environment(this_object()) )
	{
		this_object()->move(where);
		message_vision(YEL "ֻ����������һβ�ֹ��$Nһ������˳�����\n" NOR, this_object());
	}
	message_vision(RED "$Nץ�������ض�$n����˵�������������Ƕ��ݹֺ�ү���顣����Ҫ�����˲ι���һ��������ɱ�ˡ�\n" NOR, this_object(), target);

	// check whether copy data. -- mon 8/6/98
	// always   copy data. -- mon 8/18/98
//	if(target->query("combat_exp")>1000000) 
	{
	    object qm=new("/d/changan/npc/qianmian.c");
	    if(qm) {
		mapping skill=target->query_skills();
		int i=sizeof(skill);
		int *level, max_level;
		
		if(i>0) {
		    level=values(skill);
		    max_level=level[0];
		    while(i--) { // find out victim's maximum level
			if(level[i]>max_level)
			    max_level=level[i];
		    }
		    if( (int)query_temp("kill_count")<2)
		      max_level=max_level*22/20;
		    else
		      max_level=max_level*18/20;
		} else max_level=200;

		if( (int)query_temp("kill_count")<2)
		  qm->copy_status(this_object(), target, 25); // tobe 125% strong.
		else
		  qm->copy_status(this_object(), target, 20); // tobe 100% strong.
		destruct(qm);
		// mihou will use the following skills, so set to max.
	        set_skill("hammer", max_level);
	        set_skill("kaishan-chui", max_level);
	        set_skill("taiyi", max_level);
		map_skill("hammer", "kaishan-chui");
	        map_skill("spells", "taiyi");
	    }
	} 
//	else set_skills(); // set back skills.

	if( (int)query_temp("kill_count")<2) {
	  set("force_factor", query_skill("force")/2);
	  set("mana_factor", query("max_mana")/20+1);
	}

//	if( (int)query_temp("kill_count") == MAX_TRY ) 
//	{//first time, always need to initialize kill...
		command("bian " + target_id);
//	}

	        this_object()->set_leader(target); // follow.
		this_object()->kill_ob(target);    // kill
		target->kill_ob(this_object());
		
		// no problem here. kill_ob also check no_fight.
		// - mon 8/6/98
		//need consider this carefully, is it ok to make safe place unsafe?
	    
		//command("kill " + target_id);
		//command("bian " + target_id);
//	}
//	else command("kill " + target_id);
	//problem here, if kill_ob(), may bypass no_fight, ...etc;
	//if kill command, may confuse with NPC of the same name?
//	command("follow "+target_id);

	add_temp("kill_count", -1);

	remove_call_out ("try_kill");
	call_out ("try_kill", 837, target_id);//try every 15 minutes.
}


void unconcious()
{
    die();
}

void die()
{
    message_vision("$N���ˡ�\n", this_object());
    set("gin", 1000);  set("eff_gin", 1000);
    set("kee", 1000);  set("eff_kee", 1000);
    set("sen", 1000);  set("eff_sen", 1000);
    finished();
    this_object()->move("/d/city/kezhan");
}
