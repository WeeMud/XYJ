
//inherit ITEM;

#include <weapon.h>
inherit SWORD;

void create()
{
	set_name("��ʮ��ս����", ({"fighter", "j15 fighter","sword"}));
	set_weight(200000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�ܼ�ʮ�形��ս������\n");
		set("value", 200000);
		set("material", "steel");
		set("no_get",1);
		set("no_put",1);
		//set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		//set("unwield_msg", "$N�����е�$n��ؽ��ʡ�\n");
	}
	init_sword(225);
	setup();
}



