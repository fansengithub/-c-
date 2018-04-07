// test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
int _tmain(int argc, _TCHAR* argv[])
{
	char a[10]="";
	char b[10][10];
	printf("------------\n");
	for(int i=0;i<10;i++)
	{
		puts(b[i]);
		printf("%d\n",i);
	}
	return 0;
}

