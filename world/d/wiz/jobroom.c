// cracked by vikee 2/09/2002   vikee@263.net
// Room: /d/wiz/jobroom.c

inherit ROOM;

void create ()
{
  set ("short", "�������ȼ���");
  set ("long", @LONG
��������ʦ�Ǳ����Լ��������ȵļ��ң�ͬʱҲ�Ǵ���ʦץ����
�ĸ��ݣ�������й���������ó��������������Ĺ������ȣ����̫
��û�п�����Ĺ������ȱ��棬����ʦ�ǻ���Ϊ��û������ָ�ɹ�����
��Ҫ������Ȼ����Ҳ�п��ܻᱻ������Ѿ�������ʦ�Ĺ�����������
����֡�
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"wizroom.c",
  "west"  : __DIR__"menpai_room",
]));

  setup();
        call_other( "/obj/board/xyj_b", "???" );

}
