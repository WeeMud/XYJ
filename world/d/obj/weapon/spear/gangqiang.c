// cracked by vikee 2/09/2002   vikee@263.net
// gangqiang.c, created 5-28-97 pickle

#include <weapon.h>
#include <ansi.h>

inherit SPEAR;

void create()
{
  set_name(HIC "���ǹ" NOR, ({ "steel spear","qiang","spear" }));
  set_weight(9000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("value", 14000);
    set("material", "steel");
    set("long", "һ���ںڵĸ�ǹ��������ǹӧ��û�С�\n");
    set("wield_msg", "$N������һ��$n����Ȼ�������ݡ�\n");
    set("unwield_msg", "$N����$n����˳��ߣһ��ǹӧ��ȴû�ҵ���\n");
  }
  init_spear(60);
  setup();
}
