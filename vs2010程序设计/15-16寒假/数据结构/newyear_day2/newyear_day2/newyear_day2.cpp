// newyear_day2.cpp : �������̨Ӧ�ó������ڵ㡣
//
///ʵ�ֹ��ܣ����������󳤶�Ϊ100��������һ�������ڵ㽫���Ա������ѭ������kλ��
#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
#define ElemType  int 
////���Ա������
typedef struct 
{
    ElemType elem[MAXSIZE];
	int length;
}SeqList;

////�������ܣ����Ա�ĳ�ʼ��
SeqList Init_SeqList()
{
    SeqList l;
	l.length=0;
	return l;
}
////�������ܣ����Ա�Ľ���(����Ԫ�صĸ�ֵ)
SeqList  Creat_SeqList(SeqList l)
{
	printf("\n�������Ա��Ԫ�أ�������-1ʱ���������\n");
    ElemType x;
	scanf("%d",&x);
	while(x!=-1)
	{
		l.elem[l.length]=x;
		l.length++;
		scanf("%d",&x);
	}
	return l;`
}
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

