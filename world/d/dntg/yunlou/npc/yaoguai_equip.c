
string give_equip(object me,object guai) 
{
  int lev;
  string q_level;
  object eq;
  
  
  if ( random(me->query("combat_exp")*2) > guai->query("combat_exp")+random(guai->query("combat_exp")) )
  {
  eq=new("/obj/toy/narmor.c");
  lev=eq->query("equip_level");
  q_level=eq->query("armor_type")+" "+chinese_number(lev);
  
  if (lev == 4 )
	 { 
	  command_function("rumor "+ 
	    "��˵"+me->query("name")+"������"+guai->query("name")+"��������⾪ϲ��");
	 }
	  else
	  {
		  command_function("rumor "+ 
	    "��˵"+me->query("name")+"������"+guai->query("name")+"����������ջ�");
	  }
  
	  
	  if (eq->move(me))
      {
	  tell_object(me,"��õ���һ��װ����\n");
	  }
      else 
	  {
		  if(eq->move(environment(guai)))
             tell_object(environment(guai),"һ��װ������������\n");
		  else
		  {
			  eq->move("/d/city/kezhen.c");
			  tell_object(environment(eq),
                        "���һ�������ϵ���һ��������\n");

		  }

	  }
	  return q_level;
  }

  return "qnone";
}
