// cracked by vikee 2/09/2002   vikee@263.net
//fdoor.c

inherit ROOM;

void create ()
{
  set ("short", "��ѩ������");
  set ("long", @LONG

��������������������������������������������������������
   �㣬�Ǻ�ģ�
                        �죬�����ģ�
                                          �أ��ǻƵģ�
             �ǽ����覵�ѩ���ڴ�����衭��
��������������������������������������������������������

	��ѩ��ػ��ʾ(gaoshi)

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"fxtd",
  "enter" : __DIR__"living",
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "gaoshi" : "����ѩ��ء���
    http://www.ams.queensu.ca/lyh/fxtd/
��Ͷ����֪����
    http://www.qucis.queensu.ca/home/guo/fxtd/submissions.html
",
]));
  set("outdoors", 1);

  setup();
}
