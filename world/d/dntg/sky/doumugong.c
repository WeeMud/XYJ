// cracked by vikee 2/09/2002   vikee@263.net
// Room: /d/sky/nantianmen
 
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "��ľ��");
  set ("long", @LONG

���������רΪ��ʮ������ġ���ʮ��λ�ǹ���Ϊ����շ⣬ʵ
����������ɽ�󴨣�����ĺ���ƽʱ��������۽��ƣ�ֻ����͢
�����ش�����������������졣��ʮ���޵������������ʱ����
�����֮����

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south"     : __DIR__"bishuigong",
  "southeast" : __DIR__"niujingong",
  "northeast" : __DIR__"xurigong",

]));

set("no_fight", 1);
set("no_magic", 1);

  set("objects", 
      ([
       __DIR__"stars/1" : 1,
      ]));


  setup();
}
 
