// cracked by vikee 2/09/2002   vikee@263.net
// rewritten by snowcat
// Room: luzhou

inherit ROOM;

void create ()
{
  set ("short", "ɳĮ����");
  set ("long", @LONG

�����ļ����ȣ�Զ������������ľ��󡣲�����Ȼˮ�ݷ��������
�������ա����ذ��հ�����ҵ����Ҳ��Ȼ�Եá�

LONG);

  set("exits", ([
    "west" : __DIR__"shalu2",
    "east" : __DIR__"luzhou2",
  ]));
  set("outdoors", "firemount");

  setup();
}
