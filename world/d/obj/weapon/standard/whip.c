// cracked by vikee 2/09/2002   vikee@263.net
// blade.c

#include <weapon.h>

inherit WHIP;

void create()
{
        set_name("Ƥ��", ({"pi bian", "pibian", "bian", "whip"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","һ��������Ƥ�ޣ�\n");
                set("unit", "��");
                set("value", 500);
        }
        init_whip(15);
        setup();
}

