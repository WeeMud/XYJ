// cracked by vikee 2/09/2002   vikee@263.net
// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "���ε�");
  set ("long", @LONG

һ�����ɵ���ש����С�꣬����������һ�����⡱�ֵ�������
�����Ǽ���̴��ľ��������̫ʦ�Ρ�ľ���Ϸ��ż����򿪵���
�ϻ�ӣ������Ÿ������Ρ�

LONG);

  set("exits", ([
        "north"   : __DIR__"jiedao93",
      ]));
  set("objects", ([
        __DIR__"npc/wu"   : 1,
      ]));

  setup();
}


