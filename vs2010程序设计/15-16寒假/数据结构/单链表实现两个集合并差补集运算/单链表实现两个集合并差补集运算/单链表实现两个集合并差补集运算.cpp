// ������ʵ���������ϲ��������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
typedef  char ElemType;				//����Ԫ������
typedef struct NodeType
{
	ElemType data;
	NodeType * next;
}NodeType, *LinkType;				///�ڵ�������ָ������
typedef struct 
{
   LinkType head,tail;				///�ֱ�ָ�����Ա��ͷ����β�ڵ�
   int size;						///��������ǰ�ĳ���
}OrderedList;						///�������������

///������pָ�������Ԫ��Ϊe�����Ϊ�յĽڵ㣬������true��
bool  MakeNode(LinkType &p,ElemType e)  
{
    p=(LinkType)malloc(sizeof(NodeType));
	if(!p)  return false;
	p->data=e;
	p->next=NULL;
	return true;
}
//�ͷŽڵ�
void FreeNode(LinkType  &p)			
{
   free(p);
}
///���������µĽڵ�
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
///��p!=NULLʱ������Pָ��ڵ������Ԫ��
ElemType  Elem(LinkType p)				
{
    if(p!=NULL)
		return p->data;
	return '\n';
}
///��p!=NULLʱ������p���Ԫ�ص�ָ��
LinkType SuccNode(LinkType p)			
{
  if(p!=NULL)
	  return p->next;
  return NULL;
}
///��ʼ�����Ա�
bool InitList(OrderedList & L)
{
	if(MakeNode(L.head,' '))		//ͷ�������Ԫ��Ϊ�ո��
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
////ɾ�����Ա�ͷ���֮�������Ԫ��
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
///�ж����Ա��Ƿ�Ϊ�ձ�
bool  ListEmpty(OrderedList L)
{
	if(L.head->next==NULL)
		return true;
	return false;
}
////�����Ա�ĳ���
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
///����ָ���pos��Ԫ��ָ��
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

