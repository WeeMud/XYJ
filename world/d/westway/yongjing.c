// cracked by vikee 2/09/2002   vikee@263.net
// create by snowcat.c 4/8/1997
// room: /d/westway/yongjing.c

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

�������ˡ�������������һ����С�����ӣ��˿ڱȽ��ܼ�һЩ��
���ȥ����ȡ����ȥ����;�����ĳ������������Ъ�ţ���
����һ����������������ƽ�ɽ����ƽ������

LONG);

  set("exits", ([
        "east"      : __DIR__"dadao",
        "southwest" : __DIR__"pingyang",
      ]));
  set("outdoors", __DIR__);

  setup();
}





