// cracked by vikee 2/09/2002   vikee@263.net
// by snowcat

inherit NPC;

#include <reporting.h>

void create()
{
  set_name("��ï��", ({ "xu maogong", "xu", "maogong", "da chen" }));
  set("title", "��");
  set("gender", "����");
  set("age", 60);
  set("per", 30);
  set("combat_exp", 300000);
  set_skill("force", 80);
  set_skill("spells", 80);
  set_skill("unarmed", 80);
  set_skill("dodge", 80);
  set_skill("parry", 80);
  set("gin", 3000);
  set("max_gin", 3000);
  set("kee", 3000);
  set("max_kee", 3000);
  set("sen", 3000);
  set("max_sen", 3000);
  set("force", 1000);
  set("max_force", 1000);
  set("mana", 1000);
  set("max_mana", 1000);
  set("force_factor", 80);
  setup();
  carry_object("/d/obj/cloth/jinpao")->wear();
}

void reward (object who)
{
  object me = this_object ();
  int points = who->query_temp("quest/reward_point");
  string channel = "sldh";
  string *channels = who->query("channels");

  if ( !pointerp(channels) || !sizeof(channels) )
    channels = ({ channel });
  else if (member_array(channel, channels) == -1)
    channels += ({ channel });

  who->set("channels",channels);

  points=40+points*4;

  message_vision ("$N��$nһ�ݣ������б��´���ּ����"+RANK_D->query_respect(who)+
                  COMBAT_D->chinese_daoxing(points)+"���У�\n",me,who);
/*
  command (channel+" "+who->query("name")+who->query("quest/reason")+"������ּ����"+
           COMBAT_D->chinese_daoxing(points)+"���У�");
*/                  
  who->add("quest/gain/daoxing",points);
  reporting (who, who->query("quest/reason"), points, "�����");
  who->add("daoxing",points);
}

