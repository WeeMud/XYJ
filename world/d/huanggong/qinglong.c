// cracked by vikee 2/09/2002   vikee@263.net
inherit ROOM;

void create()
{
  set ("short", "������");
  set ("long", @LONG

�������Ĺ����ϳ�ǰ��Ϣ�ĵط������в����Ǻܴ󣬿�ǽ����
һ�����Σ�������һ�Ű����������в���豭����ɫ���ġ�ż
���м�����Ա���룬һ�������̹�һ���ź�
LONG);

        set("objects", ([
		__DIR__"npc/shiguan": 1,
        ]) );

        set("exits",
        ([ /* sizeof() == 4 */
                "west" : "/d/huanggong/guangchang",
        ]));
	set("no_clean_up", 1);
        setup();
}

 

