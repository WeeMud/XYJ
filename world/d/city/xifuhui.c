// cracked by vikee 2/09/2002   vikee@263.net
//changan city

inherit ROOM;

void create ()
{
        set ("short", "ϲ����");
        set ("long", @LONG

�������ھ���һ��ϲ�磬�����ŵƽ�ʣ�̨�ϸߵ����һЩ��Ů��
�������ֶ��裬�����С����������ϲ��;ơ���Χ������ǰ��ף��
�Ŀ��ˣ����ַǷ���
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
		"south" : __DIR__"baihu-w2",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/boss" : 1,
        ]));


//        set("outdoors", "changan");
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}


