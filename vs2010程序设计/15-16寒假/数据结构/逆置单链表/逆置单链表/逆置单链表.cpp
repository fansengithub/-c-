// ���õ�����.cpp : �������̨Ӧ�ó������ڵ㡣
//
///���빦�ܣ���һ�������������� a,b,c,d,e,f--->f,e,d,c,b,a
#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;
typedef struct Lnode
{
   ElemType data;			//�������������
   struct Lnode * next;		//�������ָ����
}Lnode,*LinkList;
LinkList CreatList_T()    //β�����������
{
   Lnode *L, *r,*p;
   ElemType x;		//xΪ������������Ԫ��
   L=(LinkList)malloc(sizeof(Lnode));	//����ͷ�ڵ�ռ�
   L->next=NULL;
   r=L;
   scanf("%d",&x);
   while(x!=-1)
   {
      p=(LinkList)malloc(sizeof(Lnode));		//����һ���µĽڵ�
	  p->data=x;						
	  r->next=p;						//���ڵ���뵽����β
	  r=p;
	  scanf("%d",&x);
   }
   r->next=NULL;
   return L;
}
///�������ܣ�����ͷ���ĵ��������ã����ú������ͷָ�벻��
LinkList InvertList(LinkList L)
{
	LinkList p,s;
	p=L->next;		//pָ��ԭ���е�һ���ڵ�
	L->next=NULL;
	while(p)
	{
	    s=p;		//s�ǵ�ǰ���ýڵ�
		p=p->next;	//pָ����һ�������õĽڵ�
		s->next=L->next;
		L->next=s;
	}
	return L;
}
int _tmain(int argc, _TCHAR* argv[])
{
	LinkList  list,start,p;
	printf("����һ�����������뵥�����е����ݣ�������-1ʱ���������������:\n");
	list=CreatList_T();
	printf("����֮ǰ�ĵ�����Ϊ��\n");
	for(start=list->next;start!=NULL;start=start->next)
		printf(" %d ",start->data);
	printf("\n");
	p=InvertList(list);
	printf("����֮��ĵ�����Ϊ��\n");
	for(start=list->next;start!=NULL;start=start->next)
		printf(" %d ",start->data);
	return 0;
}

