// cracked by vikee 2/09/2002   vikee@263.net
// create by snowcat jan 21 1998

inherit ROOM;

void create ()
{
  set ("short", "���Ĺ�");
  set ("long", @LONG

���Ĺ����������ƣ���ǰ��һС����������ȼ�����㣬�̻��������
�ǡ�����ǽ������д��һ����ɫ���֡����������Ϸ��ż����׵��廨
���š�

LONG);

  set("exits", ([
        "south" : __DIR__"sanxin",
        "west" : __DIR__"qingxin",
        "east" : __DIR__"jingxin",
      ]));
  set("no_fight", 1);
  set("no_magic", 1);
  setup();
}

void init ()
{
  add_action ("do_ning","ning");
}

int do_ning ()
{
  object who = this_player();
  int i = (45 - random(who->query_kar()))*2
          -who->query_temp("kaifeng_donate_silver");

  if (i<2) i=2;// minumum delay time.

  if (who->is_busy())
    return notify_fail("��Ķ�����û����ɣ����ܶ���\n");

  message_vision ("$N�����ص���һ���������֣������������¡�\n",who);
  who->start_busy (i,i);

  call_out ("finishing",i,who);
  return 1;
}

void finishing (object who)
{
  who->interrupt_me();
  who->set_temp("kaifeng_ningxin",1);
  message_vision ("$N������³�һ����������վ��������\n",who);
}

