// cracked by vikee 2/09/2002   vikee@263.net
inherit NPC;

#include <greeting.h>

void create()
{
        set_name("Ѧ�ʹ�", ({ "xue rengui", "xue", "rengui" }) );
        set("gender", "����");
        set("age", 35);
        set("long","Ѧ�ʹ��ǳ����Ǿ����ᶽ������ʹ����ⰲȫ��\n");
        set("combat_exp", 350000);
	set("title", "�����ᶽ");
	set("nickname", "�¹�����");
        set("attitude", "friendly");
	set("per", 25);
        set("str", 35);
        set("max_kee", 850);
        set("max_gin", 600);
	set("max_mana", 500);
	set("mana", 500);
        set("force", 600);
        set("max_force", 600);
        set("force_factor", 35);
        set_skill("spear", 80);
        set_skill("unarmed", 80);
	set_skill("changquan", 70);
        set_skill("parry", 80);
        set_skill("dodge", 80);
	set_skill("bawang-qiang", 70);
	set_skill("yanxing-steps", 70);
	map_skill("spear", "bawang-qiang");
	map_skill("parry", "bawang-qiang");
	map_skill("dodge", "yanxing-steps");
	map_skill("unarmed", "changquan");
        setup();

        carry_object("/d/obj/weapon/spear/tiespear")->wield();
        carry_object("/d/obj/armor/tongjia")->wear();
}

void init ()
{
	greeting2(this_player());
}

int accept_fight(object me)
{
        command("say ��Ϊ��ǰ���������������Ұƥ����գ�");
        return 0;
}


