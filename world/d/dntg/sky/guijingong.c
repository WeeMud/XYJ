// cracked by vikee 2/09/2002   vikee@263.net
// Room: /d/sky/nantianmen
 
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "���");
  set ("long", @LONG

���������רΪ��ʮ������ġ���ʮ��λ�ǹ���Ϊ����շ⣬ʵ
����������ɽ�󴨣�����ĺ���ƽʱ��������۽��ƣ�ֻ����͢
�����ش�����������������졣��ʮ���޵������������ʱ����
�����֮����

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south"     : __DIR__"xingrigong",
  "north"     : __DIR__"zhangyuegong",
  "southwest" : __DIR__"liutugong",
  "southeast" : __DIR__"jingmugong",
  "northwest" : __DIR__"yihuogong",
  "northeast" : __DIR__"zhenshuigong",

]));

set("no_fight", 1);
set("no_magic", 1);

  set("objects", 
      ([
	__DIR__"stars/17": 1,
      ]));


  setup();
}
 
