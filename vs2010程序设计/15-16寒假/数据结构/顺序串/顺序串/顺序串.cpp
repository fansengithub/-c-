// ˳��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10
typedef struct String
{
  char * ch;         //˳�򴮵�һ��Ԫ�صĴ��λ��
  int length;			//һ��˳�򴮵ľ��峤��
  int strsize;			//��������ʱ��������ڴ��С
}String;
///�������ܣ�ʵ�ִ��ĳ�ʼ��
void Init_String(String * str)
{
	str->ch=(char *)malloc(MAXSIZE*sizeof(String));
	str->length=0;
	str->strsize=MAXSIZE;
}
///��������:ͬ��һ�����飬��˳�򴮸�ֵ
void Array_String(String * str,char a[])
{
    int i=0;
	while(a[i]!='\0')			///�������a[]�ĳ��ȣ��жϺϷ���
	{
	  i++;
	}
	if(i>str->strsize)
	{
	   printf("�������鳤�ȳ���˳�򴮵���󳤶ȣ���Ҫ���������ڴ棡");
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

