// cracked by vikee 2/09/2002   vikee@263.net
// Room: /changan/nanchengkou.c
//cglaem...12/12/96.

inherit ROOM;

//#define FILE __DIR__"npc/qianmian"

void create ()
{
  set ("short", "�ϳǿ�");
  set ("long", @LONG

�����ǳ������ϳǿڡ�������ȥ�ѿɿ����ϳ������ﲻ������������
�������Ĺٱ�����ȥһ�Ÿ߿���ˮ������ʴ�����ɽ´�����غ����
����Ұ�������˲���̾�ⳤ���ǵش��������֮��壬����������֮
����
LONG);

  set("exits", ([ /* sizeof() == 4 */
  //"west" : __DIR__"wside1",
  "south" : __DIR__"nbridge",
  "north" : "/d/city/zhuque-s4",
  //"east" : __DIR__"eside1",
//  "southeast" : "/d/eastway/jinshi",
]));
        set("objects", 
        ([ //sizeof() == 1
                "/d/city/npc/wujiang" : 1,
                "/d/city/npc/bing" : 3,
        ]));


  set("outdoors", 1);

  setup();
}






