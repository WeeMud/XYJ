// cracked by vikee 2/09/2002   vikee@263.net
// create by snowcat.c 4/8/1997
// room: /d/westway/madao.c

inherit ROOM;

void create ()
{
  set ("short", "���");
  set ("long", @LONG

һ������ר�õĳ�����·�����˴Ҵ�ææ�ظ�·�����߿쵽��
Ȫ�ˡ����Ϸ�����һƬ�ֵأ�·���ֵص����ȥ���Ǳ��Ǿ�
����Σ�յ���������

LONG);

  set("exits", ([
        "southeast" : __DIR__"yinma",
        "west"      : __DIR__"jiuquan",
      ]));
  set("outdoors", __DIR__);

  setup();
}





