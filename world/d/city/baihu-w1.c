// cracked by vikee 2/09/2002   vikee@263.net
//changan city

inherit ROOM;

void create ()
{
        set ("short", "�׻����");
        set ("long", @LONG

������һ��������ʯ�����ϣ�����Ϳ쵽�������ˣ����Կ�����¥
������ǰ�����澲������һ����֣���������Щ�����ˡ�������һ��
Ǯׯ�����쿴�����˽����������Ե��������¡��
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
		"south" : __DIR__"bank",
                "north" : __DIR__"bookstore",
                "west" : __DIR__"baihu-w2",
                "east" : __DIR__"center",
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


