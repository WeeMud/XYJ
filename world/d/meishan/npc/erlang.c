// cracked by vikee 2/09/2002   vikee@263.net
#include <ansi.h>
inherit NPC;

int bianhua(string);
int bianback();
void announce_success(object);
string begin_chasing();
void gohome();
void greeting(object);

void create()
{
        set_name("�������", ({"erlang zhenjun", "erlang", "zhenjun"}));
        set("long", "���ǳ���ѻ�Ӣ��ʥ���Ի��ޱߺŶ��ɡ�
�����˹�����Զ�����÷ɽ��ʥ�С�\n");
        set("looking", "�����忡ò���ã���������Ŀ�й⡣");
        set("age", 28);
        set("attitude", "peaceful");
        set("gender", "����");
        set("title", "�ѻ�������");
set ("nickname",HIC"����"NOR);
        set("str", 40);
        set("int", 40);
        set("per", 30);
        set("con", 30);
        set("max_kee",3000);
        set("max_sen", 3000);
        set("combat_exp", 1500000);
        set("daoxing",2500000);
        set("force", 4000);
        set("max_force", 4000);
        set("mana", 4000);
        set("max_mana", 4000);
        set("force_factor", 150);
        set("mana_factor", 120);
        
        set_skill("unarmed", 200);
        set_skill("force", 180);
        set_skill("spells", 180);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("spear", 200);
        set_skill("moyun-shou", 200);
        set_skill("moshenbu", 200);
        set_skill("bawang-qiang", 200);
        set_skill("dao",200);
        set_skill("wuxiangforce",200);
        map_skill("force","wuxiangforce");
        map_skill("spells","dao");
        map_skill("unarmed", "moyun-shou");
        map_skill("dodge", "moshenbu");
        map_skill("spear","bawang-qiang");
        map_skill("parry", "bawang-qiang");
        setup();
        carry_object("/d/meishan/npc/obj/spear")->wield();
        carry_object("/d/obj/armor/jinjia")->wear();

      for (int i=0;i<random(20);i++) carry_object("/d/obj/drug/jinchuang");
  set("inquiry", ([
        "name": "���˶����������Ҳ��",
        "here": "�ҷ������ּ����Ҫ�˱�׽�÷����칬�������ʥ��",
        "�����ʥ": (:begin_chasing :),
        "me": (:begin_chasing :),
      ]) );

}

string begin_chasing() {
  object ob=this_player();
  object me=this_object();
  string *id=ob->parse_command_id_list();

  if (me->query_temp("target")==ob) {
       kill_ob(ob);
       return "���Ͷ��������һ����\n";
  }
  if (me->query_temp("target")) return "����׽��"
     +me->query_temp("target")->query("name")+"�����֪���������٣�\n";

  if (ob->query("dntg/erlang")=="done") {
     me->command("fear "+id[0] );
     return RANK_D->query_respect(ob)+"����ͨ��С��������̹��ˡ�\n";
  }
  
//  if (ob->query("daoxing")<500000) 
  if (ob->query("daoxing")<100000) 
     return "�����ʥ���и���ٱ���\n";

  me->set_temp("target",ob);
  set("eff_kee",4000);
  set("max_kee",4000);
  set("kee",4000);
  set("sen",4000);
  set("eff_sen",4000);
  set("max_sen",4000);
  set("mana",4000);
  ob->set_temp("erlang","begin");
  tell_object(ob,"��������������㿴����֪����Щʲô���⡣\n");
  me->command("jump");
  me->command("say ���������㲻������ȴ��������������������Ҳ��");
  me->set_leader(ob);
  message_vision("$N������ʼ����$nһ���ж���\n",me,ob);
  kill_ob(ob);
  return "�ٺ١���\n";
}

void init() {
  object me,ob,env;
 
  ::init();
  bianback();
  ob=this_player();
  me=this_object();
  if ( ob==me->query_temp("target") ) {
    remove_call_out("greeting");
    call_out("greeting", 1, ob);
  }           
}

void greeting(object ob) {
  object me=this_object();
  object env=environment(me);
  string *id=ob->parse_command_id_list();
  string name=ob->name();
  string stage=ob->query_temp("erlang");
  if (env->query("no_fight")) {
     command("sigh2");
     command("loser "+id[0]);
     me->delete_temp("target");
     ob->delete_temp("erlang");
     gohome();
     return;
  }
  if (name=="��ȸ" && stage=="begin") {
    me->bianhua("queying");
    ob->set_temp("erlang","maque");
  }
  if (name=="����" && stage=="maque") {
    me->bianhua("haihe");
    ob->set_temp("erlang","cihu");
  }
  if (name=="���" && stage=="cihu") {
    me->bianhua("yuying");
    ob->set_temp("erlang","fish");
  }
  if (name=="ˮ��" && stage=="fish") {
    me->bianhua("huihe");
    ob->set_temp("erlang","shuishe");
  }
  if (name=="���" && stage=="shuishe") {  
    ob->set_temp("erlang","erlang");
 
  }
}

void die()
{
  object target=this_object()->query_temp("target");
  if( environment() ) {
        message("sound", "\n\n������ŭ������ĪҪ���񣬴����������״ȥ��\n\n", environment());
        message("sound", "\n��������ϰ��ƣ����������ŷ�ȥ������\n\n", environment());
        }
  command("drop all");
 
  if (target) {
     if (target->query_temp("erlang")=="erlang")  
        announce_success(target);
     target->delete_temp("erlang");
  }
  destruct(this_object());
}
// void unconcious() {die();}

void announce_success(object ob) {
   object me=this_object();

   if (ob->query("dntg/erlang") == "done") return;
   me->set("name","�������");
   command("chat "+ob->query("name")+
            "���ո�ǿ��������Ⱥ����꯲��Ƕ��֣��ʰ��·磡");
   ob->set("dntg/erlang","done");
   ob->set("cor",(int)ob->query("cor")+2);
   message_vision(HIW"$N��ܶ�����ӭ����������õ�ʶ������\n"NOR,ob);
   log_file("dntg",sprintf("%s(%s) passed erlang shen and won 2-point cor on %s\n",
             ob->name(1), geteuid(ob), ctime(time()) ) );

}
void kill_ob(object sb) {
  object me=this_object();
  object target=me->query_temp("target");

  if (!target) ::kill_ob(sb);
  else {
     if (target!=sb && environment(me)==environment(target)) {
           command("sneer");
           command("say �ж�ȡʤ��"+target->query("name")+
                    "�ô����ͷ��ԭ��������ˣ�");
           command("bye");
           message_vision(HIG"$N����һ�����̣���ʱ��ʧȥ����Ӱ��\n"NOR,me);
           target->delete_temp("erlang");
           destruct(me);
           return;
      }
      ::kill_ob(sb);
  }
}
        
int bianhua(string id) {
    object me=this_object();    
    string name,long;
    mapping id_name=(["queying":"ȸӥ",
                     "haihe":"����",
                     "yuying": "��ӥ",
                     "huihe": "�Һ�",
                    ]);

   if (name=id_name[id]) {
      message_vision(HIY "$N����ھ�������ԣ�ҡ��һ�䣬���һֻ"
                      +name+"��\n" NOR,me);
      me->set("name",name); 
      me->delete("title");
      me->set("looking","�����һֻ"+name+"ģ����");
    }
    return 1;
}
int bianback()  {
    object me=this_object();
    
    if (me->query("name")!="�������") {
      me->set("name","�������");
      message_vision(HIY "$N�����������һ�Σ���������\n"
            NOR,me);
      set("title", "�ѻ�������");
      set("looking", "�����忡ò���ã���������Ŀ�й⡣");
    }
    return 1;
}

void heart_beat() {
    object me=this_object();
    object ob=me->query_temp("target");
    object env;
    
    if (ob) {
       env=environment(ob);
       if (ob->is_ghost()) {
           me->delete_temp("target");
           me->set_leader(0);
           me->gohome();
       }
       // tell_object(ob,"hi.\n");
      if ( (!env->query("no_fight")) && environment(me)!=env 
            && random(3)==1) {
           message_vision("$N����ææ���뿪�ˡ�\n",me);          
           me->move(env);     
           message_vision("$N���˹�����\n",me);
       }
     if (!query_temp("weapon")) set("force_factor",300);
    set("force",4000);
  if (query("eff_kee")<query("max_kee")) command("eat yao");
  if (env->query("no_fight")) delete_temp("target");
     }
    ::heart_beat();
}
void gohome() {
   object me=this_object();

   me->bianback();
   message_vision("$N����ææ���뿪�ˡ�\n",me);          
   //me->move("/d/city/center");     
   //message_vision("$N���˹�����\n",me);
   destruct(me);
}

varargs int receive_damage(string type, int damage, object who)
{
  object me=this_object();
  object target=query_temp("target");

  if (!target) return ::receive_damage(type,damage,who);
  if (target->query_temp("erlang")!="erlang") return 1;
  call_out("exertheal",1,me);
  return ::receive_damage(type,damage,who);
}

void exertheal(object me) {
  me->command("exert recover");

}


