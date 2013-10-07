// cracked by vikee 2/09/2002   vikee@263.net

inherit NPC;

void create()
{
        set_name("�����޼�", ({"zhangsun wuji","minister","wuji","zhangsun"}));
        set("gender", "����");
        set("title","��������");
        set("age", 50);
        set("attitude", "friendly");
        set("combat_exp", 250000);
        set("per", 30);
        setup();

        carry_object("/d/gao/obj/changpao")->wear();

}

void init()
{
   ::init();
   add_action("do_apply", "apply");
   add_action("do_confirm","confirm");
   this_player()->delete_temp("new_rank");

}
       
int do_apply(string arg)
{
  string type,rank;   
  object me=this_player();
  string msg="��׼����";
  int afford;

   if (!arg) return notify_fail(@LONG
��ʽ�� apply <���> to <��ν>
��𣯼۸񣯵���Ҫ��
self        ���Լ��ĳƺ�      ��ʮ���ƽ�   һ����
self_rude   ���Լ��Ĵ�³�ƺ�  ��ʮ���ƽ�   һ����
respect     ���˶��Լ������  ��ʮ���ƽ�   �����

�֣�����ʹ�ò�ǡ���ĳ�ν����Ȼ�ƺ���ȡ������ʮ��
���ӾͰװ����ˡ�����ǡ����������������ɾ�����

LONG);
  if (sscanf(arg,"%s to %s",type,rank)!=2)   return notify_fail(@LONG
��ʽ�� apply <���> to <��ν>
��𣯼۸�
self          ���Լ��ĳƺ�         ��ʮ���ƽ�
self_rude     ���Լ��Ĵ�³�ƺ�     ��ʮ���ƽ�
respect       ���˶��Լ������     ��ʮ���ƽ�

�֣�����ʹ�ò�ǡ���ĳ�ν����Ȼ�ƺ���ȡ������ʮ��
���ӾͰװ����ˡ�����ǡ����������������ɾ�����

LONG);
  
  if (type!="self" && type!="respect" && type!="self_rude")
    return notify_fail("���������������͵ĳƺ���\n");

  if (type!="respect" && me->query("daoxing")<100000) 
    return notify_fail("�������ô�ͣ�������û����˵���㣬����Ҳ�ա�\n");
  if ( type=="respect" && me->query("daoxing")<500000)
    return notify_fail("�㱾�컹���������˲������������еġ�\n");

  if( !(afford=me->can_afford(500000)) )  {
     write("�����Ǯ������\n");
     return 1; 
  } else if( afford == 2 )  {
      write("�ֽ��ף�������Ʊ��������ֽ𲻹���\n");
      return 1;
  }

  switch (type) {
    case "self" : msg+="���Լ��ĳƺ������ڵġ�"+RANK_D->query_self(me);break;
    case "self_rude" : msg+="���Լ��Ĵ�³�ƺ������ڵġ�"+RANK_D->query_self_rude(me);break;
    case "respect" :  msg+="���˶��Լ�����ƴ����ڵġ�"+RANK_D->query_respect(me);break;
  }
  msg+="���ĳɡ�"+rank+"������������(confirm)\n";
  write(msg);
  me->set_temp("new_rank/type",type);
  me->set_temp("new_rank/ready",1);
  me->set_temp("new_rank/rank",rank);
  return 1;
}

int do_confirm() {
  object me=this_player();
  int afford;

  if (!me->query_temp("new_rank/ready"))
     return notify_fail("��Ҫȷ��ʲô��\n");

  if( !(afford=me->can_afford(500000)) )  {
       write("�����Ǯ������\n");
       return 1; 
  } else if( afford == 2 )  {
      write("�ֽ��ף�������Ʊ��������ֽ𲻹���\n");
      return 1;
  }

  message_vision("$N�ó���ʮ�����ӣ�������$n��\n",me,this_object());
  message_vision("$N���˵�ͷ���ó�һ�ݾ���д�˼��ʡ�\n",this_object());
  me->pay_money(500000);
  if (me->query_temp("new_rank/rank")=="cancel")
     me->delete("rank_info/"+me->query_temp("new_rank/type"));
  else 
     me->set("rank_info/"+me->query_temp("new_rank/type"),me->query_temp("new_rank/rank"));
  write("�Ķ���ϡ�\n");
 log_file("change_rank",me->query("id")+" changes "+me->query_temp("new_rank/type")+" to "
      +me->query_temp("new_rank/rank")+" on "+ctime(time())+".\n");
 
 me->delete_temp("new_rank");
  return 1;
}
