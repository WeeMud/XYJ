// cracked by vikee 2/09/2002   vikee@263.net
//changan city

inherit ROOM;

void create ()
{
        set ("short", "Ԭ�ϲ���");
        set ("long", @LONG

������Ԭ�س��������Բ��ֵĵط�������Ԭ�سϣ������������˲�����
�����ǵ��������̨������Ԭ����常��С�������շÿ����ﲻ����
���Ϲ�һ�����������ǣ�
            ֪�׶�������̸����Ѹ
            �����������±ʹ���
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "south" : __DIR__"baihu-w3",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/shouchen" : 1,
		__DIR__"npc/xiushi" : 1,
        ]));


//        set("outdoors", "changan");
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}



