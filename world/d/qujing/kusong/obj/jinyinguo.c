// cracked by vikee 2/09/2002   vikee@263.net
inherit ITEM;

void create()
{
        set_name("������", ({ "jinyin hua", "hua"}) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
        }
}

