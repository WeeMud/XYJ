// cracked by vikee 2/09/2002   vikee@263.net
//cglaem...12/17/96.

#include <ansi.h>

int main(object me, string arg)
{
	string loc;
        int mana_cost;
	object ridee, map;
	string ridemsg;

        seteuid(getuid());

        if( me->is_fighting() )
                return notify_fail("������ս�����ɲ�����\n");
        if( me->is_busy() || me->query_temp("pending/exercising"))
                return notify_fail("����æ���أ�û�������Ƽ���\n");
        if(environment(me)->query("outdoors")==0 )
		return notify_fail("��Χû��һƬ�ƣ�û�취���Ƽ���\n");
	if( me->is_ghost() )
		return notify_fail("���˹��ˣ�����ʵ��ɣ�\n");
        if( !arg )
                return notify_fail("��Ҫ�ɵ�����ȥ��\n");
	if( me->query_temp("no_move") )
	    return notify_fail("�㱻��ס�ˣ�����ɵ�������\n");

	if( RANK_D->grade_dx( RANK_D->describe_dx( (int)me->query("daoxing") ) ) 
		< RANK_D->grade_dx(BLU "�������" NOR) )
	{
		message_vision(HIY
"$N��������һ�����ƺ���������������ز������߾�һ�����Դ�ˤ��������\n"
NOR, me);
		return notify_fail("�����ڻ����������̸���ϣ�����ɵ�������\n");
	}

	if( RANK_D->grade_fali( RANK_D->describe_fali( (int)me->query("max_mana") ) ) 
		< RANK_D->grade_fali(HIB "���Ƽ���" NOR) )
	{
		message_vision(HIY
"$N��������һ�����ƺ���������������ز������߾�һ�����Դ�ˤ��������\n"
NOR, me);
		return notify_fail("��������ķ�����Ϊ���������Ƽ���\n");
	}

	if( (int)me->query("mana") < 200 )
	{
		message_vision(HIY
"$N��������һ�����ƺ���������������ز������߾�һ�����Դ�ˤ��������\n"
NOR, me);
		return notify_fail("��Ŀǰ����������ӯ��\n");
	}


        if( (int)me->query("sen") * 100 / (int)me->query("max_sen") < 50 )
                return
notify_fail("������ͷ�Բ�̫���ѣ����ĵ�����ˤ����\n");

        if( (int)me->query("kee") * 100 / (int)me->query("max_kee") < 50 )
                return
notify_fail("��������������������ƺ��е㲻֧��\n");

        mana_cost=-(100-(int)me->query_skill("spells"))/4-40;
        if(mana_cost > 0) mana_cost=0;

	if( (string)me->query("family/family_name") == "���޵ظ�") {
		message_vision(HIY"$N��һָ��ƽ�ؼ�һ��������𣬽�$N����������\n"+
"�ٴ�һ�����ڣ���֮Ʈȥ�����ˡ�����\n\n"NOR, me);
	}else if( (string)me->query("family/family_name") == "��ѩɽ"
		|| (string)me->query("family/family_name") == "�ݿ�ɽ�޵׶�" ) {
		message_vision(HIY"$N��һָ����������һ������𣬴����˶��������۾���\n"+
"�ٴ�һ�����ڣ���֮Ʈȥ�����ˡ�����\n\n"NOR, me);
	}else {	
        message_vision(HIY
"$N��һָ������һ���Ʋʣ��߸����˵�������ȥ��\n"+
"�ٴ�һ�����ڣ���֮����ȽȽ�����𡣡���\n\n"NOR, me);
	}

        me->add("mana", mana_cost);

//        if(arg=="stone") loc="/d/4world/entrance";^M
        if(arg=="stone") loc="/d/dntg/hgs/entrance";
        else if(arg=="kaifeng") loc="/d/kaifeng/tieta";
        else if(arg=="moon") loc="/d/moon/ontop2";
        else if(arg=="lingtai") loc="/d/lingtai/gate";
        else if(arg=="putuo") loc="/d/nanhai/gate";
        else if(arg=="changan") loc="/d/city/center";
        else if(arg=="sky") loc="/d/dntg/sky/nantian";
	else if(arg=="wuzhuang") loc="/d/qujing/wuzhuang/gate";
	else if(arg=="kusong") loc="/d/qujing/kusong/kusongjian";
	else if(arg=="meishan") loc="/d/meishan/erlangwai";

	else if(arg=="penglai") {
		if(!(map=present("eastsea map", me)) && !wizardp(me)) {
			write("��������ת�˰���Ҳ��֪�����Ǳ߷ɡ�����\n");
			message_vision("\n$Nʧ���ش���������������\n", me);
			return 1;
			}
		if( !wizardp(me)&&(string)map->query("unit")!="��" ){
			write("��������ת�˰���Ҳ��֪�����Ǳ߷ɡ�����\n");
                        message_vision("\n$Nʧ���ش���������������\n", me);
                        return 1;
                        }
//		write("����������򶫱ߺ��з�ȥ������\n\n");
		loc="/d/penglai/penglai";
	}
	else if(arg=="xueshan") {
		if(!(map=present("xueshan map", me)) && !wizardp(me)) {
			write("��������ת�˰���Ҳ��֪�����Ǳ߷ɡ�����\n");
			message_vision("\n$Nʧ���ش���������������\n", me);
			return 1;
			}
		if( !wizardp(me)&&(string)map->query("unit")!="��" ){
                        write("��������ת�˰���Ҳ��֪�����Ǳ߷ɡ�����\n");
                        message_vision("\n$Nʧ���ش���������������\n", me);
                        return 1;
                        }
//		write("������������ѩɽ��ȥ������\n\n");
		loc="/d/xueshan/binggu";
	}
	else if(arg=="baoxiang"){
		loc = "/d/qujing/baoxiang/bei1.c";
		loc[strlen(loc)-3] = '1'+random(4);
	}else if(arg=="pingding"){
		loc = "/d/qujing/pingding/ping1.c";
		loc[strlen(loc)-3] = '1'+random(4);
	}else if(arg=="yalong"){
		loc = "/d/qujing/pingding/yalong1.c";
		loc[strlen(loc)-3] = '1'+random(3);
	}else if(arg=="wuji"){
		loc = "/d/qujing/wuji/square.c";
		//loc[strlen(loc)-3] = '1'+random(9);
	}else if(arg=="chechi"){
		loc = "/d/qujing/chechi/jieshi1.c";
		loc[strlen(loc)-3] = '1'+random(9);
	}else if(arg=="tongtian"){
		loc = "/d/qujing/tongtian/hedong1.c";
		loc[strlen(loc)-3] = '1'+random(6);
	}else if(arg=="jindou"){
		loc = "/d/qujing/jindou/jindou1.c";
		loc[strlen(loc)-3] = '1'+random(4);
	}else if(arg=="nuerguo"){
		loc = "/d/qujing/nuerguo/towna1.c";
		/*
		if (me->query("obstacle/nuerguo")!="done" && !wizardp(me)){
			write("\nһ�����㶫������ش��˻�����\n");
			write("�����ӷɲ���ȥ��\n");
			return 1;
			}
		*/
		loc[strlen(loc)-4] = 'a'+random(3);
		loc[strlen(loc)-3] = '1'+random(3);
	}else if(arg=="dudi"){
		loc = "/d/qujing/dudi/dudi1.c";
		loc[strlen(loc)-3] = '1'+random(4);
        }else if(arg=="firemount"){
         	loc = "/d/qujing/firemount/cuiyun1.c";
		loc[strlen(loc)-3] = '1'+random(5);
	}else if(arg=="jilei"){
		loc = "/d/qujing/jilei/jilei1.c";
		loc[strlen(loc)-3] = '1'+random(3);
	}else if(arg=="jisaiguo"){
		loc = "/d/qujing/jisaiguo/east1.c";
		loc[strlen(loc)-3] = '1'+random(4);
	}else if(arg=="jingjiling"){
		loc = "/d/qujing/jingjiling/jingji1.c";
	}else if(arg=="xiaoxitian"){
		loc = "/d/qujing/xiaoxitian/simen.c";
        }else if(arg=="zhuzi"){
         	loc = "/d/qujing/zhuzi/zhuzi1.c";
		loc[strlen(loc)-3] = '1'+random(5);
        }else if(arg=="qilin"){
         	loc = "/d/qujing/qilin/yutai.c";
        }else if(arg=="pansi"){
         	loc = "/d/qujing/pansi/ling1.c";
		loc[strlen(loc)-3] = '1'+random(6);
        }else if(arg=="biqiu"){
         	loc = "/d/qujing/biqiu/jie1.c";
		loc[strlen(loc)-3] = '1'+random(9);
        }else if(arg=="qinghua"){
         	loc = "/d/qujing/biqiu/zhuang.c";
	}else if(arg=="wudidong"){
		loc = "/d/qujing/wudidong/firemount-wudidong3.c";
		loc[strlen(loc)-3] = '1'+random(3);
        }else if(arg=="qinfa"){
         	loc = "/d/qujing/qinfa/jiedao1.c";
		loc[strlen(loc)-3] = '1'+random(8);
        }else if(arg=="yinwu"){
         	loc = "/d/qujing/yinwu/huangye1.c";
        }else if(arg=="fengxian"){
         	loc = "/d/qujing/fengxian/jiedao1.c";
		loc[strlen(loc)-3] = '1'+random(9);
        }else if(arg=="yuhua"){
         	loc = "/d/qujing/yuhua/xiaojie1.c";
		loc[strlen(loc)-3] = '1'+random(9);
        }else if(arg=="baotou"){
         	loc = "/d/qujing/baotou/shanlu1.c";
		loc[strlen(loc)-3] = '1'+random(9);
        }else if(arg=="zhujie"){
         	loc = "/d/qujing/zhujie/shanlu11.c";
		loc[strlen(loc)-3] = '1'+random(8);
        }else if(arg=="jinping"){
         	loc = "/d/qujing/jinping/xiaojie1.c";
		loc[strlen(loc)-3] = '1'+random(7);
        }else if(arg=="qinglong"){
         	loc = "/d/qujing/qinglong/shanjian.c";
        }else if(arg=="tianzhu"){
         	loc = "/d/qujing/tianzhu/jiedao11.c";
		loc[strlen(loc)-3] = '1'+random(8);
        }else if(arg=="maoying"){
         	loc = "/d/qujing/maoying/shanpo1.c";
		loc[strlen(loc)-3] = '1'+random(9);
        }else if(arg=="lingshan"){
         	loc = "/d/qujing/lingshan/dalu1.c";
		loc[strlen(loc)-3] = '1'+random(3);
        }else{
                write("\n\n���ˣ��㰴����ͷ����������\n");
                write("�ף���������ô����ԭ���ĵط���\n");
                return 1;
        }

	if (! loc)
		return 1;
		
	// mon /10/18/98
	if(MISC_D->random_capture(me,0,1)) return 1;

	if (ridee = me->ride()) {
	  ridemsg = ridee->query("ride/msg")+"��"+ridee->name();
	  ridee->move(loc);
	}  
	else  
	  ridemsg = "";
	                                            	
	me->move(loc);
        write("\n\n���ˣ��㰴����ͷ����������\n");

	if( (string)me->query("family/family_name")=="���޵ظ�") {
		message_vision(HIY"\nֻ��ƽ�ش���һ�����磬$N"+ridemsg+"���������˳�����\n"
NOR, me);
	}else if( (string)me->query("family/family_name") == "��ѩɽ"
		|| (string)me->query("family/family_name") == "�ݿ�ɽ�޵׶�") {
		message_vision(HIY"\nֻ����������$N"+ridemsg+"���������˳�����\n"NOR, me);
	}else{
        message_vision(HIY
"\nֻ������н���һ���Ʋʣ�$N"+ridemsg+"���������˳�����\n" NOR, me);
	}

        return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : fly|fei [Ŀ�ĵ�]

����ĵ��кͷ�����ǿʱ����������Ƽ���

Ŀǰ����Էɵ��ĵط���
changan         ->������                 kaifeng        ->�����
stone           ->����ɽ��ʯ             sky            ->������
moon      	->����ɽ�¹�             penglai        ->�����ɵ�
lingtai         ->��̨����ɽ    	 putuo     	->�Ϻ�����ɽ
xueshan	        ->��ѩɽ������           meishan        ->÷ɽ�཭��
wuzhuang        ->����ɽ��ׯ��

baoxiang	->�����		 pingding  	->ƽ��ɽ
yalong    	->ѹ��ɽ 		 wuji           ->�ڼ���
chechi		->���ٹ� 		 tongtian	->ͨ���
jindou  	->��ɽ 		 nuerguo	->Ů����
dudi   		->����ɽ 		 firemount	->����ɽ
jilei    	->����ɽ 		 jisaiguo	->������
jingjiling	->������		 xiaoxitian	->С����
zhuzi		->���Ϲ�		 qilin		->����ɽ
pansi		->��˿��		 biqiu		->����� 
qinghua		->�廪ׯ		 wudidong       ->�޵׶�
qinfa           ->�շ���		 fengxian	->���ɿ� 
yinwu    	->����ɽ		 yuhua   	->���� 
baotou  	->��ͷɽ		 zhujie  	->���ɽ
jinping 	->��ƽ��		 qinglong	->����ɽ 
tianzhu 	->���ù�		 maoying 	->ëӱɽ 
lingshan	->��ɽ                   

HELP
        );
        return 1;
}

