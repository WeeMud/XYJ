// cracked by vikee 2/09/2002   vikee@263.net
// Room: /d/sky/nantianmen
 
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "�һ�");
  set ("long", @LONG

���������רΪ��ʮ������ġ���ʮ��λ�ǹ���Ϊ����շ⣬ʵ
����������ɽ�󴨣�����ĺ���ƽʱ��������۽��ƣ�ֻ����͢
�����ش�����������������졣��ʮ���޵������������ʱ����
�����֮����

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "north"     : __DIR__"nutugong",
  "northwest" : __DIR__"niujingong",
  "southeast" : __DIR__"jishuigong",
  "southwest" : __DIR__"weiyuegong",

]));
set("no_fight", 1);
set("no_magic", 1);


  set("objects", 
      ([
       __DIR__"stars/5" : 1,
      ]));


  setup();
}
 
