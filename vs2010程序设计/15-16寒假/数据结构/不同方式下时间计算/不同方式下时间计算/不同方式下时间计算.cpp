// 不同方式下时间计算.cpp : 定义控制台应用程序的入口点。
//函数功能：实现两种不同方式下使用内存空间时间差异求解。
//方式1：首先在内存中申请1000 0000个特定结构体大小的内存空间，然后依次取出，进行赋值操作，然后再放回。求出时间。
//方式2：直接调用c中malloc()----free() 函数1000 0000次。求出时间。
//vs中 int 数据类型的大小：   4个字节
#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#define N 10000000   ///定义n的大小为  1千万
//////时间结构体
//结构体定义
typedef struct node{
	//char data1;
	short int data1;
	//	int data2;
	//	int data3;
	node * next;
}node;	
///函数功能：执行第一种方式:自己申请一大段内存，
int  Action_1()
{
	node * head;
	node * p;
	node * r;
	node * t;
	int i=0;
	SYSTEMTIME t1,t2;			 //用于计算时间
	int time;
	GetSystemTime(&t1);
	printf("%d:%d\n",t1.wSecond,t1.wMilliseconds);			//打印开始前的时间


	///内存申请
	head =(node *)malloc(N*sizeof(node));
	//head=(node *)malloc(sizeof(node));
	
	p=head;
	//node *flag=head;
	while(i<N)            ///将申请的一大段内存，通过结构体链接为，链表
	{
		//p=&(*head)+i;//*sizeof(node);	
		p->data1=i;
		p->next=&(*p)+1;                       //sizeof(node);
		p=p->next;
		i++;
	}
	p->next=NULL;            ///最后一个结构体，的指针域为空
	
	//printf("**********************************");

	///内存使用

	p=head;
	

	///第一个节点的使用
	p=head->next;
	head->next=NULL;
	head->data1=0;      ////第一个节点的数据元素赋值
	head->next=p;

	while(p!=NULL)
	{
		if(p->next!=NULL)     ////当p的下一不为空时
		{
			t=p;
			r=p->next;     ///当p的下一个（r）不为空时，将r单独拿出来
			p=r->next;

			r->data1=0;       ///对r指向节点的使用
			r->next=NULL;

			r=t->next;		///r节点使用完毕后，将其放入链表中
			r->next=p;
			p=t;
		}
		else             //当p的下一个为空时，（即p为最后一个节点）
		{
		    t=head;				///用t找到p前面的节点
			while(t->next!=p)
			{
				t=t->next;
			}

			t->next=NULL;			///将节点p单独取出来
			p->data1=0;         ///队节点p的使用
			p->next=NULL;

			t->next=p;           ///将节点p放回链表中
		}
	  p=p->next;
	}

	///内存释放
 	//free(flag);															///----------------------------
	GetSystemTime(&t2);
	printf("%d:%d\n",t2.wSecond,t2.wMilliseconds);					///打印执行之后的时间
	time=(t2.wSecond - t1.wSecond)*1000+t2.wMilliseconds-t1.wMilliseconds;				///求出总共用时
	printf("总共用时：  %d    微秒\n",time);
	return time;
}
///函数功能：第二中处理方式:通过for循环，调用系统函数
int Action_2()
{
	
	int i=0;
	node * p=NULL;
	node * head;
	SYSTEMTIME t1,t2;
	int t;
	GetSystemTime(&t1);
	printf("%d:%d\n",t1.wSecond,t1.wMilliseconds);
	while(i<N)                 /////直接从系统中调用  malloc()  free()  N次
	{
	   head=(node *)malloc(sizeof(node));
	   head->data1=i;
	   free(head);
	   i++;
	}
	GetSystemTime(&t2);
	printf("%d:%d\n",t2.wSecond,t2.wMilliseconds);
	t=(t2.wSecond - t1.wSecond)*1000+t2.wMilliseconds-t1.wMilliseconds;
	printf("总共用时：  %d    微秒\n",t);
	return t;
}
///函数功能:求第一种方式处理的时间
int _tmain(int argc, _TCHAR* argv[])
{
	
	printf("当运算次数为： 10000000\n");
	int t1=0;
	int t2=0;
	t1=Action_1();
	t2=Action_2();
	printf("最终结果：  %d",(t2/t1));
	return 0;
}
	
