// 进程调度1.0.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 20
typedef struct PCB {
	char name[20];//进程名字
	int size;//进程大小（时间片轮转将用到）
	int arrival_time;//提交时刻
	int running_time;//运行时间
	int start_time;//开始时刻
	int finish_time;//完成时刻
	int used_time;  ///进程已将执行的时间（时间片轮转将用到）
	int need_time;  ///进程还需要的执行时间（时间片轮转将用到）
	int T;//平均周转时间
	double W;//带权周转时间
	struct PCB * next;
}PCB;
void SJF(PCB * & ready,PCB * & run,PCB * & finish,PCB * & block);
void show(PCB *ready,PCB * block,PCB * run,PCB * finish);
void Found_Process(PCB * & ready);
void FCFS(PCB * & ready,PCB * & run,PCB * & finish,PCB * & block);
void finish_show(PCB * finish);
//void Found_Process1(PCB * & ready);
/*
///  在时间片轮转中，打印 进程已执行的时间和还需服务的时间
void ready_show(PCB * & ready)
{
PCB * temp=ready->next;
printf("\n当前将要执行的进程序列为：\n");
while(temp!=NULL)
{

printf("%s",temp->name);
printf("   该进程已执行时间为： %d",temp->used_time);
printf("   该进程还需服务时间为： %d\n",temp->need_time);
temp=temp->next;
}
}   */
//函数功能：实现时间片轮转 进程调度
void TIME_RR(PCB * & ready,PCB * & run,PCB * &finish,PCB * & block)
{
	int large;
	printf("\n请输入时间片轮转的大小!\n");
	scanf("%d",&large);
	getchar();

	int time;
	time=0;
	///ready队列执行过程
	PCB * min=ready->next;
	while(ready->next!=NULL)
	{
		///ready队列执行过程
		min=ready->next;
		PCB * p1=ready->next;
		while(p1!=NULL)
		{
			if(p1->arrival_time<=time&&p1->need_time>0)
			{   
				min=p1;
				break;
			}
			p1=p1->next;
		}
		p1=ready;      ///在ready队列中删除min节点
		while(p1!=NULL)
		{
			if(p1->next==min)  break;
			else p1=p1->next;
		}
		p1->next=min->next;   ///在ready队列中删除min节点
		run->next=min;    ///放置运行队列
		min->next=NULL;

		/////run队列执行过程
		time=time+large;
		min->used_time=large+min->used_time;
		min->need_time=min->size-min->used_time;
		printf("正在执行进程\t%s",min->name);
		printf("   已经执行时间     %d",min->used_time);
		printf("   还需执行时间     %d\n",min->need_time);


		if(min->need_time==0)     ///如果min的need_time为0，代表该进程已经执行完毕，则放入finish队列
		{
			////finish 队列操作
			if(finish->next==NULL)  ///当执行第一个进程时
			{
				finish->next=run->next;
				run->next=NULL;
			}
			else    ///当不是第一个进程时
			{
				PCB * temp_finish=finish->next;
				while(temp_finish->next!=NULL)     ///找到完成队列的最后一个节点
				{
					temp_finish=temp_finish->next;
				}  
				temp_finish->next=run->next;
				run->next=NULL;
			}
		}
		else   ///当min->need_time不为0，通过block队列，  再放到ready队列的队尾
		{
			PCB * r1=ready;
			while(r1->next!=NULL)
			{
				r1=r1->next;
			}
			r1->next=min;
			min->next=NULL;
		}

	}
}
///函数功能：创建进程
void Found_Process(PCB * & ready)
{
	PCB * temp=ready;
	char choice;
	printf("\n是否创建一个新的进程?(y or n)\n");
	scanf("%c",&choice);
	getchar();
	while(choice=='y'||choice=='Y')
	{
		PCB * p0=(PCB *)malloc(sizeof(PCB));
		p0->next=NULL;  
		temp->next=p0;
		temp=p0;
		printf("\n请输入新创建进程的名字！\n");
		gets(p0->name);
		printf("\n请输入新创建进程的提交时刻！\n");
		scanf("%d",&(p0->arrival_time));
		getchar();
		printf("\n请输入新创建进程的运行时间！\n");
		scanf("%d",&(p0->running_time));
		getchar();
		p0->size=p0->running_time;
		p0->need_time=p0->size;
		p0->used_time=0;
		printf("\n是否创建一个新的进程?(y or n)\n");
		scanf("%c",&choice);
		getchar();
	}
	temp->next=NULL;
}
///函数功能：短作业优先进程调度的实现
void SJF(PCB * & ready,PCB * & run,PCB * & finish,PCB * & block)
{
	int time;
	time=0;
	PCB * min=ready->next;  //找到同一时间内，作业运行时间最少的
	while(ready->next!=NULL)
	{
		min=ready->next;
		PCB * p1=ready->next;
		while(p1!=NULL)
		{    //寻找在一定时间范围内，并且运行时间最小的进程
			if(p1->arrival_time<=time&&p1->running_time<min->running_time)
				min=p1;
			p1=p1->next;
		}
		p1=ready;      ///在ready队列中删除min节点
		while(p1!=NULL)
		{
			if(p1->next==min)  break;
			else p1=p1->next;
		}
		p1->next=min->next;   ///在ready队列中删除min节点
		run->next=min;    ///放置运行队列
		min->next=NULL;

		////finish 队列操作
		if(finish->next==NULL)  ///当执行第一个进程时
		{
			min->start_time=time;
			min->finish_time=min->start_time+min->running_time;  ///完成时刻=开始时刻+运行时刻
			time=min->finish_time;  //-***************************************************************************在此处修改time值
			min->T=min->finish_time-min->arrival_time;   ///周转时间=完成时刻-提交时刻
			min->W=(double)min->T/min->running_time;  ///带权周转时间=周转时间/运行时间
			finish->next=run->next;

			run->next=NULL;
		}
		else    ///当不是第一个进程时
		{
			PCB * temp_finish=finish->next;
			while(temp_finish->next!=NULL)     ///找到完成队列的最后一个节点
			{
				temp_finish=temp_finish->next;
			}  
			min->start_time=temp_finish->finish_time;   ///当前进程的开始时刻是前一进程的完成时刻
			min->finish_time=min->start_time+min->running_time;  ///完成时刻=开始时刻+运行时刻
			time=min->finish_time;  //-***************************************************************************在此处修改time值
			min->T=min->finish_time-min->arrival_time;   ///周转时间=完成时刻-提交时刻
			min->W=(double)min->T/min->running_time;  ///带权周转时间=周转时间/运行时间
			temp_finish->next=run->next;
			run->next=NULL;
		}
	}
	finish_show(finish);
}
///函数功能：先来先服务进程调度的实现
void FCFS(PCB * & ready,PCB * & run,PCB * & finish,PCB * & block)
{
	//int flage=0;//标记位
	int TIME=0;   ////平均周转时间
	int count=0;
	PCB * min=ready->next;   ///找到提交时刻最小的
	while(ready->next!=NULL)
	{
		min=ready->next;
		PCB * p1=ready->next;
		while(p1!=NULL)
		{
			if(p1->arrival_time<min->arrival_time)     ///找到到达时间最小的结点
				min=p1;
			p1=p1->next;
		}
		p1=ready;      ///在ready队列中删除min节点
		while(p1!=NULL)
		{
			if(p1->next==min)  break;
			else p1=p1->next;
		}
		p1->next=min->next;   ///在ready队列中删除min节点
		run->next=min;    ///放置运行队列
		min->next=NULL;

		if(finish->next==NULL)  ///当执行第一个进程时
		{
			min->start_time=0;
			min->finish_time=min->start_time+min->running_time;  ///完成时刻=开始时刻+运行时刻
			min->T=min->finish_time-min->arrival_time;   ///周转时间=完成时刻-提交时刻
			min->W=(double)min->T/min->running_time;  ///带权周转时间=周转时间/运行时间
			finish->next=run->next;
			TIME=TIME+min->T;
			count++;
			run->next=NULL;
		}
		else    ///当不是第一个进程时
		{
			PCB * temp_finish=finish->next;
			while(temp_finish->next!=NULL)     ///找到完成队列的最后一个节点
			{
				temp_finish=temp_finish->next;
			}  
			min->start_time=temp_finish->finish_time;   ///当前进程的开始时刻是前一进程的完成时刻
			min->finish_time=min->start_time+min->running_time;  ///完成时刻=开始时刻+运行时刻
			min->T=min->finish_time-min->arrival_time;   ///周转时间=完成时刻-提交时刻
			TIME=TIME+min->T;
			count++;
			min->W=(double)min->T/min->running_time;  ///带权周转时间=周转时间/运行时间
			temp_finish->next=run->next;
			run->next=NULL;
		}
		//show(ready,block,run,finish);

	}
	finish_show(finish);
	TIME=TIME/count;
	printf("\n 平均周转时间为：%d\n",TIME);
}
///函数功能：打印最终结果
void finish_show(PCB * finish)
{
	PCB *temp=finish->next;
	printf("进程名称：\t");
	while(temp!=NULL)
	{
		printf("%s\t",temp->name);
		temp=temp->next;
	}
	printf("\n");
	temp=finish->next;
	printf("提交时刻：\t");
	while(temp!=NULL)
	{
		printf("%d\t",temp->arrival_time);
		temp=temp->next;
	}
	printf("\n");
	temp=finish->next;
	printf("运行时间：\t");
	while(temp!=NULL)
	{
		printf("%d\t",temp->running_time);
		temp=temp->next;
	}
	printf("\n");
	temp=finish->next;
	printf("开始时刻：\t");
	while(temp!=NULL)
	{
		printf("%d\t",temp->start_time);
		temp=temp->next;
	}
	printf("\n");
	temp=finish->next;
	printf("完成时刻：\t");
	while(temp!=NULL)
	{
		printf("%d\t",temp->finish_time);
		temp=temp->next;
	}
	printf("\n");
	temp=finish->next;
	printf("周转时间：\t");
	while(temp!=NULL)
	{
		printf("%d\t",temp->T);
		temp=temp->next;
	}
	printf("\n");
	temp=finish->next;
	printf("带权周转时间：\t");
	while(temp!=NULL)
	{
		printf("%f ",temp->W);
		temp=temp->next;
	}
	printf("\n");  
}
///函数功能：打印三个进程队列的结点
void show(PCB * ready,PCB * block,PCB * run,PCB * finish)
{
	printf("\nready队列节点元素分布\n");
	PCB * temp;
	temp=ready->next;
	if(temp==NULL)  
	{
		printf("\t\t\t该队列当前无节点！\n");
	}
	else 
	{
		while(temp!=NULL)
		{
			printf("\t");
			puts(temp->name);
			//printf("\t\n");
			temp=temp->next;
		}
	}
	printf("\nrun队列节点元素分布\n");
	//PCB * temp;
	temp=run->next;
	if(temp==NULL)  
	{
		printf("\t\t\t该队列当前无节点！\n");
	}
	else 
	{
		while(temp!=NULL)
		{
			printf("\t");
			puts(temp->name);
			//	printf("\t");
			temp=temp->next;
		}
	}
	printf("\nfinish队列节点元素分布\n");
	//PCB * temp;
	temp=finish->next;
	if(temp==NULL)  
	{
		printf("\t\t\t该队列当前无节点！\n");
	}
	else 
	{
		while(temp!=NULL)
		{
			printf("\t");
			puts(temp->name);
			//printf("\t");
			temp=temp->next;
		}
	}
	printf("\nblock队列节点元素分布\n");
	//PCB * temp;
	temp=block->next;
	if(temp==NULL)  
	{
		printf("\t\t\t该队列当前无节点！\n");
	}
	else 
	{
		while(temp!=NULL)
		{
			printf("\t");
			puts(temp->name);
			//printf("\t");
			temp=temp->next;
		}
	}
}
//函数功能：实现 ready队列的复制
void ready_copy(PCB * & ready1,PCB * & ready2)
{
	PCB * p1=ready1;
	PCB * p2=ready2;
	//PCB p3=ready3->next;
	while(p1->next!=NULL)
	{
		p1=p1->next;
		PCB * p0=(PCB *)malloc(sizeof(PCB));
		p2->next=p0;
		p2=p0;
		strcpy(p0->name,p1->name);
		p0->arrival_time=p1->arrival_time;
		p0->running_time=p1->running_time;
		p0->size=p0->running_time;
		p0->need_time=p0->size;
		p0->used_time=0;
	}
	p2->next=NULL;
}
///函数功能：银行家算法的实现
void banker()
{
	printf("用5个进程");
	int p[5];
	//int i=0;
	for(int i=0;i<5;i++)
	{
		p[i]=i+1;
	}
	int Available[4];  ///可利用资源数组，每一项代表一类可利用的资源数目
	printf("\n共4类可用资源\n");
	for(int i=0;i<4;i++)
	{
		printf("\n请输入第%d类资源可利用数目！\n",(i+1));
		scanf("%d",&Available[i]);
	}
	int Max[5][4];     ///最大需求矩阵
	for(int i=0;i<5;i++)
	{
		printf("\n请输入进程%d的各个资源最大需求!\n",i);
		for(int j=0;j<4;j++)
		{
			printf("请输入%d资源的最大需求！\n",(j+1));  
			scanf("%d",&Max[i][j]);
		}
	}
	int Allocation[5][4];  ///分配矩阵 
	for(int i=0;i<5;i++)
	{
		printf("\n请输入进程%d已分配各个资源的数目!\n",i);
		for(int j=0;j<4;j++)
		{
			printf("请输入%d资源的分配数目！\n",(j+1));  
			scanf("%d",&Allocation[i][j]);
		}
	}
	int Need[5][4];  ///各个进程还需要的资源数目
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<4;j++)
		{
			Need[i][j]=Max[i][j]-Allocation[i][j];
		}
	}
	////银行家算法的实现
	int Requast[4];
	int name;
	printf("\n请输入将要申请资源的进程名称！\n");
	scanf("%d",&name);
	getchar();
	int Requast_Number=0;
	printf("请输入申请各类资源的数目：\n");
	for( Requast_Number=0;Requast_Number<4;Requast_Number++)
	{
		printf("资源%d的数目：\n",(Requast_Number+1));
		scanf("%d",&Requast[Requast_Number]);
		getchar();
	}
	for(Requast_Number=0;Requast_Number<4;Requast_Number++)
	{
	if(Requast[Requast_Number]<=Need[name][Requast_Number])
	{
		if(Requast[Requast_Number]<=Available[Requast_Number])    ///系统进行试探分配
		{
			Available[Requast_Number]=Available[Requast_Number]-Requast[Requast_Number];
			Allocation[name][Requast_Number]=Allocation[name][Requast_Number]+Requast[Requast_Number];
			Need[name][Requast_Number]=Need[name][Requast_Number]-Requast[Requast_Number];
		}
		else
		{
			printf("没有足够的资源!\n");
			return ;
		}
	}
	else
	{
		printf("输入错误，所需要的资源数超过最大值!\n");
		return ;
	}
	}
	////安全性检查
	int Work[4];  ///系统可提供给进程各类资源数目
	for(int i=0;i<4;i++)
	{
		Work[i]=Available[i];
	}
	int Finish[5];
	for(int i=0;i<5;i++)
	{
		Finish[i]=0;   ////0 代表 false  1代表true 
	}
	int a,b;
	int k=0;////用于最后安全序列的输出
	int flage=0;
	int safe[5];     ///用于存放安全序列
	int count;
	count=0;
	a=0;
	b=0;
	int go_on=1;
	while(go_on==1)
	{
		for(a=0;a<5;a++)    ///在进程集合中寻找
		{
			flage=0;
			count=0;
			if(Finish[a]==0)
			{
				for(b=0;b<4;b++)
				{
					if(Need[a][b]<=Work[b])
					{  
						count++;
					}
				}
				if(count==4)
				{
				   flage=1;
				}
			}
			if(flage==1) break;
		}
		if(flage==1)    ///当两个条件同时满足时
		{
			//Work[b]=Work[b]+Allocation[a][b];
			for(b=0;b<4;b++)
				{
				  Work[b]=Work[b]+Allocation[a][b];
				}
			Finish[a]=1;		
			safe[k]=a;
			k++;
			go_on=1;
		}
		else if(flage==0)
		{
			go_on=0;
			int i=0;
			int safe_station=2;
			for(i=0;i<5;i++)
			{
				if(Finish[i]!=1)   ////如果有不能满足要求的进程，  则不安全
					safe_station=0;
			}
			if(safe_station==0)  
			{
				printf("\n*****************不安全*************\n");
			}
			else 
			{
				printf("\n*****************安全*******************\n");
				printf("\t安全序列为：\n");
				for(int i=0;i<5;i++)
				{
				    printf("%d  ",safe[i]);
				}
			}
		}
	}
}
int _tmain(int argc, _TCHAR* argv[])
{   
	PCB * ready1,*block1,*run1,*finish1;//三个进程队列分别代表 就绪态，阻塞态（时间片轮转用到），执行态，已完成态
	ready1=(PCB *)malloc(sizeof(PCB));
	strcpy(ready1->name,"ready1头结点");
	block1=(PCB *)malloc(sizeof(PCB));
	strcpy(block1->name,"block1头结点");
	run1=(PCB *)malloc(sizeof(PCB));
	strcpy(run1->name,"run1头结点");
	finish1=(PCB *)malloc(sizeof(PCB));
	strcpy(finish1->name,"finish1头结点");
	ready1->next=block1->next=run1->next=finish1->next=NULL;
	PCB * ready2,*block2,*run2,*finish2;//三个进程队列分别代表 就绪态，阻塞态（时间片轮转用到），执行态，已完成态
	ready2=(PCB *)malloc(sizeof(PCB));
	strcpy(ready2->name,"ready2头结点");
	block2=(PCB *)malloc(sizeof(PCB));
	strcpy(block2->name,"block2头结点");
	run2=(PCB *)malloc(sizeof(PCB));
	strcpy(run2->name,"run2头结点");
	finish2=(PCB *)malloc(sizeof(PCB));
	strcpy(finish2->name,"finish2头结点");
	ready2->next=block2->next=run2->next=finish2->next=NULL;
	PCB * ready3,*block3,*run3,*finish3;//三个进程队列分别代表 就绪态，阻塞态（时间片轮转用到），执行态，已完成态
	ready3=(PCB *)malloc(sizeof(PCB));
	strcpy(ready3->name,"ready3头结点");
	block3=(PCB *)malloc(sizeof(PCB));
	strcpy(block3->name,"block3头结点");
	run3=(PCB *)malloc(sizeof(PCB));
	strcpy(run3->name,"run3头结点");
	finish3=(PCB *)malloc(sizeof(PCB));
	strcpy(finish3->name,"finish3头结点");
	ready3->next=block3->next=run3->next=finish3->next=NULL;

	Found_Process(ready1);
	ready_copy(ready1,ready2);
	ready_copy(ready1,ready3);

	char i;
	i='y';
	while(i=='y'||i=='Y')
	{
		printf("\n\t请选择进程调度算法！\n");
		printf("\n\n\t FCFS(先来先服务)   SJF(短进程优先)   TIME_RR(时间片轮转)    BANKER(银行家算法)\n");
		char choice_name[N];
		gets(choice_name);
		if(strcmp(choice_name,"FCFS")==0)
		{
			FCFS(ready1,run1,finish1,block1);
		}
		else if(strcmp(choice_name,"SJF")==0)
		{
			SJF(ready2,run2,finish2,block2);
		}
		else if(strcmp(choice_name,"TIME_RR")==0)
		{
			TIME_RR(ready3,run3,finish3,block3);
		}
		else if(strcmp(choice_name,"BANKER")==0)
		{
		   banker();
		}
		printf("\n是否继续操作？（y or n）\n");
		scanf("%c",&i);
		getchar();
	}     
	
	return 0;
}

