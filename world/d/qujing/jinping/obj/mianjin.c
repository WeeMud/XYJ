// cracked by vikee 2/09/2002   vikee@263.net
 
inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("�����", ({ "you mianjin", "mianjin" }) );
  set_weight(120);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long", "һ��ը�ý�Ƶ���������\n");
    set("unit", "��");
    set("value", 140);
    set("food_remaining", 3);
    set("food_supply", 30);
  }
}

