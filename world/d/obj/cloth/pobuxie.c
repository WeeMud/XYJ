// cracked by vikee 2/09/2002   vikee@263.net
//pobuxie.c
#include <armor.h>

inherit BOOTS;

void create()
{
	set_name("�Ʋ�Ь", ({"po buxie", "buxie", "shoes"}));
	set_weight(800);
	if( clonep() ) set_default_object(__FILE__);
	else 
	{
		set("unit", "˫");
		set("material", "cloth");
		set("armor_prop/armor", 1);
	}
	setup();
}

