// ˳�������ϰ.cpp : �������̨Ӧ�ó������ڵ㡣
//�������ܣ�˳����е���ϰ

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#define N 6				///����������ܴ�ŵ����Ԫ�ظ���
typedef int ElemType;			///����Ԫ����������
typedef struct 
{
  ElemType queue[N];///��Ŷ����е�����Ԫ��
  int front;      ///ָ���ͷԪ�ص�ָʾ��
  int rear;     ///ָ���βԪ�ص�ָʾ��
}SqQueue;
///�������ܣ� ��ʼ������
void InitQueue(SqQueue * q)
{
	q->rear=-1;				///�տ�ʼʱ����ͷ����β����Ϊ-1���������
	q->front=-1;
}
///�������ܣ��ж϶����Ƿ�Ϊ��
int QueueEmpty(SqQueue * q)
{
	if(q->front==q->rear)  return 1;
	else return 0;
}
///�������ܣ��ж϶����Ƿ�����
int QueueFull(SqQueue * q)
{
	if(q->rear==(N-1))
		return 1;
	else return 0;
}
//�������ܣ�����еĳ���
int QueueLength(SqQueue * q)
{
	return (q->rear-q->front);
}
//�������ܣ�����������Ԫ��
int QueueIn(SqQueue * q,int m)
{
	if(QueueFull(q))  
	{	
		printf("�����е�Ԫ����������������������Ԫ��!\n");
		return 0;		///�ж϶����Ƿ�����
	
	}
	else
	{
	   q->rear++;					//���ʱ����βָʾ�����ƣ���1
	   q->queue[q->rear]=m;
	   return 1;
	}
}
///�������ܣ��Ӷ��������Ԫ��
int QueueOut(SqQueue *q)
{
  if(QueueEmpty(q))  
  {
     printf("�ö���Ϊ�գ��޷����Ԫ�أ�\n");
	 return 0;
  }
  else
  {
	  q->front++;				///����ʱ����ͷָʾ�����ƣ���1
	  return q->queue[q->front];
  }
}
///�������ܣ���ӡ��������е�Ԫ��
void QueueShow(SqQueue * q)
{
  if(QueueEmpty(q))
  {
    printf("\n�ö���Ϊ�ն���,�޷���������е�Ԫ��!\n");
  }
  else
  {
	  printf("\n˳������е�Ԫ��Ϊ��\n");
	  int s=q->front+1;			///��ǵ�һ��Ԫ�ص�λ��
	  while(s<=q->rear)
	  {
		  printf("%d ",q->queue[s]);
		  s++;
	  }
  }
}
int _tmain(int argc, _TCHAR* argv[])
{
	SqQueue sq;
	InitQueue(&sq);
	int n,m,n1;
	printf("�����뽫Ҫ����������Ԫ�صĸ�����\n");
	scanf("%d",&n);
	while(n>N)			///�������ж�
	{
	  printf("���������ܴ��Ԫ�ص����ֵ������������!\n");
	  scanf("%d",&n);
	}
	n1=n;
	while(n>0)
	{
		printf("����Ԫ��ֵ!\n");
		scanf("%d",&m);
		QueueIn(&sq,m);
		QueueShow(&sq);
		n--;
	}
	printf("\n ˳����еĳ���Ϊ��  ");
	printf("%d\n",QueueLength(&sq));
	while(n1>0)
	{
		printf("\n˳����еĶ�ͷԪ��Ϊ�� ");
	    printf("%d\n",QueueOut(&sq));
		//printf("˳������е�ʣ��Ԫ��Ϊ��");
		QueueShow(&sq);
	   n1--;
	}
	///��һ����������
	printf("\n���������Ԫ�أ�\n");
	scanf("%d",&n);
	QueueIn(&sq,n);
	printf("˳����еĳ���Ϊ��  %d \n",QueueLength(&sq));
	QueueShow(&sq);

	//�ڶ�����������
	printf("���������Ԫ�أ�\n");
	scanf("%d",&n);
	QueueIn(&sq,n);
	printf("˳����еĳ���Ϊ��  %d \n",QueueLength(&sq));
	QueueShow(&sq);

	return 0;
}

