// cracked by vikee 2/09/2002   vikee@263.net
// xueli.c ѩ��

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("ƻ��", ({"ping guo", "apple","pingguo"}));
	set_weight(40);
	if (clonep())
		set_default_object(__FILE__);
	else {
                set("long", "�ִ��ִ����ƻ����\n");
                set("unit", "��");
		set("value", 50);
		set("food_remaining", 4);
		set("food_supply", 30);
	}
}
