// cracked by vikee 2/09/2002   vikee@263.net
 
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "θ����");
  set ("long", @LONG

���������רΪ��ʮ������ġ���ʮ��λ�ǹ���Ϊ����շ⣬ʵ
����������ɽ�󴨣�����ĺ���ƽʱ��������۽��ƣ�ֻ����͢
�����ش�����������������졣��ʮ���޵������������ʱ����
�����֮����

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "east"      : __DIR__"bihuogong",
  "southwest" : __DIR__"angrigong",
  "southeast" : __DIR__"loujingong",

]));

set("no_fight", 1);
set("no_magic", 1);

  set("objects", 
      ([
	__DIR__"stars/9": 1,
      ]));


  setup();
}
 
