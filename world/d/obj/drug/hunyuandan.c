// cracked by vikee 2/09/2002   vikee@263.net
// hunyuandan.c ��Ԫ�� 

inherit COMBINED_ITEM;

void setup()
{}

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name("��Ԫ��", ({"hunyuan dan", "dan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "Щ");
                set("base_unit", "��");
                set("long", "һ���Դ�������ҩ�裮\n");
                set("value", 2000);
				set("drug_type", "��ҩ");
        }
     set_amount(1);
        setup();
}

int do_eat(string arg)
{
        if (!id(arg))
                return notify_fail("��Ҫ��ʲôҩ��\n");
//        if ((int)this_player()->query("eff_sen") == 
//            (int)this_player()->query("max_sen"))
//                return notify_fail("�����ڲ���Ҫ�û�Ԫ����\n")
        else {
                this_player()->receive_curing("sen", 40);
                message_vision("$N����һ�Ż�Ԫ������ɫ�������ö��ˣ�\n",
this_player());
         add_amount(-1);
                return 1;
        }
}

string query_autoload() { return query_amount() + ""; }

void autoload(string param)
{
	int amt;

	if( sscanf(param, "%d", amt)==1 )
		set_amount(amt);
}