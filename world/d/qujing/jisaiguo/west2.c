// cracked by vikee 2/09/2002   vikee@263.net
#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "���������");
  set ("long", @LONG

·�����⽨����£���ɫ����ǽ�������������쵽�Ǳߣ���ǽ��
���������ϸ���ɫ��Ƭ���ֵ��ܿ��������������࣬·��ܸɾ���
����Ϊɮ�˾�����ɨ��Ե�ʡ�·����Ӵ������򣬼���Сͯ��·
����ˣ��
LONG);

//  set("objects", ([ /* sizeof() == 1*/ 
//  __DIR__"npc/erlang" : 1,
//]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"west1",
  "south" : __DIR__"west3",
]));

  setup();
}
