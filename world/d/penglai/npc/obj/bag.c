// cracked by vikee 2/09/2002   vikee@263.net
inherit ITEM;

void create()
{
        set_name("��ң��", ({ "xiaoyao dai","bag","dai" }) );
        set_weight(10000);
        set_max_encumbrance(50000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ������������ӿڴ�����������ȴ�൱�ĳ������൱���͡�\n");
                set("value", 0);
		set("no_sell",1);
        }
}

int is_container() { return 1; }

