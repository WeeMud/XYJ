// cracked by vikee 2/09/2002   vikee@263.net
// create by snowcat jan 21 1998

inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG

�������һ�������Ĵ������·������ʯ���̳ɣ������ǳ������ľ
���Ŵ�����߳����ֿ��������дС������ǿ��⸮�ĳ��ţ�����ͨ��
�����ԶԶ����һ����ɫ�ĸ�����

LONG);

  set("exits", ([
        "west" : __DIR__"chengmen",
        "east" : __DIR__"chen2",
      ]));

  set("outdoors", __DIR__);

  setup();
}


