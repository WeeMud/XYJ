// cracked by vikee 2/09/2002   vikee@263.net
// dumpling.c

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("�����ڰ���", ({"roubao", "bao"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ�������硢�����ڵ������ڹ������ӡ�\n");
                set("unit", "��");
                set("value", 25);
                set("food_remaining", 1);
                set("food_supply", 60);
        }
}

