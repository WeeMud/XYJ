// cracked by vikee 2/09/2002   vikee@263.net
// create by snowcat.c 4/8/1997
// room: /d/westway/shandong.c

inherit ROOM;

void create ()
{
  set ("short", "ɽ����");
  set ("long", @LONG

ɽ�����е�谵���Ӷ��ⶥ�ϴ���һЩ���������ڱ��ϳ���һ
������̦��������ǵ�������һЩ�ɲݡ�������������һλ
���ˣ��ƺ���û�в����ĵ�����

LONG);

  set("exits", ([
        "out"      : __DIR__"yunti",
      ]));
  set("no_fight", 1);
  set("no_magic", 1);

  set("objects",([
        __DIR__"npc/laoren" : 1,
       ]));

  setup();
}





