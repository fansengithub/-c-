// ������ʵ�ּ��ϵĲ�.cpp : �������̨Ӧ�ó������ڵ㡣
//�õ�����la,lb�ֱ������������a,b----�󼯺�a-b(�����ڼ���a��ɾ���뼯��b��ͬ��Ԫ��)

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct Lnode
{
   ElemType data;		//������������
   struct Lnode * next;		//������ָ����
}Lnode,*LinkList;

///β�����һ��������
LinkList CreatList_T()
{
  Lnode * L,*r,*p;
  ElemType x;		//xΪ������������
  L=(LinkList)malloc(sizeof(Lnode));	//����һ���µĽڵ�
  L->next=NULL;
  r=L;		//rʼ��ָ���ն˽ڵ㣬��ʼʱָ��ͷ�ڵ�
  scanf("%d",&x);
  while(x!=-1)
  {
     p=(LinkList)malloc(sizeof(Lnode));		//���������ڵ�
	 p->data=x;
	 r->next=p;			//��������ڵ���ӵ�����β��
	 r=p;		//rʼ��ָ���ն˽ڵ�
	 scanf("%d",&x);
  }
  r->next=NULL;
  return L;
}
LinkList Diff(LinkList la,LinkList lb)
{
   LinkList s,p,q,r;
   s=la;
   p=la->next;				///pָ��la���ĳһ�ڵ㣬sָ����ǰ���ڵ�
   while(p!=NULL)
   {
	   q=lb->next;			//����ɨ��lb���鿴�Ƿ�����la��pָ��ڵ���ͬ������Ԫ��
	   while(q && q->data!=p->data)  q=q->next;
	   if(q!=NULL)			///��lb�����ҵ���la��pָ��ڵ㣬��ͬ������Ԫ�ؽڵ�
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
	printf("������һ�����������뵥��������ݣ�������-1ʱ�����������������");
    list=CreatList_T();
	printf("\n�Ѵ�����һ��������Ϊ��\n");
	for(start=list->next;start!=NULL;start=start->next)
	{
		printf("%d  ",start->data);
	}
	printf("\n");
	printf("�����ڶ������������뵥��������ݣ�������-1ʱ���������ݽ�������");
	list1=CreatList_T();
	printf("\n�Ѵ����ڶ���������Ϊ��\n");
	for(start=list1->next;start!=NULL;start=start->next)
	{
		printf("%d ",start->data);
	}
	printf("\n");
	p=Diff(list,list1);
	printf("��֮��ĵ�����Ϊ��\n");
	for(start=p->next;start!=NULL;start=start->next)
		printf("%d ",start->data);
	printf("\n");
	return 0;
}

