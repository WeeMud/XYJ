// cracked by vikee 2/09/2002   vikee@263.net
// create by snowcat jan 21 1998

inherit ROOM;

void create ()
{
  set ("short", "����·");
  set ("long", @LONG

һ��С·���ź����������ƣ����ߵĺ�ˮ����һ�㣬�紵����ˮ����
����΢�����ں�ˮ�ϻζ��ų����ĵ�Ӱ����ʱ��ݺ����������������
�����Ŀ�������

LONG);

  set("exits", ([
        "east" : __DIR__"xihu2",
        "southwest" : __DIR__"xihu3",
      ]));

  set("outdoors", __DIR__);

  setup();
}


