// cracked by vikee 2/09/2002   vikee@263.net
// Room: /d/4world/huofang.c
inherit ROOM;

void create ()
{
  set ("short", "�ֿ�");
  set ("long", @LONG

���ﲻ֪���Ǽ��̺ŵĲֿ⣬��Χ��������ѷ���Щ���ӡ��ֿ���
�������˺ܶ࣬����ǹ��Žŵ����꺺�ӡ�һ����һ�˵İ����Ż�
�ǽ�������Ŵ󱨣�������ȱ���֣�Ҫ����������(work)��
LONG);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/man" : 3,
]));

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"west1",
]));

  setup();
}
void init()
{
        add_action("do_work", "work");
}

int do_work(string arg)
{
        object ob;
        object me;

        me = this_player();

   if (! me->query_temp("working_in_liangdian")) {
message_vision("$N�ӳ���ж��һ�����Ĵ��ף�������ǽ�ߣ��۵��������ۣ�\n",me);
        me->add("kee",-20);
        me->add("sen",-20);
        ob = new("/obj/money/silver");
        ob->move(me);
        message_vision("�Ա߹�������ͷЦ���еض�$N˵����������������Ĺ�Ǯ��\n",me);
        me->set_temp("working_in_liangdian",1);
        call_out ("reset_work",1,me);
    } else
    {
        message_vision("�Աߵ�׳���Ͻ���$N����������Ъһ�����\n",me);
    }
        return 1;
}
void reset_work (object me)
{
        me->set_temp("working_in_liangdian",0);
}

