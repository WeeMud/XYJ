// cracked by vikee 2/09/2002   vikee@263.net
// zhting.c

inherit ROOM;

void create ()
{
  set ("short", "��˾");
  set ("long", @LONG

����������ܵظ�֮�У�ż������������������˾��ǣ��Щ����
��������������ȥ����Χ��һ������¥�󹬵������Ҳ�൱�ĸ�
���ûʣ���ֵ��Ƕ���һ�ȶ��Ž𶤵ĺ�ľ�ź�һ�������ż���
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"new-wayout",
  "west" : __DIR__"new-walk2",
  "north" : __DIR__"new-jimie",
  "south": __DIR__"new-yinsi1",
]));
  set("hell", 1);

  setup();
}

