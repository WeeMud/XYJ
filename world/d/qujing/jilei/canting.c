// cracked by vikee 2/09/2002   vikee@263.net
// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

������һ��ʯ����Ȼ�γɵ�ƫ��������֧��һ�ڴ�����������
���Ŵ����������һ���ܣ����������ӿ���ֱð�ͣ�ɢ��
�����˵���ζ��

LONG);

  set("exits", ([
        "east"   : __DIR__"dating",
        "southwest"   : __DIR__"cangku",
      ]));
  set("objects", ([
        __DIR__"npc/yao" : 5,
        __DIR__"obj/rou" : 3,
      ]));

  setup();
}



