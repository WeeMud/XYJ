// cracked by vikee 2/09/2002   vikee@263.net

inherit ITEM;

void create()
{
        set_name("����", ({ "bag" }) );
        set_weight(500);
        set_max_encumbrance(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ��Ѱ���Ĳ�������������װһЩ���\n");
                set("value", 50);
        }
}

int is_container() { return 1; }

