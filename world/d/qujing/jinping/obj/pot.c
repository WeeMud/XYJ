// cracked by vikee 2/09/2002   vikee@263.net

inherit ITEM;

void create()
{
  set_name("�͹�", ({"you guan", "guan", "pot"}));
  set_weight(5000000);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "һ������װ�ֺ����͵Ĵ�ʯ�ޡ�\n");
    set("unit", "��");
  }
}

