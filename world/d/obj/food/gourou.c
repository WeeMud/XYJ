// cracked by vikee 2/09/2002   vikee@263.net
// turou.c ���չ���

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("���չ���", ({"gou rou", "gourou", "gou"}));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ��������ĺ��չ���\n");
                set("unit", "��");
                set("value", 100);
                set("food_remaining", 4);
                set("food_supply", 50);
        }
}

