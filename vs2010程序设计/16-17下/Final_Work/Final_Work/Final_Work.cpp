// Final_Work.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N1  20

///�˵��ṹ��
typedef struct Menu
{
   char  Shop[N1];   ///�����̼���
   char  Name[N1];   /// ��Ʒ����
   int  Price;     ///��Ʒ����
   int  Number;    ///��Ʒ���
   int  Flage_1;      ///ͷ����־
   int  Count;    //��Ʒ��������
   struct Menu * next;    
}Menu_Node;
///�̼ҽṹ��
typedef struct producer
{
	char Name[N1];      ///�̼�����
	char Tele[N1];       //�绰
	char Adress[N1];      //��ַ
	char Boss[N1];       //�ϰ�
	int  Number;      ///�̼ҵı��
	int  Flage_1;   ///���ڱ���Ƿ�ָͷ���
	int  Count;   ///���ڼ�¼����������һ���ж����̼ҽ��
	struct producer * next;          ///ָ��producer��ָ��
	struct Menu * next_1;        ///ָ��Menu��ָ��
}P_Node;
///�˵���Ϣ�������ʼ��
Menu_Node * Menu_Init()
{
    Menu_Node * p;
	p=(Menu_Node *)malloc(sizeof(Menu_Node));
	p->next=NULL;      ///ͷ����и������ݵĳ�ʼ��
	p->Flage_1=1;
	p->Count=0;
	p->Number=0;
	p->Price=0;
	strcpy(p->Name,"");
	strcpy(p->Shop,"");
	return p;
}
///�̼���Ϣ�������ʼ������
P_Node * Shop_Init()
{
	P_Node * p;
	p=(P_Node *)malloc(sizeof(P_Node));
	p->next=NULL;              ///��ʼ����Ϊ0�ĵ�����
	p->next_1=NULL;
	p->Flage_1=1;               ///ͷ����־λ1
	p->Count=0;

	//char Inout[N1]="";         //ͷ���������ݵĳ�ʼ��
	strcpy(p->Adress,"");
	strcpy(p->Boss,"");
	strcpy(p->Name,"");
	strcpy(p->Tele,"");
	p->Number=0;
	return p;
}
///����β�巨�����˵�������
Menu_Node * CreatList_Menu(Menu_Node * head,P_Node * P_head)
{
	printf("\n����˵���ӹ���:\n");
	P_Node *  shop;
	shop=P_head->next;
	int flage=1;
	char choice;
	while(flage==1)
	{
	   Menu_Node * p;
	   p=(Menu_Node *)malloc(sizeof(Menu_Node));
	   p->next=NULL;
	   Menu_Node * q;
	   q=head;
	  
	   while(q->next!=NULL)   ///�ҵ��������ĩβ
	   {
		   q=q->next;
	   }
	   q->next=p;
	   head->Count++;
	   flage=0;
	   printf("�������Ʒ����!\n");
	   gets(p->Name);
	   printf("�����������̼ң�\n");
	   gets(p->Shop);
	   ///�˵�������̼���������
	   while(shop!=NULL)
	   {
		   if(strcmp(p->Shop,shop->Name)==0)    ///������ƥ��ʱ
		   {
			   shop->next_1=p;
			   break;
		   }
	      shop=shop->next;
	   }
	   printf("�������Ʒ���ۣ�\n");
	   scanf("%d",&p->Price);
	  // getchar();
	   p->Flage_1=0;
	   p->Number=head->Count;
	   p->Count=0;
	   	printf("�Ƿ������Ӳ˵���Ϣ����y or n��\n");
		scanf(" %c",&choice);
		getchar();
		if(choice=='y')      ///��ѡ��������ʱ
		{
		 flage=1;
		}
	}
	return head;
}
//����β�巨�����̼ҵ�����
P_Node * CreatList(P_Node * head)
{
	//char Input[N1];
	int flage=1;  ///����ѭ��������
	char choice;      
	char Input[N1];    ///������������
	while(flage==1)
	{
		P_Node * p;
		p=(P_Node *)malloc(sizeof(P_Node));
		p->next=NULL;
		p->next_1=NULL;
		P_Node * q;
		q=head;
		while(q->next!=NULL)
		{
			q=q->next;
		}
		q->next=p;       ///�����ɵĽڵ���ӵ��������ĩβ
		head->Count++;
		flage=0;
		printf("�������̼����ƣ�\n");
		gets(p->Name);
		printf("�������̼ҵ绰!\n");
		gets(p->Tele);
		printf("�������̼ҵ�ַ��\n");
		gets(p->Adress);
		printf("�������̼��ϰ壡\n");
		gets(p->Boss);
	//	printf("�������̼ұ��!\n");
	//	scanf("%d",p->Number);
		p->Number=head->Count;      ///�̼ұ�ţ�
		p->Count=0;
		p->Flage_1=0;
		printf("�Ƿ��������̼ң���y or n��\n");
		scanf("%c",&choice);
		getchar();
		if(choice=='y')      ///��ѡ��������ʱ
		{
		 flage=1;
		}
	}
	return head;
}
//��ӡ��������
void Show_List(P_Node * head)
{
   P_Node * p=head;
   p=p->next;
   if(p!=NULL)
   {
      printf("\n---------------------------------\n");
	  printf("            �̼���Ϣչʾ\n\n\n");
   }
   while(p!=NULL)
   {
      printf("�̼���:     ");
	  puts(p->Name);
	  printf("�̼ҵ绰:   ");
	  puts(p->Tele);
	  printf("�̼ҵ�ַ:   ");
	  puts(p->Adress);
	  printf("�̵��ϰ�:   ");
	  puts(p->Boss);
	  printf("�̼����:  %d",p->Number);
	  p=p->next;
	  printf("\n\n\n");
   }
   printf("---------------------------------\n");
}
///��ӡ�˵�����
void Show_Menu(Menu_Node * head)
{
   Menu_Node * p=head;
   p=p->next;
   if(p!=NULL)
   {
      printf("\n---------------------------------\n");
	  printf("            �˵���Ϣչʾ\n\n\n");
   }
   while(p!=NULL)
   {
      printf("��Ʒ����:     ");
	  puts(p->Name);
	  printf("�����̵�:     ");
	  puts(p->Shop);
	  printf("��Ʒ�۸�    %d",p->Price);
	  printf("�̼����:  %d",p->Number);
	  p=p->next;
	  printf("\n\n\n");
   }
   printf("---------------------------------\n");
}
//ͨ�����̲�ѯ�˵�
void ShopQuery_Menu()
{
   
}
int _tmain(int argc, _TCHAR* argv[])
{
	/*
	P_Node * producer=Shop_Init();
	producer=CreatList(producer);
	system("cls");    ///��������
	Show_List(producer);  
	*/
	Menu_Node * menu=Menu_Init();
	menu=CreatList_Menu(menu,producer);
	system("cls");    ///��������
	Show_Menu(menu);  
	return 0;

}


