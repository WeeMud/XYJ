// cracked by vikee 2/09/2002   vikee@263.net
//changan city

inherit ROOM;

void create ()
{
        set ("short", "���");
        set ("long", @LONG

�⻧��լ�ӽṹ�Ͽ������൱����ģ���ʾ���⻧�˼���ǰ�ƺ�����
��������֪����һ����ҵ���ʼ˥���ˣ���������Ҳ��֮���ʧ�ޡ�
�����⻧�˼ҵ��������Ӹ������������ֺ��У�������ҵ��
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
		"east" : __DIR__"beiyin3",
        ]));

        set("objects", 
        ([ //sizeof() == 1
		__DIR__"npc/xiaopizi" : 2,
        ]));


//        set("outdoors", "changan");
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}



