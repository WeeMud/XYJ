// cracked by vikee 2/09/2002   vikee@263.net
// Room: /d/33tian/west1
inherit ROOM;

void create ()
{
  set ("short", "�����");
  set ("long", @LONG

�Ĵ���ããһƬ�����ƺ�Ʈ�ڰ���֮�ϡ����ߣ��ϱߣ��ͱ��߶�����
Զ��ֻ�����ߣ������ֳ�һ����������Ϻ����һ����������Ľ�
�ң���д�š�����������
LONG);

  set("light_up", 1);
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"doushuai-gate",
  "east" : __DIR__"33tian",
]));

  setup();
}
