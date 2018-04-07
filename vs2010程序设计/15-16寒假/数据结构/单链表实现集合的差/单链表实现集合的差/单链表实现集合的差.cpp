// 单链表实现集合的差.cpp : 定义控制台应用程序的入口点。
//用单链表la,lb分别代表两个集合a,b----求集合a-b(即，在集合a中删除与集合b相同的元素)

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct Lnode
{
   ElemType data;		//单链表数据域
   struct Lnode * next;		//单链表指针域
}Lnode,*LinkList;

///尾差法建立一个单链表、
LinkList CreatList_T()
{
  Lnode * L,*r,*p;
  ElemType x;		//x为单链表数据域
  L=(LinkList)malloc(sizeof(Lnode));	//创建一个新的节点
  L->next=NULL;
  r=L;		//r始终指向终端节点，开始时指向头节点
  scanf("%d",&x);
  while(x!=-1)
  {
     p=(LinkList)malloc(sizeof(Lnode));		//申请新增节点
	 p->data=x;
	 r->next=p;			//将新申请节点添加到链表尾部
	 r=p;		//r始终指向终端节点
	 scanf("%d",&x);
  }
  r->next=NULL;
  return L;
}
LinkList Diff(LinkList la,LinkList lb)
{
   LinkList s,p,q,r;
   s=la;
   p=la->next;				///p指向la表的某一节点，s指向其前驱节点
   while(p!=NULL)
   {
	   q=lb->next;			//依次扫描lb，查看是否有与la中p指向节点相同的数据元素
	   while(q && q->data!=p->data)  q=q->next;
	   if(q!=NULL)			///在lb表中找到与la中p指向节点，相同的数据元素节点
	   {
	       r=p;
		   s->next=p->next;
		   p=p->next;
		   free(r);
	   }
	   else
	   {
	       s=p;
		   p=p->next;
	   }
   }
   return la;
}
int _tmain(int argc, _TCHAR* argv[])
{
	LinkList  list,list1,start,p;
	printf("创建第一个单链表，输入单链表的数据（当输入-1时，代表输入结束！）");
    list=CreatList_T();
	printf("\n已创建第一个单链表为：\n");
	for(start=list->next;start!=NULL;start=start->next)
	{
		printf("%d  ",start->data);
	}
	printf("\n");
	printf("创建第二个单链表，输入单链表的数据（当输入-1时，代表数据结束！）");
	list1=CreatList_T();
	printf("\n已创建第二个单链表为：\n");
	for(start=list1->next;start!=NULL;start=start->next)
	{
		printf("%d ",start->data);
	}
	printf("\n");
	p=Diff(list,list1);
	printf("求差集之后的单链表为：\n");
	for(start=p->next;start!=NULL;start=start->next)
		printf("%d ",start->data);
	printf("\n");
	return 0;
}

