// cracked by vikee 2/09/2002   vikee@263.net
inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG

������һƬ��ڣ�ͷ�������������������ס�˹��ߣ������ѱ�
�����ϱ�����紵������������������ȴ�������˷�����
LONG);
  set("exits", ([ /* sizeof() == 4 */
  "south" :  "/d/qujing/wuji/shandao5",
  "northeast" : __DIR__"songlin3",
  "northwest" : __DIR__"songlin2",
  "southwest" : __DIR__"songlin3",
  "southeast" : __DIR__"songlin2",
]));



  setup();
}

