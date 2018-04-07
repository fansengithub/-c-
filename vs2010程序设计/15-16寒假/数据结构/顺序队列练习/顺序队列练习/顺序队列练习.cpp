// 顺序队列练习.cpp : 定义控制台应用程序的入口点。
//函数功能：顺序队列的练习

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#define N 6				///定义队列中能存放的最大元素个数
typedef int ElemType;			///定义元素数据类型
typedef struct 
{
  ElemType queue[N];///存放队列中的数据元素
  int front;      ///指向队头元素的指示器
  int rear;     ///指向队尾元素的指示器
}SqQueue;
///函数功能： 初始化队列
void InitQueue(SqQueue * q)
{
	q->rear=-1;				///刚开始时，队头，队尾，都为-1，方便计算
	q->front=-1;
}
///函数功能：判断队列是否为空
int QueueEmpty(SqQueue * q)
{
	if(q->front==q->rear)  return 1;
	else return 0;
}
///函数功能：判断队列是否已满
int QueueFull(SqQueue * q)
{
	if(q->rear==(N-1))
		return 1;
	else return 0;
}
//函数功能：求队列的长度
int QueueLength(SqQueue * q)
{
	return (q->rear-q->front);
}
//函数功能：向队列中添加元素
int QueueIn(SqQueue * q,int m)
{
	if(QueueFull(q))  
	{	
		printf("队列中的元素已满，不能向队列中添加元素!\n");
		return 0;		///判断队列是否已满
	
	}
	else
	{
	   q->rear++;					//入队时，队尾指示器后移，加1
	   q->queue[q->rear]=m;
	   return 1;
	}
}
///函数功能：从队列中输出元素
int QueueOut(SqQueue *q)
{
  if(QueueEmpty(q))  
  {
     printf("该队列为空，无法输出元素！\n");
	 return 0;
  }
  else
  {
	  q->front++;				///出队时，队头指示器后移，加1
	  return q->queue[q->front];
  }
}
///函数功能：打印输出队列中的元素
void QueueShow(SqQueue * q)
{
  if(QueueEmpty(q))
  {
    printf("\n该队列为空队列,无法输出队列中的元素!\n");
  }
  else
  {
	  printf("\n顺序队列中的元素为：\n");
	  int s=q->front+1;			///标记第一个元素的位置
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
	printf("请输入将要向队列中添加元素的个数！\n");
	scanf("%d",&n);
	while(n>N)			///合理性判断
	{
	  printf("超过队列能存放元素的最大值！请重新输入!\n");
	  scanf("%d",&n);
	}
	n1=n;
	while(n>0)
	{
		printf("输入元素值!\n");
		scanf("%d",&m);
		QueueIn(&sq,m);
		QueueShow(&sq);
		n--;
	}
	printf("\n 顺序队列的长度为：  ");
	printf("%d\n",QueueLength(&sq));
	while(n1>0)
	{
		printf("\n顺序队列的队头元素为： ");
	    printf("%d\n",QueueOut(&sq));
		//printf("顺序队列中的剩余元素为：");
		QueueShow(&sq);
	   n1--;
	}
	///第一次输入数据
	printf("\n请输入队列元素！\n");
	scanf("%d",&n);
	QueueIn(&sq,n);
	printf("顺序队列的长度为：  %d \n",QueueLength(&sq));
	QueueShow(&sq);

	//第二次输入数据
	printf("请输入队列元素！\n");
	scanf("%d",&n);
	QueueIn(&sq,n);
	printf("顺序队列的长度为：  %d \n",QueueLength(&sq));
	QueueShow(&sq);

	return 0;
}

