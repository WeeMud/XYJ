// cracked by vikee 2/09/2002   vikee@263.net
// create by snowcat.c 12/8/1997

inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("��ȫ��", ({ "kao quanyang", "quanyang", "yang", "lamb" }) );
  set_weight(1050);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long", "һֻ������͸�˵�С����\n");
    set("unit", "ֻ");
    set("value", 6000);
    set("food_remaining", 20);
    set("food_supply", 40);
    set("material", "meat");
  }
  setup();
}

