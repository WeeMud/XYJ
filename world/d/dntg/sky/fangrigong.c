// cracked by vikee 2/09/2002   vikee@263.net
// Room: /d/sky/nantianmen
 
#include <room.h>
#include <ansi.h>
inherit ROOM;

void init();
void close_gate();
int do_knock(string);
int valid_leave();
string look_gate();

void create ()
{
  set ("short", "���չ�");
  set ("long", @LONG

���������רΪ��ʮ������ġ���ʮ��λ�ǹ���Ϊ����շ⣬ʵ
����������ɽ�󴨣�����ĺ���ƽʱ��������۽��ƣ�ֻ����͢
�����ش�����������������졣��ʮ���޵������������ʱ����
������֮����

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "west"     : __DIR__"kangjingong",
  "northwest" : __DIR__"jiaomugong",
  "southwest"      : __DIR__"ditugong",

]));

set("no_fight", 1);
set("no_magic", 1);


  set("objects", 
      ([
       __DIR__"stars/21" : 1,
      ]));


  setup();
}
 