// cracked by vikee 2/09/2002   vikee@263.net
//changan city

inherit ROOM;

void create ()
{
        set ("short", "�������");
        set ("long", @LONG

������һ��������ʯ�����ϣ����߾Ϳ�Ҫ���˳��ţ�ԶԶ����һЩ
��������Ѳ�ߡ�����ֱͨ�������ġ������ǳ���һ�������������
��������Ů�ǽ�����������Ϊ���֡�
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
		"south" : "/d/eastway/wangnan1",
                "north" : __DIR__"chenghuang",
                "west" : __DIR__"qinglong-e2",
                "east" : __DIR__"dongmen",
        ]));

        set("objects", 
        ([ //sizeof() == 1
//                __DIR__"npc/youxia" : 1,
        ]));


        set("outdoors", "changan");
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}

