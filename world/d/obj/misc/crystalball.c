// cracked by vikee 2/09/2002   vikee@263.net

#define RUMORCENTER "/d/city/rumorcenter"
#include <ansi.h>

inherit ITEM;
object room;

void create() {

  set_name("ˮ����", ({"shuijing qiu","crystal","ball","qiu"}));
  set_weight(200);
  set("unit", "ֻ");
  set("long", "һֻ�̹������ˮ������Ȼ����δ����֪�����֮��(detect)��Ҳ��������\n");
  set("value", 1000);
  setup();
//  room=find_object(RUMORCENTER);
  room=load_object(RUMORCENTER);
  set("room",room);
}

void init() {
  add_action("do_detect","detect");
}

int do_detect(string arg) {
  mapping rumor;
  int number;
  object me=this_player();
  object ob=this_object();

  if (! arg || sscanf(arg, "%d", number)!=1) 
    return notify_fail("�÷��� �������� ������������ \n");
  if (number<1 || number>10) return notify_fail("�÷�����\n");
  
  if (!room) {
    set("value",0);
    write("��ֻˮ�����Ѿ�ʧȥ�����ˡ�\n");    
    write("ˮ���򻯳�һ̲��ˮ����һ�ء�\n");
    destruct(this_object());
    return 1;
  }

  if (me->query("mana")<100) return notify_fail("��ķ����������޷���ˮ����ͨ��\n");

  rumor=room->reveal(number);
  set("rumor",rumor);

  me->add("mana",-10);
  message_vision(HIG"$N����ˮ���򣬿��������\n"NOR,me);
  if (!rumor) {
    tell_object(me,"����ʲôҲû�з�����\n");
    return 1;
  }
  tell_object(me,CYN"�����ˮ���򣺸ղš�"+rumor["body"]+"����˭˵�ģ�\n"NOR);
  if (!rumor["disclose"])
     tell_object(me,HIB"ˮ����ش��㣺�������й¶��\n"NOR);
  else {
    tell_object(me,MAG"ˮ���򻺻���ת���ţ���·���п�����һ����Ӱ��\n"); 
    tell_object(me,HIR"��ӰԽ��Խ����������ϸһ����ԭ����"HIW
               +rumor["name"]+HIR"("+rumor["id"]+")��\n"NOR);
  }

  return 1;
}  
