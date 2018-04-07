// 栈的基本操作.cpp : 定义控制台应用程序的入口点。
//利用栈的顺序结构输入一组数据。要求实现栈的初始化，入栈，出栈，取栈顶元素，输出栈顶yuansu

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE  100
typedef struct SqStack
{
   int elem[MAXSIZE];
   int top;
}SqStack,*stack_type;
///函数功能：创建一个顺序栈，创建一个指向栈的指针。返回0时，代表分配失败.
stack_type Init_SqStack()
{
   SqStack * s;
   s=(stack_type)malloc(sizeof(SqStack));
   if(s)
   {
	   s->top=-1;
	   printf("置空栈成功！\n");
   }
   return s;
}
//函数功能：判断栈是否为空，为空栈时，返回1.否则，返回0
int  Empty_SqStack(stack_type S)
{
	//if()
	if(S->top==-1)
		return -1;
	else
		return 0;
}
//函数功能：向栈顶压入一个新的元素，当入栈成功时，返回1，否则，返回0；
int Push_SqStack(stack_type s)
{
   int n;
   if(s->top==MAXSIZE)
   {
     printf("栈内元素已满，不能向里压入元素!\n");
	 return 0;
   }
   else
   {
      printf("请输入需要入栈的数据元素的个数!\n");
	  scanf("%d",&n);
	  printf("请依次输入将要入栈的元素！\n");
	  while(s->top<n-1)
	  {
		  s->top++;
		  scanf("%d",&s->elem[s->top]);
	  }
	  printf("向栈内压入数据元素成功！\n");
	  return 1;
   }
}
///函数功能：删除栈顶元素，成功时，返回1.否则返回0；
int Pop_SqStack(stack_type s,int * tmp)
{
	if(Empty_SqStack(s))
	{
	  printf("为空栈，不能弹出元素!\n");
	  return 0;
	}
	else
	{
		*tmp=s->elem[s->top];
		s->top--;
		return 1;
	}
}
//函数功能：取出栈顶元素，当成功时，返回1.否则，返回0；
int GetTop_SqStack(stack_type s,int * tmp)
{
    if(Empty_SqStack(s))					///判断是否为空栈
	{
	   printf("位空栈，没有栈顶元素!\n");
	   return 0;
	}
	else
	{
		*tmp=s->elem[s->top];
		return 1;
	}
}
///函数功能：打印栈中所有元素
void Print_SqStack(stack_type s)
{
	int i=s->top;
	while(i>=0)
	{
		printf("%d   ",s->elem[i]);
		i--;
	}
}
///函数功能：菜单函数
void menu()
{
 	printf("---------------------------\n");
	printf("		1---栈的初始化\n");
	printf("		2---入栈\n");
	printf("		3---出栈\n");
	printf("		4---取栈顶元素\n");
	printf("		5---输出栈中的元素\n");
	printf("		6---退出\n");
	printf("---------------------------\n");
}

int _tmain(int argc, _TCHAR* argv[])
{
	int select,data,k,k1;
	stack_type s;
	printf("\n");
	menu();
	printf("请输入相应选项!\n");
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
			   printf("出栈的元素为： %d\n",data);
		   break;
	   case 4:
		   k1=GetTop_SqStack(s,&data);
		   if(k1)
			   printf("当前栈顶的元素为： %d\n",data);
		   break;
	   case 5:
		   Print_SqStack(s);
		   break;
	   case 6:
		   exit(0);
	   default:printf("输入错误!\n");
	   }
	   menu();
	   printf("请输入相应选项：\n");
	   scanf("%d",&select);
	}
	return 0;
}

