// cracked by vikee 2/09/2002   vikee@263.net
// Room: /d/changan/fendui.c
inherit ROOM;

void create()
{
  set ("short", "�ķض�");
  set ("long", @LONG

�����ǳ������ϵ�һƬ�ĵأ���Χ��������ض��˺ü�ʮ����ͷ��
��Щ��ǰ����Щ���룬��ֽ�ĺۼ����Ĵ����������������߶���ż
���м�ֻѰʳ��Ұ���ܹ���
LONG);
  set("mai_corpse_able", 1);
  set("outdoors", __DIR__"");
  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"broadway1",
]));
  setup();
}
