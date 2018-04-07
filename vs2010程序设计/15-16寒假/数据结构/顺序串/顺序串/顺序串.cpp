// 顺序串.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10
typedef struct String
{
  char * ch;         //顺序串第一个元素的存放位置
  int length;			//一个顺序串的具体长度
  int strsize;			//重新申请时，申请的内存大小
}String;
///函数功能：实现串的初始化
void Init_String(String * str)
{
	str->ch=(char *)malloc(MAXSIZE*sizeof(String));
	str->length=0;
	str->strsize=MAXSIZE;
}
///函数功能:同过一个数组，向顺序串赋值
void Array_String(String * str,char a[])
{
    int i=0;
	while(a[i]!='\0')			///求出数组a[]的长度，判断合法性
	{
	  i++;
	}
	if(i>str->strsize)
	{
	   printf("给定数组长度超过顺序串的最大长度！需要重新申请内存！");
	   exit (0);
	} 
	while(a[i]!='\0')
	{
		str->ch[i]=a[i];
		i++;
	}
	str->ch[i]='\0';
	str->length=i;
}
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

