// 单链表实现两个集合并差补集运算.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
typedef  char ElemType;				//定义元素类型
typedef struct NodeType
{
	ElemType data;
	NodeType * next;
}NodeType, *LinkType;				///节点类型与指针类型
typedef struct 
{
   LinkType head,tail;				///分别指向线性表的头结点和尾节点
   int size;						///代表链表当前的长度
}OrderedList;						///有序的链表类型

///分配由p指向的数据元素为e，后继为空的节点，并返回true，
bool  MakeNode(LinkType &p,ElemType e)  
{
    p=(LinkType)malloc(sizeof(NodeType));
	if(!p)  return false;
	p->data=e;
	p->next=NULL;
	return true;
}
//释放节点
void FreeNode(LinkType  &p)			
{
   free(p);
}
///复制生成新的节点
LinkType Copy(LinkType  p)					
{
	LinkType  s;
	s=(LinkType)malloc(sizeof(NodeType));
	if(!s)
		return NULL;
	s->data=p->data;
	s->next=NULL;
	return s;
}
///当p!=NULL时，返回P指向节点的数据元素
ElemType  Elem(LinkType p)				
{
    if(p!=NULL)
		return p->data;
	return '\n';
}
///当p!=NULL时，返回p后继元素的指针
LinkType SuccNode(LinkType p)			
{
  if(p!=NULL)
	  return p->next;
  return NULL;
}
///初始化线性表
bool InitList(OrderedList & L)
{
	if(MakeNode(L.head,' '))		//头结点虚设元素为空格符
	{
		L.tail=L.head;
		L.size=0;
		return true;
	}
	else
	{
		L.head=NULL;
		return false;
	}
}
////删除线性表头结点之后的所有元素
void DestoryList(OrderedList &L)
{
   LinkType p;
   while(L.head->next)
   {
	   p=L.head->next;
	   L.head->next=p->next;
	   FreeNode(p);
   }
}
///判断线性表是否为空表
bool  ListEmpty(OrderedList L)
{
	if(L.head->next==NULL)
		return true;
	return false;
}
////求线性表的长度
int ListLength(OrderedList L)
{
  LinkType p;
  int len=0;
  p=L.head;
  while(p!=L.tail)
  {
	  p=p->next;
	  ++len;
  }
  return len;
}
///返回指向第pos个元素指针
LinkType GetElemPos(OrderedList L,int pos)
{
   LinkType p;
   int k;
   if(!L.head || pos<1 ||pos>L.size)
	   return NULL;
   else if(pos==L.size)
	   return L.tail;
   else
   {
	   p=L.head->next;
	   k=1;
	   while(p&&k<pos)
	   {
	      p=SuccNode(p);
	   }
   }
}
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

