// cracked by vikee 2/09/2002   vikee@263.net
//renshenguo-yuan.c

inherit ROOM;

void create ()
{
	set ("short", "�˲ι�԰");
	set ("long", @LONG

�ô��һ���˲ι�԰���޴�Ĺ����ϵ���һöö���˴������ε�
�˲ι���ֻ�ǲ�֪����������Ū����������˵���˲ι������ޱȣ�
Ҫ����ժһ��ʲô���Բ��ϡ�
LONG);

	set("exits", 
	([ //sizeof() == 4
	]));
	
	set("objects", 
	([ //sizeof() == 1
	]));

	set("outdoors", "wuzhuang");

	setup();
}

void init()
{
	object me, zhenyuan;

	me = this_player();

	if( me->query_temp("used_huangtong_key") == 1 )
	{
		me->delete_temp("used_huangtong_key");
		
		message_vision("ֻ������������Ц����Ԫ�������˳�����\n", me);
		message_vision("��Ԫ����˵������Ȼ���㷢���ˡ������ǾͿ����˲ι����ɣ�\n\n\n", me);

   add_action("do_clear","clear");
		if( !objectp(zhenyuan=present("zhenyuan daxian", environment(me))) )
		{//if zhenyuan already here, we do not need creat another one.
			zhenyuan = new(__DIR__"npc/zhenyuan");
			zhenyuan->move(environment(me));
		}
		zhenyuan->start_renshen();
	}
}

int do_clear() {
  object me=this_player();
  object *env=all_inventory(this_object());
  object zhenyuan=present("zhenyuan daxian",this_object());

  if (!zhenyuan) return notify_fail("��Ԫ���ɲ��ڡ�\n");
  if (!env) return 0;
  message_vision("$N����$nС���ֹ�������ô���ˣ��˲ι�԰����г��ˡ�������\n",me,zhenyuan);
  message_vision("$N������ü��ͻȻ��������������ׯ���˵�����������֮�徻���ڣ������˵�һ����ء���\n",zhenyuan);

  for (int i=0;i<sizeof(env);i++)
   if (env[i]!=me && userp(env[i]) && env[i]->query("daoxing")<10000) zhenyuan->send_back(zhenyuan,env[i]);
  return 1;
}
