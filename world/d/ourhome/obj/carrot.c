// cracked by vikee 2/09/2002   vikee@263.net
// carrot.c ���ܲ�

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("���ܲ�", ({"carrot", "huluobo"}));
	set_weight(40);
	if (clonep())
		set_default_object(__FILE__);
	else {
                set("long", "һ�����ʿ��˵ĺ��ܲ���\n");
                set("unit", "��");
		set("value", 80);
		set("food_remaining", 4);
		set("food_supply", 30);
	}
}
