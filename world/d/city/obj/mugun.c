// cracked by vikee 2/09/2002   vikee@263.net
#include <weapon.h>

inherit STICK;

void create()
{
        set_name("ľ��", ({"mu gun"}));
        set_weight(1400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 100);
                set("material", "wood");
                set("wield_msg", "$N��������һ�����һ��$n�������С�\n");
        }
        init_stick(15);
        setup();
}
