// cracked by vikee 2/09/2002   vikee@263.net
//changan city

inherit ROOM;

void create ()
{
        set ("short", "�׻����");
        set ("long", @LONG

������һ��������ʯ�����ϣ�����Ϳ쵽�������ˣ����Կ�����¥
������ǰ�������ǼҴ�ľ�¥�������������£����ַǷ�������ȴ��
�ҹ�ģ��С����Ժ�������Ϳ�Ҫ�����ˡ�
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
		"south" : __DIR__"huashengsi",
                "north" : __DIR__"xifuhui",
                "west" : __DIR__"baihu-w3",
                "east" : __DIR__"baihu-w1",
        ]));

        set("objects", 
        ([ //sizeof() == 1
//                __DIR__"npc/libai" : 1,
        ]));


        set("outdoors", "changan");
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}


