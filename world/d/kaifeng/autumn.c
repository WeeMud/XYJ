// cracked by vikee 2/09/2002   vikee@263.net
// create by snowcat.c 2/8/1997

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

�����ǳ�����ֱ�ǳȻ�ɫ�������������������紵ɽ��Ҷͼ��
�ȱ߷������β輸���ɹ��������Ϣ���ġ����߸���һͨ����
��������̨��

LONG);

  set("exits", ([
        "west"   : __DIR__"south",
        "north"   : __DIR__"east",
      ]));

  setup();
}




