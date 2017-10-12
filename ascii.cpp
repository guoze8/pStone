// ConsoleApplication1.cpp: 定义控制台应用程序的入口点。
//


#include "stdafx.h"
#include <stdlib.h>
#include <string.h>

//储存控制字符
char *a[33] = { "NUL","SOH","STX",
"ETX","EOT","ENQ",
"ACK","BEL","BS",
"TAB","LF","VT",
"FF","CR","SO",
"SI","DLE","CC1",
"DC2","DC3","DC4",
"NAD","SYN","ETB",
"CAN","EM","SUB",
"ESC","FS","GS",
"RS","US","SPACE" };

void printHelp();
void printAscii(int radix);
void printError();


void main(int argc, char** argv)
{
	switch (argc)
	{
	case 1:
		printHelp();
		break;
	case 2:
		if (strcmp(argv[1], "-h") == 0)
			printHelp();
		else if (strcmp(argv[1], "-d") == 0)
		{
			printAscii(10);//输出ASCII的10进制代码
		}
		else if (strcmp(argv[1], "-o") == 0)
		{
			printAscii(8);//输出ASCII的8进制代码
		}
		else if (strcmp(argv[1], "-x") == 0)
		{
			printAscii(16);//输出ASCII的16进制代码
		}
		else if (strcmp(argv[1], "-b") == 0)
		{
			printAscii(2);//输出ASCII的2进制代码
		}
		else
		{
			printError();
		}
		break;
	default:
		printError();
		break;
}
}

void printHelp()
{
	printf("ascii [-h/-d/-o/-x/-b]\n");
	printf("h:Help\n");
	printf("d:Decimcal\n");
	printf("o:Octal\n");
	printf("x:Hex\n");
	printf("b:Binary\n");
}


void printAscii(int radix)
{
	//输出控制字符
	for (int i = 0; i < 33; i++)
	{
		switch (radix)
		{
		case 10:
			printf("%d\t%s\t\t", i, a[i]);
			break;
		default:
			char s[8];
			_itoa_s(i, s, 8, radix);
			printf("%s\t%s\t\t", s, a[i]);
			break;
		}
	}
	//输出普通字符
	for (int i = 33; i < 128; i++)
	{
		char c = (char)i;
		switch (radix)
		{
		case 10:
			printf("%d\t%c\t\t", i, c);
			break;
		default:
			char s[8];
			_itoa_s(i, s, 8, radix);
			printf("%s\t%c\t\t", s, c);
			break;
		}
	}
}

void printError()
{
	printf("Params invalid.\n");
	printHelp();
}