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
    "northwest" : "/d/qujing/pansi/ling5",
    "southeast" : __DIR__"lin5",
  ]));
  set("outdoors", __DIR__"");
  setup();
}
