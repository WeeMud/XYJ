// cracked by vikee 2/09/2002   vikee@263.net
inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

���ڵĳ����൱�Ĵ����ؾ���ʮ����С��æ����ڸ��ִ���
Ҳ��Ӧ�о��У�����һ���ش������ð��ˮ����
LONG);
  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"yongdao8", 
]));
  set("objects", ([ /* sizeof() == 1*/
  __DIR__"npc/xian": 1,
]));



  setup();
}

