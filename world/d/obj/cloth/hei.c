// cracked by vikee 2/09/2002   vikee@263.net
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("����", ({"black cloth", "cloth"}));
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("long", "һ����ɫ�Ĳ��ۣ�һ˿��ɫҲû�У�\n");
                set("unit", "��");
                set("value", 200);
                set("armor_prop/armor", 5);

        }
        setup();
}
