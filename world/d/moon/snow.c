// cracked by vikee 2/09/2002   vikee@263.net
// Room: /d/moon/xiaoyuan.c

#include <ansi.h>
#include <room.h>
inherit ROOM;

int do_stand(string temp2);
int do_sit(string temp3);

void create ()
{
  set ("short", "�߷���");
  set ("long", @LONG

�˴��������䣬ȴ�����˱ǡ�һ�껨ľҲ�ޣ�ֻ�������ݣ�����ǣ�ٵ�
�����������ģ���ɽ�ۣ���ʯ϶���������������������̽ס���Щ��
�����٣��������Դ䣬������ʵ����ɺ������һ�㣬�۴��ɰ���������ѩ
��һ�㣬һɫ������ȫ�ޡ�����ֻ��һ������ƿ��ƿ�й�����֦�ա�
LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/d/obj/flower/juhua.c" : 1,
]));
  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"road3",
]));

  setup();
}
