// cracked by vikee 2/09/2002   vikee@263.net
//changan city

inherit ROOM;

void create ()
{
        set ("short", "������");
        set ("long", @LONG

һ��СС�Ķ��ң�Ҳû�д�����������ֻ����һյС�͵ƣ��Ե��ر�
�谵��һ�һ����ռȥ����Ĵ�룬����м�����棬Ҳ���ƾɲ�����
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "west" : __DIR__"baodian",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/faming" : 1,
        ]));


//        set("outdoors", "changan");
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}


