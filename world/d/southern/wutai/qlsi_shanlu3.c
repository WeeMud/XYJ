// cracked by vikee 2/09/2002   vikee@263.net
// ajax

inherit ROOM;

void create()
{
set("short", "ɽ·");
set("long", @LONG
    

��������ɽ·ǰ�У��������������������ĸ��ͣ���ӳ��
�ʻ����̲ݵ�ɽȪ�����������κ����Ƶ��������������׵�
�ݵ�ӳ���Ź����������ϵ�Ϧ�������������Ŀ�������
LONG );


set("exits", ([
  "northup"   : __DIR__"qlsi_shanlu2",
  "west"   : __DIR__"qlsi_shanlu4",
  "southdown"   : __DIR__"qinglianggu",
 
]));


set("objects", ([
]));



set("outdoors", 1);

setup();
}
