// cracked by vikee 2/09/2002   vikee@263.net
inherit ITEM;

void create()
{
  set_name("ˮ������", ({ "yao pai" }));
  set_weight(1000);
  set("long", "����һ��ˮ���Ƴɵ����ƣ��Ͽ��С������������ĸ��֡�
��ֵ��Ǳ߷�����Щͻ�ۣ�����Կ��һ�㡣\n" );
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "ֻ");
    set("longgong", 1);
    set("no_sell", 1);
    set("material", "bone");
  }
  setup();
}

void init()
{

  object me = this_object();
  object where = environment();

  if (userp(where))
  {
    if (me->query("owned"))
    {
      if (me->query("owned")!=where->query("id"))
      {
        call_out("destruct_me",1,where,me);
      }
    }
    else
    {
      me->set("owned",where->query("id"));
    }
  }
}
void destruct_me(object where, object me)
{
        message_vision("$N���е�$n��������ˤ���ˡ�\n",where,me);
        destruct(me);
}

