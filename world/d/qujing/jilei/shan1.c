// cracked by vikee 2/09/2002   vikee@263.net
// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "ɽ��");
  set ("long", @LONG

ֻ��ɽ��·�գ����ϻ��ǹ�ͺͺ���ҹ����һƬ��������ľ��
ɭ�֣�����Х�ش�����������ҰԳ����ԶԶ�س����е���
�˵����ľ���

LONG);

  set("exits", ([
        "southeast"   : __DIR__"shan2",
        "west"   : "/d/qujing/jisaiguo/to-baoxiang5",
      ]));
  set("outdoors", __DIR__);

  setup();
}



