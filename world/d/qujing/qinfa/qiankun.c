// cracked by vikee 2/09/2002   vikee@263.net
// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "Ǭ����");
  set ("long", @LONG

����������һ��ˣ�����������Ʈ���������濴ȥ�е�����
¥����������������֮���ڡ����������ֵĽֵ�����ʱ����һ
Щ���ӵ�������

LONG);

  set("exits", ([
        "east"    : __DIR__"gongmen",
        "west"    : __DIR__"jiedao2",
        "south"    : __DIR__"zhongshi",
      ]));
  set("outdoors",__DIR__"");
  setup();
}

