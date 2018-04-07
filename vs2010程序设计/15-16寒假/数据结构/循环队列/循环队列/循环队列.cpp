// ѭ������.cpp : �������̨Ӧ�ó������ڵ㡣
//�㷨˵����ʵ��ѭ������ʱ���ճ�һ������Ԫ�ش��β��ָʾ����
//����ͷָʾ����ָ���һ��Ԫ�� . ����βָʾ����ָ�����һ��Ԫ�ص���һλ��

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;			///������е�����Ԫ������
#define N 6						///������е����洢����
///ѭ�����нṹ�嶨��
typedef struct 
{
	ElemType * data;  //��������Ԫ��ָ��
	int front;   ///����ͷָʾ����ָ���һ��Ԫ��
	int rear;  ///����βָʾ����ָ�����һ��Ԫ�ص���һλ��
}CyQueue;
///�������ܣ���ʼ��ѭ������
void Init_CyQueue(CyQueue * cq)
{
	//cq->p=(ElemType *)malloc(sizeof(ElemType)*N);
	cq->data=(ElemType *)malloc(N*sizeof(ElemType)); ///��̬����һ���ڴ�ռ�
	if(cq->data==NULL)
	{
		printf("�ڴ����ʧ�ܣ�\n");
		return ;
	}
	cq->front = 0;
	cq->rear = 0;
}
///�������ܣ��ж϶����Ƿ�Ϊ��
int Empty_CyQueue(CyQueue * cq)
{
	if(cq->front==cq->rear)      //����λָ��ͬһ���ڴ�ʱ��������Ԫ�ظ���Ϊ��
	{
		printf("   �˶���Ϊ�ն��У�\n");
		return 1;
	}
	else
	{
		return 0;
	}
}
//�������ܣ��ж϶����Ƿ�����
int Full_CyQueue(CyQueue * cq)
{
	if(cq->front==(cq->rear+1)%N)     //����ͷָʾ�����βָʾ������һ����Ҫ���������������ͬʱ����������
	{
		printf("   ѭ������������\n");
		return 1;
	}
	else
		return 0;
}

///�������ܣ����һ��ѭ�����еĳ���
int Length_CyQueue(CyQueue * cq)
{
	return ((cq->rear+N-cq->front)%N);
}
///�������ܣ���������������Ԫ��
void In_CyQueue(CyQueue * cq,int n)
{
	if(Full_CyQueue(cq))			///����������ʱ
	{
		printf("������������Ԫ�أ�\n");
		return;
	}
	else
	{
		cq->data[cq->rear]=n;
		cq->rear=(cq->rear++)%N;
		return;
	}
}
//�������ܣ��Ӷ��������һ��Ԫ�أ�FIFO---�Ƚ��ȳ���
void  Out_CyQueue(CyQueue * cq)
{
	if(Empty_CyQueue(cq))			//������Ϊ��ʱ
	{
		printf("�޷����Ԫ�أ�\n");
		return;
	}
	else			//����ʱ
	{
		printf("�������Ԫ�أ� %d \n",cq->data[cq->front]);
		cq->front=(cq->front++)%N;
		return;
	}
}
//�������ܣ���ӡѭ�������е�Ԫ��
void Show_CyQueue(CyQueue * cq)
{
	if(Empty_CyQueue(cq))			//��������û���κ�Ԫ��ʱ
	{
		printf("��ǰ���κ�Ԫ�أ�\n");
		return;
	}
	else
	{
		printf("��ǰ�����е�Ԫ��Ϊ��\n");
		int i=cq->front;			///��i����ͷָʾ�������α��������е�Ԫ��
		while(i!=cq->rear)
		{
			printf(" %d	",cq->data[i]);
			i=(i++)%N;
			//cq->front=(cq->front++)%N;
		}
	}
	printf("\n");
}
int _tmain(int argc, _TCHAR* argv[])
{
	int n,m,length;
	int count=1;
	CyQueue cq;
	Init_CyQueue(&cq);
	printf("�����뽫Ҫ�������Ԫ�صĸ�������n<6��\n");
	scanf("%d",&n);
	while(n>=N)					///nֵ�Ϸ��Լ��
	{
		printf("Ԫ�ظ����������пɴ洢�����ֵ�����������룡\n");
		scanf("%d",&n);
	}
	printf("�����뽫Ҫ��ӵ�Ԫ��ֵ��\n");
	while(count<=n)				///����Ԫ����Ӳ���
	{
		scanf("%d",&m);
		In_CyQueue(&cq,m);
		count++;
	}
	Show_CyQueue(&cq);
	length=Length_CyQueue(&cq);
	printf("��ǰ���еĳ���Ϊ��			%d\n",length);
	while(!Empty_CyQueue(&cq))
	{
		Out_CyQueue(&cq);
		Show_CyQueue(&cq);
	}
	printf("�����һ����ӵ����ݣ�\n");
	scanf("%d",&n);
	In_CyQueue(&cq,n);
	Show_CyQueue(&cq);
	printf("��ǰ���еĳ���Ϊ��  %d\n",Length_CyQueue(&cq));

	printf("����ڶ�����ӵ����ݣ�\n");
	scanf("%d",&n);
	In_CyQueue(&cq,n);
	Show_CyQueue(&cq);
	printf("��ǰ���еĳ���Ϊ��  %d\n",Length_CyQueue(&cq));
	return 0;
}

