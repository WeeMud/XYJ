// cracked by vikee 2/09/2002   vikee@263.net
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("�𲼳���", ({ "cloth" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "cloth");
                set("armor_prop/armor", 1);
        }
        setup();
}

