// cracked by vikee 2/09/2002   vikee@263.net
//xiwangmu.c
inherit NPC;
inherit F_MASTER;

void create()
{
       set_name("����ĸ", ({"xi wangmu", "xi", "wangmu","master"}));
       set("long", "����������������������������ء�\n");
       set("title", "�¹���ʦ");
       set("gender", "Ů��");
       set("age", 100);
       set("class","xian");
       set("attitude", "friendly");
       set("rank_info/respect", "��̫̫");
       set("cor", 30);
       set("per", 30);
	set("looking", "��ɫ����������̬��");
       set("max_kee", 4500);
       set("max_gin", 800);
       set("max_sen", 4500);
       set("force", 4000);
       set("max_force", 2000);
       set("force_factor", 125);
       set("max_mana", 2000);
       set("mana", 4000);
       set("mana_factor", 100);
       set("combat_exp", 2000000);
  set("daoxing", 5000000);

       set_skill("literate", 150);
       set_skill("unarmed", 180);
       set_skill("dodge", 180);
       set_skill("force", 180);
       set_skill("parry", 180);
       set_skill("sword", 200);
       set_skill("spells", 190);
	set_skill("moonshentong", 190);
	set_skill("baihua-zhang", 180);
	set_skill("moonforce", 180);
	set_skill("snowsword", 200);
	set_skill("moondance", 150);
	map_skill("spells", "moonshentong");
	map_skill("unarmed", "baihua-zhang");
	map_skill("force", "moonforce");
	map_skill("sword", "snowsword");
	map_skill("parry", "snowsword");
	map_skill("dodge", "moondance");
   set("inquiry",([
//    "pantao": (: ask_pantao :),
//    "���԰":(:ask_pantao:),
  ]));
	set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: cast_spell, "arrow" :),

               (: cast_spell,"mihun" :),
               (: cast_spell,"shiyue" :),
        }) );

create_family("�¹�", 1, "��");
setup();

        carry_object("/d/obj/cloth/tianyi.c")->wear();
        carry_object("/d/ourhome/obj/shoes")->wear();
}

void attempt_apprentice(object ob)
{
	if ( !((string)ob->query("gender")=="Ů��")){
	   command("shake");
    	   command("say �����¹�ֻ��Ůͽ����λ" + RANK_D->query_respect(ob) + "��������߾Ͱɡ�\n");
	   return;
	}

	if ( (string)ob->query("family/family_name")=="�¹�") {
    if ( (int)ob->query("combat_exp")+(int)ob->query("daoxing")<200000) {
	command("say " + RANK_D->query_respect(ob) +
"�ĵ��в��������Щ��ѧ�ط�������������\n");
	return;
	}
        command("pat "+ob->query("id"));
        command("say �ã�ϣ��" + RANK_D->query_respect(ob) +
"���Ŭ�����������¹�������\n");
       command("recruit " + ob->query("id") );
	return;
	}
	command("shake");
	command("say " + RANK_D->query_respect(ob) +
"������ȥѧЩ��������ɡ�\n");
        return;
}
int accept_fight(object me)
{
	return 0;
}
�
string ask_pantao() {return "ok.";}
string ask_pantao() {
    return " ";
} /*
  if (this_player()->query("dntg/pantao")=="done")
  {
    command("slogan "+this_player->query("id"));
    message_vision("$N�ݺݵص���$nһ�ۡ�\n",this_object(),this_player());
    return "����ȥ�����԰��û�Ŷ���";
  }
  if (this_player()->query_temp("dntg/pantao")=="doing")
    return "�����Ѿ�����ȥ����԰���𣿻���ʲô��";
  this_player()->set_temp("dntg/pantao","doing");
  return "OK.";
}
*/
