// cracked by vikee 2/09/2002   vikee@263.net
#include <armor.h>

inherit BOOTS;

void create()
{
  set_name( "¹ƤЬ", ({ "pi xie", "pixue", "xie" }) );
  set_weight(1000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "˫");
    set("long", "һ˫����Ӳ�׵�¹ƤЬ��\n");
    set("value", 140);
    set("material", "boots");
    set("armor_prop/dodge", 3);
  }
  setup();
}

