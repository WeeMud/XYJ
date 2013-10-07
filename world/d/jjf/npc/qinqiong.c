// cracked by vikee 2/09/2002   vikee@263.net

inherit NPC;
inherit F_MASTER;
string expell_me(object me);
void create()
{
  set_name("����", ({ "qin qiong", "qin", "shubao", "qiong", "qin shubao", "master", "shifu" }));
  set("title", "����Ԫѫ");
  set("gender", "����");
  set("age", 43);
  set("str", 30);
  set("per", 26);
  set("int", 30);
  set("cor", 50);
  set("cps", 50);
  set("long", "���屦�Ǵ��ƹ���������������һλ�������佫��\n");
  set("combat_exp", 1200000);
  set_skill("literate", 60);
  set_skill("spear", 120);
  set_skill("force", 120);
  set_skill("dodge", 180);
  set_skill("parry", 150);
  set_skill("mace", 200);
  set_skill("archery", 150);
  set_skill("wusi-mace", 180);
  set_skill("yanxing-steps", 150);
  set_skill("bawang-qiang", 100);
  set_skill("lengquan-force", 120);
  set_skill("unarmed", 160);
  set_skill("changquan", 120);
  map_skill("mace", "wusi-mace");
  map_skill("force", "lengquan-force");
  map_skill("unarmed", "changquan");
  map_skill("spear", "bawang-qiang");
  map_skill("parry", "bawang-qiang");
  map_skill("dodge", "yanxing-steps");
  set("max_sen", 2800);
  set("max_kee", 4400);
  set("force", 2000);
  set("max_force", 1800);
  set("force_factor", 80);
  set("inquiry", ([
		   "name": "�����������屦��",
		   "here": "������ǽ����������ѵ��㲻֪����",
		   "rumors": "���²��ڽ������ߺܾ��ˣ������ϵ��������¿ɲ�̫�����",
	   "תҵ": (: expell_me :),
	   "leave": (: expell_me :),
		   ]) );

  create_family("������", 2, "��");
  set("chat_chance_combat", 60);
  set("chat_msg_combat", ({
		(: perform_action, "spear", "qiangjian" :),
  }) );

  setup();
  carry_object("/d/obj/weapon/spear/yinqiang")->wield();
  carry_object("/d/obj/armor/tiejia")->wear();
  carry_object("/d/obj/weapon/mace/goldjian");
}

int accept_fight(object me)
{
  command("say �Ϸ��δ�ͽ����˶��ֹ����ˣ�����Ҳ����������\n");
  return 0;
}

int attempt_apprentice(object me)
{
  string myname=RANK_D->query_respect(me);
  if ((int)me->query("combat_exp")< 100000)
    {
      command("say ��λ"+myname+"������ȥ�������ҽ��������ɣ�");
      return 0;
    }
  command("haha");
  command("say �ܺã�ʱ����������֮�ʣ�"+myname+"���Ŭ�������ձض��гɡ�\n");
  command("recruit " + me->query("id") );
  return 1;
}
int recruit_apprentice(object ob)
{
  if( ::recruit_apprentice(ob) )
    ob->set("class", "fighter");
}
int prevent_learn(object me, string skill)
{
  string myname=RANK_D->query_respect(me);

  if (me->query("combat_exp") < 100000)
    {
      command("emote ������üͷ��˵����"+myname+"��Ƿ�������Ϸ�����"+myname+"����������⡣");
      return 1;
    }
  return 0;
}

string expell_me(object me)
{
  me=this_player();
  if((string)me->query("family/family_name")=="������")
    {
      me->set_temp("betray", 1);
      command("sigh");
      return ("���Ҵ����ɷ���ȴ���ܷ������Ը��(agree)��");
    }
  return ("ȥ����Ԭ�����ɣ�������֪����");
}
void init()
{
  add_action("do_agree", "agree");
}
int do_agree(string arg)
{
  if(this_player()->query_temp("betray"))
    {
      message_vision("$N���������Ը�⡣\n\n", this_player());
      command("say �����ȥ�ɣ������ն񣬺���Ϊ֮������");
      this_player()->add("betray/count", 1);
      this_player()->add("betray/jjf", 1);
      this_player()->set("combat_exp", this_player()->query("combat_exp")*80/100);
      this_player()->delete("family");
      this_player()->delete("class");
      this_player()->set("title", "��ͨ����");
      this_player()->set_temp("betray", 0);
      this_player()->save();
      return 1;
    }
  return 0;
}

