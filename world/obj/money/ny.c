// cracked by vikee 2/09/2002   vikee@263.net
// gold.c

inherit ITEM;
string *names = ({
	"״Ԫ����",
	"�ʶ�����",
	"�˱�����",
});
void create()
{
	set_name(names[random(sizeof(names))], ({"happy_new_year"}));
//	set_name("�ƽ�", ({"gold", "ingot", "gold_money"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ������С�����,ֻ�й���ʱ���ܼ�����\n");
		set("unit", "��");
		set("value", 8888);
//		set("base_value", 9999);
//		set("base_unit", "��");
//		set("base_weight", 37);
	}
	setup();
//	set_amount(1);
}

