// cracked by vikee 2/09/2002   vikee@263.net
// create by snowcat jan 21 1998

inherit ROOM;

void create ()
{
  set ("short", "�����");
  set ("long", @LONG

����˧���ߴ���ΰ���������ӭ�����ÿ������϶����Ŵ���ͷ��
��ǰ�м�����ͷ���Եı�ʿ������Ѳ�ߣ�������Ң���֣����������
��˧���ڡ�

LONG);

  set("exits", ([
        "east" : __DIR__"shuaifu",
        "west" : __DIR__"yao1",
      ]));
  set("objects", ([
        __DIR__"npc/zhubing" :  2,
      ]));

  setup();
}


