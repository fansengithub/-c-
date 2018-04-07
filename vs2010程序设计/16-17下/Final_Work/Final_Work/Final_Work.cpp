// Final_Work.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N1  20

///菜单结构体
typedef struct Menu
{
   char  Shop[N1];   ///所属商家名
   char  Name[N1];   /// 菜品名称
   int  Price;     ///菜品单价
   int  Number;    ///菜品编号
   int  Flage_1;      ///头结点标志
   int  Count;    //菜品数量计数
   struct Menu * next;    
}Menu_Node;
///商家结构体
typedef struct producer
{
	char Name[N1];      ///商家姓名
	char Tele[N1];       //电话
	char Adress[N1];      //地址
	char Boss[N1];       //老板
	int  Number;      ///商家的编号
	int  Flage_1;   ///用于标记是否指头结点
	int  Count;   ///用于记录整个单链表一共有多少商家结点
	struct producer * next;          ///指向producer的指针
	struct Menu * next_1;        ///指向Menu的指针
}P_Node;
///菜单信息单链表初始化
Menu_Node * Menu_Init()
{
    Menu_Node * p;
	p=(Menu_Node *)malloc(sizeof(Menu_Node));
	p->next=NULL;      ///头结点中各种数据的初始化
	p->Flage_1=1;
	p->Count=0;
	p->Number=0;
	p->Price=0;
	strcpy(p->Name,"");
	strcpy(p->Shop,"");
	return p;
}
///商家信息单链表初始化函数
P_Node * Shop_Init()
{
	P_Node * p;
	p=(P_Node *)malloc(sizeof(P_Node));
	p->next=NULL;              ///初始长度为0的单链表
	p->next_1=NULL;
	p->Flage_1=1;               ///头结点标志位1
	p->Count=0;

	//char Inout[N1]="";         //头结点各项数据的初始化
	strcpy(p->Adress,"");
	strcpy(p->Boss,"");
	strcpy(p->Name,"");
	strcpy(p->Tele,"");
	p->Number=0;
	return p;
}
///采用尾插法建立菜单单链表
Menu_Node * CreatList_Menu(Menu_Node * head,P_Node * P_head)
{
	printf("\n进入菜单添加功能:\n");
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
	  
	   while(q->next!=NULL)   ///找到单链表的末尾
	   {
		   q=q->next;
	   }
	   q->next=p;
	   head->Count++;
	   flage=0;
	   printf("请输入菜品名称!\n");
	   gets(p->Name);
	   printf("请输入所属商家！\n");
	   gets(p->Shop);
	   ///菜单链表和商家链表链接
	   while(shop!=NULL)
	   {
		   if(strcmp(p->Shop,shop->Name)==0)    ///当两者匹配时
		   {
			   shop->next_1=p;
			   break;
		   }
	      shop=shop->next;
	   }
	   printf("请输入菜品单价！\n");
	   scanf("%d",&p->Price);
	  // getchar();
	   p->Flage_1=0;
	   p->Number=head->Count;
	   p->Count=0;
	   	printf("是否继续添加菜单信息？（y or n）\n");
		scanf(" %c",&choice);
		getchar();
		if(choice=='y')      ///当选择继续添加时
		{
		 flage=1;
		}
	}
	return head;
}
//采用尾插法建立商家单链表
P_Node * CreatList(P_Node * head)
{
	//char Input[N1];
	int flage=1;  ///控制循环的条件
	char choice;      
	char Input[N1];    ///定义输入数组
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
		q->next=p;       ///新生成的节点添加到单链表的末尾
		head->Count++;
		flage=0;
		printf("请输入商家名称！\n");
		gets(p->Name);
		printf("请输入商家电话!\n");
		gets(p->Tele);
		printf("请输入商家地址！\n");
		gets(p->Adress);
		printf("请输入商家老板！\n");
		gets(p->Boss);
	//	printf("请输入商家编号!\n");
	//	scanf("%d",p->Number);
		p->Number=head->Count;      ///商家编号，
		p->Count=0;
		p->Flage_1=0;
		printf("是否继续添加商家？（y or n）\n");
		scanf("%c",&choice);
		getchar();
		if(choice=='y')      ///当选择继续添加时
		{
		 flage=1;
		}
	}
	return head;
}
//打印链表内容
void Show_List(P_Node * head)
{
   P_Node * p=head;
   p=p->next;
   if(p!=NULL)
   {
      printf("\n---------------------------------\n");
	  printf("            商家信息展示\n\n\n");
   }
   while(p!=NULL)
   {
      printf("商家名:     ");
	  puts(p->Name);
	  printf("商家电话:   ");
	  puts(p->Tele);
	  printf("商家地址:   ");
	  puts(p->Adress);
	  printf("商店老板:   ");
	  puts(p->Boss);
	  printf("商家序号:  %d",p->Number);
	  p=p->next;
	  printf("\n\n\n");
   }
   printf("---------------------------------\n");
}
///打印菜单内容
void Show_Menu(Menu_Node * head)
{
   Menu_Node * p=head;
   p=p->next;
   if(p!=NULL)
   {
      printf("\n---------------------------------\n");
	  printf("            菜单信息展示\n\n\n");
   }
   while(p!=NULL)
   {
      printf("菜品名称:     ");
	  puts(p->Name);
	  printf("所属商店:     ");
	  puts(p->Shop);
	  printf("菜品价格：    %d",p->Price);
	  printf("商家序号:  %d",p->Number);
	  p=p->next;
	  printf("\n\n\n");
   }
   printf("---------------------------------\n");
}
//通过店铺查询菜单
void ShopQuery_Menu()
{
   
}
int _tmain(int argc, _TCHAR* argv[])
{
	/*
	P_Node * producer=Shop_Init();
	producer=CreatList(producer);
	system("cls");    ///清屏函数
	Show_List(producer);  
	*/
	Menu_Node * menu=Menu_Init();
	menu=CreatList_Menu(menu,producer);
	system("cls");    ///清屏函数
	Show_Menu(menu);  
	return 0;

}


