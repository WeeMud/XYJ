// cracked by vikee 2/09/2002   vikee@263.net
// surcoat.c

#include <armor.h>

inherit EQUIP;

void setup()
{
	if( clonep(this_object()) ) return;

	set("armor_type", TYPE_SURCOAT);
	if( !query("armor_apply/dodge")
	&&	weight() > 3000 )
		set("armor_prop/dodge", - weight() / 3000 );
}
