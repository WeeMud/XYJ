// cracked by vikee 2/09/2002   vikee@263.net
// hammer.c

#include <weapon.h>

inherit SPEAR;

void create()
{
        set_name("��ǹ", ({"spear", "qiang"}));
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�ѳ�ǹ��ǹ���������⣮\n");
                set("value", 500);
                set("material", "iron");
                set("wield_msg", "$N�ó�һ��$n���������С�\n");
                set("unwield_msg", "$N�������е�$n��\n");
        }

        init_spear(25);
        setup();
}
