// cracked by vikee 2/09/2002   vikee@263.net
#include <armor.h>

inherit SURCOAT;

void create()
{
  set_name("��Ƥ���", ({ "hupi dachang", "dachang", "chang" }) );
  set_weight(1600);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("material", "leather");
    set("value", 1600);
    set("armor_prop/armor", 4);
  }
  setup();
}

