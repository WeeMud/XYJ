// cracked by vikee 2/09/2002   vikee@263.net
//sgzl 

#include <ansi.h>
inherit NPC;
void create()
{
        set_name("ħ���", ({ "tian wang", "guangmu tianwang", "hong", "tianwang" }) );
        set("gender", "����" );
	set("long",
		"ħ���Ľ�֮һ��ʹһ�˷��컭ꪣ�����һ��ɡ����Ի������Ԫɡ����\n"
                "ɡ�����鴩�ɣ�����ĸ�̣���ĸ�̣�ҹ���飬�ٳ��飬�ٻ��飬��ˮ\n"
                "�飬�����飬�����飬�����飬�����顣�������鴩�ɡ�װ��Ǭ����\n"
                "���֣����ɡ���ҳţ��ſ�ʱ���ذ��������޹⣬תһתǬ���ζ���\n"
	);
	set("age",50);
	set("title", "��Ŀ����");
	set("attitude", "heroism");
	set("str",40);
	set("int",30);
	set("max_kee",3100);
	set("kee",3100);
	set("max_sen",3100);
	set("sen",3100);
	set("combat_exp",4000000);
        set("daoxing",3500000);
	set("force",2500);
	set("max_force",1500);
	set("mana",2500);
	set("max_mana",1600);
	set("force_factor", 120);
	set("mana_factor",120);


        set("eff_dx", 3500000);
        set("nkgain", 800);

	
	set_skill("unarmed",180);
	set_skill("yingzhaogong", 180);
	set_skill("parry",180);
	set_skill("dodge",180);
	set_skill("spear",180);
	set_skill("bawang-qiang",180);
	set_skill("force",180);
	set_skill("spells", 180);
	set_skill("moshenbu", 180);
	map_skill("dodge", "moshenbu");
	map_skill("parry", "bawang-qiang");
	map_skill("spear","bawang-qiang");
	map_skill("unarmed", "yingzhaogong");
	set("inquiry", ([
		"name" : "���¹�Ŀ����ħ��죬��ʥ�Ͱ��ض����š�",
		"here" : "������Ƕ�����, ���ھ�������ˡ�",
	]) );

	setup();
	carry_object("/d/obj/weapon/spear/huaji")->wield();
	carry_object("/d/obj/armor/jinjia")->wear();
}


void kill_ob (object ob)
{
  object me = this_object();

  call_out ("san",5+random(5),me,ob);  
  ::kill_ob(ob);
}


void san (object me, object ob)
{
  object huobing;
  int damage;

  if (! me)
    return;

  if( !living(me) )
    return;

  if (! ob)
    return;

  if (environment(ob) != environment(me))
    return;

  message_vision (HIY"$N�ӻ��г����ħɡ���������˼��������ħɡ�����޵�������$n������\n"NOR,me,ob);

  if ( ((int)ob->query_skill("dodge", 1)+ random(100)) > 240 )
     message_vision (HIY"$N����Ծ����ħɡ������������һ����\n"NOR,ob);
  else 
    {
     message_vision (HIY"���$N����ס�����ж���\n"NOR,ob,me);
     ob->start_busy(10+random(10));
    } 

  remove_call_out ("san");  
  call_out ("san",random(15)+15,me,ob);  
}


void die ()
{
  object me = this_object();
  message_vision (HIY"$N�ŵ����Ⱦ��ܡ�\n"NOR,me);
  destruct (this_object());
  return ;
}

