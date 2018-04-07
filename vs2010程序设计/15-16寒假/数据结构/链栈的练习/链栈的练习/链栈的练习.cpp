// ��ջ����ϰ.cpp : �������̨Ӧ�ó������ڵ㡣
//ʵ�ֹ��ܣ�����ջ����ʽ�洢�ṹ����һ��������ջ������ջ��һ��Ԫ�غ������ջ��Ԫ�ء�

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
//�������ܣ��ж���ջ�Ƿ�Ϊ��
int NoEmpty_LinkStack(LinkStack p)
{
   if(p==NULL)  return 0;
   else return 1;
}
//�������ܣ���ջ��ѹ��һ��Ԫ��
void push(LinkStack * ls,int * x)
{
    LinkStack p;
   p=(LinkStack)malloc(sizeof(StackNode));
   p->data=*x;
   p->next=*ls;
   *ls=p;
}
///�������ܣ���ջ������һ��Ԫ��
int pop(LinkStack * ls,int * y)
{
   if(NoEmpty_LinkStack((*ls)))			//����Ϊ����ջʱ
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
   printf("�����ջ�е�����Ԫ��!!!\n");
   while(p!=NULL)
   {
	   printf("%d ",p->data);
	   p=p->next;
   }
}
int _tmain(int argc, _TCHAR* argv[])
{
	int n,i,x,y;
	printf("�����뽫Ҫ��ջ�����ݸ�����\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("������Ԫ��ֵ��\n");
		scanf("%d",&x);
	    push(&ls,&x);
	}
	print();
	printf("������ջ��ջ��Ԫ��Ϊ��%d",pop(&ls,&y));
	print();
	return 0;
}

