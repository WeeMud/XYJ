// cracked by vikee 2/09/2002   vikee@263.net
// created by ajax 05/28/1999
// ȡ����

inherit NPC;
// inherit F_CLEAN_UP;

#include <ansi.h>
#include "qujingquest.c"

int ask_for_help();
int random_move_xuanzang();
int leave_this_quest_xuanzang();
int success_this_quest_xuanzang();

void create()
{

  set_name("������", ({"chen xuanzang", "chen", "xuanzang", "san zang", "tang seng", "tang"}));
  set("gender", "����" );
  set("age", 36);
  set("title", "���ط�ʦ");
  set ("long", @LONG
��ͨ����Ž����ֻΪ�������𽲣�ת�г�������ĥ������������������
Ͷ̥��ؾͷ��ף�δ��֮ǰ�ٶ񵳡����Ǻ��ݳ�״Ԫ���⹫�ܹܵ�������
���������佭�ǣ�˳ˮ�沨�����󡣺�����ɽ�д�Ե��Ǩ�����н�������
�귽ʮ��������ظ��������ⳤ���ܹܿ�ɽ����������ݽ˿����׵���
״Ԫ���������ޣ��Ӹ���꿰�ؽ������˵��������������̸��������졣
���ٲ���ԸΪɮ���鸣ɳ�Ž����á�С�ֽ����ŷ�����������������ʡ�
LONG);

  set("class", "monk");
  set("combat_exp", 0);
  set("attitude", "peaceful");
  set_skill("fofa", 300);
  set("per", 30);
  set("max_kee", 500);
  set("kee", 500);
  set("max_sen", 500);
  set("sen", 500);

//temp flag
  set("qujing/id", "yingchou");
  set("qujing/ppl","none");


  setup();
  carry_object("/d/obj/cloth/hufa-jiasha")->wear();


  set("inquiry", ([
     "name"     :   "ƶɮ����������ʿ�����һ�̫��ּ��ǰȥ����ȡ����",
     "qujing"   :   (: ask_for_help() :),
     "ȡ��"     :   (: ask_for_help() :),
     ]) );

  set("chat_msg", ({
      (: random_move :),
        }) );
  set("chat_chance", 20);

}

// ��ʼ����
int ask_for_help()
{
  object me = this_object();
  object who = this_player();
  int daoxing_needed,time_needed;

  sscanf(obstacles[me->query("qujing/id")][1],"%d",daoxing_needed);
  daoxing_needed=daoxing_needed*1000;
  sscanf(obstacles[me->query("qujing/id")][5],"%d",time_needed);
  time_needed=time_needed*60;

  if (who->query("class") == "yaomo" )
    {
    message_vision("$N��$n����ʩ��������������֪�����Ǻξ��ģ�"
         +"�ຣ�ޱߣ���ͷ�ǰ�����Ȱʩ�����Ǻ���Ϊ֮�ɡ�\n", me,who);
    return 1;
    }

  if (who->query("daoxing") < daoxing_needed )
    {
    message_vision("$N��$n˵������лʩ���ĺ��⣬ֻ����·;���գ�"
         +"��ħ�ڶ࣬����ƶɮ������ʩ����\n", me,who);
    return 1;
    }

  if (me->query("qujing/ppl") == who->query("id") )
    {
    message_vision("$N��$n˵�����²��ɳ٣����ǻ��ǸϽ���·�ɡ�\n", me,who);
    return 1;
    }

  if (me->query("qujing/ppl") != "none" )
    {
    message_vision("$N��$nһ��ȭ����л"
         +RANK_D->query_respect(who)+"�ĺ��⣬�����˰���ƶɮ�ˡ�\n", me,who);
    return 1;
    }

  if (me->query("qujing/id"))
    {
    message_vision("$N��$nһ���֣�ƶɮ"+obstacles[me->query("qujing/id")][3]
       +RANK_D->query_respect(who)+"�ܷ���ƶɮһ��֮����\n", me,who);
    me->command("follow "+who->query("id"));
    me->set("chat_chance",0);
    me->set("qujing/ppl",who->query("id"));
    remove_call_out("random_move_xuanzang");
    remove_call_out("leave_this_quest_xuanzang");  
    call_out("success_this_quest_xuanzang", 1);  
    call_out("leave_this_quest_xuanzang", time_needed);  
    return 1;
    }
}

// ÿ�����������û�˹��أ�auto move to a new quest place
int random_move_xuanzang()
{
  int i;
  string *quest_id = keys(obstacles);
  object me = this_object();
  
  i=random(sizeof(quest_id));
  me->move(obstacles[quest_id[i]][2]);
  me->set("qujing/id",quest_id[i]);
  me->set("qujing/ppl","none");
  set("chat_chance", 20);
  remove_call_out("random_move_xuanzang");
  call_out("random_move_xuanzang", 300);  
  return 1;
}


int leave_this_quest_xuanzang()
{
  object me = this_object();
  message_vision("$N��̾һ��������֮·����˼�����\n", me);
// here need clear ppl's mark and give punishment 
  message_vision("$N��Ȼ���뿪�ˡ�\n", me);
  call_out("random_move_xuanzang", 1);  
  return 1;  
}

int success_this_quest_xuanzang()
{
  object me = this_object();
  object who;
  int reward_daoxing;

  sscanf(obstacles[me->query("qujing/id")][6],"%d",reward_daoxing);
  who=find_player(me->query("qujing/ppl"));
  if (who)
    {
    me->command("chat "+who->query("name")+obstacles[me->query("qujing/id")][4]
       +who->query("name")+"����������һ�أ�");
// here need clear ppl's mark and give reward 
    message_vision("$N��$nһ���֣���л"+RANK_D->query_respect(who)+
         "���������Ǻ�����ڣ�\n", me,who);
    message_vision("$N����������·ȥ�ˡ�\n", me);
    call_out("random_move_xuanzang", 1);  
    }
  return 1;  
}


void unconcious()
{
  die ();
}

void die()
{
  object me = this_object();
  message_vision("$N��̾һ�����Ҳ��������˭�������"
      +"ֻ��ȡ��δ�ɣ�����������̫�ڵ�һƬ���ġ�\n", me);
  message_vision("$N���ˡ�\n", me);
// ������ɮ��
  set("eff_kee", 500);
  set("eff_sen", 500);
  set("kee", 500);
  set("sen", 500);
  me->move(__DIR__"shengsilunlui");
  call_out("random_move_xuanzang", 1800);  
}

