// cracked by vikee 2/09/2002   vikee@263.net
// by snowcat oct 15 1997

inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("�����", ({"roujia mo", "roujiamo", "mo"}));
  set_weight(1000);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "һֻ�Ⱥ���������ɡ�\n");
    set("unit", "ֻ");
    set("value", 200);
    set("food_remaining", 6);
    set("food_supply", 35);
  }
}
