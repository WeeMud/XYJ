// cracked by vikee 2/09/2002   vikee@263.net
inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

������һ��ԲԲ��ʯ�ң�������һ��̿�𣬰����ں��ůů�ġ�
���ܺ������˵�����ʮ������Ƥ��ʱ��ʱ��С������˯����
LONG);
  set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"zhongdong",
]));
        set("sleep_room",1);
        set("if_bed",1);



  setup();
}

