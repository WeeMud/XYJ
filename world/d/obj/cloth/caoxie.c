// cracked by vikee 2/09/2002   vikee@263.net
#include <armor.h>

inherit BOOTS;

void create()
{
        set_name("��Ь", ({ "cao xie", "xie", "shoes" }) );
        set_weight(900);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "һ˫�����˴��Ĳ�Ь��\n");
                set("material", "wood");
                set("unit", "˫");
                set("value", 10);
        }
        setup();
}

