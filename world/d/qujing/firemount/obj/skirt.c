// cracked by vikee 2/09/2002   vikee@263.net
// pink_cloth.c

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
  set_name(HIG "�Ž�ȹ" NOR, ({ "palm skirt", "skirt" }) );
  set_weight(1000);
  if (clonep())
    set_default_object(__FILE__);
  else
  {
    set("long", "һ����ɫ�İ�Ҷ�Ž�ȹ��\n");
    set("unit", "��");
    set("value", 0);
    set("material", "cloth");
    set("armor_prop/armor", 10);
    set("armor_prop/personality", 3);
  }
  setup();
}


