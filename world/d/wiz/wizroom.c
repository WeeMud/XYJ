// cracked by vikee 2/09/2002   vikee@263.net
// Room: /d/wiz/wizroom.c

inherit ROOM;

int block_cmd();

void create ()
{
  set ("short", "��ʦ������");
  set ("long", @LONG

��������ʦ�������۵ĵط��������ʦ��Ҫ����Ļ���Ҳ����ѡ����
����С�
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"system",
  "north" : __DIR__"jobroom",
  "sleeve": __DIR__"sleeveroom",
  "guest": __DIR__"guest",
  "jail":__DIR__"punish",
  "kz": "/d/city/kezhan",
  "empty": "/obj/empty",
]));

  set("wiz_board",1);

  setup();
  call_other("/obj/board/wizard_b", "???");
}

void init()
{   
        if (!wizardp(this_player()))
          add_action("block_cmd","",1);   
}

int block_cmd()
{
       string verb = query_verb();

       if (verb=="say") return 0; //allow say
       if (verb=="chat") return 0;
       if (verb=="quit") return 0;
       if (verb=="look") return 0;
       return 1;
}

