// cracked by vikee 2/09/2002   vikee@263.net
//changan city

inherit ROOM;

void create ()
{
        set ("short", "�������");
        set ("long", @LONG

��������վ��һ��������ݵĽ������У��������Ż�ɫ��ϸɰ��һȺ
��ʮ�������������������Ŭ���ز�����, ����һ�����꺺���ڲ�ͣ
�ĺ��ź��ӣ�������ܡ�
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "south" : __DIR__"qinglong-e1",
      "north" : __DIR__"misc/kantai",
		"east" : __DIR__"wuguanzhong",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/dizi" : 4,
		__DIR__"npc/jiaotou" : 1,
        ]));


        set("outdoors", "changan");
	set("no_clean_up", 0);
        setup();
}
void init()
{
        add_action("do_skills", "skills");
}

int do_skills(string arg)
{       object ob;
        object me;
        me=this_player();
        if(!(ob = present("fan luping", environment(me))))
                return
notify_fail("ֻ����ʦ����ʦͽ��ϵ�����ܲ쿴���˵ļ��ܡ�\n");
        if ( (arg != "fan") )
                return
notify_fail("ֻ����ʦ����ʦͽ��ϵ�����ܲ쿴���˵ļ��ܡ�\n");
        else
write("
��«ƽĿǰ��ѧ���ļ��ܣ�

  �����Ṧ (dodge)                         - �������  30/    0
  �ڹ��ķ� (force)                         - �������  30/    0
  ����ж��֮�� (parry)                     - �������  30/    0
  �˻���֮�� (unarmed)                   - ������  30/    0

\n");
                return 1;
}

