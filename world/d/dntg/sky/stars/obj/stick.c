// cracked by vikee 2/09/2002   vikee@263.net
// bintiegun.c

#include <weapon.h>
#include "self_destruct.c";

inherit STICK;

void create()
{
	set_name("����", ({ "stick" }) );
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 200);
		set("material", "steel");
		set("long", "һ���������������������\n");
		set("wield_msg", "$N����һ��$n��˳�����˸�������\n");
		set("unwield_msg", "$N����һ������$n��غ�����\n");
	}
	init_stick(35);
	setup();
}
