// cracked by vikee 2/09/2002   vikee@263.net
// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "ɽ·");
  set ("long", @LONG

ɽ·��Ϊ����ն���������һ��ͻأ����ʯ�ڶ��ͣ�Զ��
���͵ĺ����϶������ش���������Ұ�ַ紵�ݶ�������ë���
Ȼ�����������˽Ų���

LONG);

  set("exits", ([
        "northup"   : __DIR__"shanlu9",
        "southeast"   : "/d/qujing/yuhua/xiaolu2",
      ]));
  set("outdoors", __DIR__);

  setup();
}



