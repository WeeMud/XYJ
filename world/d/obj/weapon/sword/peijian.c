// cracked by vikee 2/09/2002   vikee@263.net
// �彣 


#include <weapon.h>

inherit "/d/obj/weapon/sword/anqi_container.c";

void create()
{
   set_name("�彣", ({"pei jian","jian","sword"}));
   set_weight(4000);
   if( clonep() ) 
          set_default_object(__FILE__);
   else 
     {
      set("long", "һ��������彣���������ƺ���Щ������װ(install)Щ������ȥ��\n");
      set("orilong", "һ��������彣���������ƺ���Щ������װ(install)Щ������ȥ��\n");
      set("unit", "��");
      set("value", 3000);
      set("material", "iron");
      set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
      set("unwield_msg", "$N�����е�$n��ؽ��ʡ�\n");
      set("anqi/allow", 1);
      set("anqi/max", 20);
      set("anqi/now", 0);
     }
     init_sword(20);
     setup();
}

