// cracked by vikee 2/09/2002   vikee@263.net
// Room: /d/nanhai/chanfang
inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

��������ɽ���˵��������������ĵط���ֻ������ɮ������
һ��ߺ������ȭŪ�ţ����⼸������ϰ�������ݽǰ��ż���
������ǹ��
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"zoulang",
]));
 set("no_clean_up", 1);
set("light_up", 1);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/zhangchan" : 1,
]));

  setup();
}
