// cracked by vikee 2/09/2002   vikee@263.net
// shoupi.c

#include <armor.h>

inherit WAIST;

void create()
{
        set_name("����", ({"waist"}));
	set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "leather");
                set("unit", "��");
		set("armor_prop/armor", 1);
        }
        setup();
}

