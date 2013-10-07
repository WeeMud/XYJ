// zong guan vikee.c
// created by vikee 2000.11

#include <ansi.h>

inherit NPC;

void create()
{
        set_name(""HIC"���"NOR"", ({"zong guan", "null"}));
        set("long", "���Ƿ���װ�����ܹܿ��,�����(list)�鿴��Ҫ�Ķ�����\n");
	set("gender", "����");
	set("age", 20);
	set("per", 40);
        set("title",""HIG"���μ�װ���ܹ�"NOR);
	set_skill("literate", 141);
	set("chat_chance",5);
    set("chat_msg", ({
        "������������㣺�������listָ���г���Ҫ�Ķ�����\n",
        "������������㣺�������yaoָ�����ܹ�����ȡװ����\n",
        "����������˵���Ҿ����ܹܣ��ܹܾ����ң�\n",               
        }));
	setup();
	carry_object("/d/obj/cloth/magua")->wear();
}

void init()
{
	::init();
  add_action("do_fight", "fight");
  add_action("do_kill", "kill");
  add_action("do_steal", "steal");
  add_action("do_cast", "cast");
  add_action("do_ji","ji");
  add_action("do_throw","throw");
  add_action("do_list","list");
  add_action("do_yao","yao");
}

void die()
{
 return;
}

int do_fight(string arg)
{
  object who = this_player();
  object me = this_object();

  if (arg && present(arg,environment(who))==me)
  {
	message_vision("$N���������ܣ���һҶ֪����к���,����$N���֡�\n",who,me);
     return 1;
  }
  return 0;
}

int do_kill(string arg)
{
  object who = this_player();
  object me = this_object();

  if (arg && present(arg,environment(who))==me)
  {
message_vision("$N��������ɱ��һҶ֪���һҶ֪�����Ļ���,û��$Nһ���ʶ��\n",who,me);

    return 1;
  }
  return 0;
}

int do_cast(string arg)
{
  object who = this_player();
  object me = this_object();

  message_vision("$N����һҶ֪����Ͱ͵����˼�������Լ����о��������ˡ�\n",who,me);

  return 1;
}


int do_steal(string arg)
{
  object who = this_player();
  object me = this_object();

  message_vision("$N��͵������������������û������\n",who,me);

  return 1;
}


int do_ji(string arg)
{
  object who = this_player();
  object me = this_object();

  message_vision("$N���һҶ֪���������ǰ˼���룬����û�ҡ�\n",who,me);

  return 1;
}

int do_throw(string arg)
{
  object who = this_player();
  object me = this_object();

  message_vision("$N�ͳ����������˿�һҶ֪����Ĳ��㣬�ְѰ�������������\n",who,me);

  return 1;
}

int do_list(string arg)
{
	object who = this_player();
	object me = this_object();
  message("vision",""HIG"\n��������������������������������������������������������������������������
          \n"HIY"���ף�"HIC"
          1.���(armor)      2. ����(pifeng)    3.����(shield)
          4.����(kui)        5. ս��(cloth)     6.̤��ѥ(shoes)
          7.��ʦ����(bonnet)
          \n"HIY"������"HIC" 
           1.��ħ��(stick)    2.��罣(sword)    3.������(whip)
           4.��(blade)      5.����צ(zhua)     6.��ͭ����(staff)
           7.������(axe)      8.������(fork)     9.÷����(hammer)
          10.���ǹ(spear)   11.�����(qin)     12 ��β�� (mace)
          13.��ͷ����(guai)  14.��ɳ(sha)
"HIG"\n��������������������������������������������������������������������������\n"NOR"",who,me);

  return 1;
}

int do_yao(string arg)
{
	string type;
	object ob;
	object who=this_player();
	object me=this_object();
/*
	if (who->query("combat_exp")>500000)
		return notify_fail("ƾ���Ĺ��򣬻����Լ�ȥ��װ����! :P\n");
*/
    if (!arg)
		return notify_fail("����Ҫʲô�����������ǿ��ף�(����:yao sword)\n");
	else 
	{
		sscanf(arg,"%s",type);
			switch(type)
			{
			//����
			case "armor":
				ob=new("/d/city/npc/obj_ex/armor.c");
				ob->set("no_sell", 1);
			        ob->set("no_drop", 1);
        			ob->set("no_give", 1);
				ob->move(who);
				tell_object(who,"һҶ֪���"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;
			case "pifeng":
				ob=new("/d/city/npc/obj_ex/pifeng.c");
				ob->set("no_sell", 1);
			        ob->set("no_drop", 1);
        			ob->set("no_give", 1);
				ob->move(who);
				tell_object(who,"һҶ֪���"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;
			case "shield":
				ob=new("/d/city/npc/obj_ex/shield.c");
				ob->set("no_sell", 1);
			        ob->set("no_drop", 1);
        			ob->set("no_give", 1);
				ob->move(who);
				tell_object(who,"һҶ֪���"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;
			case "shoes":
				ob=new("/d/city/npc/obj_ex/shoes.c");
				ob->set("no_sell", 1);
			        ob->set("no_drop", 1);
        			ob->set("no_give", 1);
				ob->move(who);
				tell_object(who,"һҶ֪���"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;
			case "cloth":
				ob=new("/d/city/npc/obj_ex/cloth.c");
				ob->set("no_sell", 1);
			        ob->set("no_drop", 1);
        			ob->set("no_give", 1);
				ob->move(who);
				tell_object(who,"һҶ֪���"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;
			case "kui":
				ob=new("/d/city/npc/obj_ex/kui.c");
				ob->set("no_sell", 1);
			        ob->set("no_drop", 1);
        			ob->set("no_give", 1);
				ob->move(who);
				tell_object(who,"һҶ֪���"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;
			case "bonnet":
				ob=new("/d/city/npc/obj_ex/faguan.c");
				ob->set("no_sell", 1);
			        ob->set("no_drop", 1);
        			ob->set("no_give", 1);
				ob->move(who);
				tell_object(who,"һҶ֪���"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;
				//����
			case "sword":
				ob=new("/d/city/npc/obj_ex/sword.c");
				ob->set("no_sell", 1);
			        ob->set("no_drop", 1);
        			ob->set("no_give", 1);
				ob->move(who);
				tell_object(who,"һҶ֪���"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;
			case "whip":
				ob=new("/d/city/npc/obj_ex/whip.c");
				ob->set("no_sell", 1);
			        ob->set("no_drop", 1);
        			ob->set("no_give", 1);
				ob->move(who);
				tell_object(who,"һҶ֪���"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;
			case "blade":
				ob=new("/d/city/npc/obj_ex/blade.c");
				ob->set("no_sell", 1);
			        ob->set("no_drop", 1);
        			ob->set("no_give", 1);
				ob->move(who);
				tell_object(who,"һҶ֪���"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;
			case "stick":
				ob=new("/d/city/npc/obj_ex/stick.c");
				ob->set("no_sell", 1);
			        ob->set("no_drop", 1);
        			ob->set("no_give", 1);
				ob->move(who);
				tell_object(who,"һҶ֪���"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;
                        case "spear":
                                ob=new("/d/city/npc/obj_ex/spear.c");
				ob->set("no_sell", 1);
			        ob->set("no_drop", 1);
        			ob->set("no_give", 1);
				ob->move(who);
				tell_object(who,"һҶ֪���"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;
			case "fork":
				ob=new("/d/city/npc/obj_ex/fork.c");
				ob->set("no_sell", 1);
			        ob->set("no_drop", 1);
        			ob->set("no_give", 1);
				ob->move(who);
				tell_object(who,"һҶ֪���"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;
			case "hammer":
				ob=new("/d/city/npc/obj_ex/hammer.c");
				ob->set("no_sell", 1);
			        ob->set("no_drop", 1);
        			ob->set("no_give", 1);
				ob->move(who);
				tell_object(who,"һҶ֪���"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;
                          case "qin":
                                  ob=new("/d/city/npc/obj_ex/qin.c");
                                  ob->set("no_sell", 1);
                                  ob->set("no_drop", 1);
                                  ob->set("no_give", 1);
                                  ob->move(who);
tell_object(who,"һҶ֪���"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
                                  break;
			case "axe":
				ob=new("/d/city/npc/obj_ex/axe.c");
				ob->set("no_sell", 1);
			        ob->set("no_drop", 1);
        			ob->set("no_give", 1);
				ob->move(who);
				tell_object(who,"һҶ֪���"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;
			case "staff":
				ob=new("/d/city/npc/obj_ex/staff.c");
				ob->set("no_sell", 1);
			        ob->set("no_drop", 1);
        			ob->set("no_give", 1);
				ob->move(who);
				tell_object(who,"һҶ֪���"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;
			case "zhua":
				ob=new("/d/city/npc/obj_ex/zhua.c");
				ob->set("no_sell", 1);
			        ob->set("no_drop", 1);
        			ob->set("no_give", 1);
				ob->move(who);
				tell_object(who,"һҶ֪���"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;           
            case "mace":
				ob=new("/d/city/npc/obj_ex/mace.c");
				ob->set("no_sell", 1);
			        ob->set("no_drop", 1);
        			ob->set("no_give", 1);
				ob->move(who);
				tell_object(who,"һҶ֪���"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;           
            case "guai":
				ob=new("/d/city/npc/obj_ex/guai.c");
				ob->set("no_sell", 1);
			        ob->set("no_drop", 1);
        			ob->set("no_give", 1);
				ob->move(who);
				tell_object(who,"һҶ֪���"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;           
            case "sha":
				ob=new("/d/city/npc/obj_ex/jindan.c");
				ob->set("no_sell", 1);
			        ob->set("no_drop", 1);
        			ob->set("no_give", 1);
				ob->move(who);
				tell_object(who,"һҶ֪���"+ob->query("name")+"������,��������:���ã����Ҷ�Ŷ��\n");
				break;           
			}
	}
return 1;

}
