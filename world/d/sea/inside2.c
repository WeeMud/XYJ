// cracked by vikee 2/09/2002   vikee@263.net
// inside2.c

inherit ROOM;

void create ()
{
  set ("short", "���");
  set ("long", @LONG

�ɴ������������������������ס�����档һ������̨�׶����á�����
�����ɣ���������������ʿ���������ף�ɷ�����硣
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "eastup" : __DIR__"inside3.c",
  "westdown" : __DIR__"yujie3.c",
]));
//      
        set("water", 1);
//  
  setup();
}
