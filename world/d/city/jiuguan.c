// cracked by vikee 2/09/2002   vikee@263.net
//changan city

inherit ROOM;

void create ()
{
        set ("short", "С�ƹ�");
        set ("long", @LONG

С�ƹݲ����������ҵİ��˼��ŷ������������ʡ�С��̨�ϰ���Щ
��̳������Ҳ������Щ�����ף��ϰ׸�֮�ࡣ����һ��Ŀ������ܰ�
�յ�һ��ȼ���������ţ����ĥʱ�⡣
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
		"west" : __DIR__"beiyin2",
                "south" : __DIR__"beiyin4",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/jia" : 1,
		__DIR__"npc/kuli" : 2,
        ]));


//        set("outdoors", "changan");
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}


