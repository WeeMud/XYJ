// cracked by vikee 2/09/2002   vikee@263.net
//puti.c
inherit NPC;
inherit F_MASTER;
string expell_me(object me);
void create()
{
       set_name("��������", ({"master yunyang", "master", "yunyang"}));
       set("long", "����������������ʦʵ�ǰ�ʦ���ѣ�Ҳ�����Ƕ������ܹܣ�
����׳��ʱ��ħ�����������˳ơ�С��ʦ����\n");
       set("gender", "����");
	set("title", "С��ʦ");
	set("class", "taoist");
       set("age", 70);
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "�ϵ���");
       set("per", 30);
	set("int", 30);
	set("str", 30);
	set("cps", 30);
       set("max_kee", 1100);
       set("max_gin", 1100);
       set("max_sen", 1100);
       set("force", 2300);
       set("max_force", 1200);
       set("force_factor", 80);
       set("max_mana", 1200);
       set("mana", 2300);
       set("mana_factor", 60);
       set("combat_exp", 800000);
	set("daoxing", 1500000);


        set("eff_dx", 250000);
        set("nkgain", 400);

       set_skill("literate", 90);
       set_skill("unarmed", 120);
       set_skill("dodge", 120);
       set_skill("parry", 120);
	set_skill("stick", 120);
	set_skill("spells", 120);
	set_skill("dao", 120);
	set_skill("puti-zhi", 120);
	set_skill("wuxiangforce", 120);
	set_skill("force", 120);
	set_skill("qianjun-bang", 120);
	set_skill("jindouyun", 120);
	map_skill("spells", "dao");
	map_skill("unarmed", "puti-zhi");
	map_skill("force", "wuxiangforce");
	map_skill("stick", "qianjun-bang");
	map_skill("parry", "qianjun-bang");
	map_skill("dodge", "jindouyun");
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
		(: cast_spell, "light" :),
                (: cast_spell, "dingshen" :),
                (: cast_spell, "thunder" :)
        }) );

        set("inquiry", ([
		"��ɽ": (: expell_me :),
		"leave": (: expell_me :),
]) );

create_family("����ɽ���Ƕ�", 1, "��");
setup();

        carry_object("/d/lingtai/obj/xiangpao")->wear();
        carry_object("/d/lingtai/obj/bang")->wield();
}

void attempt_apprentice(object ob)
{
	if ( (string)ob->query("family/family_name")=="����ɽ���Ƕ�") {
	if (((int)ob->query("daoxing") < 100000 )) {
	command("say ��������֮ʿ���صľ��ǵ��У�" + RANK_D->query_respect(ob) + "������Ŭ�����ǡ�\n");
	return;
	}
        command("smile");
	command("say �ü����ü���ʱ����ħ��������ֺ��С���"  + RANK_D->query_respect(ob) +
"����������֮ʿȴ���ټ���\n");
        command("say �ܺã�" + RANK_D->query_respect(ob) + "���Ŭ�������ձض��гɡ�\n");
       command("recruit " + ob->query("id") );
	return;
	}
	command("shake");
	command("say �Ϸ������ŵ��ӣ�" + RANK_D->query_respect(ob) + "������Ѱ���˰ɣ�\n");
        return;
}
string expell_me(object me)
{       me=this_player();
        if((string)me->query("family/family_name")=="����ɽ���Ƕ�") {
                command("say �����ִ����ɽ��Ϊʦȴ�м��仰˵��");
                me->set_temp("betray", 1);
		command("say �ҷ���ɽҲ���������ɣ��������ڡ����й�����ɽ��ɽ�棡");
                return ("����Ҫ��ɽ��ȴ����ɽ��ͷ������Ը��(agree)?");
        }
        return ("ƶ����֪��");
}
void init()
{
::init();
        add_action("do_agree", "agree");
}

int do_agree(string arg)
{
        if(this_player()->query_temp("betray")) {
                message_vision("$N���������Ը�⡣\n\n", this_player());
		this_player()->add("betray/count", 1);
		this_player()->add("betray/fangcun", 1);
                command("say �����ҷ���ɽ��ǳ�ݲ��������������ɽȥ�ɣ�");
this_player()->set("combat_exp", this_player()->query("combat_exp")*80/100);
this_player()->set("daoxing", this_player()->query("daoxing")*80/100);
		if( this_player()->query_skill("dao") )
		    this_player()->delete_skill("dao");
                this_player()->delete("family");
                this_player()->delete("class");
                this_player()->set("title", "��ͨ����");
		this_player()->save();
                command("say �����粨���ƶ����Σ�����Ϊ֮������\n");
                return 1;
                }
        return 0;
}
�
