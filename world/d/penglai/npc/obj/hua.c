// cracked by vikee 2/09/2002   vikee@263.net
#include <ansi.h>

#include <dbase.h>
#include <armor.h>

inherit NECK;
#include <flowers.h>

string chinese_daoxing(int);
void create() {
    set_name(flowers[random(sizeof(flowers))], ({ "flower"}));
  set_weight(100);
  set("unit", "��");
  set("armor_prop/armor", 1);
  set("armor_prop/personality", 2);
  setup();
}

void init() {
    add_action("do_eat","eat");
}

int do_eat(string arg) {
  object me=this_player();
   int qn=0;
  int score=query("score");
  
  if (!arg) return 0;
  if (this_object()!=present(arg,me)) return 0;
   message_vision(HIC"$N����һ��"+query("name")+HIC"��ֻ���������˱ǣ��ݼշҷ���\n"NOR,me);
  if (query("target")==me && score>0) {
	if (me->query("daoxing") > 5000000) score/=10; //by hexiu
    me->add("daoxing",score);
  qn=score*(20+random(10))/100;
//if (me->query("potential")-me->query("learned_points")<1000) 
  me->add("potential",qn);
    tell_object(me,HIC"��õ���"+chinese_daoxing(score)+"���У�"+qn+"��Ǳ�ܡ�\n"NOR);
  MONITOR_D->report_system_object_msg(me," got "+score+" daoxing "+qn+" pots from baihua-gu.\n" );
  log_file("baihuagu",me->query("id")+" got "+score+" daoxing "+qn+" pots on "+ctime(time())+".\n");
  }
  destruct(this_object());
  return 1;
}
string chinese_daoxing(int gain) {
            int year,day,hour;
             string str;

             year=gain/1000;
             day=(gain-year*1000)/4;
             hour=(gain-year*1000-day*4)*3;
             str="";
             if(year) str=str+chinese_number(year)+"��";
             if(day) str=str+chinese_number(day)+"��";
             if(hour) str=str+chinese_number(hour)+"ʱ��";
             return str;
}
