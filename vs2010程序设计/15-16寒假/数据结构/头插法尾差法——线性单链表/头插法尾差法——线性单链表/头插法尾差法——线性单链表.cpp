// ͷ�巨β��������Ե�����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef int ElemType;
//����ڵ�����
typedef struct Lnode
{
    ElemType  data;   //������������
	struct Lnode  * next;   ///������ָ����
}Lnode,*LinkList;

///������ĳ�ʼ��
LinkList LinkListInit()
{
  Lnode * L;
  L=(Lnode *)malloc(sizeof(Lnode));  //����ڵ�ռ�
  if(L==NULL)                        ///�ж��Ƿ����㹻���ڴ�ռ�
	  printf("�����ڴ�ʧ�ܣ�\n");
  L->next=NULL;
  return L;
}

///������Ľ��� 1��ͷ�巨����������
LinkList CreatList_H()
{
   Lnode  *L;
   ElemType  x;				///xΪ���������������
   L=(LinkList)malloc(sizeof(Lnode));
   L->next=NULL;
   scanf("%d",&x);
   while(x!= -1)      ///��ʼ��һ��������
   {
      Lnode  *p;
	  p=(LinkList)malloc(sizeof(Lnode));  //�����µĽڵ�
	  p->data=x;
	  p->next=L->next;      ///���ڵ���뵽��ͷ
	  L->next=p;
	  scanf("%d",&x);
   }
   return L;
}
////������Ľ�����2--β�巨����������
LinkList  CreatList_T()
{
   Lnode *L,*r,*p;
   ElemType x;      ///�����������е�����
   L=(Lnode *)malloc(sizeof(Lnode));
   L->next=NULL;    ///��ʼ��һ��������
   r=L;				//rʼ��ָ���ն˽ڵ㣬��ʼʱ��ָ��ͷ�ڵ�
   scanf(" %d",&x);
   while(x!= -1)
   {
      p=(Lnode *)malloc(sizeof(Lnode));
	  p->data=x;
	  r->next=p;
	  r=p;
	  scanf("%d",&x);
   }
   r->next=NULL;
   return L;
}

///������Ĳ��ң��ڴ�ͷ�ڵ�ĵ������в���λ�ú�Ϊi��Ԫ��
int  GetElem(LinkList L,int i)
{
	 int j;
	 LinkList  p;
	 p=L;j=0;
	 while(p->next && j<i)
	 {
		 p=p->next;
		 j++;
	 }
	 if(j==i)  return p->data;
	 else  return -1;
}

///������Ĳ��ң���ֵ����
int Locate_L(LinkList L,ElemType e)
{
  LinkList p;
  int i=1;
  p=L->next;
  while(p)
  {
	  if(p->data==e) return i;
	  else p=p->next;
	  i++;
  }
  return -1;
}

///������Ĳ��룬�������iλ�ò���xԪ��
LinkList LinkList_L(LinkList L,int i,ElemType x)
{
   Lnode * pre,*p;    ///pre Ϊǰ���ڵ㣬����Ľڵ�Ϊ p
   int j=0;
   pre=L;
   for(j=1;j<i;j++)
	   pre=pre->next;
   p=(Lnode *)malloc(sizeof(Lnode));
   p->data=x;
   p->next=pre->next;
   pre->next=p;
   return L;
}

//���������ɾ��������ɾ����ͷ���ĵ�����L�е�i��Ԫ�أ�����e������ֵ
LinkList ListDelete_L(LinkList L,int i,ElemType e)
{
   Lnode *p,*s,*q;
   int j=0;
   int k=0;
   q=L;
   while(q)
   {
	   q=q->next;
	   k++;
   }
   if(i<1||i>k)  
	   return NULL;   ///���iֵ�Ƿ����
   for(p=L;j<i-1&&p->next!=NULL;j++)    ///Ѱ�ҵ�i-1���ڵ�
	   p=p->next;
   s=p->next;
   p->next=s->next;   ///ɾ��s��ָ��Ľڵ�
   e=s->data;
   free(s);       ///�ͷű�ɾ���Ľڵ�ռ�
   return L;
}
int _tmain(int argc, _TCHAR* argv[])
{
	LinkList list,start,p,list1;
	int i,k,m,n;
	ElemType x;
	printf("ʹ��ͷ�巨������һ�������������뵥�������ݣ�\n");
	list=CreatList_H();
	for(start=list->next;start!=NULL;start=start->next)
		printf(" %d ",start->data);
	printf("\n");
	printf("ʹ��β�巨�����ڶ��������������뵥�������ݣ�\n");
	list1=CreatList_T();
	for(start=list1->next;start!=NULL;start=start->next)
		printf(" %d ",start->data);
	printf("\n");
	printf("������Ҫ��ѯԪ�ص�λ�úţ���һ��������:\n");
	scanf("%d",&k);
	m=GetElem(list,k);
	if(m== -1)  printf("�����λ�úŴ���");
	else printf("��%d��λ�ö�Ӧ��Ԫ��Ϊ��%d\n",k,m);
	printf("������Ҫ���ҵ�Ԫ��ֵ������һ��������\n");
	scanf("%d",&k);
	m=Locate_L(list,k);
	if(m== -1)  printf("�Բ���û���ҵ���\n");
	else printf("��Ҫ��������Ԫ�ص�λ�ú�Ϊ��%d\n",m);
	printf("�������������Ԫ�ص�λ�ã���һ��������!\n");
	scanf("%d",&i);
	printf("������������ݵ�ֵ��\n");
	scanf("%d",&x);
	LinkList_L(list,i,x);
	printf("����������ֵ�����������Ԫ��Ϊ��\n");
	for(start=list->next;start!=NULL;start=start->next)
		printf("%d ",start->data);
	printf("\n");
	printf("�����뽫Ҫɾ��Ԫ�ص�λ�ã���һ��������):");
	scanf("%d",&x);
	ListDelete_L(list,x,m);
	printf("ɾ��ָ��λ��Ԫ��֮��ĵ�����Ϊ��");
	for(start=list->next;start!=NULL;start=start->next)
		printf("%d ",start->data);
	printf("\n");
	return 0;
}

