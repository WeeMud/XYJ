// cracked by vikee 2/09/2002   vikee@263.net
//changan city

inherit ROOM;

void create ()
{
        set ("short", "�׻����");
        set ("long", @LONG

�������ǰ׻���ֵ����Σ�����С������Լ����һ����Ĳ��ã�����
��һ�������ӣ���дһ�����ԡ��֡���������һ��������������լ��
����Сͬ��������ˣ��
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
		"south" : __DIR__"beiyin1",
                "north" : __DIR__"caotang",
                "west" : __DIR__"ximen",
                "east" : __DIR__"baihu-w2",
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



