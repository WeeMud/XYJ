// cracked by vikee 2/09/2002   vikee@263.net
// Room: some place in ��ţ����
// jingge.c

inherit ROOM;

void create()
{
  set ("short", "С��");
  set ("long", @LONG

�����Ǿ����е�һ��С�ң�Ϊ�������ж������ṩ��һ��������
�ط���ǽ�Ϲ���һ��������д�ţ�Ǳ˼�붨���ĸ����ɷ���Ĵ��֣�
LONG);
set("exits", ([ /* sizeof() == 4 */
"down": __DIR__"jingge",
]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}



