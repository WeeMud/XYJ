// cracked by vikee 2/09/2002   vikee@263.net
inherit ROOM;

void create ()
{
  set ("short", "�̷�");
  set ("long", @LONG

�̷����ر�Ļ谵���������Ÿ������ӣ�������ż�����Ѫ����
�����������ż���Ƥ�ޡ�������һ�����ţ�����С�ڣ������Ǽ�
���ҡ�
LONG);
  set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"yongdao8", 
]));

  set("objects", ([ /* sizeof() == 1*/
  __DIR__"npc/yao1" : 1,    
  __DIR__"npc/xing" : 1,
]));


  setup();
}

