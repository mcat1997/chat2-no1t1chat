#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
char Input[100];                                               //�洢������ַ�
char token[20];                                                //�洢�����Ĵʷ���Ԫ
int mark;                                                      //�ʷ��Ǻ�
char *KeyWords[10] = { "for","if","then","else","while","do" ,"until","int","input","output" };//�ؼ������飬�����ж�
char ch;
int p = 0, n, sum;
int m;//mΪtoken�±�

void Scanner()
{
	sum = 0;
	for (m = 0; m<20; m++)
		token[m++] = NULL;
	m = 0;
	ch = Input[p++];
	while ((ch == ' ') || (ch == '\n'))
		ch = Input[p++];
	if (((ch <= 'z') && (ch >= 'a')) || ((ch <= 'Z') && (ch >= 'A')))
	{
		while (((ch <= 'z') && (ch >= 'a')) || ((ch <= 'Z') && (ch >= 'A')) || ((ch >= '0') && (ch <= '9')))
		{
			if (ch == ' ')
				break;
			token[m++] = ch;//������������ַ��浽token��
			ch = Input[p++];

		}
		p--;
		mark = 10;
		for (n = 0; n < 10; n++)
		{
			if (strcmp(token, KeyWords[n]) == 0)//�ж�token����ַ����Ƿ��ǹؼ���
			{
				if(n<6) mark = n + 1;
				else mark = n + 23;
				break;
			}
		}
	}
	else if ((ch >= '0') && (ch <= '9'))
	{
		while ((ch >= '0') && (ch <= '9'))//�ж��Ƿ�������
		{
			sum = sum * 10 + ch - '0';
			ch = Input[p++];
		}
		p--;
		mark = 11;
	}
	else switch (ch)//�����ַ���switch�ж�֮
	{
	case '<':
		token[m++] = ch;
		ch = Input[p++];
		if (ch == '=')
		{
			mark = 22;
			token[m++] = ch;
		}
		else if (ch == '>')
		{
			mark = 21;
			token[m++] = ch;
		}
		else
		{
			mark = 20;
			p--;
		}
		break;
	case '>':
		token[m++] = ch;
		ch = Input[p++];
		if (ch == '=')
		{
			mark = 24;
			token[m++] = ch;
		}
		else
		{
			mark = 23;
			p--;
		}
		break;
	case '+':
		token[m++] = ch;
		ch = Input[p++];
		if (ch == '+')
		{
			mark = 17;
			token[m++] = ch;
		}
		else
		{
			mark = 13;
			p--;
		}
		break;
	case '-':
		token[m++] = ch;
		ch = Input[p++];
		if (ch == '-')
		{
			mark = 29;
			token[m++] = ch;
		}
		else
		{
			mark = 14;
			p--;
		}
		break;

		/*case '!':
		mark = 31;
		p--;
		break;*/

	case '=':
		mark = 25;
		token[m++] = ch;
		break;
	case '*':
		mark = 15;
		token[m++] = ch;
		break;
	case '/':
		mark = 16;
		token[m++] = ch;
		break;
	case '(':
		mark = 27;
		token[m++] = ch;
		break;
	case ')':
		mark = 28;
		token[m++] = ch;
		break;
		case '{':
		mark = 5;
		token[m++] = ch;
		break;
		case '}':
		mark = 6;
		token[m++] = ch;
		break;
	case ';':
		mark = 26;
		token[m++] = ch;
		break;
	case '\"':
		mark = 30;
		token[m++] = ch;
		break;
	case':':
		token[m++] = ch;
		ch = Input[p++];
		if (ch == '=')
		{
			mark = 18;
			token[m++] = ch;
		}
		else
		{
			mark = 17;
			p--;
		}
		break;

	case '#':
		mark = 0;
		token[m++] = ch;
		break;
	default:
		mark = -1;
		break;
	}
	token[m++] = '\0';
}
int main()
{
	int i = 0;
	cout << "���������'#'����:" << endl;
	while ((cin >> noskipws >> ch) && ch != '#')//�������
	{
		Input[i++] = ch;
	}
	do
	{
		Scanner();//���ú���ɨ�����
		switch (mark)
		{
		case 11:
			cout << "(" << mark << "," << sum << ")" << endl;//�������
			break;
		case -1:
			cout << "InputErroe" << endl;//�ʷ��Ǻ�Ϊ-1����������
			exit(0);
		default:
			cout << "(" << mark << "," << token << ")" << endl;//һ���ַ�
			break;
		}
	} while (mark != 0);
	return 0;
}