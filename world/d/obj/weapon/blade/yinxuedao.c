//by hexiu 20130616
#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void create()
{
        set_name(RED"��Ѫ��"NOR, ({"yinxue dao", "dao"}));

        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ�ѵ�����ĳ�������������Ƕ�к챦ʯ��\n");
             set("no_give", 1);
             set("no_sell", 1);
             set("no_drop", 1);
             set("no_put", 1);
                set("value", 2500);
                set("material", "gold");
                set("wield_msg", "$N��ৡ���һ�����һ��$n�������У�\n");
                set("unwield_msg", "$N�����е�$n���뵶�ʡ�\n");
        set("weapon_prop/courage", 15);

        }
        init_blade(80);
        setup();
}
int query_autoload() { return 1; }

mixed hit_ob(object me, object victim,int damage_bonus,int gp)
{if (50<random(100)) return 0;
        gp=(int)(random(damage_bonus/4));
if (gp < 1) gp=1;if (gp > 100) gp=100;
message_vision(HIR"$N������Ѫ��һ������������\n"NOR,me,victim);
if(wizardp(me)) tell_object(me,HIY"��Ѫ����"+gp+"\n"NOR);
//if( (int)me->query("kee")  < 3*(int)me->query("max_kee")/2 ) me->add("kee", gp);
	call_out("leech",1,me,gp);
return gp;}
void leech(object me,int gp)
{if (!living(me)) return;
if( (int)me->query("kee")  > 3*(int)me->query("max_kee")/2 )
{message_vision(HIR"\n$N�������������\n"NOR,me);return;}
else {me->add("kee", gp);
message_vision(HIR"\n$N������Ѫ�����ָ���\n"NOR,me);
if(wizardp(me)) tell_object(me,HIR"��Ѫ����"+gp+"\n"NOR);
return;}
}



