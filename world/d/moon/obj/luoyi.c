// cracked by vikee 2/09/2002   vikee@263.net
#include <armor.h>
inherit CLOTH;

void create()
{
        set_name("��ˮ����", ({"fancy skirt", "skirt"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
            set("long",
"����һ���������ǳ����ŵĳ�ȹ��ȴ��֪��ʲô�Ƴɣ�\n");
                set("value", 2200);
                set("material", "cloth");
                set("armor_type", "cloth");
                set("armor_prop/armor", 10);
		set("armor_prop/dodge", 10);
                set("armor_prop/personality", 3);
                set("female_only", 1);
             }
        setup();
}
