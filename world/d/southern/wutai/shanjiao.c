// cracked by vikee 2/09/2002   vikee@263.net
// ajax

inherit ROOM;

void create()
{
set("short", "��̨ɽ����");
set("long", @LONG
    

�����Ӵ��Ա��ķ�Բ�������Ͷ�����̨ɽ�ˣ���������ɽ�壬
��幰�����࣬��ɽ�ȴ�����ϰϰ����ʹ���С��صĹ�������
�������������ɫ����ʩ�ɡ�

LONG );


set("exits", ([
  "northup"   : __DIR__"qinglianggu",
  "south"   : __DIR__"guandao1",
 
]));


set("objects", ([
]));



set("outdoors", 1);

setup();
}
