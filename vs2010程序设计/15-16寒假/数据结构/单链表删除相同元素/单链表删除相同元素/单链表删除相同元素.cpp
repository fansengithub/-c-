// ������ɾ����ͬԪ��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct Lnode{
    ElemType data;      //������������
	struct Lnode * next;   //������ָ����
}Lnode,*LinkList;
///β�巨����������
LinkList CreatList_T()
{
  Lnode *L,*r,*p;
  ElemType x;       ///xΪ�����������е�����
  L=(LinkList)malloc(sizeof(Lnode));  //����ͷ���ռ�
  L->next=NULL;     ///��ʼ��һ������
  r=L;   //rʼ��ָ���ն˽ڵ㣬��ʼʱָ��ͷ�ڵ�
  scanf("%d",&x);
  while(x!=-1)
  {
     p=(LinkList)malloc(sizeof(Lnode));    //�����µĽڵ�
	 p->data=x;      /// �ڵ�������ֵ
	 r->next=p;     ///��������ڵ㣬���뵽����β��
	 r=p;				//rʼ��ָ���ն˽ڵ�
	 scanf("%d",&x);
  }
  r->next=NULL;
  return L;
}
///�ڴ�ͷ��㵥������ɾ���������ظ���Ԫ��
LinkList purge(LinkList L)
{
	LinkList r,q,p=L->next;
	while(p &&p->next)    ///p������p->next�����ն˽ڵ�ʱ��
	{
		q=p;r=p->next;
		while(r)
		{
			if(p->data==r->data)
			{
				q->next=r->next;
				free(r);		//ɾ���ڵ�r
				r=q->next;		//rָ��ɾ�ڵ�ĺ��
			} 
			else      ///���������ͬ������Ԫ�أ�����ɨ��
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
	printf("����һ�������������뵥�����е����ݣ�����-1���������");
	list=CreatList_T();
	printf("ɾ����ͬԪ��֮ǰ�ĵ�����Ϊ��\n");
	for(start=list->next;start!=NULL;start=start->next)
		printf("%d  ",start->data);
	printf("\n");
	p=purge(list);
	printf("ɾ����ͬԪ��֮��ĵ�����Ϊ�� \n");
	for(start=list->next;start!=NULL;start=start->next)
		printf("%d  ",start->data);

	return 0;
}

