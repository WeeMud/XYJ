// cracked by vikee 2/09/2002   vikee@263.net
// Room: /u/mimi/zhuziguo/westroom  snowcat moved to /d/qujing/wuji

inherit ROOM;

void create ()
{
  set ("short", "���᷿");
  set ("long", @LONG

�˼����������ֵ��������������ҹ���ֹ������Ѱ�ȥ�𴦡���
�г������ǵ��š���������ϰ����˾��飬���ϵİ�����һ����¯
ȴ����þ�û�������ˡ�

LONG);

  set("light_up", 1);
  set("exits", ([ /* sizeof() == 1 */
    "east" : __DIR__"zheng",
  ]));
  set("sleep_room",1);

  setup();
}

void init()
{
  add_action ("do_sleep","sleep");
}

int do_sleep (string arg)
{
  object who = this_player();
  int phase = NATURE_D->query_current_day_phase();

  if (random(5))
    return 0;
  if (present("ghost guo wang"))
    return 0;
  if (who->query("combat_exp")<50000)
    return 0;
  if (phase > 0 && phase < 5)
    return 0;

  message_vision ("$N����������˯�ţ��������е�����������\n",who);
  remove_call_out ("create_king");
  call_out ("create_king",2+random(10));
  return 1; 
}

int create_king() 
{
  object  king;

  if(!present("ghost guo wang"))
  {
    king = new("/d/qujing/wuji/npc/king.c");
    king->move("/d/qujing/wuji/westroom.c");
  }

  return 1;
}

void set_given()
{
  object me = this_object();

  me->set("has_given",1);
  remove_call_out("reset_given");
  call_out("reset_given",900);
}

void reset_given ()
{
  object me = this_object();

  me->set("has_given",0);
}
