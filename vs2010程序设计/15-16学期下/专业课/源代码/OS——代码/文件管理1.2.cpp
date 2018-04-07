// �ļ�����1.1.cpp : �������̨Ӧ�ó������ڵ㡣
//
// �ļ�����1.0.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<math.h>
#define N 20

////�ļ���Ŀ¼���ƿ�
typedef struct FCB 
{
	char name[10];  ///e�ļ�����
	int size;   ///��С
	int First_Block;  ///��һ����
	char  type;  //���� 1Ϊ�ļ� 2ΪĿ¼ 0Ϊ��ɾ��Ŀ¼��
	char  Date_Time[20];  ///����ʱ��
	FCB * first;  ///ָ����һ���Ŀ��ƿ�
	FCB * next1;  //ָ��ͬ���Ŀ��ƿ�  
	int level;     //Ŀ¼�ļ����������ļ������ļ���
}FCB;
void Display_Tree(FCB * p0);
void  Make_File(FCB * change,char * name,int Graph[][10],int FAT[64]);
FCB * Delete_Catlog1(FCB * p0,char * name2);
//FCB * Creat_Catalog(FCB * t);
FCB * Tree_Init(FCB * p0);
FCB * Delete_Catlog1(FCB * p0);
//FCB * Delete_Catlog(FCB * t);
void Command_Input(char * & name1,char * & name2);
/////�������ܣ� �˵���ʾ
void menu()
{
	printf("\n\t************************************\n");
	printf("\t\t MD+���� --����Ŀ¼\n");
	printf("\t\t CD+���� --�л�����Ŀ¼\n");
	printf("\t\t RD+���� --ɾ��Ŀ¼ \n");
	printf("\t\t MK+���� --�������ļ�\n");
	printf("\t\t DEL+����--ɾ���ļ�\n");
	//��ѯ�ļ�����Ŀ¼������·��
	printf("\t\t DIR--�г���ǰĿ¼����Ŀ¼��\n");
	printf("\t\t TREE--��ӡ����������Ŀ¼\n");
	//printf("");
	printf("\t************************************\n");
}
FCB * Tree_Init(FCB * p0)
{ 
	strcpy(p0->name,"ͷ���");
	//////////////////*******************************һ��Ŀ¼�Ľ���
	FCB * temp=(FCB *)malloc(sizeof(FCB));
	strcpy(temp->name,".");
	temp->type=2;     //ΪĿ¼
	p0->next1=temp;
	FCB * temp1=(FCB *)malloc(sizeof(FCB));
	strcpy(temp1->name,"..");
	temp1->type=2;     //ΪĿ¼
	temp->next1=temp1;
	temp->first=temp1->first=NULL;
	FCB * temp2=(FCB *)malloc(sizeof(FCB));
	strcpy(temp2->name,"J1");
	temp2->type=2;
	temp1->next1=temp2;
	FCB * temp3=(FCB *)malloc(sizeof(FCB));
	strcpy(temp3->name,"J2");
	temp3->type=2;
	temp2->next1=temp3;
	FCB * temp4=(FCB *)malloc(sizeof(FCB));
	strcpy(temp4->name,"J3");
	temp3->next1=temp4;
	temp4->type=2;
	temp4->next1=NULL;
	temp->level=temp1->level=temp2->level=temp3->level=temp4->level=1;
	//********************************** ------------------------------------------
	/////********************************************************************����Ŀ¼�Ľ���
	FCB *  temp5=(FCB *)malloc(sizeof(FCB));
	strcpy(temp5->name,".");
	temp5->type=2;
	temp2->first=temp5;
	FCB *  p1=(FCB *)malloc(sizeof(FCB));
	strcpy(p1->name,"..");
	p1->type=2;
	temp5->next1=p1;
	temp5->first=p1->first=NULL;
	FCB *  p2=(FCB *)malloc(sizeof(FCB));
	strcpy(p2->name,"J1");
	p2->type=2;
	p1->next1=p2;
	FCB *  p3=(FCB *)malloc(sizeof(FCB));
	strcpy(p3->name,"J2");
	p1->type=2;
	p2->next1=p3;
	p3->next1=NULL;
	FCB *  p4=(FCB *)malloc(sizeof(FCB));
	strcpy(p4->name,".");
	p4->type=2;
	temp3->first=p4;
	FCB *  p5=(FCB *)malloc(sizeof(FCB));
	strcpy(p5->name,"..");
	p5->type=2;
	p4->next1=p5;
	p5->next1=NULL;
	p5->first=p4->first=NULL;


	FCB *  p6=(FCB *)malloc(sizeof(FCB));
	strcpy(p6->name,".");
	p6->type=2;
	temp4->first=p6;
	FCB *  p7=(FCB *)malloc(sizeof(FCB));
	strcpy(p7->name,"..");
	p7->type=2;
	p6->next1=p7;
	p7->next1=NULL;
	p6->first=p7->first=NULL;
	temp5->level=p1->level=p2->level=p3->level=p4->level=p5->level=p6->level=p7->level=2;
	////////---------------------------------------------------
	////-------------------------------------**********************����Ŀ¼�Ľ���
	FCB *  q1=(FCB *)malloc(sizeof(FCB));
	strcpy(q1->name,".");
	q1->type=2;
	p2->first=q1;
	FCB *  q2=(FCB *)malloc(sizeof(FCB));
	strcpy(q2->name,"..");
	q2->type=2;
	q1->next1=q2;
	q2->next1=NULL;
	q1->first=q2->first=NULL;

	FCB *  q3=(FCB *)malloc(sizeof(FCB));
	strcpy(q3->name,".");
	q3->type=2;
	p3->first=q3;
	FCB *  q4=(FCB *)malloc(sizeof(FCB));
	strcpy(q4->name,"..");
	q4->type=2;
	q3->next1=q4;
	q4->next1=NULL;
	q3->first=q4->first=NULL;
	q1->level=q2->level=q3->level=q4->level=3;

	return p0;
}  
void Display_Tree(FCB * p0)
{
	FCB * t;
	if(strcmp(p0->name,"ͷ���")==0)
	{ t=p0->next1; }
	else
	{
		t=p0;
	}
	int x;
	if(t->level==1)
	{
		x=0;
	}
	else if(t->level==2)
	{
		x=12;
	}
	else if(t->level==3)
	{
		x=25;
	}
	while(t->next1!=NULL)
	{
		printf("\n");
		for(int i=0;i<x;i++)
		{
			printf(" ");
		}
		printf("|  ");
		printf("%s",t->name);
		printf("  |");
		if(t->first!=NULL)   ///��������һ��Ŀ¼ʱ
		{
			printf("----");

			Display_Tree(t->first);
		}
		if(t->next1!=NULL)
		{
			t=t->next1;
		}
	}
	if(t->next1==NULL)    ///���Ŀ¼�����һ���ļ�
	{
		printf("\n");
		for(int i=0;i<x;i++)
		{
			printf(" ");
		}
		printf("|  ");
		printf("%s",t->name);
		printf("  |");
		int z=0;
		if(t->first!=NULL)   ///��������һ��Ŀ¼ʱ
		{
			printf("----");
			Display_Tree(t->first);
		}
	}

}
/*
///�������ܣ�����Ŀ¼��ѭ��ѡ��
FCB * Creat_Catalog(FCB * t,char * name)
{
printf("\n�Ƿ񴴽�Ŀ¼��(y or n)\n");
char i;
scanf("%c",&i);
getchar();
while(i=='Y'||i=='y')
{
t=Creat_Catalog1(t);
printf("\n�Ƿ񴴽�Ŀ¼��(y or n)\n");
scanf("%c",&i);
getchar();
}
return t;
}   */
///�������ܣ�����Ŀ¼
FCB * Creat_Catalog1(FCB * t,char * name)
{
	printf("\n�����뽫Ҫ����Ŀ¼�ļ���1��2��3����\n");
	int choice;
	scanf("%d",&choice);
	getchar();
	FCB *  New_Node=(FCB *)malloc(sizeof(FCB));
	//printf("�����뽫Ҫ����Ŀ¼�����ƣ�\n");
	//gets(New_Node->name);
	int i=0;
	while((*name)!='\0')
	{
		New_Node->name[i]=*name;
		name++;
		i++;
	}
	for(int k=i+1;k<10;k++)
	{
		New_Node->name[i]='\0';
	}
	//strcpy(New_Node->name,(*name));
	New_Node->type=2;
	New_Node->level=choice;
	if(choice==1)
	{
		FCB * one=t->next1;
		while(one->next1!=NULL)
		{
			one=one->next1;
		}
		one->next1=New_Node;
		New_Node->next1=New_Node->first=NULL;
		New_Node->level=1;
		////--------------------------------------------------------
		FCB *  p6=(FCB *)malloc(sizeof(FCB));
		strcpy(p6->name,".");
		p6->type=2;
		New_Node->first=p6;
		FCB *  p7=(FCB *)malloc(sizeof(FCB));
		strcpy(p7->name,"..");
		p7->type=2;
		p6->next1=p7;
		p7->next1=NULL;
		p6->first=p7->first=NULL;
		p6->level=p7->level=2;
	}
	if(choice==2)   ////����뽫Ŀ¼�����ڵڶ���
	{
		FCB * one=t->next1;
		while(one->next1!=NULL)
		{
			one=one->next1;
		}
		if(one->first!=NULL)     ///�ж�1��Ŀ¼���һ���ڵ��Ƿ�������һ��
		{
			FCB * two=one->first;
			while(two->next1!=NULL)
			{
				two=two->next1;
			}
			two->next1=New_Node;
			New_Node->next1=New_Node->first=NULL;
			New_Node->level=2;
		}
		else if(one->first==NULL)
		{
			//one->first=New_Node;
			FCB *  p6=(FCB *)malloc(sizeof(FCB));
			strcpy(p6->name,".");
			p6->type=2;

			FCB *  p7=(FCB *)malloc(sizeof(FCB));
			strcpy(p7->name,"..");
			p7->type=2;
			p6->next1=p7;
			p7->next1=New_Node;
			New_Node->next1=New_Node->first=NULL;
			New_Node->level=2;
			p6->first=p7->first=NULL;
			p6->level=p7->level=2;   
		}
	}
	if(choice==3)
	{
		FCB * one=t->next1;
		while(one->next1!=NULL)
		{
			one=one->next1;
		}
		if(one->first!=NULL)     ///�ж�1��Ŀ¼���һ���ڵ��Ƿ�������һ��
		{
			FCB * two=one->first;
			while(two->next1!=NULL)
			{
				two=two->next1;
			}
			// two->next1=New_Node;
			if(two->first!=NULL)      ///�ж�2��Ŀ¼���һ���ڵ��Ƿ�������һ��
			{
				FCB * three=two->first;
			}
			else if(two->first==NULL)      ///������Ŀ¼���һ���ڵ�����һ��ʱ
			{
				FCB *  p6=(FCB *)malloc(sizeof(FCB));
				strcpy(p6->name,".");
				p6->type=2;
				two->first=p6;
				FCB *  p7=(FCB *)malloc(sizeof(FCB));
				strcpy(p7->name,"..");
				p7->type=2;
				p6->next1=p7;
				p7->next1=NULL;
				p6->first=p7->first=NULL;
				p6->level=p7->level=3;
				p7->next1=New_Node;
				New_Node->next1=New_Node->first=NULL;
				New_Node->level=3;
			}
		}
		else 
		{

		}
	}
	return t;
}
/*
//�������ܣ�ɾ����Ŀ¼
FCB * Delete_Catlog(FCB * t)
{
printf("\n�Ƿ�ɾ��Ŀ¼��(y or n)\n");
char i;
scanf("%c",&i);
getchar();
while(i=='Y'||i=='y')
{
t=Delete_Catlog1(t);
// t=Creat_Catalog1(t);
printf("\n�Ƿ�ɾ��Ŀ¼��(y or n)\n");
scanf("%c",&i);
getchar();
}
return t;
}          */
///�������ܣ�ɾ��Ŀ¼
FCB * Delete_Catlog1(FCB * p0,char * name2)
{
	printf("\nɾ��֮ǰ������Ŀ¼Ϊ\n");
	Display_Tree(p0);
	/* printf("\n�����뽫Ҫɾ��Ŀ¼��Ӧ��1��Ŀ¼���ƣ�\n");
	char name1[10];
	gets(name1);
	printf("\n�����뽫Ҫɾ��Ŀ¼��Ӧ��2��Ŀ¼����(���û��������0)��\n");
	char name2[10];
	gets(name2);
	printf("\n�����뽫Ҫɾ��Ŀ¼��Ӧ��1��Ŀ¼���ƣ����û��������0����\n");
	char name3[10];
	gets(name3);    */
	FCB * p1=p0->next1;
	char aim[10];
	int i=0;
	while((*name2)!='\0')
	{
		aim[i]=(*name2);
		name2++;
		i++;
	}
	for(int k=i;k<10;k++)
	{
		aim[k]='\0';
	}
	while(strcmp(p1->name,aim)!=0)
	{
		p1=p1->next1;
	}
	if(strcmp(p1->name,aim)==0)     ///��Ҫɾ����Ŀ¼�µ�һ��Ŀ¼ʱ
	{
		FCB * p2=p0->next1;
		while(p2->next1!=p1)
		{
			p2=p2->next1;
		}
		p2->next1=p2->next1->next1;
	}
	return p0;
}
///�������ܣ��л�2��Ŀ¼

/*
FCB * Chang_2(FCB * )
{

}   */
///�������ܣ��л�����Ŀ¼
FCB * Change_Catalog(FCB * p0,char * name)
{
	printf("\n�����뽫Ҫ��ת����Ŀ¼�ļ���1 2  3��!\n");
	int Class;
	scanf("%d",&Class);
	getchar();
	//printf("\n��Ҫ��ת��Ŀ¼����Ϊ\n");
	//puts(name);
	FCB * p1=p0->next1;
	FCB * temp1;
	if(Class==2)     ///����Ҫ��ת���ڶ���Ŀ¼ʱ
	{
		while((strcmp(p1->name,".")==0)||(strcmp(p1->name,"..")==0))
		{
			p1=p1->next1;
		}
		FCB * temp=p1->first;
		while(strcmp(temp->name,name)!=0)
		{
			temp=temp->next1;
		}
		if(strcmp(temp->name,name)==0)  ///���ҵ���Ҫ��ת��Ŀ¼ʱ
		{
			temp1=temp->first;
		}
		printf("\n�Ѿ���ת��ָ��Ŀ¼\n");
		return temp1;
		/*	    while((strcmp(temp1->name,".")==0)||(strcmp(temp1->name,"..")==0))
		{
		temp1=temp1->next1;
		}
		FCB * aim=(FCB *)malloc(sizeof(FCB));
		aim->next1=aim->first=NULL;
		aim->level=3;
		aim->  */
	}
}
///�������ܣ�����������
void Command_Input(char * & name1,char * & name2)
{
	printf("\n������ѡ�\n");   /////�����е�ʵ��
	char choice[N];
	for(int i=0;i<20;i++)
	{
		choice[i]='\0';
	}
	gets(choice);
	int i=0;
	int j=0;
	int k=0;
	for(i=0;i<N;i++)
	{  
		if(choice[i]!=' ')
		{
			k++;
		}
		else  if(choice[i]==' ')
		{
			break;
		}
	}
	char * p1=(char *)malloc(N*sizeof(char));
	char * p2=(char *)malloc(N*sizeof(char));
	for(int i=0;i<20;i++)
	{
		p1[i]='\0';
		p2[i]='\0';
	}
	for(j=0;j<k;j++)           ///  ��ȡ�����еĵ�һ������
	{
		p1[j]=choice[j];
	}
	for(i=0,j=k+1;j<N;i++,j++)       /// ��ȡ�����еĵڶ�������
	{
		p2[i]=choice[j];
		if(choice[j]=='\0')  break;
	}
	name1=p1;
	name2=p2;
}
///�������ܣ�����λʾͼ
void Creat_Position(int  Graph[][10])
{

	///*****************�����������Ϊλʾͼ���ݸ�ֵ
	int n,i,j;
	//	int k;  ///��¼ i  , j��Ӧ�����λ��

	int count=0;

	i=j=0;
	n=64;
	srand((int)time(0));
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			Graph[i][j]=rand()%2;
		}
	}
	printf("***********λʾͼ�Ĵ�СΪ8*8***************\n");
	printf("�����ڴ滮�ֵ�λʾͼΪ��\n");
	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
		{
			printf("%d    ",Graph[i][j]);
		}
		printf("\n");
	}
}
///�������ܣ�ʵ�ִ����ļ�
void  Make_File(FCB * change,char * name,int  Graph[][10],int FAT[64])
{
	printf("\n���̿�Ĵ�СΪ50 Byte\n");
	printf("\n�����뽫Ҫ�����ļ����Ĵ�С��\n");
	//long double size;
	int size;
	scanf("%d",&size);
	getchar();
	int a;
	int first_block;  ///��¼��һ�����
	a=size/50;
	if((size%50)!=0)  a++;
	//a=ceil(size);    ///һ����Ҫ�õ�a���̿�
	int k=0;
	int mark;
	//int FAT[64];
	////FAT��ĳ�ʼ��
	for(int i=0;i<64;i++)
	{
		FAT[i]=-2;
	}
	printf("\n�����ڴ�֮ǰ��FAT��Ϊ\n");
	for(int i=0;i<64;i++)
	{
		printf("%d ",FAT[i]);
	}
	for(int i=0;i<8;i++)        ////ͨ��λʾͼ���޸�FAT��
	{
		for(int j=0;j<8;j++)
		{
			//	printf("%d ",Graph[i][j]);
			if(Graph[i][j]==0)  
			{
				if(k>0)
					FAT[mark]=8*i+j;  
				k++;
				mark=8*i+j;
				if(k==1)    first_block=mark;
			}
			if(k==a)
			{
				FAT[mark]=-1;
				break;
			}
		}
		if(k==a)  break;
	}
	printf("\n�����ڴ�֮���FAT��Ϊ\n");
	for(int i=0;i<64;i++)
	{
		printf("%d ",FAT[i]);
	}
	////////////////////////////////////////-----------------------------------------------------------
	while(strcmp(change->name,".")==0)
	{
		change=change->next1;
	}

	FCB * aim=(FCB *)malloc(sizeof(FCB));
	change->next1=aim;
	aim->next1=aim->first=NULL;
	aim->level=3;
	aim->type=1;
	aim->First_Block=first_block;
	strcpy(aim->name,name);
}
void Judge_1(FCB * p0,char * name)
{
	if(p0->type==1)   //���ýڵ�Ϊ�����ļ�ʱ
	{
		if(strcmp(p0->name,name)==0);
	}
}
///�������ܣ�Ѱ��Ŀ���ļ�
void Find(FCB * p1,FCB * p2,int FAT[64],char * name)      ///p2 p1 �Ĺ�ϵ  p2=p1->first;
{
	int flage=0;
    while(p2->next1!=NULL)
	{
		if(p2->type==1)  ///��p2���ļ�ʱ
		{
			if(strcmp(p2->name,name)==0)  ///�ҵ�Ŀ���ļ�ʱ  ,�޸�FAT��
			{
			 ////ɾ���ļ�
				FCB * temp=p1->first;
				while(temp->next1!=p2)
				{
					temp=temp->next1;
				}
				temp->next1=p2->next1;
             ////�޸�FAT��
				int we[N];
				int i;
				i=p2->First_Block;
				int j=0;
				we[j]=i;
				j++;
				while(FAT[i]!=-1)
				{
				    we[j]=FAT[i];
					j++;
					i=FAT[i];
				}
				for(int k=0;k<=j;k++)
				{
				    FAT[we[k]]=-2;
				}
				///
				flage=1;
				if(flage==1)
					break;
			}
		}
		else  if(p2->type==2)  ///��Ŀ¼ʱ
		{
		   if(p2->first!=NULL)     //���p1��һ�������ļ���Ŀ¼
		   {
			   FCB * p3=p2->first;
			    //p2=p1->first;
				Find(p2,p3,FAT,name);
		   }
		   else if(p2->next1!=NULL)    ///���p1�ĺ��滹��ʱ
		   {
			  p2=p2->next1; 
		   }
		}
	}
	if(p2->next1==NULL)
	{
	   if(p2->type==1)  ///��p2���ļ�ʱ
		{
			if(strcmp(p2->name,name)==0)  ///�ҵ�Ŀ���ļ�ʱ  ,�޸�FAT��
			{
			 ////ɾ���ļ�
				FCB * temp=p1->first;
				while(temp->next1!=p2)
				{
					temp=temp->next1;
				}
				temp->next1=p2->next1;
             ////�޸�FAT��
				int we[N];
				int i;
				i=p2->First_Block;
				int j=0;
				we[j]=i;
				j++;
				while(FAT[i]!=-1)
				{
				    we[j]=FAT[i];
					j++;
					i=FAT[i];
				}
				for(int k=0;k<=j;k++)
				{
				    FAT[we[k]]=-2;
				}
				///
				flage=1;
			//	if(flage==1)   	break;
				
			}
		}
		else  if(p2->type==2)  ///��Ŀ¼ʱ
		{
		   if(p2->first!=NULL)     //���p1��һ�������ļ���Ŀ¼
		   {
			   FCB * p3=p2->first;
			    //p2=p1->first;
				Find(p2,p3,FAT,name);
		   }
		/*   else if(p2->next1!=NULL)    ///���p1�ĺ��滹��ʱ
		   {
			  p2=p2->next1; 
		   }     */
		}
	}
}
////�������ܣ�ɾ���ļ�
FCB * Delete_File(FCB * p0,char * name,int FAT[64])
{
	FCB * p2=p0->next1;
	FCB * p1=p0;
	Find(p1,p2,FAT,name);
	return p0;
}   
int _tmain(int argc, _TCHAR* argv[])
{
	int FAT[64];
	int   Graph[10][10];  ////λʾͼ�Ķ���
	Creat_Position(Graph);
	FCB * p0=(FCB *)malloc(sizeof(FCB));     ///������Ŀ¼ͷ���
	FCB * change;
	p0=Tree_Init(p0);
	Display_Tree(p0);
	char  key;
	key='y';
	while(key=='y'||key=='Y')
	{
		menu();
		char * name1=NULL;
		char * name2=NULL;
		Command_Input(name1,name2);
		if(strcmp(name1,"MD")==0)          ////������봴��Ŀ¼
		{
			p0=Creat_Catalog1(p0,name2);
			Display_Tree(p0);
		}
		else if(strcmp(name1,"CD")==0)    ///������ת����
		{
			change=Change_Catalog( p0,name2);
			
		}
		else if(strcmp(name1,"RD")==0)     ///����ɾ������
		{
			p0=Delete_Catlog1(p0,name2);
			printf("\nɾ������֮�������Ŀ¼\n");
			Display_Tree(p0);   
		}
		else if(strcmp(name1,"MK")==0)                   ///����ָ����С���ļ�
		{
			Make_File(change,name2,Graph,FAT);
			Display_Tree(p0);
			//getchar();
		}
		else if(strcmp(name1,"DEL")==0)
		{
		   p0=Delete_File(p0,name2,FAT);
		   Display_Tree(p0);
		   //Delete_File(FCB * p0,char * name,int FAT)
		}
		else if(strcmp(name1,"TREE")==0)
		{
		   Display_Tree(p0);
		}
		printf("\n�Ƿ��������y or n��");
		scanf("%c",&key);
		getchar();   
	}
	return 0;
}



