// cracked by vikee 2/09/2002   vikee@263.net
// Room: /d/huanggong/yhy1a
inherit ROOM;

void create ()
{
  set ("short", "����԰");
  set ("long", @LONG

�д�����������԰����������������ɫ���η��˵��滨����
�м���������ת������ʯ��С����Ϊ������紵������
���ⴼ�����ޱȣ����˻�Ȼ����

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"fst.c",
  "south" : __DIR__"yhy2a",
]));
  set("outdoors", "/d/huanggong");

  setup();
}
