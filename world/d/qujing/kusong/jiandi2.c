// cracked by vikee 2/09/2002   vikee@263.net
inherit ROOM;

void create ()
{
  set ("short", "����С·");
  set ("long", @LONG

������������Ȫˮ��������������Щ��������С���Χ������
���������ݣ������ֳ�����Ұ����
LONG);
  set("exits", ([ /* sizeof() == 4 */
  "southeast" : __DIR__"jiandi",
  "northeast" : __DIR__"wangyue", 
  "southwest" : __DIR__"qingcao0",
]));
  set("outdoors",1);


  setup();
}

