// cracked by vikee 2/09/2002   vikee@263.net
// gender.c

string gender_pronoun(string sex)
{
	switch(sex) {
		case "������":	return "��";	break;
		case "����":	return "��";	break;
		case "Ů��":	return "��";	break;
		case "����":
		case "����":	return "��";	break;
		default: return "��";
	}
}

string gender_self(string sex)
{
     return "��";
}

