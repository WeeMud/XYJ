// cracked by vikee 2/09/2002   vikee@263.net
//changan city

inherit ROOM;

void create ()
{
        set ("short", "������");
        set ("long", @LONG

�������ǳ��������ģ����һ�Ҵ����ˡ��������������ƣ��̾���
�����ڶ������������㻹Ը��������ŮҲ�ر�࣬�����˻ʵ����գ�
������ɽ�˺���
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
		"south" : __DIR__"baodian",
                "north" : __DIR__"baihu-w2",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/sengren1" : 1,
		__DIR__"npc/sengren" : 2,
        ]));


        set("outdoors", "changan");
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}


