// cracked by vikee 2/09/2002   vikee@263.net
// create by snowcat jan 21 1998

inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG

���ฮ�ı����������С���󲿷ֱ����������ռ�������������ѡ֮
���صȾ�Ʒ��ר���͵������������������ϵȼ�Ʒ�;���󳼴���
�����졣���������ϱ���һ��ͨ���ฮ���á�

LONG);

  set("exits", ([
        "south" : __DIR__"zhong",
      ]));
  set("objects", ([
        __DIR__"npc/xiaotong" :  1,
        __DIR__"npc/xgong" :  1,
      ]));

  setup();
}


