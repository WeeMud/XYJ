// cracked by vikee 2/09/2002   vikee@263.net
// create by snowcat jan 21 1998

inherit ROOM;

void create ()
{
  set ("short", "���׳�");
  set ("long", @LONG

���ฮ�Ŀ��׳���ѻ��˲��ٸ��ָ����Ŀ��׷��ߣ��������Ǵ��Ĵ�
�ռ���������Щ���׷����ڷ�����ѡ֮�󣬻����������ǽ���������
ת��������󳼴������׳��ı����ǳ��ڡ�

LONG);

  set("exits", ([
        "north" : __DIR__"zhong",
      ]));
  set("objects", ([
        __DIR__"npc/xiaotong" :  1,
        __DIR__"npc/xpo" :  1,
      ]));

  setup();
}


