// 链式队列.cpp : 定义控制台应用程序的入口点。
//
///实现基本功能：向链式队列输入n个数据，输出队列中所有元素。
//出队一个，打印剩余队列中所有元素和长度。再入队一个元素，打印所有元素
#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;    ///定义数据元素类型
///结构体定义节点类型
typedef struct Qnode{			
	ElemType data;       ///节点中的数据元素
	struct Qnode * next;   //节点中的指针类型
}Qnode;
//结构体定义链式队列类型
typedef struct LinkQueue
{
	Qnode * front;   ///头节点指针
	Qnode * rear;       ///尾部节点指针
}LinkQueue;
//函数功能：初始化链式队列
void Init_LinkQueue(LinkQueue * lq)
{
	lq->front = lq->rear = (Qnode *)malloc(sizeof(Qnode));     ///头指针，尾指针都指向头结点
	if(lq->front == NULL)						///安全性检查
	{
		printf("分配内存失败！\n");
		exit(0);
	}
	lq->front->next = NULL;			///头结点的指针域，数据域赋值
	lq->front->data = -1;
}
//函数功能：销毁队列
void Destory_LinkQueue(LinkQueue * lq)
{
	while(lq->front!=NULL)
	{
		lq->rear=lq->front->next;
		free(lq->front);
		lq->front=lq->rear;
	}
	printf("该链式队列已经被销毁！\n");
}
///函数功能：判断队列是否为空
int Empty_LinkQueue(LinkQueue * lq)
{
	if(lq->front == lq->rear)				///当头指针与尾指针相等时，即为空
		return 1;
	else
		return 0;
}
///函数功能：入队操作
void In_LinkQueue(LinkQueue * lq,ElemType n)
{
	if(Empty_LinkQueue(lq))			///当链队列为空时
	{
		lq->rear = (Qnode *)malloc(sizeof(Qnode));   ///申请一个新的节点
		if(!lq->rear)  exit(0);						///安全性检查
		lq->front->next = lq->rear;
		lq->rear->data = n;
		lq->rear->next=NULL;
	}
	else					///当链队列非空时
	{
		lq->rear->next=(Qnode *)malloc(sizeof(Qnode));
		if(!lq->rear)  exit(0);					///
		lq->rear=lq->rear->next;
		lq->rear->data=n;
		lq->rear->next=NULL;
	}
}
//函数功能：出队操作
void Out_LinkQueue(LinkQueue * lq)
{
	if(Empty_LinkQueue(lq))				///判断队列是否为空
	{
		printf("此队列为空队列，无法执行出队操作！\n");
	}
	else				///队列非空时
	{
		Qnode * p;
		p=lq->front->next;
		lq->front->next=p->next;
		if(p->next==NULL)      ////当只剩最后一个节点时，让头指针与尾指着都指向头结点
		{
			lq->rear=lq->front;
		}
		printf("当前出队元素为：  ");
		printf("    %d   \n",p->data);
		free(p);
	}
}
///函数功能：打印队列中的所有数据元素
void Show_LinkQueue(LinkQueue * lq)
{
	if(Empty_LinkQueue(lq))				///判断队列是否为空
	{
		printf("当前队列为空,无法打印队列中的元素！\n");
	}
	else
	{
		Qnode * p;
		p=lq->front->next;
		while(p!=NULL)
		{
			printf("  %d  ",p->data);
			p=p->next;
		}
	}
	printf("\n\n");
}
int _tmain(int argc, _TCHAR* argv[])
{
	LinkQueue *lq;
	int n;
	int m;
	int  count=0;     ///用于求解队列长度时，计数
	Qnode * p;			///用于求当前队列的长度
	lq=(LinkQueue *)malloc(sizeof(LinkQueue));
	Init_LinkQueue(lq);
	printf("请输入将要输入数据元素的个数！\n");
	scanf("%d",&n);
	printf("请依次输入将要入队的数据元素：\n");
	while(n>0)
	{
		scanf("%d",&m);
		In_LinkQueue(lq,m);
		n--;
	}
	printf("当前队列中所有的数据元素为：\n");
	Show_LinkQueue(lq);
	Out_LinkQueue(lq);
	printf("当前队列中所有的数据元素为：\n");		///求队首元素
	Show_LinkQueue(lq);

	if(!Empty_LinkQueue(lq))
	{
	printf("当前队列的队首元素为：      ");			///求队列的首节点
	printf("   %d \n",lq->front->next->data);
	}
	else							////安全性检查
	{
	  printf("当前队列为空队列，没有首节点！  \n");
	}
	if(!Empty_LinkQueue(lq))
	{
		printf("当前队列的长度为：");					///求队列的长度
		p=lq->front->next;
		while(p!=NULL)
		{
			count++;
			p=p->next;
		}
		printf("   %d    \n",count);
	}
	else
	{
		printf("当前队列为空！");
	}
	printf("请输入入队元素！\n");
	scanf("%d",&n);
	In_LinkQueue(lq,n);
	Show_LinkQueue(lq);
	Destory_LinkQueue(lq);
	return 0;
}

