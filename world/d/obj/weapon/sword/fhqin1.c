// cracked by vikee 2/09/2002   vikee@263.net
// �����  


#include <weapon.h>

inherit "/d/obj/weapon/sword/anqi_container.c";

void create()
{
   set_name("�����", ({"fenghuang qin","qin","sword"}));
   set_weight(4000);
   if( clonep() ) 
          set_default_object(__FILE__);
   else 
     {
      set("long", "һ����ɫ���ɵĹ��٣�������ֻ����ķ�ˣ�����ȥ��˵Ҳ���ϰ���ı����ˡ�\n");
      set("orilong", "һ����ɫ���ɵĹ��٣�������ֻ����ķ�ˣ�����ȥ��˵Ҳ���ϰ���ı����ˡ�\n");
                set("no_sell", 1);
set("no_give", 1);
                set("no_drop", 1);
                set("no_put", 1);
      set("unit", "��");
      set("value", 20000);
      set("material", "leather");
      set("wield_msg", "$N�ӱ���ժ��һ��$n���������С�\n");
      set("unwield_msg", "$N�������е�$n��С�������ı��ر���\n");
      set("anqi/allow", 1);
      set("anqi/max", 100);
      set("anqi/now", 0);
      set("music/type", "qin");
     }
init_sword(500);
     setup();
}
int query_autoload() { return 1; }
