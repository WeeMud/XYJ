// cracked by vikee 2/09/2002   vikee@263.net
// Room: /d/sky/nantianmen
 
#include <room.h>
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short", "����");
  set ("long", @LONG

���������רΪ��ʮ������ġ���ʮ��λ�ǹ���Ϊ����շ⣬ʵ
����������ɽ�󴨣�����ĺ���ƽʱ��������۽��ƣ�ֻ����͢
�����ش�����������������졣��ʮ���޵������������ʱ����
�����֮����

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "east"     : __DIR__"fangrigong",
  "west"     : __DIR__"xinyuegong",
  "southeast" : __DIR__"ditugong",
  "southwest" : __DIR__"weihuogong",
  "northeast" : __DIR__"jiaomugong",
  "northwest" : __DIR__"jishuigong",

]));

set("no_fight", 1);
set("no_magic", 1);

  set("objects", 
      ([
       __DIR__"stars/24" : 1,
      ]));


  setup();
}
 
