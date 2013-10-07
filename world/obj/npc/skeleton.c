// cracked by vikee 2/09/2002   vikee@263.net
#include <ansi.h>

inherit NPC;

int reset_status();
void create()
{
	set_name("���ñ�", ({ "kulou bing","bing", "guard" }) );

	set("people", 1);
	set("long", "һ�߱�������������ŵ����á�\n");
	set("attitude", "heroism");

	set("max_gin", 300);
	set("max_kee", 300);
	set("max_sen", 300);

	set("max_mana", 100);
	set("mana", 100);
	set("max_force", 100);
	set("force", 100);

	set("str", 30);
	set("per", 100);
	set("looking", "ȫ��ֻ��һ���Ǽܣ����������ǿֲ���");

	set("combat_exp", 50000);
	set("daoxing", 50000);

	set_skill("blade", 20);
	set_skill("parry", 20);
	set_skill("dodge", 20);

	setup();

	
	carry_object("/d/obj/weapon/blade/blade")->wield();
}

void init()
{
	add_action("do_attack", "attack");
}

int do_attack(string arg)
{
	object obj, owner;

	if( (string)this_player()->query("id") != (string)this_object()->query("owner") )
		return notify_fail("���ñ�������������������Ը���㣡\n");

	if( !arg || !objectp(obj=present(arg,environment(this_player()))))
           return notify_fail("���������ñ�ȥ����˭��\n");

	if( !obj->is_character() )
                return notify_fail("�����һ�㣬�ǲ��������\n");

	if( userp(obj) )
		return notify_fail("���ñ�����ȥ������ҡ�\n");

	message_vision("$N������$n˵��Щʲô��\n", this_player(), this_object());
        message_vision("$N��$n������ȥ���ɣ�\n", this_object(), obj);

	command("kill "+obj->query("id"));
	return 1;
}

void invocation(object who)
{
	set_leader(who);
	command("protect " + who->query("id"));
	set("owner", who->query("id"));
	reset_status();
	return;
}

void die()
{
	message_vision("\n$N������ȥ����Ϊһ�ѿݹǡ�\n", this_object());
	destruct(this_object());
}

void unconcious()
{
	message_vision("\n$N������ȥ����Ϊһ�ѿݹǡ�\n", this_object());
        destruct(this_object());
}

int reset_status()
{
	object owner;
	int n;

	if(  !query("owner")
	|| !objectp(owner=present( query("owner"), environment(this_object()) )) ){
		message_vision("$N������ȥ����Ϊһ�ѿݹǡ�\n", this_object());
		destruct( this_object());
		return 1;
	}

	if( (int)this_object()->query("eff_kee") < (int)this_object()->query("eff_sen") ) {
		n=(int)this_object()->query("eff_kee")/200;
	} else {
		n=(int)this_object()->query("eff_sen")/200;
	}

	if( (int)this_object()->query("eff_kee") < 200
	|| (int)this_object()->query("eff_sen") < 200 ) {
		n=1;
	}

	set("people", n);
	set("combat_exp", 50000 + 30000 * n );
	set("combat_exp", 50000 + 30000 * n );
	set_skill("blade", 20 + 15 * n );
	set_skill("parry", 20 + 15 * n );
	set_skill("dodge", 20 + 15 * n );

	set("short", chinese_number(n)+"�����ñ�(Kulou bing)");
	set("long", chinese_number(n)+"�߱�������������ŵ����á�\n");
	call_out("reset_status", 3);
	return 1;
}
