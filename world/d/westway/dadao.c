// cracked by vikee 2/09/2002   vikee@263.net
// create by snowcat.c 4/8/1997
// room: /d/westway/dadao.c

inherit ROOM;

void create ()
{
  set ("short", "���");
  set ("long", @LONG

����һ�������Ĵ������ԶԶ��ɽ�����ƹ�����ز�ã������
������ش��ţ�����·������ķ�ɳ��������������Ե����ˣ�
���ڴҴ�ææ�ظ���·�������ǽ�ǿ����������ٸ�һ��·��
���Ե��������ˡ�

LONG);

  set("exits", ([
        "east" : __DIR__"jincheng",
        "west" : __DIR__"yongjing",
      ]));
  set("outdoors", __DIR__);

  setup();
}



