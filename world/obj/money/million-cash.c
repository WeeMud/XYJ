// cracked by vikee 2/09/2002   vikee@263.net
// million.c

inherit MONEY;

void create()
{
        set_name("һ��������Ʊ", ({"million-cash", "million-cash_money", "cash"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("money_id", "million-cash");
                set("long", "һ�����ֵһ���������ӵ���Ʊ��\n");
		set("unit", "��");
                set("base_value", 100000000);
		set("base_unit", "��");
		set("base_weight", 3);
	}
	set_amount(1);
}

