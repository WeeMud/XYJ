// cracked by vikee 2/09/2002   vikee@263.net
inherit ROOM;

void create ()
{
  set ("short", "�����");
  set ("long", @LONG

��������Խ��Խ�ܣ���ǰ���޵�·��ѭ������ż��Ұ�����
С���ܹ�������ϤϤ���µ�������
LONG);
  set("exits", ([ /* sizeof() == 4 */
  "northeast" : __DIR__"jiandi2", 
  "west" : __DIR__"qingcao1",
]));

  set("outdoors", 1);

  setup();
}

