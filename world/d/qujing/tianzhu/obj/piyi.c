// cracked by vikee 2/09/2002   vikee@263.net
#include <armor.h>

inherit CLOTH;

void create()
{
  set_name("ϬţƤ��", ({"xiniu piyi", "piyi", "yi"}));
  set_weight(4000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("value", 5000);
    set("material", "leather");
    set("armor_prop/armor", 25);
  }
  setup();
}

