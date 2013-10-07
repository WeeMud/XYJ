// cracked by vikee 2/09/2002   vikee@263.net
// created by snowcat.c 4/4/1997
// room: /d/nuerguo/greenyard.c

inherit ROOM;

void leave_here(object me);

void create ()
{
  set ("short", "���Թ�");
  set ("long", @LONG

һ���������������޼��ɵĴ��Թ���ǰ�����Ҷ���һƬ��ɫ
�������ԣ����ѱ����Ҳ�������κγ��ڡ�

LONG);

  set("exits", ([
        "east"      : __DIR__"greenyard",
        "west"      : __DIR__"greenyard",
        "south"     : __DIR__"greenyard",
        "north"     : __DIR__"greenyard",
        "northwest" : __DIR__"greenyard",
        "southwest" : __DIR__"greenyard",
      ]));
  set("no_mieyao",1);
  set("valid_startroom",1);
  setup();
}

void init()
{
  add_action("do_fly", "fly");
  add_action("do_quit", "quit");
}

int do_quit ()
{
  object me;
  me = this_player();

  me->set("startroom",base_name(environment(me)));
  tell_object(me,"��ʱ�뿪�Թ�����\n");
  return 0; // return 0 to invoke normal quit
}

int do_fly (string arg)
{
  object me;
  me = this_player();

  message_vision("ֻ��$N����һ�ɣ����ص�ˤ��������ͷ��ճ�ż�Ƭ����Ҷ��\n", me);
  tell_object(me,"���������Թ������ǲ���ѷɡ���\n");
  return 1;
}

// called by move()
mixed no_leave(object who, object where)
{
    string file;

    // allow wiz or wiz summon out.
    if(this_player(1) && wizardp(this_player(1))) return 0;

    if(where) file=base_name(where);
    else return 0;
	 
    if(member_array(file, ({__DIR__"greenyard",
                   __DIR__"outlet",
                   }))>-1) return 0;
    return "���������Թ������ǲ�����ӡ���\n";
}


int valid_leave (object me, string dir)
{
  object icedew;
  int i;

  me->set("startroom",base_name(environment(me)));
  if (i = me->query_temp("out_of_greenyard"))
  {
    i++;
    me->set_temp("out_of_greenyard",i);
    if (i > 5)
    {
      me->set_temp("lost_in_greenyard",0);
      me->set_temp("out_of_greenyard",0);
      
      call_out("leave_here",1,me);

      return 1;
    }
  }
  else if (! me->query_temp("lost_in_greenyard"))
  {
    me->set_temp("lost_in_greenyard",1);
    call_out("found_outlet",240+random(240),me);
  }
  return 1;
}

// mon move this out of the valid_leave function
// to prevent an Illegal move error.
// 4/11/98
void leave_here(object me)
{
      object icedew;

      me->move(__DIR__"outlet");
      if (! present("icedew",environment(me)))
      {
        icedew = new(__DIR__"obj/icedew");
        icedew->move(environment(me));
      }
      tell_object(me,"�̲ݵ�����һ���������Ķ�����\n");
}

void found_outlet(object me)
{
  if(!me) return;
  me->set_temp("lost_in_greenyard",0);
  me->set_temp("out_of_greenyard",1);
}
