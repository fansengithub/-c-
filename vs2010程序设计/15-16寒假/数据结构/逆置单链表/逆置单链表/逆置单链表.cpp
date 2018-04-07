// 逆置单链表.cpp : 定义控制台应用程序的入口点。
//
///代码功能：将一个单链表逆置如 a,b,c,d,e,f--->f,e,d,c,b,a
#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;
typedef struct Lnode
{
   ElemType data;			//单链表的数据域
   struct Lnode * next;		//单链表的指针域
}Lnode,*LinkList;
LinkList CreatList_T()    //尾差法建立单链表
{
   Lnode *L, *r,*p;
   ElemType x;		//x为单链表中数据元素
   L=(LinkList)malloc(sizeof(Lnode));	//申请头节点空间
   L->next=NULL;
   r=L;
   scanf("%d",&x);
   while(x!=-1)
   {
      p=(LinkList)malloc(sizeof(Lnode));		//申请一个新的节点
	  p->data=x;						
	  r->next=p;						//将节点插入到链表尾
	  r=p;
	  scanf("%d",&x);
   }
   r->next=NULL;
   return L;
}
///函数功能：将带头结点的单链表逆置，逆置后单链表的头指针不变
LinkList InvertList(LinkList L)
{
	LinkList p,s;
	p=L->next;		//p指向原表中的一个节点
	L->next=NULL;
	while(p)
	{
	    s=p;		//s是当前逆置节点
		p=p->next;	//p指向下一个将逆置的节点
		s->next=L->next;
		L->next=s;
	}
	return L;
}
int _tmain(int argc, _TCHAR* argv[])
{
	LinkList  list,start,p;
	printf("创建一个单链表，输入单链表中的数据（当输入-1时，代表输入结束）:\n");
	list=CreatList_T();
	printf("逆置之前的单链表为：\n");
	for(start=list->next;start!=NULL;start=start->next)
		printf(" %d ",start->data);
	printf("\n");
	p=InvertList(list);
	printf("逆置之后的单链表为：\n");
	for(start=list->next;start!=NULL;start=start->next)
		printf(" %d ",start->data);
	return 0;
}

