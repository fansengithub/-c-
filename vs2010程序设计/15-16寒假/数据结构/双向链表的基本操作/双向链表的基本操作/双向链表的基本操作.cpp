// ˫������Ļ�������.cpp : �������̨Ӧ�ó������ڵ㡣
//���ʵ�֣�˫������Ĵ��������룬ɾ��

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
//����˫������Ľڵ�����
typedef struct Node
{
  ElemType data;
  struct Node * prior;		//ָ��ǰ���ڵ�
  struct Node * next;		//ָ���̽ڵ�
}Node,* DLinkList;
//����β�巨����˫������
DLinkList DLinkListCreat_T()
{
   Node *L, *p,*r;
   ElemType x;
   L=(Node *)malloc(sizeof(Node));		//����ͷ���
   L->next=NULL;
   r=L;
   r->next=NULL;		//rʼ��ָ���ն˽ڵ�
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
///˫������Ĳ������
DLinkList DLinkListInsert(DLinkList L,int i,ElemType x)
{
  DLinkList p,s;		//sΪҪ����Ľڵ�
  int k;
  p=L;					//�ҵ�Ҫ�����λ��
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
//˫�������ɾ����ɾ��˫�������еĵ�i���ڵ�
DLinkList Delete_Dul(DLinkList L,int i)
{
    int k=1;
	DLinkList p;		//pΪ���ҽڵ�
	p=L->next;
	while((k++)!=i && p!=NULL)
	{
		p=p->next;
	}
	if(p==NULL)  printf("λ�ò��Ϸ���\n");
	else if(p->next==NULL)		//���һ���ڵ����⴦��
	{
		p->prior->next=NULL;
		free(p);
	}
	else				//һ�����ʱ������ɾ������
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
	printf("����˫��������������Ԫ�أ�������-1ʱ�����������������\n");
	list=DLinkListCreat_T();
	printf("�Ѵ�����˫�������е�����Ԫ��Ϊ��\n");
	for(start=list->next;start!=NULL;start=start->next)
		printf("%d ",start->data);
	printf("\n");
	printf("�������λ�ã�\n");
	scanf("%d",&i);
	printf("����Ҫ�����Ԫ�أ�\n");
	scanf("%d",&x);
	DLinkListInsert(list,i,x);
	printf("�������֮���˫�������е�����Ԫ��Ϊ��\n");
	for(start=list->next;start!=NULL;start=start->next)
		printf("%d ",start->data);
	printf("\n");
	printf("�����뽫Ҫɾ����λ�ã�\n");
	scanf("%d",&i);
	Delete_Dul(list,i);
	printf("ɾ������֮���˫�������е�����Ԫ��Ϊ��\n");
	for(start=list->next;start!=NULL;start=start->next)
		printf("%d ",start->data);
	printf("\n");
	return 0;
}

