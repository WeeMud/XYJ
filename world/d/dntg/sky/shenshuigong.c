// cracked by vikee 2/09/2002   vikee@263.net
// Room: /d/sky/nantianmen
 
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "��ˮ��");
  set ("long", @LONG

���������רΪ��ʮ������ġ���ʮ��λ�ǹ���Ϊ����շ⣬ʵ
����������ɽ�󴨣�����ĺ���ƽʱ��������۽��ƣ�ֻ����͢
�����ش�����������������졣��ʮ���޵������������ʱ����
�����֮����

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "southeast" : __DIR__"yihuogong",
  "west"      : __DIR__"kuimugong",
  "northeast" : __DIR__"biyuegong",
  "northwest" : __DIR__"loujingong",

]));
set("no_fight", 1);
set("no_magic", 1);


  set("objects", 
      ([
	__DIR__"stars/11": 1,
      ]));


  setup();
}
 
