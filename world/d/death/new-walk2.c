// cracked by vikee 2/09/2002   vikee@263.net
// zhting.c

inherit ROOM;

void create ()
{
  set ("short", "�����");
  set ("long", @LONG

���������һ�ķ���̨��̨�Ͽ��������ǳ���ɽ����ӵ�ͼ�ڡ�̨
�ϵ�ͭ����ż�������������ܵ����׻�������ð���⡣������
һ������¥�󹬵������Ҳ�൱�ĸ����ûʣ����м���������
��˾��������ȥ��
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"new-walk3",
  "west" : __DIR__"new-walk4",
  "north" : __DIR__"new-walk5",
  "south": __DIR__"new-zhaopo",
]));
  set("hell", 1);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/zhangmen" : 1,
]));
  set("valid_startroom", 1);

  setup();
}

