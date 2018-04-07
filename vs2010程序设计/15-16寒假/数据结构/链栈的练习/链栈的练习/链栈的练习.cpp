// 链栈的练习.cpp : 定义控制台应用程序的入口点。
//实现功能：利用栈的链式存储结构，将一组数据入栈，弹出栈中一个元素后，再输出栈中元素。

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct node
{
   int data;
   struct node * next;
}StackNode,*LinkStack;
LinkStack ls=NULL;
//函数功能：判断链栈是否为空
int NoEmpty_LinkStack(LinkStack p)
{
   if(p==NULL)  return 0;
   else return 1;
}
//函数功能：向栈顶压入一个元素
void push(LinkStack * ls,int * x)
{
    LinkStack p;
   p=(LinkStack)malloc(sizeof(StackNode));
   p->data=*x;
   p->next=*ls;
   *ls=p;
}
///函数功能：从栈顶弹出一个元素
int pop(LinkStack * ls,int * y)
{
   if(NoEmpty_LinkStack((*ls)))			//当不为空链栈时
   {
    LinkStack p;
	p=*ls;
	*y=p->data;
	*ls=(*ls)->next;
	p->next=NULL;
	free(p);
	return *y;
   }
   else
   {
      return 0;
   }
}
//
void print()
{
   LinkStack p;
   p=ls;
   printf("输出链栈中的所有元素!!!\n");
   while(p!=NULL)
   {
	   printf("%d ",p->data);
	   p=p->next;
   }
}
int _tmain(int argc, _TCHAR* argv[])
{
	int n,i,x,y;
	printf("请输入将要进栈的数据个数！\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("请输入元素值！\n");
		scanf("%d",&x);
	    push(&ls,&x);
	}
	print();
	printf("弹出链栈的栈顶元素为：%d",pop(&ls,&y));
	print();
	return 0;
}

