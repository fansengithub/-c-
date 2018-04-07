// ��ʽ����.cpp : �������̨Ӧ�ó������ڵ㡣
//
///ʵ�ֻ������ܣ�����ʽ��������n�����ݣ��������������Ԫ�ء�
//����һ������ӡʣ�����������Ԫ�غͳ��ȡ������һ��Ԫ�أ���ӡ����Ԫ��
#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;    ///��������Ԫ������
///�ṹ�嶨��ڵ�����
typedef struct Qnode{			
	ElemType data;       ///�ڵ��е�����Ԫ��
	struct Qnode * next;   //�ڵ��е�ָ������
}Qnode;
//�ṹ�嶨����ʽ��������
typedef struct LinkQueue
{
	Qnode * front;   ///ͷ�ڵ�ָ��
	Qnode * rear;       ///β���ڵ�ָ��
}LinkQueue;
//�������ܣ���ʼ����ʽ����
void Init_LinkQueue(LinkQueue * lq)
{
	lq->front = lq->rear = (Qnode *)malloc(sizeof(Qnode));     ///ͷָ�룬βָ�붼ָ��ͷ���
	if(lq->front == NULL)						///��ȫ�Լ��
	{
		printf("�����ڴ�ʧ�ܣ�\n");
		exit(0);
	}
	lq->front->next = NULL;			///ͷ����ָ����������ֵ
	lq->front->data = -1;
}
//�������ܣ����ٶ���
void Destory_LinkQueue(LinkQueue * lq)
{
	while(lq->front!=NULL)
	{
		lq->rear=lq->front->next;
		free(lq->front);
		lq->front=lq->rear;
	}
	printf("����ʽ�����Ѿ������٣�\n");
}
///�������ܣ��ж϶����Ƿ�Ϊ��
int Empty_LinkQueue(LinkQueue * lq)
{
	if(lq->front == lq->rear)				///��ͷָ����βָ�����ʱ����Ϊ��
		return 1;
	else
		return 0;
}
///�������ܣ���Ӳ���
void In_LinkQueue(LinkQueue * lq,ElemType n)
{
	if(Empty_LinkQueue(lq))			///��������Ϊ��ʱ
	{
		lq->rear = (Qnode *)malloc(sizeof(Qnode));   ///����һ���µĽڵ�
		if(!lq->rear)  exit(0);						///��ȫ�Լ��
		lq->front->next = lq->rear;
		lq->rear->data = n;
		lq->rear->next=NULL;
	}
	else					///�������зǿ�ʱ
	{
		lq->rear->next=(Qnode *)malloc(sizeof(Qnode));
		if(!lq->rear)  exit(0);					///
		lq->rear=lq->rear->next;
		lq->rear->data=n;
		lq->rear->next=NULL;
	}
}
//�������ܣ����Ӳ���
void Out_LinkQueue(LinkQueue * lq)
{
	if(Empty_LinkQueue(lq))				///�ж϶����Ƿ�Ϊ��
	{
		printf("�˶���Ϊ�ն��У��޷�ִ�г��Ӳ�����\n");
	}
	else				///���зǿ�ʱ
	{
		Qnode * p;
		p=lq->front->next;
		lq->front->next=p->next;
		if(p->next==NULL)      ////��ֻʣ���һ���ڵ�ʱ����ͷָ����βָ�Ŷ�ָ��ͷ���
		{
			lq->rear=lq->front;
		}
		printf("��ǰ����Ԫ��Ϊ��  ");
		printf("    %d   \n",p->data);
		free(p);
	}
}
///�������ܣ���ӡ�����е���������Ԫ��
void Show_LinkQueue(LinkQueue * lq)
{
	if(Empty_LinkQueue(lq))				///�ж϶����Ƿ�Ϊ��
	{
		printf("��ǰ����Ϊ��,�޷���ӡ�����е�Ԫ�أ�\n");
	}
	else
	{
		Qnode * p;
		p=lq->front->next;
		while(p!=NULL)
		{
			printf("  %d  ",p->data);
			p=p->next;
		}
	}
	printf("\n\n");
}
int _tmain(int argc, _TCHAR* argv[])
{
	LinkQueue *lq;
	int n;
	int m;
	int  count=0;     ///���������г���ʱ������
	Qnode * p;			///������ǰ���еĳ���
	lq=(LinkQueue *)malloc(sizeof(LinkQueue));
	Init_LinkQueue(lq);
	printf("�����뽫Ҫ��������Ԫ�صĸ�����\n");
	scanf("%d",&n);
	printf("���������뽫Ҫ��ӵ�����Ԫ�أ�\n");
	while(n>0)
	{
		scanf("%d",&m);
		In_LinkQueue(lq,m);
		n--;
	}
	printf("��ǰ���������е�����Ԫ��Ϊ��\n");
	Show_LinkQueue(lq);
	Out_LinkQueue(lq);
	printf("��ǰ���������е�����Ԫ��Ϊ��\n");		///�����Ԫ��
	Show_LinkQueue(lq);

	if(!Empty_LinkQueue(lq))
	{
	printf("��ǰ���еĶ���Ԫ��Ϊ��      ");			///����е��׽ڵ�
	printf("   %d \n",lq->front->next->data);
	}
	else							////��ȫ�Լ��
	{
	  printf("��ǰ����Ϊ�ն��У�û���׽ڵ㣡  \n");
	}
	if(!Empty_LinkQueue(lq))
	{
		printf("��ǰ���еĳ���Ϊ��");					///����еĳ���
		p=lq->front->next;
		while(p!=NULL)
		{
			count++;
			p=p->next;
		}
		printf("   %d    \n",count);
	}
	else
	{
		printf("��ǰ����Ϊ�գ�");
	}
	printf("���������Ԫ�أ�\n");
	scanf("%d",&n);
	In_LinkQueue(lq,n);
	Show_LinkQueue(lq);
	Destory_LinkQueue(lq);
	return 0;
}

