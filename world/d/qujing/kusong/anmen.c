// cracked by vikee 2/09/2002   vikee@263.net
inherit ROOM;

void create ()
{
  set ("short", "б��");
  set ("long", @LONG

�����������·�ľ�ͷ���·���һ��խխ��б�����ںڵ���
�����ף���֪��ͨ���δ�����ڹ���һ��ľ�ƣ�д�š��������
��������֡�
LONG);
  set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"yongdao5",
]));

  set("objects", ([ /* sizeof() == 1*/
  __DIR__"npc/bianfu" : 1,
  __DIR__"npc/mahuang" : 1,    
]));


  setup();
}

