// cracked by vikee 2/09/2002   vikee@263.net
// by snowcat oct 15 1997

inherit ITEM;
inherit F_FOOD;

void create()
{
  string name = "ʱ���߲�";
  set_name(name, ({"shuxian shucai", "shucai", "shucai"}));
  set_weight(1000);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "һ�����˴��ѵ�"+name+"��\n");
    set("unit", "��");
    set("value", 250);
    set("food_remaining", 5);
    set("food_supply", 25);
  }
}
