// cracked by vikee 2/09/2002   vikee@263.net
// rake.c

#include <weapon.h>

inherit RAKE;

void create()
{
  set_name("�ųݶ���", ({ "ding pa", "pa","rake" }) );
  set_weight(9000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("value", 8000);
    set("material", "iron");
    set("long", "һ�������ľųݸְҡ�\n");
    set("wield_msg", "$N����һ��$n������һ���ٹ�ͷ����\n");
  }
  init_rake(75);
  setup();
}


