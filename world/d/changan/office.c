// cracked by vikee 2/09/2002   vikee@263.net
// Room: /u/wuliao/housingoffice
inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG
��ˮ�ӱߵľ��������࣬����ر��ڴ���������������ʱ��
һ����֪������ͷ����
LONG);


	set("no_fight", 1);
	set("no_magic", 1);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"officer" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"ph",
]));

  setup();
}
