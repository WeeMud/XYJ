// cracked by vikee 2/09/2002   vikee@263.net
// shoe.c

#include <armor.h>

inherit BOOTS;

void create()
{
	set_name( "�廨СЬ", ({ "xiuhua xie", "xie", "shoes" }) );
	set_weight(900);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "cloth");
		set("unit", "˫");
		set("value", 300);
		set("armor_prop/armor", 1 );
		set("female_only", 1);
	}
	setup();
}
