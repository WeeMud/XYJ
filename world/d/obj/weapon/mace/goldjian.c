// cracked by vikee 2/09/2002   vikee@263.net
// goldjian.c
// created 5-30-97 pickle
// please do not use this weapon, reserved for /d/jjf/npc/qinqiong.c

#include <weapon.h>
#include <ansi.h>

inherit MACE;

void create()
{
  set_name(HIY "��װ�" NOR, ({"gold mace", "mace", "goldmace", "jinjian"}));
  set_weight(10000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("value", 20000);
    set("material", "gold");
    set("long", "�ؼ��洫�Ľ�װﵣ���ɳ����Ϊ���������˺����͡�\n");
    set("wield_msg", "$N�����$n���૵���ﵶ���ﵶ���������һ�أ�\n");
    set("unwield_msg", "$N������$n��������һ����������ﵹ�Ȼ�����۷磡\n");
  }
  
  init_mace(95);
  setup();
}

