// cracked by vikee 2/09/2002   vikee@263.net
// Room: some place in ��ţ����
// inside2.c

inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG

���������Ƕ��Ľ����ã�ƽʱ��ʿ�Ǳ������ｲ��˵��������
��ʲô���£�Ҳ�����Ｏ�����顣������������ط�������ʮ
����棬Ҳ����һ��ʮ����ʿ��
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"houlang1.c",
  "southdown" : __DIR__"inside1.c",
]));
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/xiao" : 1,
  __DIR__"npc/yunyang" : 1,
]));
  set("valid_startroom", 1);

  setup();
}
int valid_leave(object me, string dir)
{
        if (dir == "north" ) {
        if (objectp(present("master yunyang", environment(me)))) {
	if((string)me->query("family/family_name")=="����ɽ���Ƕ�") {
		if((int)me->query("family/generation") < 2) {
			me->set("family/generation", 2);
			me->set("title", "����ɽ���Ƕ��ڶ�������");
		}
	if((string)me->query("family/master_name")=="������ʦ") {
		me->set("pending/kick_out",1);
	}
	return ::valid_leave(me, dir);
	}
        return notify_fail("��������˵������ʦ���ޣ��ټ����ˣ���������ذɣ�\n");
	}
	}
        return ::valid_leave(me, dir);
}

