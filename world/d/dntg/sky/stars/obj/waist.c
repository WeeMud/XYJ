// cracked by vikee 2/09/2002   vikee@263.net
#include <armor.h>
#include "self_destruct.c";

inherit WAIST;


void create()
{
  set_name("����", ({"waist"}));
  set_weight(5000);
  if ( clonep() )
     set_default_object(__FILE__);
  else {
   set("unit", "��");
   set("value", 200);
   set("material", "metal");
   set("armor_prop/armor", 14);
   set("armor_prop/dodge", -1);
  }
  set("no_sell",1);
  setup();
}
