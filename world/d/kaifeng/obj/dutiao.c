// cracked by vikee 2/09/2002   vikee@263.net
// by snowcat

inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("���ж���", ({"du tiao", "dutiao", "du", "tiao"}));
  set_weight(600);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "һ�ոճ��������Ȳˡ�\n");
    set("unit", "��");
    set("value", 400);
    set("food_remaining", 8);
    set("food_supply", 25);
  }
}

