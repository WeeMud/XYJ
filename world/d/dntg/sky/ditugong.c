// cracked by vikee 2/09/2002   vikee@263.net
 
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "ص����");
  set ("long", @LONG

���������רΪ��ʮ������ġ���ʮ��λ�ǹ���Ϊ����շ⣬ʵ
����������ɽ�󴨣�����ĺ���ƽʱ��������۽��ƣ�ֻ����͢
�����ش�����������������졣��ʮ���޵������������ʱ����
�����֮����

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "west"     : __DIR__"weihuogong",
  "northeast" : __DIR__"fangrigong",
  "northwest" : __DIR__"kangjingong",

]));

set("no_fight", 1);
set("no_magic", 1);

  set("objects", 
      ([
       __DIR__"stars/23" : 1,
      ]));


  setup();
}
 
