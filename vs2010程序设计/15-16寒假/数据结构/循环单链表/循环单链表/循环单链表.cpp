// ѭ��������.cpp : �������̨Ӧ�ó������ڵ㡣
//
/// �������ܣ���������ͷ�ڵ��ѭ������LA,LB�ϲ�Ϊһ��ѭ��������

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct Lnode
{
   ElemType data;
   struct Lnode * next;
}Lnode,*LinkList;
///�������ܣ�β�巨����ѭ��������
LinkList CreatList_T()
{
    Lnode * L,*r,*p;
	ElemType x;			//xΪ�������������е�����
	L=(LinkList)malloc(sizeof(Lnode));		//����ͷ���ռ�
	L->next=NULL;
	r=L;					//rʼ��ָ���ն˽ڵ㣬��ʼʱָ��ͷ��㣬
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
//�������ܣ��ϲ�����ѭ��������Ϊһ��ѭ��������
LinkList Merge(LinkList la,LinkList lb)
{
	Lnode *p, *q;
	p=la;
	q=lb;
	while(p->next!=la)  p=p->next;			///�ҵ���la�ı�β����pָ����
	while(q->next!=lb)  q=q->next;				///�ҵ�Lb�ı�β����qָ����
	q->next=la;				///�޸�lb���βָ��,ʹָ֮��la���ͷ�ڵ�
	p->next=lb->next;       ///�޸�la���βָ�룬ʹָ֮��lb��ĵ�һ���ڵ�
	free(lb);         ///�ͷ�lb���ͷ���
	return la;
}

int _tmain(int argc, _TCHAR* argv[])
{
	LinkList  list,list1,start,p;
	printf("������һ��ѭ�������������뵥�����е����ݣ�������-1ʱ�������������!��");
	list=CreatList_T();
	printf("�Ѵ�����һ��ѭ��������������ǣ�\n");
	for(start=list->next;start!=list;start=start->next)
		printf("%d ",start->data);
	//printf("%d ",start->data);
	printf("\n");
	printf("�����ڶ���ѭ�������������뵥�����е����ݣ�������-1ʱ�����������������");
	list1=CreatList_T();
	printf("�Ѵ����ڶ���ѭ��������������ǣ�\n");
	for(start=list1->next;start!=list1;start=start->next)
		printf("%d ",start->data);
	//printf("%d ",start->data);
	printf("\n");
	list=Merge(list,list1);
	printf("�ϲ�֮���ѭ��������Ϊ");
	for(start=list->next;start!=list;start=start->next)
		printf("%d ",start->data);
	//printf("%d ",start->data);
	return 0;
}

