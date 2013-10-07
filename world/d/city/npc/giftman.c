// zaoshen.c

//inherit F_VENDOR_SALE;

#include <ansi.h>

inherit NPC_SAVE;

void create()
{
		reload(query_save_file());
        set_name("����ү", ({"zao wangye","wangye"}));
        set("title", "�ϳǿ�ջ");
        set("gender", "����" );
        set("age", 16);
        set("long", "һ�������������ֵ�����ү����������Ц��\n");
        set("combat_exp", 2000);
        set("attitude", "friendly");
        setup();
}
void init()
{
	//::init();
	add_action("do_yao","yao");
}

int do_yao(string arg)
{
	object m,mm,me;
	message_vision("$N��ƤЦ����������ү�ʵ�:���������ģ���û�м�����ѽ?\n", this_player());
	me=this_player();
	if ( me->query("wizgift/newbiegift") )
	{
		return notify_fail("����үһ���ۣ������ң�\n"); 
	}
//	if ( me->query("combat_exp") < 5000 )
//	 return notify_fail("����ү˵��: С�һ����㹦��������!\n");
//
	m=new("/d/city/npc/obj_ex/giftbox");
//        mm=new("/obj/money/thousand-cash");
	m->move(this_player());
//        mm->move(this_player());
	me->set("wizgift/newbiegift",1);
	log_file("static/NEWBIEGIFT","["+ctime(time())+"] "+sprintf("%s(%s)������ү���õ���%s(%s)\n",
		this_player()->query("name"),this_player()->query("id"),
		m->query("name"),m->query("id")));
	message_vision("����ү��$Nһ����Ʒ��.\n", this_player());
//        message_vision("����ү��$Nһ��һǧ������Ʊ\n",this_player()); 
	message_vision("����ү��$NЦ�����ú�����\n", this_player());
	return 1;
}

int accept_object(object who, object item)
{
	string code;
	string *base_char = ({
			 "a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"
			,"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"
			,"0","1","2","3","4","5","6","7","8","9","0","1","2","3","4","5","6","7","8","9"
		});
	int cnt_char, i, len_code;
	object npc = find_object("/d/city/npc/giftman");
	object me = this_player();
	if(base_name(item) == "/d/obj/drug/renshen-guo")
	{
		command("say ��λ" + RANK_D->query_respect(me) + "��Ȼ��λ�����ˣ�");
		command("say ����Ұﲻ�ϣ���������������û����ġ�");
		printf( "������� " + HIC +  "yqm" + NOR + " �鿴�ѻ���������б�\n");

		cnt_char = sizeof(base_char);
		code = "";

		for(len_code=8; ; len_code++)
		{
			for(i=0; i<len_code; i++)
			{
				code = code + base_char[random(cnt_char)];
			}

			if(!this_object()->query("yqm/#"+code))
				break;
		}

		this_object()->set("yqm/"+me->query("id")+"/"+code, "");
		this_object()->set("yqm/#"+code, me->query("id"));
		this_object()->save();
		return 1;
	}
	return 0;
}
