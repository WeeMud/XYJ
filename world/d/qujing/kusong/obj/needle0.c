// cracked by vikee 2/09/2002   vikee@263.net
#include <weapon.h>
inherit DAGGER;

void create()
{
        set_name("̫�״�", ({"taibai ci", "ci", "dagger"}));
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�������İ�������\n");
                set("value", 500);
                set("material", "steel");
                set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
        }
        init_dagger(10);
        setup();
}
