// cracked by vikee 2/09/2002   vikee@263.net
//changan city

inherit ROOM;

void create ()
{
        set ("short", "������");
        set ("long", @LONG

��һ���žͿ����������ϰ��Ÿ��ֱ��������ϰٽ��صĴ󵶵������
�ӵķɻ�ʯ����Ӧ�о��С�Ů�ϰ�����Ӣ������Զ��СŮ����Ҳ����
Զ�ھֶ��ϰ壬����������ü��
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "north" : __DIR__"qinglong-e1",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/xiaoxiao" : 1,
        ]));


//        set("outdoors", "changan");
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}

