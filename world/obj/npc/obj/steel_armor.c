// cracked by vikee 2/09/2002   vikee@263.net
// steel_armor.c

#include <armor.h>

inherit ARMOR;

void create()
{
	set_name("�ظ�����", ({ "steel armor", "armor" }) );
	set_weight(70000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "steel");
		set("value", 9000);
		set("armor_prop/armor", 70);
		set("armor_prop/dodge", -30);
	}
	setup();
}
