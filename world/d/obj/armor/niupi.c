// cracked by vikee 2/09/2002   vikee@263.net
#include <armor.h>

inherit SHIELD;

void create()
{
        set_name("ţƤ��", ({"leather shield","shield", "jia", "armor"}));
        set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "wood");
                set("value", 1000);
                set("armor_prop/armor", 15);
        }
        setup();
}


