// cracked by vikee 2/09/2002   vikee@263.net
// jinjia.c ���
#include <armor.h>
#include "self_destruct.c"

inherit ARMOR;

void create()
{
        set_name("ս��", ({"armor"}));
        set_weight(30000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", "һ��ս�ף�\n");
                set("material", "steel");
                set("value", 200);
                set("armor_prop/armor", 55);
        }
        setup();
}


