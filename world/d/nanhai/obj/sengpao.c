// cracked by vikee 2/09/2002   vikee@263.net
// cloth.c
//

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
	set_name(HIY"僧袍"NOR, ({ "seng pao", "pao", "cloth" }) );
	set("long", "这是一件寻常的僧袍，是和尚们的普通装束。\n");     
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "cloth");
		set("armor_prop/armor", 15);
		set("armor_prop/spells", 10);
		set("armor_prop/dodge", 5);
	}
	setup();
}

