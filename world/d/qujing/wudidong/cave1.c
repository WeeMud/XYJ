// cracked by vikee 2/09/2002   vikee@263.net
inherit ROOM;

int do_leap();
void reset();

void create ()
{
  set ("short", "�ض�");
  set ("long", @LONG

�������޵׶���һ���ص���Ѱ��С����׼����������������ͻȻ����
���¾���������Ԩ��������ģ��������ס��ڰ�֮���㼫ĿԶ����ֻ
��ģģ�������ƺ�����һ�����¡�����ȥ����֮�䲻��һ��֮ң����
һʧ�㡣����
LONG);
  set("outdoors", 0);
  setup();
}
void init()
{
  add_action("do_leap", "leap");
  add_action("do_leap", "jump");
  add_action("do_leap", "tiao");
  add_action("do_push", "push");
  add_action("do_push", "tui");
}
int do_leap()
{
  object me, corpse;
  int mydodge,mykar,factor,mypot,mylp,mynewpot;
  int i;
  object *inv;
  me=this_player();
  mydodge=(int)me->query_skill("dodge");
  mykar=(int)me->query_kar();
  factor=mydodge+mykar*4;

  inv=all_inventory(me);
  i=sizeof(inv);

  message_vision("$N���������˳�ȥ��\n", me);

  while (i--)
  {
	if(userp(inv[i])) {
		me->move("/d/qujing/wudidong/yadi");
		message_vision("$Nһ��ûվ�ȣ����¾��£�������ǣ�����ȥ�ˣ�\n", me);
                me->delete_temp("last_damage_from");
                me->set_temp("death_msg", "ˤ���ˡ�\n");
                me->die(); 
                me->save();
		inv[i]->move("/d/qujing/wudidong/yadi");
		return 1;
	}
  }


  if ( (string)me->query("family/family_name") != "�ݿ�ɽ�޵׶�" ) {
	if( random(mykar) < 10 || mydodge < 100 ) {
		me->move("/d/qujing/wudidong/yadi");
		message_vision("$Nһ��ûվ�ȣ����¾��£�������ǣ�����ȥ�ˣ�\n", me);
      		me->delete_temp("last_damage_from");
      		me->set_temp("death_msg", "ˤ���ˡ�\n");
      		me->die();
      		me->save();
	      	return 1;
    	}
  }else{
	if( random(mykar) < 5 || mydodge < 100 ) {
		me->move("/d/qujing/wudidong/yadi");
                me->unconcious();
                return 1;

       	}
  }
      message_vision("$N�ڿ�������������ȥ�ˡ�\n", me);
      me->move(__DIR__"cave2");
      message_vision("$N���˹�����\n",me);
	return 1;
}

int do_push(string arg)
{
  object me=this_player();
  int myeffstr=me->query_skill("unarmed",1)/10-2+me->query("str");
  int mystr=me->query_str();
  int myforce=me->query("maximum_force");

  if ( !arg || ((arg !="men") ))
    return notify_fail("��Ҫ��ʲô�� \n");
  if ( mystr <50 || myeffstr<20) 
    return notify_fail("������̫С�ˣ��Ʋ����� \n");
  if (random(myforce)>1000)
    {
      message_vision("$N��ʯ��ʱ�������ͣ��ƺ��������ˡ�\n", me);
      me->add_maximum_force(-myforce/100);
    }
  message_vision("$Nһ��ʯ�ţ�ͻȻ�䣬һ�������$N�Ƶ�����һ�䷿��ȥ�ˡ�\n", me);
  me->move(__DIR__"inner-bedroom");
  message_vision("ʯ�ŷ�ת����$N���˹�����\n", me);
  return 1;
}
