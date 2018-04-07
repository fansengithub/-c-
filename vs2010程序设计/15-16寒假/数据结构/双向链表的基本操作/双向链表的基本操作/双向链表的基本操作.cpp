// 双向链表的基本操作.cpp : 定义控制台应用程序的入口点。
//编程实现，双向链表的创建，插入，删除

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
//定义双向链表的节点类型
typedef struct Node
{
  ElemType data;
  struct Node * prior;		//指向前驱节点
  struct Node * next;		//指向后继节点
}Node,* DLinkList;
//采用尾插法建立双向链表
DLinkList DLinkListCreat_T()
{
   Node *L, *p,*r;
   ElemType x;
   L=(Node *)malloc(sizeof(Node));		//申请头结点
   L->next=NULL;
   r=L;
   r->next=NULL;		//r始终指向终端节点
   scanf("%d",&x);
   while(x!= -1)
   {
       p=(Node *)malloc(sizeof(Node));
	   p->data=x;
	   p->next=NULL;
	   p->prior=r;
	   r->next=p;
	   r=p;
	   scanf("%d",&x);
   }
   r->next=NULL;
   return L;
}
///双向链表的插入操作
DLinkList DLinkListInsert(DLinkList L,int i,ElemType x)
{
  DLinkList p,s;		//s为要插入的节点
  int k;
  p=L;					//找到要插入的位置
  for(k=1;k<=i;k++)
	  p=p->next;
  s=(DLinkList)malloc(sizeof(Node));
  s->data=x;
  s->prior=p->prior;
  s->next=p;
  p->prior->next=s;
  p->prior=s;
  return L;
}
//双向链表的删除，删除双向链表中的第i个节点
DLinkList Delete_Dul(DLinkList L,int i)
{
    int k=1;
	DLinkList p;		//p为查找节点
	p=L->next;
	while((k++)!=i && p!=NULL)
	{
		p=p->next;
	}
	if(p==NULL)  printf("位置不合法！\n");
	else if(p->next==NULL)		//最后一个节点特殊处理
	{
		p->prior->next=NULL;
		free(p);
	}
	else				//一般情况时，进行删除操作
	{
		p->prior->next=p->next;
		p->next->prior=p->prior;
		free(p);
	}
	return L;
}
int _tmain(int argc, _TCHAR* argv[])
{
	DLinkList list,start;
	int i;
	ElemType x;
	printf("创建双向链表，输入数据元素（当输入-1时，代表输入结束！）\n");
	list=DLinkListCreat_T();
	printf("已创建的双向链表中的数据元素为：\n");
	for(start=list->next;start!=NULL;start=start->next)
		printf("%d ",start->data);
	printf("\n");
	printf("输入插入位置！\n");
	scanf("%d",&i);
	printf("输入要插入的元素！\n");
	scanf("%d",&x);
	DLinkListInsert(list,i,x);
	printf("插入操作之后的双向链表中的数据元素为：\n");
	for(start=list->next;start!=NULL;start=start->next)
		printf("%d ",start->data);
	printf("\n");
	printf("请输入将要删除的位置：\n");
	scanf("%d",&i);
	Delete_Dul(list,i);
	printf("删除操作之后的双向链表中的数据元素为：\n");
	for(start=list->next;start!=NULL;start=start->next)
		printf("%d ",start->data);
	printf("\n");
	return 0;
}

