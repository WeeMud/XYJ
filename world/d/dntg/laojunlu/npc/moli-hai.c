// cracked by vikee 2/09/2002   vikee@263.net
//sgzl 

#include <ansi.h>
inherit NPC;
void create()
{
        set_name("ħ��", ({ "tian wang", "duowen tianwang", "hai", "tianwang" }) );
        set("gender", "����" );
	set("long",
		"ħ���Ľ�֮һ��ʹһ��������������һ�����ã����������ң�Ҳ��\n"
                "�ء�ˮ���𡢷磬������������������������ƽ�һ�㡣\n"
	);
	set("age",50);
	set("title", "��������");
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
	set_skill("stick",180);
	set_skill("kusang-bang",180);
	set_skill("force",180);
	set_skill("spells", 180);
	set_skill("moshenbu", 180);
	map_skill("dodge", "moshenbu");
	map_skill("parry", "bawang-qiang");
	map_skill("spear","bawang-qiang");
	map_skill("unarmed", "yingzhaogong");
	set("inquiry", ([
		"name" : "���¶�������ħ�񺣣���ʥ�Ͱ��������š�",
		"here" : "�������������, ���ھ�������ˡ�",
	]) );

	setup();
	carry_object("/d/sea/obj/dragonstick")->wield();
	carry_object("/d/obj/armor/jinjia")->wear();
}


void kill_ob (object ob)
{
  object me = this_object();

  call_out ("pipa",5+random(5),me,ob);  
  ::kill_ob(ob);
}


void pipa (object me, object ob)
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

  message_vision (HIY"$N�ͳ��������ã�����ս������Ȼ�Եõĵ���������\n"NOR,me);

  if ( (ob->query("mana")+random(1000)) > 3000 )
     message_vision (HIY"$N������ţ���Ϊ������\n"NOR,ob);
  else 
    {
     message_vision (HIY"$N��������ħһ�����ٸ�ͷ�����ǣ�\n"NOR,ob);
     damage=(me->query("mana"))/5; 
     if ( ob->query("sen") < damage ) ob->unconcious();
     else ob->add("sen",-damage);
    } 

  remove_call_out ("pipa");  
  call_out ("pipa",random(15)+15,me,ob);  
}


void die ()
{
  object me = this_object();
  message_vision (HIY"$N�ŵ����Ⱦ��ܡ�\n"NOR,me);
  destruct (this_object());
  return ;
}


