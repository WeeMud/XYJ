// cracked by vikee 2/09/2002   vikee@263.net
// sgzl

#include <weapon.h>

inherit THROWING;

void create()
{
        set_name("����", ({"yin zhen","zhen"}));
        if( clonep() )
                set_default_object(__FILE__);
        else 
	  {
           set("long",    "һ��ϸС���廨�룬���ŵ�㺮â��\n");
           set("unit", "��");
           set("base_unit", "��");
           set("base_weight", 5);
           set("can_install", 1);
           set("value", 30);
          }
        set_amount(2000);
        init_throwing(10);
        setup();
}

