// cracked by vikee 2/09/2002   vikee@263.net
// yuelao.c ��������
// AceP
// mon 1/2/97

inherit NPC;

int do_register();
int do_zuomei(string);
int do_divorce(string);

void create()
{
	set_name("��������", ({ "yuexia laoren", "yuelao", "laoren" }));
	set("long", 
"������ר�����ϵ�����Ե�����������ˡ�
��������⣬��ü�԰ף��������Ƕ�����һ���飬
�������һ������������������������Щʲô��\n");
	set("gender", "����");
	set("per", 100);
	set("age", 101);
	set("attitude", "friendly");
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("per", 25);
      
	set("max_kee", 1200);
	set("max_gin", 1000);
	set("max_sen", 1200);
	set("force", 1000);
	set("max_force", 1000);
	set("max_mana", 1200);
	set("mana", 1200);
	set("combat_exp", 500000);
  set("daoxing", 5000000);


	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("unarmed", 100);
	set_skill("parry", 100);
	set_skill("literate", 150);

	set("inquiry", ([
		"name" : "�����������ϣ��ڴ˸������ϵ������е���Ե�����в�֪���������ˡ�",
		"here" : "��������Ұ칫�ĵط������е���Ե�����������͵͵ǣ���ߣ�Ҳ�������ע�����ġ�",
		"���" : "���飿��Ҫ�ҵ�������ע��������Ե��Ȼ��һ���������Ǽ���顣",
		"���" : "�����������ˣ�����ͷ���Ĳ��ţ�����ʸߵÿ��¡�����������������Ҳ���������(divorce)���롣",
		"��ý" : "ý���ǽ��ز����ٵ�֤�ˣ���ý(zuomei)�ĸ����Ů����֤��",
       ]) );

	setup();
}

void init()
{
	add_action("do_divorce", "divorce");
	add_action("do_zuomei", "zuomei");
	add_action("do_propose", "propose");
	add_action("do_marry", "marry");
}


int do_propose(string arg)
{
	object me,who;
	me=this_player();
        if(me->query("age") < 16)
           return notify_fail("С����һ�����ȥ��\n");

        if (!arg) return notify_fail("��Ҫ��˭��飿\n");

        if (me->query("gender")=="Ů��")
                return notify_fail("ֻ�����˲����������飡\n");

        if (!objectp(who=present(arg,environment(me))))
                return notify_fail("����û������ˡ�\n");

        if (!who->is_character())
                return notify_fail("�������"+who->name()+"��ʲôѽ��\n");

        if (who==me)
                return notify_fail("��ʲô��Ц������\n");

        if (who->query("gender")=="����")
                return notify_fail("�ţ����̬�𣿣���\n");

        if (me->query("married"))
                return notify_fail("�ٺ٣�����" + me->query("couple/name") + "������\n");

        if (!living(who))
                return notify_fail("��...�㻹���Ȱ�"+who->name()+"Ū�Ѱɡ�\n");


	if ((me->query("bonze/class")=="bonze")||(who->query("bonze/class")=="bonze"))
		return notify_fail("�������Ĵ�Կգ����֮�¾����˰ɡ�\n");

        if (who->query("married"))
                return notify_fail("�������˰ɣ�"+who->name()+"���з�֮������\n");

        message_vision("$N����$n�����ظ�˵��ֻҪ��޸��ң��������ʲô�Ҿ���ʲô��\n", me, who);

        me->set("proposing",1);
        me->set("propose_target", getuid(who));
        who->set("proposed",1);
        who->set("propose_man", getuid(me));

        return 1;
}

int do_marry(string arg)
{
	object me,who;
	me=this_player();

	if(me->query("age") < 15)
           	return notify_fail("С����һ�����ȥ��\n");

        if (me->query("gender")=="����")
                return notify_fail("ֻ��Ů�˲��ܴ�Ӧ���˵���飡\n");

        if (!arg) 
		return notify_fail("��Ҫ�޸�˭��\n");

        if (!me->query("proposed"))
                return notify_fail("�ţ�û��������鰡��\n");

        if (!objectp(who=present(arg,environment(me))))
                return notify_fail("����û������ˡ�\n");

        if (!who->is_character())
                return notify_fail("�������"+who->name()+"��ʲôѽ��\n");

        if (who==me)
                return notify_fail("��ʲô��Ц������\n");

        if (!living(who))
                return notify_fail("��...�㻹���Ȱ�"+who->name()+"Ū�Ѱɡ�\n");

        if (me->query("propose_man")!=getuid(who))
                return notify_fail("�ţ�"+who->name()+"û��������鰡��\n");


        if (who->query("propose_target")!=getuid(me))
                return notify_fail("�Բ���"+who->name()+"�Ѿ��ı����ⲻ��������ˡ�\n");
	
	if(!me->query("meiren"))
		return notify_fail("�����ҵģ��������ý�������װɣ�\n");

        message_vision("$N��ͷ���˻ᣬ���ߴ���˵�����ðɣ�\n",me,who);

        who->delete("proposing");
        who->delete("propose_target");

        me->delete("proposed");
        me->delete("propose_man");

        command("say �����������ü��ˣ�һ���뱸�������Ϊ�������飡");
        write("�������˵�ͷ����Ե�����˷���д��Щʲô��\n");
        command("say ��ϲ����ϲ��");
        command("say ����������������");
        command("say "+me->name()+"��"+who->name()+"��"+me->query("meiren")+"��ý������ϲ����Ե����λ����������֤��");
        command("say ��ף��λ��ͷ���ϣ��������ӡ�");

        who->delete("meiren");
        who->set("married",1);
        who->set("husband/"+getuid(me), me->name());
        who->set("couple/id", getuid(me));
        who->set("couple/name", me->name());
        me->set("married", 1);
        me->set("wife/"+getuid(who), who->name());
        me->set("couple/id", getuid(who));
        me->set("couple/name", who->name());
        me->set_temp("marrying",1);
        me->set_temp("bride",getuid(who));

        return 1;
}


int do_zuomei(string arg)
{
	object me, who;
	me=this_player();

 	if (!arg || !objectp(who=present(arg,environment(me)))) {
		tell_object(me,"��Ҫ��˭��ý��\n");
		return 1;
	}
        if (who->query("gender")=="����")
                return notify_fail("����˲�����Ҫ����ý��\n");

	if (arg==me->query("proposed_target"))
		return notify_fail("�������Լ���ý����˵���𣿣���\n");

	if (arg==me->query("id"))
		return notify_fail("�������Լ���ý����˵���𣿣���\n");

	if (!who->query("proposed")) 
		return notify_fail("�ţ�����û�����鰡����Ϲ��ʲô�壿����\n");

	message_vision("$NЦ������˵�������Ů����ý��\n", me);
	command("say " + me->query("name") + "ԭ���" + who->name() + "��ý��");
	command("say ����ǳ���֮�������°����ü��ˣ�����ͼ�¼������");
	who->set("meiren", me->query("name"));
	return 1;
}

int do_divorce(string arg)
{
	object me,who;
	me=this_player();

	if (!arg)
		return notify_fail("������˭��飿\n");

 	if (!me->query("married"))
		return notify_fail("�����û����飡\n");

	if (me->query("gender")=="����") {
		if (!me->query("wife/"+arg))
			return notify_fail("����������ֵؿ�����һ�ۣ��������˸������������ӣ�\n");
		if (!(who=find_player(arg))) {
			message_vision("$N�����������˴��������ţ�������û�����ˣ���Ҫ��飡\n", me);
			command("say �Բ������������ڲ������ϣ����ܰ����������");
			return 1; }
		if (!me->query_temp("divorcing")) {
			message_vision("$N�����������˴��������ţ�������û�����ˣ���Ҫ��飡\n", me);
			command("say �����㵱���������������������ǣ�������������һ�Ρ�");
			me->set_temp("divorcing",1);
			return 1; }
		me->delete("married");
		me->delete("couple");
		me->delete("wife");
		me->delete_temp("divorcing");
		who->delete("married");
		who->delete("couple");
		who->delete("husband");
		tell_object(who, me->name()+"�������ˡ�");
	}
	else {
		if (!me->query("husband/"+arg))
			return notify_fail("����������ֵؿ�����һ�ۣ��������˸����������ɷ�\n");
		if (!(who=find_player(arg))) {
			message_vision("$N�����������˴��������ţ�������û�����ˣ���Ҫ��飡\n", me);
			command("say �Բ������ɷ����ڲ������ϣ����ܰ����������");
			return 1; }
		if (!me->query_temp("divorcing")) {
			message_vision("$N�����������˴��������ţ�������û�����ˣ���Ҫ��飡\n", me);
			command("say �����㵱������������ɷ�������ǣ�������������һ�Ρ�");
			me->set_temp("divorcing",1);
			return 1; 
			}

		who->delete("married");
		who->delete("wife");
		who->delete("couple");
		me->delete("married");
		me->delete("couple");
		me->delete_temp("divorcing");
		me->delete("husband");
		tell_object(who, me->name()+"�������㣬��֪�Ǹ�˭˽��ȥ�ˡ�");
	}
	command("say �� ... ...");
	command("say �� ... �ӽ�����"+me->name()+"��"+who->name()+"�Ͳ����Ƿ����ˡ�");
	command("say ��һ׮ʧ�ܵĻ������� ... ... ");

        log_file("yl.rc",me->name()+"��"+who->name()+
	   "��"+NATURE_D->game_time()+"("+ctime(time())+")��顣\n");

		return 1;
}