// cracked by vikee 2/09/2002   vikee@263.net
//changan city

inherit ROOM;

void create ()
{
        set ("short", "���̨");
        set ("long", @LONG

������ǳ����������̨����͢ÿ��ļ�����ʽ����������С�����
�㳡�ϻ��Ű���ͼ�Σ���Χ������һЩʩ��ʱ�õ����ߣ����̨����
����������Ԭ����ܿ������￴��������Ӱ��
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "east" : __DIR__"xuanwu-n1",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/yuantiangang" : 1,
        ]));


        set("outdoors", "changan");
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}

