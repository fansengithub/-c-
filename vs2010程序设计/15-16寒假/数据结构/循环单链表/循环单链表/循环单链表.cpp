// 循环单链表.cpp : 定义控制台应用程序的入口点。
//
/// 函数功能：将两个带头节点的循环单链LA,LB合并为一个循环单链表

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct Lnode
{
   ElemType data;
   struct Lnode * next;
}Lnode,*LinkList;
///函数功能：尾插法建立循环单链表
LinkList CreatList_T()
{
    Lnode * L,*r,*p;
	ElemType x;			//x为链表中数据域中的数据
	L=(LinkList)malloc(sizeof(Lnode));		//申请头结点空间
	L->next=NULL;
	r=L;					//r始终指向终端节点，开始时指向头结点，
	scanf("%d",&x);
	while(x!= -1)
	{
	 p=(LinkList)malloc(sizeof(Lnode));
	 p->data=x;
	 r->next=p;
	 r=p;
	 scanf("%d",&x);
	}
	r->next=L;
	return L;
}
//函数功能：合并两个循环单链表为一个循环单链表
LinkList Merge(LinkList la,LinkList lb)
{
	Lnode *p, *q;
	p=la;
	q=lb;
	while(p->next!=la)  p=p->next;			///找到表la的表尾，用p指向它
	while(q->next!=lb)  q=q->next;				///找到Lb的表尾，用q指向它
	q->next=la;				///修改lb表的尾指针,使之指向la表的头节点
	p->next=lb->next;       ///修改la表的尾指针，使之指向lb表的第一个节点
	free(lb);         ///释放lb表的头结点
	return la;
}

int _tmain(int argc, _TCHAR* argv[])
{
	LinkList  list,list1,start,p;
	printf("创建第一个循环单链表，请输入单链表中的数据（当输入-1时，代表输入结束!）");
	list=CreatList_T();
	printf("已创建第一个循环单链表的数据是：\n");
	for(start=list->next;start!=list;start=start->next)
		printf("%d ",start->data);
	//printf("%d ",start->data);
	printf("\n");
	printf("创建第二个循环单链表，请输入单链表中的数据（当输入-1时，代表输入结束！）");
	list1=CreatList_T();
	printf("已创建第二个循环单链表的数据是：\n");
	for(start=list1->next;start!=list1;start=start->next)
		printf("%d ",start->data);
	//printf("%d ",start->data);
	printf("\n");
	list=Merge(list,list1);
	printf("合并之后的循环单链表为");
	for(start=list->next;start!=list;start=start->next)
		printf("%d ",start->data);
	//printf("%d ",start->data);
	return 0;
}

