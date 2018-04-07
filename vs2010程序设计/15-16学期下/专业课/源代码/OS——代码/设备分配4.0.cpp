// �豸����1.0.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 10
///�豸�ṹ��
typedef struct Node0
{
	char name[10];
	struct PCB * process;  ///�Ľڵ�ռ�õĽ���
	struct PCB * waitinglist;  //�ȴ��ýڵ�Ľ��̶���
	struct Node0 * next;  //��һ���ڵ�
	struct Node1 * parent;     ///���ڵ�
	struct Node0 * first_next;  ///��������ʱ�õ�ָ��
	struct Node0 * Link_List;   ///����ָ��ͬһ�������Ĳ�ͬ�豸
}DCT;
///�������ṹ��
typedef struct Node1
{
	char name[10];    ///����
	struct PCB * process;  ///�Ľڵ�ռ�õĽ���
	struct PCB * waitinglist;  //�ȴ��ýڵ�Ľ��̶���
	struct Node1 * next;  //��һ���ڵ�
	struct Node2 * parent;     ///���ڵ�
	struct Node0 * first_next;  ///��������ʱ�õ�ָ��
	struct Node1 * Link_List;     ////����ָ��ͬһͨ���Ĳ�ͬ������
}COCT;
//// ͨ���ṹ��
typedef struct Node2
{
	char name[10];
	struct PCB * process;  ///�Ľڵ�ռ�õĽ���
	struct PCB * waitinglist;  //�ȴ��ýڵ�Ľ��̶���
	struct Node2 * next;  //��һ���ڵ�
	struct Node2 * parent;     ///���ڵ�
	struct Node1 * first_next;  ///��������ʱ�õ�ָ��
}CHCT;
///�������ܣ���ӡ�豸ͼ

///�������ܣ���ӡ�豸����Ԫ��
void print2(COCT * Controller)
{
	printf("                                    |\n");
	printf("                                    |\n");
	printf("                                    |");
	DCT *  Device0=(* Controller).first_next;    ///�豸���еĵ�һ��Ԫ��
	printf("-----[%s]-----\n",(* Device0).name);
	while((*Device0).Link_List!=NULL)      ///�豸���Ӷ����еڶ�Ԫ��ʱ
	{
		DCT * Device=(*Device0).next;
		printf("                                    |\n");
		printf("                                    |\n");
		printf("                                    |\n");
		printf("                                    ---------[%s]-----\n",(* Device).name);
		Device0=Device;
	}
}
///�������ܣ���ӡ�����������ϵ�Ԫ��
void  print1(CHCT *  Channel)
{
	/*	CHCT * Channel=(CHCT *)malloc(sizeof(CHCT)); 
	Channel=(* CHCTS).next;    ////ͨ���еĵ�һ��Ԫ��     */
	if((* Channel).first_next!=NULL)   ///ͨ�����ӵĿ�����������Ԫ��ʱ
	{
		COCT * Controller=(* Channel).first_next;    /// ���������еĵ�һ��Ԫ��
		printf("--------[%s]-------",(* Controller).name);
		if((*Controller).Link_List==NULL)
		{
			if((* Controller).first_next!=NULL)   //// ���������������ӵ��豸������Ԫ��ʱ
			{  
				print2(Controller);
			}   
		}
		else  {      ////�����һ������������������������
			while((*Controller).Link_List!=NULL)
			{
				if((* Controller).first_next!=NULL)   //// ���������������ӵ��豸������Ԫ��ʱ
				{
					print2(Controller);
				}   
				COCT * Controller1=(* Controller).Link_List;
				Controller=Controller1;
			}
			if((*Controller).Link_List==NULL)   ///����������е����һ��Ԫ��
			{
				if((* Controller).first_next!=NULL)   //// ���������������ӵ��豸������Ԫ��ʱ
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
	if((* CHCTS).next!=NULL)   ///��ͨ����������Ԫ��ʱ
	{
		Channel=(* CHCTS).next;    ////ͨ���еĵ�һ��Ԫ��
		while((*Channel).next!=NULL)   
		{
			CHCT * p=(* Channel).next;     ///ͨ���еĵڶ���Ԫ��
			printf("-------[%s]------",(* Channel).name);
			print1( Channel);
			printf("\n");
			printf("-------[%s]------",(* p).name);     ///����ڶ���ͨ��������
			Channel=p;
			print1(Channel);


		}
	}              
}    
///�������ܣ�����ͷ��� 
void Creat_Init()
{
	COCT * COCTS=(COCT *)malloc(sizeof(COCT));  ///����������ͷ���
	DCT * DCTS=(DCT  *)malloc(sizeof(DCT));   ///�豸����ͷ���
	CHCT * CHCTS=(CHCT  *)malloc(sizeof(CHCT));   ///ͨ������ͷ���

	/* char i;
	printf("�Ƿ�����µ��豸");
	scanf("%c",&i);
	while(i=='y'||i=='Y')
	{
	NODE * p =(NODE  *)malloc(sizeof(NODE));    ///�����½ڵ�

	}   */

	DCT * p0 =(DCT *)malloc(sizeof(DCT));

	///�豸��ʼ��
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
	///���������г�ʼ��
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
	///ͨ�����г�ʼ��
	CHCT * r0 =(CHCT  *)malloc(sizeof(CHCT));
	strcpy((*r0).name,"CH1");
	(*CHCTS).next=r0;
	CHCT * r1 =(CHCT  *)malloc(sizeof(CHCT));
	strcpy((*r1).name,"CH2");
	(*r0).next=r1;
	(*r1).next=NULL;
	///���ֶ����У���Ԫ��֮���ָ������
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
///�������ܣ����ɾ���豸��������


void Add_Delete(COCT * COCTS,DCT * DCTS,CHCT * CHCTS)
{
	char i;
	printf("�Ƿ�����µ��豸");
	scanf("%c",&i);
	while(i=='y'||i=='Y')
	{
		int choice;
		printf("��ѡ����ӷ�ʽ�� \n 1-----��ԭ����������         2-------�½������� \n  ����ѡ�\n");
		scanf("%d",&choice);
		getchar();
		if(choice==1)   ////��ԭ���ڵ����
		{
		   char  Contro_Name[N];
		   printf("��������ѡ���������ƣ�\n");
		   gets(Contro_Name);
		   if(strcmp(Contro_Name,"CO1")==0)                      //��ͨ��1��������豸
		   {
		        DCT * p4 =(DCT *)malloc(sizeof(DCT));    ///����һ���豸ָ��
				DCT * temp =(DCT *)malloc(sizeof(DCT));
				temp=(* COCTS).first_next;
				if((*temp).Link_List!=NULL)
				{
				   temp=temp->next;       ////�ҵ�ͬ���豸�����һ��
				}
				temp->next=p4;
				temp->Link_List=p4;
		   }
		                                                                                  ///********************************************       CO2
		    if(strcmp(Contro_Name,"CO2")==0)                      //��ͨ��2��������豸
		   {
		        DCT * p4 =(DCT *)malloc(sizeof(DCT));    ///����һ���豸ָ��
				DCT * temp =(DCT *)malloc(sizeof(DCT));
				COCT * temp1=(COCT *)malloc(sizeof(COCT));
				temp1=COCTS->next;
				temp1=temp1->next;
				temp=(* temp1).first_next;
				if((*temp).Link_List!=NULL)
				{
				   temp=temp->next;       ////�ҵ�ͬ���豸�����һ��
				}
				temp->next=p4;
				temp->Link_List=p4;
		   }
			if(strcmp(Contro_Name,"CO3")==0)                                         ///********************************************       CO3
			{
			    DCT * p4 =(DCT *)malloc(sizeof(DCT));    ///����һ���豸ָ��
				DCT * temp =(DCT *)malloc(sizeof(DCT));
				COCT * temp1=(COCT *)malloc(sizeof(COCT));
				temp1=COCTS->next;
				temp1=temp1->next;
				temp1=temp1->next;
				temp=(* temp1).first_next;
				if((*temp).Link_List!=NULL)
				{
				   temp=temp->next;       ////�ҵ�ͬ���豸�����һ��
				}
				temp->next=p4;
				temp->Link_List=p4;
			}
		}
		else                       /////�½�������
		{
		   printf("�½�������ʱͨ����ѡ��\n  1 *******ѡ��ԭ��ͨ��      2*******ѡ���½�ͨ�� \n");
		   int i;
		   scanf("%d",&i);
		   getchar();               
		   if(i==1)     ///ѡ��ԭ����ͨ��
		   {
			  char  Channel_Name[N]; 
		      printf("��������ѡ��ͨ������\n");
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

