// cracked by vikee 2/09/2002   vikee@263.net
// created by snowcat

inherit ROOM;

void create ()
{
  set ("short", "���");
  set ("long", @LONG

�ʹ����������˸���������������ƣ������ǵ���������ƶ�
�䣬������һ����̨�ף������ǽ�����������̫����Ȼ��������
�����������Ȼ��������̬ׯ�ϡ�

LONG);

  set("exits", ([
        "south"   : __DIR__"baiyujie",
        "north"   : __DIR__"houdian",
        "east"   : __DIR__"dongdian",
        "west"   : __DIR__"xidian",
      ]));
  set("objects", ([
        __DIR__"npc/dachen1" : 1,
        __DIR__"npc/dachen2" : 1,
        __DIR__"npc/dachen3" : 1,
        __DIR__"npc/dachen4" : 1,
        __DIR__"npc/dachen5" : 1,
        __DIR__"npc/emperor" : 1,
       ]));

  set("no_fight",1);
  set("no_magic",1);
  setup();
}

int valid_leave (object who, string dir)
{
  if (dir == "east" || 
      dir == "west" ||
      dir == "north")
  {
    message_vision ("$N��ͷ������һ̽�����漸���������ͽ�$N�ܳ���\n",who);
    return notify_fail("");
  }
  return 1;
}

