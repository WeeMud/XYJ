// cracked by vikee 2/09/2002   vikee@263.net
// blade.c

#include <weapon.h>

inherit HAMMER;

void create()
{
        set_name("�സ", ({"luochui", "hammer"}));
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
        }
        init_hammer(1);
        setup();
}

