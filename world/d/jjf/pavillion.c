// cracked by vikee 2/09/2002   vikee@263.net
// Room: /d/jjf/pavillion.c

inherit ROOM;

void create ()
{
  set ("short", "��ͤ");
  set ("long", @LONG
��ͤ�����Ϊ���£��м�һʯ�������Ͽ��ź�ʮ�ţ���ʮ�ŵ�
һ�����̣��оֻ�δ��ȥ���峿��������飬Ϧ������ʱƷ��̸�죬
��������һ����¡�
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "northeast" : __DIR__"stone_road",
  "southeast" : __DIR__"nw_garden",
  "west" : __DIR__"guest_cabinet",
]));

  setup();
}
