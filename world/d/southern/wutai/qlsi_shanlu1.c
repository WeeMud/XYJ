// cracked by vikee 2/09/2002   vikee@263.net
// ajax

inherit ROOM;

void create()
{
set("short", "ɽ·");
set("long", @LONG
    
�����ɴ���ɽ�͵��������ˣ�ǰ��һ��ʯ�����Ǵ�˵������
��������������������ʯ(stone)��
LONG );

set("item_desc",(["stone":
"��ʯʯ�����ף�����װ룬 ������Χʮ���ף�ʯ����ɫ����
���ƣ��������ϣ��������⡣
"
]));

set("exits", ([
  "north"   : __DIR__"qlsi_gate",
  "southdown"   : __DIR__"qlsi_shanlu2",
 
]));


set("objects", ([
]));



set("outdoors", 1);

setup();
}
