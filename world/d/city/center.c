// cracked by vikee 2/09/2002   vikee@263.net
//changan city

inherit ROOM;

void create ()
{
        set ("short", "ʮ�ֽ�ͷ");
        set ("long", @LONG

������ǳ����ǵ����ģ�������ֽ����ڴˡ�һ��Ρ��ߴ����¥��
����ǰ��������Щ���ơ�ÿ���峿�����������������ŵ���������
�򳤰��ǵĴ��С�·�ڳ�ˮ�����������˳����ϡ�
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
		"south" : __DIR__"zhuque-s1",
        "down": __DIR__"recycle",
                "north" : __DIR__"xuanwu-n1",
                "west" : __DIR__"baihu-w1",
                "east" : __DIR__"qinglong-e1",
//		"northwest" : "/d/jjf/qilin",
//		"southeast" : "/d/jjf/zuixing",
        ]));
        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/libai" : 1,
		"/d/qujing/wuzhuang/npc/zhangguolao": 1,
        ]));

        set("outdoors", "changan");
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}

