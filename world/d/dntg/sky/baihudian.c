// cracked by vikee 2/09/2002   vikee@263.net
//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "�׻���");
set("long", @LONG
    
�칬��һ��ƫ��������������֮ǰ���ڴ�ЪϢ��
ֻ�������ı����������ƷǷ���
LONG );


set("exits", ([
  "east"   : __DIR__"xuanyuantang",
  "west"   : __DIR__"biyuegong",
]));


set("objects", ([
]));



setup();
}
