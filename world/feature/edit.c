// cracked by vikee 2/09/2002   vikee@263.net
// edit.c

int edit(function callback)
{
	write("�����뿪�� '.'��ȡ�������� '~q'��\n"); // ��ʹ���ڽ��б༭���� '~e'��\n");
	write("��������������������������������������������������������������������������������\n");
	input_to("input_line", "", 0, callback);
	return 1;
}

#define MAXLINES 250
#define MAXCOL 80

void input_line(string line, string text, int lines, function callback)
{
        // mon 6/16/98
        line=CONVERT_D->input(line, this_object());

	if(strlen(line) > MAXCOL) {
		write("һ��ֻ�ܰ��� "+MAXCOL+" ���ַ������ಿ�ֱ����ԡ�\n");
		line = line[0..MAXCOL-1];
	}

	if( line=="." ) {
		(*callback)(text);
		return;
	} else if( line=="~q" ) {
		write("����ȡ����\n");
		return;
//	} else if( line=="~e" ) {
	}

	if (lines >= MAXLINES) {
		write("���ĳ��� "+MAXLINES+" �У����ಿ�ֱ����ԡ�\n");
	} else {
		text += line + "\n";
		lines ++;
	}
	input_to("input_line", text, lines, callback);
}
