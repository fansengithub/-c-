// ջ�Ļ�������.cpp : �������̨Ӧ�ó������ڵ㡣
//����ջ��˳��ṹ����һ�����ݡ�Ҫ��ʵ��ջ�ĳ�ʼ������ջ����ջ��ȡջ��Ԫ�أ����ջ��yuansu

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE  100
typedef struct SqStack
{
   int elem[MAXSIZE];
   int top;
}SqStack,*stack_type;
///�������ܣ�����һ��˳��ջ������һ��ָ��ջ��ָ�롣����0ʱ���������ʧ��.
stack_type Init_SqStack()
{
   SqStack * s;
   s=(stack_type)malloc(sizeof(SqStack));
   if(s)
   {
	   s->top=-1;
	   printf("�ÿ�ջ�ɹ���\n");
   }
   return s;
}
//�������ܣ��ж�ջ�Ƿ�Ϊ�գ�Ϊ��ջʱ������1.���򣬷���0
int  Empty_SqStack(stack_type S)
{
	//if()
	if(S->top==-1)
		return -1;
	else
		return 0;
}
//�������ܣ���ջ��ѹ��һ���µ�Ԫ�أ�����ջ�ɹ�ʱ������1�����򣬷���0��
int Push_SqStack(stack_type s)
{
   int n;
   if(s->top==MAXSIZE)
   {
     printf("ջ��Ԫ����������������ѹ��Ԫ��!\n");
	 return 0;
   }
   else
   {
      printf("��������Ҫ��ջ������Ԫ�صĸ���!\n");
	  scanf("%d",&n);
	  printf("���������뽫Ҫ��ջ��Ԫ�أ�\n");
	  while(s->top<n-1)
	  {
		  s->top++;
		  scanf("%d",&s->elem[s->top]);
	  }
	  printf("��ջ��ѹ������Ԫ�سɹ���\n");
	  return 1;
   }
}
///�������ܣ�ɾ��ջ��Ԫ�أ��ɹ�ʱ������1.���򷵻�0��
int Pop_SqStack(stack_type s,int * tmp)
{
	if(Empty_SqStack(s))
	{
	  printf("Ϊ��ջ�����ܵ���Ԫ��!\n");
	  return 0;
	}
	else
	{
		*tmp=s->elem[s->top];
		s->top--;
		return 1;
	}
}
//�������ܣ�ȡ��ջ��Ԫ�أ����ɹ�ʱ������1.���򣬷���0��
int GetTop_SqStack(stack_type s,int * tmp)
{
    if(Empty_SqStack(s))					///�ж��Ƿ�Ϊ��ջ
	{
	   printf("λ��ջ��û��ջ��Ԫ��!\n");
	   return 0;
	}
	else
	{
		*tmp=s->elem[s->top];
		return 1;
	}
}
///�������ܣ���ӡջ������Ԫ��
void Print_SqStack(stack_type s)
{
	int i=s->top;
	while(i>=0)
	{
		printf("%d   ",s->elem[i]);
		i--;
	}
}
///�������ܣ��˵�����
void menu()
{
 	printf("---------------------------\n");
	printf("		1---ջ�ĳ�ʼ��\n");
	printf("		2---��ջ\n");
	printf("		3---��ջ\n");
	printf("		4---ȡջ��Ԫ��\n");
	printf("		5---���ջ�е�Ԫ��\n");
	printf("		6---�˳�\n");
	printf("---------------------------\n");
}

int _tmain(int argc, _TCHAR* argv[])
{
	int select,data,k,k1;
	stack_type s;
	printf("\n");
	menu();
	printf("��������Ӧѡ��!\n");
	scanf("%d",&select);
	while(select)
	{
	   switch(select)
	   {
	   case 1:
		   s=Init_SqStack();break;
	   case 2:
		   Push_SqStack(s);break;
	   case 3:
		   k=Pop_SqStack(s,&data);
		   if(k)
			   printf("��ջ��Ԫ��Ϊ�� %d\n",data);
		   break;
	   case 4:
		   k1=GetTop_SqStack(s,&data);
		   if(k1)
			   printf("��ǰջ����Ԫ��Ϊ�� %d\n",data);
		   break;
	   case 5:
		   Print_SqStack(s);
		   break;
	   case 6:
		   exit(0);
	   default:printf("�������!\n");
	   }
	   menu();
	   printf("��������Ӧѡ�\n");
	   scanf("%d",&select);
	}
	return 0;
}

