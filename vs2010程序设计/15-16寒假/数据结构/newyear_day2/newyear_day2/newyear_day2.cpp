// newyear_day2.cpp : 定义控制台应用程序的入口点。
//
///实现功能：设数组的最大长度为100，仅利用一个辅助节点将线性表的数据循环右移k位。
#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
#define ElemType  int 
////线性表的类型
typedef struct 
{
    ElemType elem[MAXSIZE];
	int length;
}SeqList;

////函数功能：线性表的初始化
SeqList Init_SeqList()
{
    SeqList l;
	l.length=0;
	return l;
}
////函数功能：线性表的建立(表内元素的赋值)
SeqList  Creat_SeqList(SeqList l)
{
	printf("\n输入线性表的元素，当输入-1时，代表结束\n");
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

