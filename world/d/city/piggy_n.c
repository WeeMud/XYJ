// cracked by vikee 2/09/2002   vikee@263.net
inherit __DIR__"piggy.c";

void create()
{
    ::create();

    set ("short", "������");
    set("exits", ([
        "south": __DIR__"club3",
    ]) );
}
