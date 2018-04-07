// ���̵���1.0.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 20
typedef struct PCB {
	char name[20];//��������
	int size;//���̴�С��ʱ��Ƭ��ת���õ���
	int arrival_time;//�ύʱ��
	int running_time;//����ʱ��
	int start_time;//��ʼʱ��
	int finish_time;//���ʱ��
	int used_time;  ///�����ѽ�ִ�е�ʱ�䣨ʱ��Ƭ��ת���õ���
	int need_time;  ///���̻���Ҫ��ִ��ʱ�䣨ʱ��Ƭ��ת���õ���
	int T;//ƽ����תʱ��
	double W;//��Ȩ��תʱ��
	struct PCB * next;
}PCB;
void SJF(PCB * & ready,PCB * & run,PCB * & finish,PCB * & block);
void show(PCB *ready,PCB * block,PCB * run,PCB * finish);
void Found_Process(PCB * & ready);
void FCFS(PCB * & ready,PCB * & run,PCB * & finish,PCB * & block);
void finish_show(PCB * finish);
//void Found_Process1(PCB * & ready);
/*
///  ��ʱ��Ƭ��ת�У���ӡ ������ִ�е�ʱ��ͻ�������ʱ��
void ready_show(PCB * & ready)
{
PCB * temp=ready->next;
printf("\n��ǰ��Ҫִ�еĽ�������Ϊ��\n");
while(temp!=NULL)
{

printf("%s",temp->name);
printf("   �ý�����ִ��ʱ��Ϊ�� %d",temp->used_time);
printf("   �ý��̻������ʱ��Ϊ�� %d\n",temp->need_time);
temp=temp->next;
}
}   */
//�������ܣ�ʵ��ʱ��Ƭ��ת ���̵���
void TIME_RR(PCB * & ready,PCB * & run,PCB * &finish,PCB * & block)
{
	int large;
	printf("\n������ʱ��Ƭ��ת�Ĵ�С!\n");
	scanf("%d",&large);
	getchar();

	int time;
	time=0;
	///ready����ִ�й���
	PCB * min=ready->next;
	while(ready->next!=NULL)
	{
		///ready����ִ�й���
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
		p1=ready;      ///��ready������ɾ��min�ڵ�
		while(p1!=NULL)
		{
			if(p1->next==min)  break;
			else p1=p1->next;
		}
		p1->next=min->next;   ///��ready������ɾ��min�ڵ�
		run->next=min;    ///�������ж���
		min->next=NULL;

		/////run����ִ�й���
		time=time+large;
		min->used_time=large+min->used_time;
		min->need_time=min->size-min->used_time;
		printf("����ִ�н���\t%s",min->name);
		printf("   �Ѿ�ִ��ʱ��     %d",min->used_time);
		printf("   ����ִ��ʱ��     %d\n",min->need_time);


		if(min->need_time==0)     ///���min��need_timeΪ0������ý����Ѿ�ִ����ϣ������finish����
		{
			////finish ���в���
			if(finish->next==NULL)  ///��ִ�е�һ������ʱ
			{
				finish->next=run->next;
				run->next=NULL;
			}
			else    ///�����ǵ�һ������ʱ
			{
				PCB * temp_finish=finish->next;
				while(temp_finish->next!=NULL)     ///�ҵ���ɶ��е����һ���ڵ�
				{
					temp_finish=temp_finish->next;
				}  
				temp_finish->next=run->next;
				run->next=NULL;
			}
		}
		else   ///��min->need_time��Ϊ0��ͨ��block���У�  �ٷŵ�ready���еĶ�β
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
///�������ܣ���������
void Found_Process(PCB * & ready)
{
	PCB * temp=ready;
	char choice;
	printf("\n�Ƿ񴴽�һ���µĽ���?(y or n)\n");
	scanf("%c",&choice);
	getchar();
	while(choice=='y'||choice=='Y')
	{
		PCB * p0=(PCB *)malloc(sizeof(PCB));
		p0->next=NULL;  
		temp->next=p0;
		temp=p0;
		printf("\n�������´������̵����֣�\n");
		gets(p0->name);
		printf("\n�������´������̵��ύʱ�̣�\n");
		scanf("%d",&(p0->arrival_time));
		getchar();
		printf("\n�������´������̵�����ʱ�䣡\n");
		scanf("%d",&(p0->running_time));
		getchar();
		p0->size=p0->running_time;
		p0->need_time=p0->size;
		p0->used_time=0;
		printf("\n�Ƿ񴴽�һ���µĽ���?(y or n)\n");
		scanf("%c",&choice);
		getchar();
	}
	temp->next=NULL;
}
///�������ܣ�����ҵ���Ƚ��̵��ȵ�ʵ��
void SJF(PCB * & ready,PCB * & run,PCB * & finish,PCB * & block)
{
	int time;
	time=0;
	PCB * min=ready->next;  //�ҵ�ͬһʱ���ڣ���ҵ����ʱ�����ٵ�
	while(ready->next!=NULL)
	{
		min=ready->next;
		PCB * p1=ready->next;
		while(p1!=NULL)
		{    //Ѱ����һ��ʱ�䷶Χ�ڣ���������ʱ����С�Ľ���
			if(p1->arrival_time<=time&&p1->running_time<min->running_time)
				min=p1;
			p1=p1->next;
		}
		p1=ready;      ///��ready������ɾ��min�ڵ�
		while(p1!=NULL)
		{
			if(p1->next==min)  break;
			else p1=p1->next;
		}
		p1->next=min->next;   ///��ready������ɾ��min�ڵ�
		run->next=min;    ///�������ж���
		min->next=NULL;

		////finish ���в���
		if(finish->next==NULL)  ///��ִ�е�һ������ʱ
		{
			min->start_time=time;
			min->finish_time=min->start_time+min->running_time;  ///���ʱ��=��ʼʱ��+����ʱ��
			time=min->finish_time;  //-***************************************************************************�ڴ˴��޸�timeֵ
			min->T=min->finish_time-min->arrival_time;   ///��תʱ��=���ʱ��-�ύʱ��
			min->W=(double)min->T/min->running_time;  ///��Ȩ��תʱ��=��תʱ��/����ʱ��
			finish->next=run->next;

			run->next=NULL;
		}
		else    ///�����ǵ�һ������ʱ
		{
			PCB * temp_finish=finish->next;
			while(temp_finish->next!=NULL)     ///�ҵ���ɶ��е����һ���ڵ�
			{
				temp_finish=temp_finish->next;
			}  
			min->start_time=temp_finish->finish_time;   ///��ǰ���̵Ŀ�ʼʱ����ǰһ���̵����ʱ��
			min->finish_time=min->start_time+min->running_time;  ///���ʱ��=��ʼʱ��+����ʱ��
			time=min->finish_time;  //-***************************************************************************�ڴ˴��޸�timeֵ
			min->T=min->finish_time-min->arrival_time;   ///��תʱ��=���ʱ��-�ύʱ��
			min->W=(double)min->T/min->running_time;  ///��Ȩ��תʱ��=��תʱ��/����ʱ��
			temp_finish->next=run->next;
			run->next=NULL;
		}
	}
	finish_show(finish);
}
///�������ܣ������ȷ�����̵��ȵ�ʵ��
void FCFS(PCB * & ready,PCB * & run,PCB * & finish,PCB * & block)
{
	//int flage=0;//���λ
	int TIME=0;   ////ƽ����תʱ��
	int count=0;
	PCB * min=ready->next;   ///�ҵ��ύʱ����С��
	while(ready->next!=NULL)
	{
		min=ready->next;
		PCB * p1=ready->next;
		while(p1!=NULL)
		{
			if(p1->arrival_time<min->arrival_time)     ///�ҵ�����ʱ����С�Ľ��
				min=p1;
			p1=p1->next;
		}
		p1=ready;      ///��ready������ɾ��min�ڵ�
		while(p1!=NULL)
		{
			if(p1->next==min)  break;
			else p1=p1->next;
		}
		p1->next=min->next;   ///��ready������ɾ��min�ڵ�
		run->next=min;    ///�������ж���
		min->next=NULL;

		if(finish->next==NULL)  ///��ִ�е�һ������ʱ
		{
			min->start_time=0;
			min->finish_time=min->start_time+min->running_time;  ///���ʱ��=��ʼʱ��+����ʱ��
			min->T=min->finish_time-min->arrival_time;   ///��תʱ��=���ʱ��-�ύʱ��
			min->W=(double)min->T/min->running_time;  ///��Ȩ��תʱ��=��תʱ��/����ʱ��
			finish->next=run->next;
			TIME=TIME+min->T;
			count++;
			run->next=NULL;
		}
		else    ///�����ǵ�һ������ʱ
		{
			PCB * temp_finish=finish->next;
			while(temp_finish->next!=NULL)     ///�ҵ���ɶ��е����һ���ڵ�
			{
				temp_finish=temp_finish->next;
			}  
			min->start_time=temp_finish->finish_time;   ///��ǰ���̵Ŀ�ʼʱ����ǰһ���̵����ʱ��
			min->finish_time=min->start_time+min->running_time;  ///���ʱ��=��ʼʱ��+����ʱ��
			min->T=min->finish_time-min->arrival_time;   ///��תʱ��=���ʱ��-�ύʱ��
			TIME=TIME+min->T;
			count++;
			min->W=(double)min->T/min->running_time;  ///��Ȩ��תʱ��=��תʱ��/����ʱ��
			temp_finish->next=run->next;
			run->next=NULL;
		}
		//show(ready,block,run,finish);

	}
	finish_show(finish);
	TIME=TIME/count;
	printf("\n ƽ����תʱ��Ϊ��%d\n",TIME);
}
///�������ܣ���ӡ���ս��
void finish_show(PCB * finish)
{
	PCB *temp=finish->next;
	printf("�������ƣ�\t");
	while(temp!=NULL)
	{
		printf("%s\t",temp->name);
		temp=temp->next;
	}
	printf("\n");
	temp=finish->next;
	printf("�ύʱ�̣�\t");
	while(temp!=NULL)
	{
		printf("%d\t",temp->arrival_time);
		temp=temp->next;
	}
	printf("\n");
	temp=finish->next;
	printf("����ʱ�䣺\t");
	while(temp!=NULL)
	{
		printf("%d\t",temp->running_time);
		temp=temp->next;
	}
	printf("\n");
	temp=finish->next;
	printf("��ʼʱ�̣�\t");
	while(temp!=NULL)
	{
		printf("%d\t",temp->start_time);
		temp=temp->next;
	}
	printf("\n");
	temp=finish->next;
	printf("���ʱ�̣�\t");
	while(temp!=NULL)
	{
		printf("%d\t",temp->finish_time);
		temp=temp->next;
	}
	printf("\n");
	temp=finish->next;
	printf("��תʱ�䣺\t");
	while(temp!=NULL)
	{
		printf("%d\t",temp->T);
		temp=temp->next;
	}
	printf("\n");
	temp=finish->next;
	printf("��Ȩ��תʱ�䣺\t");
	while(temp!=NULL)
	{
		printf("%f ",temp->W);
		temp=temp->next;
	}
	printf("\n");  
}
///�������ܣ���ӡ�������̶��еĽ��
void show(PCB * ready,PCB * block,PCB * run,PCB * finish)
{
	printf("\nready���нڵ�Ԫ�طֲ�\n");
	PCB * temp;
	temp=ready->next;
	if(temp==NULL)  
	{
		printf("\t\t\t�ö��е�ǰ�޽ڵ㣡\n");
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
	printf("\nrun���нڵ�Ԫ�طֲ�\n");
	//PCB * temp;
	temp=run->next;
	if(temp==NULL)  
	{
		printf("\t\t\t�ö��е�ǰ�޽ڵ㣡\n");
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
	printf("\nfinish���нڵ�Ԫ�طֲ�\n");
	//PCB * temp;
	temp=finish->next;
	if(temp==NULL)  
	{
		printf("\t\t\t�ö��е�ǰ�޽ڵ㣡\n");
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
	printf("\nblock���нڵ�Ԫ�طֲ�\n");
	//PCB * temp;
	temp=block->next;
	if(temp==NULL)  
	{
		printf("\t\t\t�ö��е�ǰ�޽ڵ㣡\n");
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
//�������ܣ�ʵ�� ready���еĸ���
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
///�������ܣ����м��㷨��ʵ��
void banker()
{
	printf("��5������");
	int p[5];
	//int i=0;
	for(int i=0;i<5;i++)
	{
		p[i]=i+1;
	}
	int Available[4];  ///��������Դ���飬ÿһ�����һ������õ���Դ��Ŀ
	printf("\n��4�������Դ\n");
	for(int i=0;i<4;i++)
	{
		printf("\n�������%d����Դ��������Ŀ��\n",(i+1));
		scanf("%d",&Available[i]);
	}
	int Max[5][4];     ///����������
	for(int i=0;i<5;i++)
	{
		printf("\n���������%d�ĸ�����Դ�������!\n",i);
		for(int j=0;j<4;j++)
		{
			printf("������%d��Դ���������\n",(j+1));  
			scanf("%d",&Max[i][j]);
		}
	}
	int Allocation[5][4];  ///������� 
	for(int i=0;i<5;i++)
	{
		printf("\n���������%d�ѷ��������Դ����Ŀ!\n",i);
		for(int j=0;j<4;j++)
		{
			printf("������%d��Դ�ķ�����Ŀ��\n",(j+1));  
			scanf("%d",&Allocation[i][j]);
		}
	}
	int Need[5][4];  ///�������̻���Ҫ����Դ��Ŀ
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<4;j++)
		{
			Need[i][j]=Max[i][j]-Allocation[i][j];
		}
	}
	////���м��㷨��ʵ��
	int Requast[4];
	int name;
	printf("\n�����뽫Ҫ������Դ�Ľ������ƣ�\n");
	scanf("%d",&name);
	getchar();
	int Requast_Number=0;
	printf("���������������Դ����Ŀ��\n");
	for( Requast_Number=0;Requast_Number<4;Requast_Number++)
	{
		printf("��Դ%d����Ŀ��\n",(Requast_Number+1));
		scanf("%d",&Requast[Requast_Number]);
		getchar();
	}
	for(Requast_Number=0;Requast_Number<4;Requast_Number++)
	{
	if(Requast[Requast_Number]<=Need[name][Requast_Number])
	{
		if(Requast[Requast_Number]<=Available[Requast_Number])    ///ϵͳ������̽����
		{
			Available[Requast_Number]=Available[Requast_Number]-Requast[Requast_Number];
			Allocation[name][Requast_Number]=Allocation[name][Requast_Number]+Requast[Requast_Number];
			Need[name][Requast_Number]=Need[name][Requast_Number]-Requast[Requast_Number];
		}
		else
		{
			printf("û���㹻����Դ!\n");
			return ;
		}
	}
	else
	{
		printf("�����������Ҫ����Դ���������ֵ!\n");
		return ;
	}
	}
	////��ȫ�Լ��
	int Work[4];  ///ϵͳ���ṩ�����̸�����Դ��Ŀ
	for(int i=0;i<4;i++)
	{
		Work[i]=Available[i];
	}
	int Finish[5];
	for(int i=0;i<5;i++)
	{
		Finish[i]=0;   ////0 ���� false  1����true 
	}
	int a,b;
	int k=0;////�������ȫ���е����
	int flage=0;
	int safe[5];     ///���ڴ�Ű�ȫ����
	int count;
	count=0;
	a=0;
	b=0;
	int go_on=1;
	while(go_on==1)
	{
		for(a=0;a<5;a++)    ///�ڽ��̼�����Ѱ��
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
		if(flage==1)    ///����������ͬʱ����ʱ
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
				if(Finish[i]!=1)   ////����в�������Ҫ��Ľ��̣�  �򲻰�ȫ
					safe_station=0;
			}
			if(safe_station==0)  
			{
				printf("\n*****************����ȫ*************\n");
			}
			else 
			{
				printf("\n*****************��ȫ*******************\n");
				printf("\t��ȫ����Ϊ��\n");
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
	PCB * ready1,*block1,*run1,*finish1;//�������̶��зֱ���� ����̬������̬��ʱ��Ƭ��ת�õ�����ִ��̬�������̬
	ready1=(PCB *)malloc(sizeof(PCB));
	strcpy(ready1->name,"ready1ͷ���");
	block1=(PCB *)malloc(sizeof(PCB));
	strcpy(block1->name,"block1ͷ���");
	run1=(PCB *)malloc(sizeof(PCB));
	strcpy(run1->name,"run1ͷ���");
	finish1=(PCB *)malloc(sizeof(PCB));
	strcpy(finish1->name,"finish1ͷ���");
	ready1->next=block1->next=run1->next=finish1->next=NULL;
	PCB * ready2,*block2,*run2,*finish2;//�������̶��зֱ���� ����̬������̬��ʱ��Ƭ��ת�õ�����ִ��̬�������̬
	ready2=(PCB *)malloc(sizeof(PCB));
	strcpy(ready2->name,"ready2ͷ���");
	block2=(PCB *)malloc(sizeof(PCB));
	strcpy(block2->name,"block2ͷ���");
	run2=(PCB *)malloc(sizeof(PCB));
	strcpy(run2->name,"run2ͷ���");
	finish2=(PCB *)malloc(sizeof(PCB));
	strcpy(finish2->name,"finish2ͷ���");
	ready2->next=block2->next=run2->next=finish2->next=NULL;
	PCB * ready3,*block3,*run3,*finish3;//�������̶��зֱ���� ����̬������̬��ʱ��Ƭ��ת�õ�����ִ��̬�������̬
	ready3=(PCB *)malloc(sizeof(PCB));
	strcpy(ready3->name,"ready3ͷ���");
	block3=(PCB *)malloc(sizeof(PCB));
	strcpy(block3->name,"block3ͷ���");
	run3=(PCB *)malloc(sizeof(PCB));
	strcpy(run3->name,"run3ͷ���");
	finish3=(PCB *)malloc(sizeof(PCB));
	strcpy(finish3->name,"finish3ͷ���");
	ready3->next=block3->next=run3->next=finish3->next=NULL;

	Found_Process(ready1);
	ready_copy(ready1,ready2);
	ready_copy(ready1,ready3);

	char i;
	i='y';
	while(i=='y'||i=='Y')
	{
		printf("\n\t��ѡ����̵����㷨��\n");
		printf("\n\n\t FCFS(�����ȷ���)   SJF(�̽�������)   TIME_RR(ʱ��Ƭ��ת)    BANKER(���м��㷨)\n");
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
		printf("\n�Ƿ������������y or n��\n");
		scanf("%c",&i);
		getchar();
	}     
	
	return 0;
}

