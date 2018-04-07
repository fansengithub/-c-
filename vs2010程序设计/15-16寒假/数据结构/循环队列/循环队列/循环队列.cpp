// 循环队列.cpp : 定义控制台应用程序的入口点。
//算法说明：实现循环队列时，空出一个数据元素存放尾部指示器。
//队列头指示器，指向第一个元素 . 队列尾指示器，指向最后一个元素的下一位置

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;			///定义队列的数据元素类型
#define N 6						///定义队列的最大存储容量
///循环队列结构体定义
typedef struct 
{
	ElemType * data;  //队列数据元素指针
	int front;   ///队列头指示器，指向第一个元素
	int rear;  ///队列尾指示器，指向最后一个元素的下一位置
}CyQueue;
///函数功能：初始化循环队列
void Init_CyQueue(CyQueue * cq)
{
	//cq->p=(ElemType *)malloc(sizeof(ElemType)*N);
	cq->data=(ElemType *)malloc(N*sizeof(ElemType)); ///动态生成一块内存空间
	if(cq->data==NULL)
	{
		printf("内存分配失败！\n");
		return ;
	}
	cq->front = 0;
	cq->rear = 0;
}
///函数功能：判断队列是否为空
int Empty_CyQueue(CyQueue * cq)
{
	if(cq->front==cq->rear)      //当首位指向同一块内存时，队列中元素个数为空
	{
		printf("   此队列为空队列！\n");
		return 1;
	}
	else
	{
		return 0;
	}
}
//函数功能：判断队列是否已满
int Full_CyQueue(CyQueue * cq)
{
	if(cq->front==(cq->rear+1)%N)     //当队头指示器与队尾指示器的下一个（要利用求余操作）相同时，代表已满
	{
		printf("   循环队列已满！\n");
		return 1;
	}
	else
		return 0;
}

///函数功能：求解一个循环队列的长度
int Length_CyQueue(CyQueue * cq)
{
	return ((cq->rear+N-cq->front)%N);
}
///函数功能：向队列中添加数据元素
void In_CyQueue(CyQueue * cq,int n)
{
	if(Full_CyQueue(cq))			///当队列已满时
	{
		printf("不能向队列添加元素！\n");
		return;
	}
	else
	{
		cq->data[cq->rear]=n;
		cq->rear=(cq->rear++)%N;
		return;
	}
}
//函数功能：从队列中输出一个元素（FIFO---先进先出）
void  Out_CyQueue(CyQueue * cq)
{
	if(Empty_CyQueue(cq))			//当队列为空时
	{
		printf("无法输出元素！\n");
		return;
	}
	else			//不空时
	{
		printf("输出队列元素： %d \n",cq->data[cq->front]);
		cq->front=(cq->front++)%N;
		return;
	}
}
//函数功能：打印循环队列中的元素
void Show_CyQueue(CyQueue * cq)
{
	if(Empty_CyQueue(cq))			//当队列中没有任何元素时
	{
		printf("当前无任何元素！\n");
		return;
	}
	else
	{
		printf("当前队列中的元素为：\n");
		int i=cq->front;			///用i代替头指示器，依次遍历队列中的元素
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
	printf("请输入将要入队数据元素的个数！（n<6）\n");
	scanf("%d",&n);
	while(n>=N)					///n值合法性检查
	{
		printf("元素个数超过队列可存储的最大值，请重新输入！\n");
		scanf("%d",&n);
	}
	printf("请输入将要入队的元素值！\n");
	while(count<=n)				///数据元素入队操作
	{
		scanf("%d",&m);
		In_CyQueue(&cq,m);
		count++;
	}
	Show_CyQueue(&cq);
	length=Length_CyQueue(&cq);
	printf("当前队列的长度为：			%d\n",length);
	while(!Empty_CyQueue(&cq))
	{
		Out_CyQueue(&cq);
		Show_CyQueue(&cq);
	}
	printf("输入第一次入队的数据：\n");
	scanf("%d",&n);
	In_CyQueue(&cq,n);
	Show_CyQueue(&cq);
	printf("当前队列的长度为：  %d\n",Length_CyQueue(&cq));

	printf("输入第二次入队的数据：\n");
	scanf("%d",&n);
	In_CyQueue(&cq,n);
	Show_CyQueue(&cq);
	printf("当前队列的长度为：  %d\n",Length_CyQueue(&cq));
	return 0;
}

