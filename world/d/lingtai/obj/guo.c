// cracked by vikee 2/09/2002   vikee@263.net
// songguo.c

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("松果", ({"songguo"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一个黑色的松果．\n");
                set("unit", "个");
                set("food_remaining", 1);
                set("food_supply", 60);
        }
}

