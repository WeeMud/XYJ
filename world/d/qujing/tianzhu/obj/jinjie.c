// cracked by vikee 2/09/2002   vikee@263.net
#include <armor.h>

inherit FINGER;

void create()
{
  set_name("���ָ", ({ "jin jie", "jinjie", "ring" }));
  set("weight", 400);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("value", 9000);
    set("material", "gold");
    set("armor_prop/armor", 1);
    set("armor_prop/personality", 1);
  }
  setup();
}       

