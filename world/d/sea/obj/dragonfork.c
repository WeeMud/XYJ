// cracked by vikee 2/09/2002   vikee@263.net
#include <weapon.h>

inherit FORK;

void create()
{
        set_name("���ǲ�", ({ "dragon fork", "cha","fork" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 5000);
                set("material", "iron");
                set("long", "һ�����������ǲ档\n");
                set("wield_msg", "$N����һ��$n����ͷ�ϻ�����һȦ��\n");
        }
        init_fork(50);
        setup();
}

