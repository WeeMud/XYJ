// cracked by vikee 2/09/2002   vikee@263.net
// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG

�����Ｘյ�����͵��յ�����ͨ����������Ķ��ڷ���һ�໨
ľǶ����һ���λ���������������͸�������̳�ӣ�����
ʢ�������͡�

LONG);

  set("exits", ([
        "west"   : __DIR__"tongdao2",
      ]));
  set("objects", ([
        __DIR__"npc/pi2"  : 1,
      ]));

  setup();
}



