// cracked by vikee 2/09/2002   vikee@263.net
inherit ROOM;

void create ()
{
  set ("short", "��");
  set ("long", @LONG

���ڷ���һ��Ѫ������ǽ�Ϲ����͵ƣ����������ĵƹ�������
����ǰ��ĵ�·��
LONG);
  set("exits", ([ /* sizeof() == 4 */
  "northwest" : __DIR__"yongdao4", 
  "southwest" : __DIR__"yongdao1",
]));
  set("objects", ([ /* sizeof() == 1*/
  __DIR__"npc/yao1" : 3,    
]));



  setup();
}

