#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
char Input[100];                                               //存储输入的字符
char token[20];                                                //存储连续的词法单元
int mark;                                                      //词法记号
char *KeyWords[10] = { "for","if","then","else","while","do" ,"until","int","input","output" };//关键字数组，用于判断
char ch;
int p = 0, n, sum;
int m;//m为token下标

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
			token[m++] = ch;//将连续读入的字符存到token中
			ch = Input[p++];

		}
		p--;
		mark = 10;
		for (n = 0; n < 10; n++)
		{
			if (strcmp(token, KeyWords[n]) == 0)//判断token存的字符串是否是关键字
			{
				if(n<6) mark = n + 1;
				else mark = n + 23;
				break;
			}
		}
	}
	else if ((ch >= '0') && (ch <= '9'))
	{
		while ((ch >= '0') && (ch <= '9'))//判断是否是数字
		{
			sum = sum * 10 + ch - '0';
			ch = Input[p++];
		}
		p--;
		mark = 11;
	}
	else switch (ch)//其他字符用switch判断之
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
	cout << "输入代码以'#'结束:" << endl;
	while ((cin >> noskipws >> ch) && ch != '#')//输入代码
	{
		Input[i++] = ch;
	}
	do
	{
		Scanner();//调用函数扫描代码
		switch (mark)
		{
		case 11:
			cout << "(" << mark << "," << sum << ")" << endl;//定义变量
			break;
		case -1:
			cout << "InputErroe" << endl;//词法记号为-1，输入有误
			exit(0);
		default:
			cout << "(" << mark << "," << token << ")" << endl;//一般字符
			break;
		}
	} while (mark != 0);
	return 0;
}