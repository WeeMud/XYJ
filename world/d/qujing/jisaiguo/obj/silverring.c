// cracked by vikee 2/09/2002   vikee@263.net
#include <armor.h>

inherit FINGER;

void create()
{
        set_name("����ָ", ({ "silver ring", "ring" }));
        set("weight", 500);
        set("long", "һ������ӲӵĽ�ָ��\n");
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 400);
                set("material", "gold");
		set("wear_msg", "$N����һ��$n��\n");
                set("armor_prop/armor", 1);
        }
        setup();
}

