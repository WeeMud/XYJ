// cracked by vikee 2/09/2002   vikee@263.net
// Room: /d/wiz/guest.c    snowcat

#include <login.h>

inherit ROOM;

int clean_up();

void create()
{
  set("short", "ӭ����");
  set("long", @LONG

�Բ������ĵ�ַ�����μǵ������������ƻ��ˣ�Ϊ�˱�֤
���������ڵĴ��������ܹ�������Ϸ�����ǲ��ò�����
����������ɣе�ַ�����ߡ������ڿ����Ժ����μ���ʦ
�ᾡ��������Ӧ����ͬʱ���������Ķ������ļ�(help)��
��Ϸ����(story)��

LONG
);

  set("valid_startroom", 1);
  set("no_fight", 1);
  set("no_magic", 1);
  set("objects", ([
    __DIR__"npc/guest":1,
  ]));
  setup();
  (load_object("/obj/board/guestroom_b"))->move(this_object());
}

int nb_guests (object where)
{
  int i = 0;
  int j = 0;
  object *obs = all_inventory(where);

  j = sizeof(obs);
  while (j--)
  {
    if (userp(obs[j]) && !wizardp(obs[j]))
      i++;
  } 
  return i;
}

void init()
{  
  object who = this_player(); 
  object where = this_object();

  if (!wizardp(who)&&userp(who))
  {
    if (who->query("banned_approved")==1)
    {
      tell_object (who,"��ӭ���������μ����磡\n");
      if(who->is_ghost())
	  who->move(DEATH_ROOM);
      else
          who->move(who->query("startroom"));
      MONITOR_D->report_system_object_msg (who,  
        "�ɱ�����IP���룬�ѱ���׼ֱ�����μ����硣"); 
      return; 
    }
    who->set("startroom","/d/wiz/guest");
    who->save();
    add_action("block_cmd","",1);  
    MONITOR_D->report_system_object_msg (who,  
      "��IP�������ֱ��������μ�ӭ����(/d/wiz/guest.c)��");  
    if (nb_guests(where) > 10)
    {
      tell_object ("�Բ���ӭ���������̫�࣬���´�������\n",who);
      who->command_function("quit");
      return;
    }
  }
}

int clean_up()
{      //special for this room. no clean_up.

       return 0;
}

void inform_wiz (object who)
{
  tell_object (who,"�����ʹ��approve����׼��ҽ������μ����硣\n");
}

int block_cmd()
{
  string verb = query_verb();
  if (verb=="say") return 0; 
  if (verb=="help") return 0;
  if (verb=="who") return 0;
  if (verb=="look") return 0;
  if (verb=="story") return 0;
  if (verb=="quit") return 0;
  if (verb=="post") return 0;
  return 1;
}
