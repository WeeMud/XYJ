// cracked by vikee 2/09/2002   vikee@263.net
#include <room.h>
inherit HOCKSHOP;

void create ()
{
  set ("short", "���ǵ���");
  set ("long", @LONG

���ǳ�����������һ�ҵ����ˡ�������������ƽ�ųơ��ſڹ���һ
������ (paizi)�����ϰ��Ǹ��ܾ����������ˣ��������˽������ܿ�
���غ��㺮�ѣ����۾���ȴû��ʲôЦ�⣬�������ش������㡣
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"zhuque-s1",
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "paizi" : "
�����̲����ۺ�ͯ�����ۣ���ӭ�ݹˣ����Ա��ܡ�
�͹ٿ��������
    ������������������������������
    ��	�䵱(pawn)		��
    ��	����(sell)		��
    ��	����(value)		��
    ��	���(retrieve stamp)	��
    ��	����(buy) ��list�鿴��	��
    ������������������������������
���ֻ��ͭǮ���������ƽ���Ʊһ��ͨ�á�

"]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/pablo" : 1,
]));
  set("no_clean_up", 1);

  setup();
}

int clean_up()
{
      return 0;
}

