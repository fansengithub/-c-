// 设备管理1.0.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 10
///设备结构体
typedef struct Node0
{
	char name[10];
	struct PCB * process;  ///改节点占用的进程
	struct PCB * waitinglist;  //等待该节点的进程队列
	struct Node0 * next;  //下一个节点
	struct Node1 * parent;     ///父节点
	struct Node0 * first_next;  ///横向连接时用的指针
	struct Node0 * Link_List;   ///连接指向同一控制器的不同设备
}DCT;
///控制器结构体
typedef struct Node1
{
	char name[10];    ///名称
	struct PCB * process;  ///改节点占用的进程
	struct PCB * waitinglist;  //等待该节点的进程队列
	struct Node1 * next;  //下一个节点
	struct Node2 * parent;     ///父节点
	struct Node0 * first_next;  ///横向连接时用的指针
	struct Node1 * Link_List;     ////连接指向同一通道的不同控制器
}COCT;
//// 通道结构体
typedef struct Node2
{
	char name[10];
	struct PCB * process;  ///改节点占用的进程
	struct PCB * waitinglist;  //等待该节点的进程队列
	struct Node2 * next;  //下一个节点
	struct Node2 * parent;     ///父节点
	struct Node1 * first_next;  ///横向连接时用的指针
}CHCT;
///函数功能：打印设备图

///函数功能：打印设备队列元素
void print2(COCT * Controller)
{
	printf("                                    |\n");
	printf("                                    |\n");
	printf("                                    |");
	DCT *  Device0=(* Controller).first_next;    ///设备队列的第一个元素
	printf("-----[%s]-----\n",(* Device0).name);
	while((*Device0).Link_List!=NULL)      ///设备连接队列有第二元素时
	{
		DCT * Device=(*Device0).next;
		printf("                                    |\n");
		printf("                                    |\n");
		printf("                                    |\n");
		printf("                                    ---------[%s]-----\n",(* Device).name);
		Device0=Device;
	}
}
///函数功能：打印控制器队列上的元素
void  print1(CHCT *  Channel)
{
	/*	CHCT * Channel=(CHCT *)malloc(sizeof(CHCT)); 
	Channel=(* CHCTS).next;    ////通道中的第一个元素     */
	if((* Channel).first_next!=NULL)   ///通道连接的控制器队列有元素时
	{
		COCT * Controller=(* Channel).first_next;    /// 控制器队列的第一个元素
		printf("--------[%s]-------",(* Controller).name);
		if((*Controller).Link_List==NULL)
		{
			if((* Controller).first_next!=NULL)   //// 控制器队列相连接的设备队列有元素时
			{  
				print2(Controller);
			}   
		}
		else  {      ////如果第一个控制器后面有其他控制器
			while((*Controller).Link_List!=NULL)
			{
				if((* Controller).first_next!=NULL)   //// 控制器队列相连接的设备队列有元素时
				{
					print2(Controller);
				}   
				COCT * Controller1=(* Controller).Link_List;
				Controller=Controller1;
			}
			if((*Controller).Link_List==NULL)   ///输出控制器中的最后一个元素
			{
				if((* Controller).first_next!=NULL)   //// 控制器队列相连接的设备队列有元素时
				{
					print2(Controller);
				} 
			}
		}
	}
}
void print(CHCT * CHCTS,COCT * COCTS)
{   
	CHCT * Channel=(CHCT *)malloc(sizeof(CHCT));
	if((* CHCTS).next!=NULL)   ///当通道队列中有元素时
	{
		Channel=(* CHCTS).next;    ////通道中的第一个元素
		while((*Channel).next!=NULL)   
		{
			CHCT * p=(* Channel).next;     ///通道中的第二个元素
			printf("-------[%s]------",(* Channel).name);
			print1( Channel);
			printf("\n");
			printf("-------[%s]------",(* p).name);     ///输出第二个通道的内容
			Channel=p;
			print1(Channel);


		}
	}              
}    
///函数功能：创建头结点 
void Creat_Init()
{
	COCT * COCTS=(COCT *)malloc(sizeof(COCT));  ///控制器队列头结点
	DCT * DCTS=(DCT  *)malloc(sizeof(DCT));   ///设备队列头结点
	CHCT * CHCTS=(CHCT  *)malloc(sizeof(CHCT));   ///通道队列头结点

	/* char i;
	printf("是否添加新的设备");
	scanf("%c",&i);
	while(i=='y'||i=='Y')
	{
	NODE * p =(NODE  *)malloc(sizeof(NODE));    ///申请新节点

	}   */

	DCT * p0 =(DCT *)malloc(sizeof(DCT));

	///设备初始化
	//(*p).name="K";
	strcpy((*p0).name,"K");
	(*DCTS).next=p0;
	DCT * p1 =(DCT  *)malloc(sizeof(DCT));
	//(*p).name="K";
	strcpy((*p1).name,"M");
	(*p0).next=p1;
	DCT * p2 =(DCT  *)malloc(sizeof(DCT));
	//(*p).name="K";
	strcpy((*p2).name,"T");
	(*p1).next=p2;
	DCT * p3 =(DCT  *)malloc(sizeof(DCT));
	//(*p).name="K";
	strcpy((*p3).name,"P");
	(*p2).next=p3;
	(*p3).next=NULL;
	///控制器队列初始化
	COCT * q0 =(COCT  *)malloc(sizeof(COCT));
	strcpy((*q0).name,"CO1");
	(*COCTS).next=q0;
	COCT * q1 =(COCT  *)malloc(sizeof(COCT));
	strcpy((*q1).name,"CO2");
	(*q0).next=q1;
	COCT * q2 =(COCT  *)malloc(sizeof(COCT));
	strcpy((*q2).name,"CO3");
	(*q1).next=q2;
	(*q2).next=NULL;
	///通道队列初始化
	CHCT * r0 =(CHCT  *)malloc(sizeof(CHCT));
	strcpy((*r0).name,"CH1");
	(*CHCTS).next=r0;
	CHCT * r1 =(CHCT  *)malloc(sizeof(CHCT));
	strcpy((*r1).name,"CH2");
	(*r0).next=r1;
	(*r1).next=NULL;
	///三种队列中，个元素之间的指针连接
	(*p0).parent=q0;
	(*q0).first_next=p0;
	(*p1).parent=q0;
	(*p0).Link_List=p1;
	(*p1).Link_List=NULL;
	(*p2).parent=q1;
	(*q1).first_next=p2;
	(*p2).Link_List=NULL;
	(*p3).parent=q2;
	(*q2).first_next=p3;
	(*p2).Link_List=NULL;
	(*p3).Link_List=NULL;
	///******************************
	(*q0).parent=r0;
	(*r0).first_next=q0;
	(*q0).Link_List=NULL;
	(*q1).parent=r1;
	(*r1).first_next=q1;
	(*q2).parent=r1;
	(*q1).Link_List=q2;
	(*q2).Link_List=NULL;
	///**************************************
	print(CHCTS,COCTS);
}
///函数功能：添加删除设备，控制器


void Add_Delete(COCT * COCTS,DCT * DCTS,CHCT * CHCTS)
{
	char i;
	printf("是否添加新的设备");
	scanf("%c",&i);
	while(i=='y'||i=='Y')
	{
		int choice;
		printf("请选择添加方式： \n 1-----在原来控制器上         2-------新建控制器 \n  输入选项！\n");
		scanf("%d",&choice);
		getchar();
		if(choice==1)   ////在原来节点添加
		{
		   char  Contro_Name[N];
		   printf("请输入已选控制器名称：\n");
		   gets(Contro_Name);
		   if(strcmp(Contro_Name,"CO1")==0)                      //在通道1后面添加设备
		   {
		        DCT * p4 =(DCT *)malloc(sizeof(DCT));    ///申请一个设备指针
				DCT * temp =(DCT *)malloc(sizeof(DCT));
				temp=(* COCTS).first_next;
				if((*temp).Link_List!=NULL)
				{
				   temp=temp->next;       ////找到同类设备的最后一个
				}
				temp->next=p4;
				temp->Link_List=p4;
		   }
		                                                                                  ///********************************************       CO2
		    if(strcmp(Contro_Name,"CO2")==0)                      //在通道2后面添加设备
		   {
		        DCT * p4 =(DCT *)malloc(sizeof(DCT));    ///申请一个设备指针
				DCT * temp =(DCT *)malloc(sizeof(DCT));
				COCT * temp1=(COCT *)malloc(sizeof(COCT));
				temp1=COCTS->next;
				temp1=temp1->next;
				temp=(* temp1).first_next;
				if((*temp).Link_List!=NULL)
				{
				   temp=temp->next;       ////找到同类设备的最后一个
				}
				temp->next=p4;
				temp->Link_List=p4;
		   }
			if(strcmp(Contro_Name,"CO3")==0)                                         ///********************************************       CO3
			{
			    DCT * p4 =(DCT *)malloc(sizeof(DCT));    ///申请一个设备指针
				DCT * temp =(DCT *)malloc(sizeof(DCT));
				COCT * temp1=(COCT *)malloc(sizeof(COCT));
				temp1=COCTS->next;
				temp1=temp1->next;
				temp1=temp1->next;
				temp=(* temp1).first_next;
				if((*temp).Link_List!=NULL)
				{
				   temp=temp->next;       ////找到同类设备的最后一个
				}
				temp->next=p4;
				temp->Link_List=p4;
			}
		}
		else                       /////新建控制器
		{
		   printf("新建控制器时通道的选择：\n  1 *******选择原有通道      2*******选择新建通道 \n");
		   int i;
		   scanf("%d",&i);
		   getchar();               
		   if(i==1)     ///选择原来的通道
		   {
			  char  Channel_Name[N]; 
		      printf("请输入已选的通道名：\n");
			  gets(Channel_Name);
			  getchar();
			  if(strcmp(Channel_Name,"CH1")==0)      //////************************************************************CH1
			  {
			     p
			  }
		   }
		}

	} 
}                     
int _tmain(int argc, _TCHAR* argv[])
{
	Creat_Init();
	return 0;
}

