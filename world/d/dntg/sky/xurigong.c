// cracked by vikee 2/09/2002   vikee@263.net
// Room: /d/sky/nantianmen
 
#include <ansi.h>
inherit ROOM;

void init();

void create ()
{
  set ("short", "���չ�");
  set ("long", @LONG

���������רΪ��ʮ������ġ���ʮ��λ�ǹ���Ϊ����շ⣬ʵ
����������ɽ�󴨣�����ĺ���ƽʱ��������۽��ƣ�ֻ����͢
�����ش�����������������졣��ʮ���޵������������ʱ����
�����֮����

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south"     : __DIR__"niujingong",
  "north"     : __DIR__"caihongqiao2",
  "southeast" : __DIR__"nutugong",
  "southwest" : __DIR__"doumugong",

]));
set("no_fight", 1);
set("no_magic", 1);


  set("objects", 
      ([
       __DIR__"stars/0" : 1,
      ]));


  setup();
}
 
