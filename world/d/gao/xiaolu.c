// cracked by vikee 2/09/2002   vikee@263.net
// xiaolu.c

inherit ROOM;

void create()
{
  set ("short", "С·");
  set ("long", @LONG

�߼Һ�ǽ���һ��С·�������Ӽ����������������ǰ��˶�ߵ���
�ݣ�ÿ��һ�����ᾪ�����С���ӣ���ЩС���ƻ��ĵ�������ϣ�����
LONG);
set("exits", ([ /* sizeof() == 4 */
"north" : __DIR__"xiaolin",
]));

        set("outdoors", 1);
        set("no_clean_up", 0);
        setup();
}
void init()
{
        add_action("do_climb", "climb");
}
int do_climb(string arg)
{       object me;
        me=this_player();

        if ( !arg || ((arg != "wall") ))
                return notify_fail("��Ҫ��ʲô��\n");
        else
                message_vision("$Nһ��ǽͷ�����˹�ȥ��\n", me);
                me->move("/d/gao/huayuan");
                tell_room( environment(me), "�����ˡ�һ����" + me->name() + "��ǽͷ������������\n", ({me}) );
                return 1;
}


