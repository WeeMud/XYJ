// cracked by vikee 2/09/2002   vikee@263.net
// created by ajax on 7/8/1999

#include <weapon.h>

inherit F_UNIQUE;

inherit SWORD;

void create()
{
	set_name("�Ͻ���", ({ "zijin xiao","xiao","zijinxiao"}) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "wood");
		set("long", "�����ӵ��Ͻ����˵�����Ϻ����������һ���������ġ���\n");
                set("no_sell", 1);
                set("no_drop", 1);
                set("no_put", 1);
                set("value", 30000);
                set("replace_file", "/d/obj/weapon/sword/yudi");
		set("wield_msg", "$N����$n������������Ϊ����������Ϻ������ˡ�\n");
		set("unwield_msg", "$N����ή�ң��޾���ɵĽ�$n������䡣\n");
       	        set("weapon_prop/int", 2);
                set("music/type", "xiao");
	}
	init_sword(15);
	setup();
}
