// cracked by vikee 2/09/2002   vikee@263.net

inherit ITEM;

void create()
{
        set_name("���", ({ "kuang" }) );
        set_weight(1000);
        set_max_encumbrance(18000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�����ƾ�ϸ���������װһЩ���\n");
                set("value", 50);
        }
}

int is_container() { return 1; }

