// cracked by vikee 2/09/2002   vikee@263.net
// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "�ܶ�");
  set ("long", @LONG

������߼�Ϊ΢��������ǿ�ؿ�����������ԼԼ��һЩ������
ȴ�ֿ��ò���ʮ��������㲻������������Ŷ��ڣ�С�ĵ���
�����ж���

LONG);

  set("exits", ([
        "down" : __DIR__"houdong",
      ]));
  set ("sleep_room",1);
   set ("no_mieyao",1);

  setup();
}



