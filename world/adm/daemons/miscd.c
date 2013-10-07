// cracked by vikee 2/09/2002   vikee@263.net
// miscd.c
// by mon@xyj 10/19/98

#pragma optimize

#include <ansi.h>

inherit F_DBASE;

mapping maps=([]);

void create()
{
   string filename=__DIR__"find.map";
   string buf, *buf1;
   string dir, name;
   int size, i;

   seteuid(getuid());
   set("name", "��ؾ���");
   set("id", "miscd");

   maps=([]);

   buf=read_file(filename);
   if(!buf) return; //no data available.

   buf1=explode(buf,"\n");
   size=sizeof(buf1);
   if(!size) return;

   for(i=0;i<size;i++) {
     if(sscanf(buf1[i],"%s %s",dir,name)==2) {
       name=replace_string(name," ","");
       if(strlen(dir)>2 && strlen(name)>2) {
         maps+=([dir:name]);
       }
     }
   }
}

int random_capture(object me,int chance,int silent)
{
        if(!me) return 0;
        if(!chance) chance=5000;
//	if(wizardp(me)) chance=1;

        if(random(chance)==0) {
	    if(silent)
                tell_object(me,"\n��Ȼһ��Ʒ��Х�����������ɼ�"+
                    "�����˽�ȥ��\n");
	    else
                message_vision("\n��Ȼһ��Ʒ��Х������$N���ɼ�"+
                    "�����˽�ȥ��\n",me);
            tell_object(me,"\n��֪���˶�ã�����\n\n");
            me->set_temp("old_place",environment(me));
            me->move("/d/qujing/baihuling/jail",1);
            message_vision("$N���ص�һ��ˤ�ڵ��ϣ�\n",me);
            return 1;
        }
	return 0;
}


string find_place(object where)
{
	string fail, msg, filename, filename1, answer;
	int len;

	fail=""; // default fail message

        filename=file_name(where);
	len=strlen(filename);
	if(len<2) return fail;

        len--;
        while(filename[len]!='/' && len>0) {
	  len--;
	}
	if(len<2) return fail;

	filename1=filename[1..(len-1)];

        if(sscanf(filename,"/d/changan/bed#%*s")==1) {
	//this need check first.
	  answer="����";
        } else if(!undefinedp(maps[filename1])) {
	  answer=maps[filename1];
	} else if(where->is_character()) {
	  answer=where->query("name")+"����";
        } else if(sscanf(filename,"/obj/home#%*s")==1) {
          answer="ס����";
        } else { 
          answer=undefinedp(where->query("short"))?
		  where->short():
		  where->query("short");
        }

	return answer;
}

// mon 1/14/00
int check_date()
{
//2002-2-9 0:16
//annotated by һҶ֪��(vikee).skip the date check.
//xyj2000 use date check to persuade other to span the MudLIB.

/*
    int current=47908841;
    int now=time();
    int day=3600*24;
    int past;
    
    current=current+100000000*9;   

    past=(now-current)/day;
    
    if(past<-2 || past >(30*6)) {
	log_file("shutdown",ctime(time())+" expired.\n");
	shutdown(-1);
	return 0;
    }
*/	
    return 1;
}
