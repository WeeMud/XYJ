// cracked by vikee 2/09/2002   vikee@263.net
// dart.c

#include <weapon.h>

inherit THROWING;

void create()
{
        set_name("ʯ��", ({"shi kuai", "shi", "stone"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "Щ");
		set("long","һ���ʯͷ��");
                set("base_unit", "��");
                set("base_weight", 4000);
                set("fill_sea",1);
        }
        set_amount(random(10)+5);
        init_throwing(5);
        setup();
}

