// cracked by vikee 2/09/2002   vikee@263.net
// �Ź�񫣬duguoyin.c 
// 5-3-97, pickle

inherit NPC;

void create()
{
  set_name("�Ź��", ({"du guoyin", "du", "guoyin", "duguoyin", "boss"})); 
  set("gender", "����" );
  set("age", 52);
  set("title", "�ĳ��ϰ�");
  set("long","����ͷ������һ�����У�ʱ��ʱ̧ͷ�����ĸ������ϵĶĿ͡�");
  set("combat_exp", 40000);
  set("daoxing", 20000);

  set_skill("dodge", 50);
  set_skill("parry", 50);
  set_skill("unarmed", 50);
  set_skill("literate", 70);
  set("attitude", "friendly");
  set("rank_info/respect", "�����");
  set("per",25);
  set("vendor_goods", ([
    "xiji": "/d/obj/books-nonskill/xiji",
    "fuji": "/d/obj/books-nonskill/fuji",
    "kunlun": "/d/obj/books-nonskill/kunlun",
    "san": "/d/obj/book/san",
    "blade-book" : "/d/obj/book/basic_blade",
    "unarmed-book": "/d/obj/book/basic_unarmed",
   ]));
  setup();
  carry_object("/d/obj/cloth/choupao")->wear();
}

void init()
{
  object ob;

  ::init();
  if( interactive(ob = this_player()) && !is_fighting() ) {
    remove_call_out("greeting");
    call_out("greeting", 1, ob);
  }
  add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
  if( !ob || !visible(ob) || environment(ob) != environment() ) return;
  command("say ��λ" + RANK_D->query_respect(ob) +"��������\n");
}

mixed buy_object (object who, object item)
{
  object npc = this_object();
  string st;

  st= "total"+(string)item;
  if (npc->query_temp("total_books") < 30)
      {
	if (npc->query_temp(st)<10)
	  {
	    npc->add_temp(st,1);
  	    return buy_object(who,item);
	  }
	else
	  {
	    return notify_fail("�׷���˵�����Բ�������Ҫ���������ˣ�������һ�������ɡ�\n");
	  }
	npc->add_temp("total_books", 1);
      }
      else
      {
	return notify_fail("�׷���˵����С�걾С�������Խ���������ˡ����ϵ���һ���ɡ�\n");
      }
    }
�