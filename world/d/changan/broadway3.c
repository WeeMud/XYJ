// cracked by vikee 2/09/2002   vikee@263.net
// Room: /changan/broadway3.c
//cglaem...12/12/96.

inherit ROOM;

void create ()
{
  set ("short", "��ٵ�");
  set ("long", @LONG

����һ��������ֱ�Ĺٵ�������ݵ���ʮ���ۡ�����ͨ��
�ϲ��غ���������ֱ����ƹ��������ǡ�������һ����ʯ·��
������ͨ���������
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"wroad1",
  "south" : __DIR__"broadway4",
  "north" : __DIR__"nanyue",
]));
  set("outdoors", 1);

    if(random(2))
	    set("objects", ([ "/d/obj/weapon/throwing/shi.c" : 1, ]));
      else
	      set("objects", ([ "/d/obj/weapon/throwing/smallshi.c" : 1, ]));

  setup();
}






