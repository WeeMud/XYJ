// cracked by vikee 2/09/2002   vikee@263.net
#include <armor.h>

inherit CLOTH;

void create()
{
  set_name("����", ({"guan pao", "pao"}));
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long","һ�����Ż��Ƶ���˿���ۡ�\n");
    set("material", "cloth");
    set("unit", "��");
    set("value", 400);
    set("armor_prop/armor", 5);
    set("armor_prop/personality", 1);
  }
  setup();
}

