// cracked by vikee 2/09/2002   vikee@263.net
inherit ROOM;

void create ()
{
  set ("short", "���ɽ�");
  set ("long", @LONG

���ֱ�����һƬС��ʯ�£�������һ��ɽ�����ƺ�����������ˮ
��������������һ��С��ʯ�ţ�Զ���ź���һ���ߵĹ�ʯ�£���
����Ӱ�ܶ���
LONG);
  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"songlin4",
  "north" : __DIR__"guaishiya",
]));
  set("outdoors",1);


  setup();
}

