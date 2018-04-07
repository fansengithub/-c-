// 单链表删除相同元素.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct Lnode{
    ElemType data;      //单链表数据域
	struct Lnode * next;   //单链表指针域
}Lnode,*LinkList;
///尾插法建立单链表
LinkList CreatList_T()
{
  Lnode *L,*r,*p;
  ElemType x;       ///x为链表数据域中的数据
  L=(LinkList)malloc(sizeof(Lnode));  //申请头结点空间
  L->next=NULL;     ///初始化一个链表
  r=L;   //r始终指向终端节点，开始时指向头节点
  scanf("%d",&x);
  while(x!=-1)
  {
     p=(LinkList)malloc(sizeof(Lnode));    //申请新的节点
	 p->data=x;      /// 节点数据域赋值
	 r->next=p;     ///将新申请节点，插入到链表尾部
	 r=p;				//r始终指向终端节点
	 scanf("%d",&x);
  }
  r->next=NULL;
  return L;
}
///在带头结点单链表中删除，多余重复的元素
LinkList purge(LinkList L)
{
	LinkList r,q,p=L->next;
	while(p &&p->next)    ///p不空且p->next不是终端节点时，
	{
		q=p;r=p->next;
		while(r)
		{
			if(p->data==r->data)
			{
				q->next=r->next;
				free(r);		//删除节点r
				r=q->next;		//r指向被删节点的后继
			} 
			else      ///如果不是相同的数据元素，继续扫描
			{
			   q=r;
			   r=r->next;
			}
		}
			p=p->next;
	}
	return L;
}
int _tmain(int argc, _TCHAR* argv[])
{
	LinkList  list,start,p;
	printf("创建一个单链表，请输入单链表中的数据（输入-1代表结束）");
	list=CreatList_T();
	printf("删除相同元素之前的单链表为：\n");
	for(start=list->next;start!=NULL;start=start->next)
		printf("%d  ",start->data);
	printf("\n");
	p=purge(list);
	printf("删除相同元素之后的单链表为： \n");
	for(start=list->next;start!=NULL;start=start->next)
		printf("%d  ",start->data);

	return 0;
}

