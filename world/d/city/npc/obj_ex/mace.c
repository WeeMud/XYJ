#include <weapon.h>

inherit MACE;


void create()
{
              set_name("���ֻ�β��", ({ "jinggang mace", "mace" }) );
        set_weight(12000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                   set("unit", "��");
                   set("long", "����һ���޵л�β�ޡ�\n");
                   set("value", 0);
                   set("no_sell", 1);
                   set("material", "iron");
set("wield_msg", "$N����һ��$n�����͵ذ��˸���ʽ��\n");
set("unwield_msg", "$NС������$n������䡣\n");
                   set("no_sell",1);
                   set("no_drop","ȥ�����Ѷ��ɣ����ӻ���Ⱦ����!\n");
                   set("no_give","�ܹܷ���װ�����ɲ���������Ӵ��\n");
                   set("no_get","�����ܹܿ�򷢵�װ�������ΰ�!\n");
 
        }
         init_mace(65);
        setup();
}


