// cracked by vikee 2/09/2002   vikee@263.net
#include <room.h>
inherit ROOM;


void create ()
{
  set ("short", "��¥̨");
  set ("long", @LONG

���˹���һС̨��Զ���ɾ���������������ϼ������ǧ������
�̡�Զ�ϳ��ű����ɣ��칬����ӳ�ƹ⡣�����������������ɾ���
�����˼�����ࡣ
LONG);

  set("exits", ([ /* sizeof() == 1 */
    "down": __DIR__"yunlou",
  ]));
  set("objects", ([ /* sizeof() == 3 */
"/d/city/npc/wangyufeng":1,
  __DIR__"npc/litianwang" : 1,
]));

  set("outdoors", 1);
  setup();
}


