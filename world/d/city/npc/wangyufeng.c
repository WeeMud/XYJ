


inherit NPC;
#include <ansi.h>

void greeting(object me);

void create()
{
        set_name("���Ϸ�", ({"wang yufeng", "wang", "actor"}));
        set("long",@LONG
�й���������Ա����ҵ�ڱ�����ӰѧԺ����ϵ��������������
��׷�㴫�桷�������ھ֡��о��г�ɫ�ݼ�����Ϊ��MUD�����
���ˡ�
LONG);
        set("title", HIC"������Ӱ������"NOR);
		set("nickname",HIM"��MUD���������"NOR);
        set("gender", "����");
        set("age", 30);
        set("per",40);
        set("kee", 800); 
        set("max_kee", 800);
        set("sen", 200);
        set("max_sen", 200);
        set("combat_exp", 50000);
        set("attitude", "friendly");
        set("env/wimpy", 50);
        set("chat_chance", 3);
        set("chat_msg", ({
         "���Ϸ������Ц����ͷ�����ضԴ��˵������λ�������������Ѿã��һᣡ�һᣡ\n",
         "���Ϸ滷����һ�����ܣ���ȭ�Ͽҵص���������λ���֧�֣���\n",
         "���Ϸ�˫�ֱ�ȭ�����˸�Ҿ������λ�ɳ����ˣ�\n",
        }));

        set_skill("unarmed", 60);
        set_skill("parry", 60);
        set_skill("dodge", 60);

        setup();
        carry_object("/d/obj/cloth/choupao")->wear();
        add_money("gold", 1);
}

void init()
{
    call_out("greeting", 1, this_player());
    ::init();
}
void greeting(object who) {
  tell_object(who,"���Ϸ������ٷ磬�������Ρ�\n");
}

int accept_object(object who, object ob)
{
	int i;
	if (ob->query("equip_level"))
	{
		i=(int)ob->query("equip_level")+1;
		command("nod");
        command("say ��л��������Ϸ��");
		call_out("destroy", 1, ob);
		add_money("gold", i);
		command("give gold to " + who->query("id"));
		return 1;
	}
	return 0;
}

void destroy(object ob)
{
        destruct(ob);
        return;
}