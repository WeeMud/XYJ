// cracked by vikee 2/09/2002   vikee@263.net
// by snowcat oct 15 1997
#include <armor.h>
#include "self_destruct.c"

inherit SURCOAT;

void create()
{
  set_name("����", ({"pifeng"}));
  set_weight(4500);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "һ�����硣\n");
    set("material", "leather");
    set("unit", "��");
    set("value", 700);
    set("armor_prop/armor", 35);
  }
  setup();
}
