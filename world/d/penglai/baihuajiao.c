// cracked by vikee 2/09/2002   vikee@263.net
inherit ROOM;
#include <room.h>

void create() {
  set("short","�ٻ���");
  set("long",@LONG

һ���ܲ�͸���Ҥ����������ǰٻ�������Ƶ������ˡ�

LONG);
  set("exits",(["north":__DIR__"hongyandong",]));
  set("objects",([ __DIR__"obj/baihuaniang":1,]));
  setup();
}
