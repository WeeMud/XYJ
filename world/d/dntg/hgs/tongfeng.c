// cracked by vikee 2/09/2002   vikee@263.net
//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "ͨ���ʥ��");
set("long", @LONG

      �ǹ����

   ǧ          ��
   ��          ��
   ��          ��
   ��          ��
   ��          Ⱥ
   ��          Ӣ
   ��          ��

LONG );


set("exits", ([
  "out": __DIR__"fuhai",
  "northup": __DIR__"shanya",
]));


set("objects", ([
  "/d/dntg/sky/stars/ivan" : 1,
]));



  set("outdoors", 1);

setup();
}
