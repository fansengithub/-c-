// 头插法尾差法——线性单链表.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef int ElemType;
//定义节点类型
typedef struct Lnode
{
    ElemType  data;   //单链表数据域
	struct Lnode  * next;   ///单链表指针域
}Lnode,*LinkList;

///单链表的初始化
LinkList LinkListInit()
{
  Lnode * L;
  L=(Lnode *)malloc(sizeof(Lnode));  //申请节点空间
  if(L==NULL)                        ///判断是否有足够的内存空间
	  printf("申请内存失败！\n");
  L->next=NULL;
  return L;
}

///单链表的建立 1，头插法建立单链表
LinkList CreatList_H()
{
   Lnode  *L;
   ElemType  x;				///x为链表数据域的数据
   L=(LinkList)malloc(sizeof(Lnode));
   L->next=NULL;
   scanf("%d",&x);
   while(x!= -1)      ///初始化一个空链表
   {
      Lnode  *p;
	  p=(LinkList)malloc(sizeof(Lnode));  //申请新的节点
	  p->data=x;
	  p->next=L->next;      ///将节点插入到表头
	  L->next=p;
	  scanf("%d",&x);
   }
   return L;
}
////单链表的建立，2--尾插法建立单链表
LinkList  CreatList_T()
{
   Lnode *L,*r,*p;
   ElemType x;      ///链表数据域中的数据
   L=(Lnode *)malloc(sizeof(Lnode));
   L->next=NULL;    ///初始化一个空链表
   r=L;				//r始终指向终端节点，开始时，指向头节点
   scanf(" %d",&x);
   while(x!= -1)
   {
      p=(Lnode *)malloc(sizeof(Lnode));
	  p->data=x;
	  r->next=p;
	  r=p;
	  scanf("%d",&x);
   }
   r->next=NULL;
   return L;
}

///单链表的查找，在带头节点的单链表中查找位置号为i的元素
int  GetElem(LinkList L,int i)
{
	 int j;
	 LinkList  p;
	 p=L;j=0;
	 while(p->next && j<i)
	 {
		 p=p->next;
		 j++;
	 }
	 if(j==i)  return p->data;
	 else  return -1;
}

///单链表的查找，按值查找
int Locate_L(LinkList L,ElemType e)
{
  LinkList p;
  int i=1;
  p=L->next;
  while(p)
  {
	  if(p->data==e) return i;
	  else p=p->next;
	  i++;
  }
  return -1;
}

///单链表的插入，在链表的i位置插入x元素
LinkList LinkList_L(LinkList L,int i,ElemType x)
{
   Lnode * pre,*p;    ///pre 为前驱节点，插入的节点为 p
   int j=0;
   pre=L;
   for(j=1;j<i;j++)
	   pre=pre->next;
   p=(Lnode *)malloc(sizeof(Lnode));
   p->data=x;
   p->next=pre->next;
   pre->next=p;
   return L;
}

//单项链表的删除操作，删除带头结点的单链表L中的i个元素，并由e返回其值
LinkList ListDelete_L(LinkList L,int i,ElemType e)
{
   Lnode *p,*s,*q;
   int j=0;
   int k=0;
   q=L;
   while(q)
   {
	   q=q->next;
	   k++;
   }
   if(i<1||i>k)  
	   return NULL;   ///检查i值是否合理
   for(p=L;j<i-1&&p->next!=NULL;j++)    ///寻找第i-1个节点
	   p=p->next;
   s=p->next;
   p->next=s->next;   ///删除s所指向的节点
   e=s->data;
   free(s);       ///释放被删除的节点空间
   return L;
}
int _tmain(int argc, _TCHAR* argv[])
{
	LinkList list,start,p,list1;
	int i,k,m,n;
	ElemType x;
	printf("使用头插法创建第一个单链表，请输入单链表数据：\n");
	list=CreatList_H();
	for(start=list->next;start!=NULL;start=start->next)
		printf(" %d ",start->data);
	printf("\n");
	printf("使用尾插法创建第二个单链表，请输入单链表数据：\n");
	list1=CreatList_T();
	for(start=list1->next;start!=NULL;start=start->next)
		printf(" %d ",start->data);
	printf("\n");
	printf("请输入要查询元素的位置号（第一个单链表）:\n");
	scanf("%d",&k);
	m=GetElem(list,k);
	if(m== -1)  printf("输入的位置号错误！");
	else printf("第%d个位置对应的元素为：%d\n",k,m);
	printf("请输入要查找的元素值！（第一个单链表）\n");
	scanf("%d",&k);
	m=Locate_L(list,k);
	if(m== -1)  printf("对不起，没有找到！\n");
	else printf("所要查找数据元素的位置号为：%d\n",m);
	printf("请输入插入数据元素的位置（第一个单链表）!\n");
	scanf("%d",&i);
	printf("请输入插入数据的值：\n");
	scanf("%d",&x);
	LinkList_L(list,i,x);
	printf("插入操作完成值后，链表的数据元素为：\n");
	for(start=list->next;start!=NULL;start=start->next)
		printf("%d ",start->data);
	printf("\n");
	printf("请输入将要删除元素的位置（第一个单链表):");
	scanf("%d",&x);
	ListDelete_L(list,x,m);
	printf("删除指定位置元素之后的单链表为：");
	for(start=list->next;start!=NULL;start=start->next)
		printf("%d ",start->data);
	printf("\n");
	return 0;
}

