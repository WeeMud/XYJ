// cracked by vikee 2/09/2002   vikee@263.net
// create by snowcat jan 21 1998

inherit ROOM;

void create ()
{
  set ("short", "��ͤ��");
  set ("long", @LONG

��ͤ��������������������СС��ʯ�ӣ�Ʈ�������Ҷ����·��
�����ǳ��ŵ������紵��ɳɳ���졣��·���ϱ�ͨ�򿪷�����������
�ɼ�һ���

LONG);

  set("exits", ([
        "northup" : __DIR__"wanshou",
        "west" : __DIR__"xihu4",
        "east" : __DIR__"donghu3",
        "south" : __DIR__"guting2",
      ]));

  set("outdoors", __DIR__);

  setup();
}


