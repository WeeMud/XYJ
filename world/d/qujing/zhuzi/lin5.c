// cracked by vikee 2/09/2002   vikee@263.net
// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "����·");
  set ("long", @LONG

�����ڳ���������·�ϣ������������ģ���紵��Ҷ��֦�裬ʱ��
ʱ����Զ���Ļ�ХԳ�䡣���˲��������ؼӿ첽����

LONG);

  set("exits", ([ 
    "northwest" : __DIR__"lin3",
    "east" : __DIR__"lin6",
  ]));
  set("outdoors", __DIR__"");
  setup();
}
