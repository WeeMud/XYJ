// cracked by vikee 2/09/2002   vikee@263.net
#include <weapon.h>

inherit BOW; 

void create()
{
        set_name("Ǭ����", ({"qiankun gong", "qiankungong", "bow", "gong", "qiankun"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "Ǭ�������ǳ��ƹ��ܱ�������֮����������ύ\n��׿ͱ��ɶ����뾩�ǣ�Ҳ��������ˡ�\n");
                set("unit", "��");
		set("value", 30000);
                set("wield_msg", "$Nץ��һ��$n���������е�������\n");
                set("material", "steel");
        }

        init_bow(1);
        setup();

}

