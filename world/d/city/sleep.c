// cracked by vikee 2/09/2002   vikee@263.net
inherit ROOM;

inherit "/d/wiz/no_get";
void create()
{
        set("short", "�͵�˯��");
        set("long", @LONG

��ջ��һ��˯��������ɸɾ�����һ�Ŵ󴲣�����������Ϣ˯����
LONG
        );
  set("no_magic",1);

        set("sleep_room",1);
        set("if_bed",1);

        set("exits", ([
                "west" : __DIR__"kezhan",
        ]));

        setup();
}

int valid_leave(object me, string dir)
{
        me->delete_temp("rent_paid");
        return ::valid_leave(me, dir);
}

