// cracked by vikee 2/09/2002   vikee@263.net
// /d/changan/playerhomes/stdbed.c
// this  is a standard bed for married couples.
// wiz should modify /d/changan/playerhomes/h_playername  to 
// connect here.
// IMPORTANT: should copy this to bed_playername, otherwise...  

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG

LONG
        );
        
	set("exits", ([
                "out": "/d/changan/playerhomes/h_mon",
            ]));
	set("sleep_room",1);
	set("if_bed",1);                                
              
        setup();
}



