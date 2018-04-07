// 线性表的顺序存储结构.cpp : 定义控制台应用程序的入口点。
//
//设循序表的最大长度为100，编程实现顺序表的创建，查找，插入，删除，及合并算法
#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100    //定义顺序表的最大容量
#define ElemType int   ///定义顺序表的存储类型，可自行设定
//顺序存储结构的线性表的类型
typedef struct
{
   ElemType  elem[MAXSIZE];    //存放线性表的数组
   int length;    // length 是线性表的长度
}SeqList;
///顺序表的初始化
SeqList InitList_Seq()
{
   //构造一个空的线性表L
	SeqList L;       //定义一个顺序表
	L.length=0;      //顺序表的长度为0
	return L;   // 返回空的顺序表
}

///顺序表的建立
SeqList CreatList_Seq(SeqList L)
{
    ElemType x;
	scanf(" %d",&x);
	while(x!= -1)      ///存储顺序表的元素
	{
		L.elem[L.length]=x;
		L.length++;
		scanf(" %d",&x);
	}
	return L;
}
///顺序表的插入
SeqList ListInsert_Seq(SeqList L,int i,ElemType x)
{
	///在顺序表L的第i个位置插入元素x
	///先判断顺序表是否满，然后判断i是否在合法范围内，
	int j;
	if(L.length==MAXSIZE)
	{
	   printf("表已经满了\ｎ");
	}
	else if(i<1 ||i>L.length)
	{	
		printf("插入位置错误\n");
	}
	else{
		///第i个位置之后的元素依次后移
		for(j=L.length;j>=i;j--)
		{
			L.elem[j]=L.elem[j-1];
		}
		L.elem[i-1]=x;
		L.length++;
	}
	return L;
}
///查找操作
int LocateElem_Seq(SeqList L,ElemType x)
{
	///在顺序表L中查找x，若找到，返回对应位置。否则，返回0
	int  i=0;
	while(i<=L.length && L.elem[i]!=x)
	{
	  i++;
	}
	if(i<=L.length)  return i+1;
	else return 0;
}
//删除操作
SeqList ListDelete_Seq(SeqList L,int i)
{   ///删除顺序表中的第i个位置的元素
  int j;
  if(i<1 || i>L.length)   //检查删除位置的合法性
  {
    printf(" 删除位置错误\n");
  }
  for(j=i;j<L.length;j++)
  {
	  L.elem[j-1]=L.elem[j];   ///将第i个位置之后的元素前移
  }
  L.length--;
  return L;
}
///合并两个无序的线性表
void MergeList_Seq(SeqList la,SeqList lb)
{
	//已知顺序表la lb无序，首先将la lb的元素按非递减排列，归并la lb 得到新的顺序线性表lc,按非递减排列，然后去掉重复元素
   SeqList lc;
   int i,j,k,t;
   i=j=k=0;
   ///对线性表la 按非递减进行排序
   for(i=0;i<la.length-1;i++)
   {
	   for(j=0;j<la.length-1-i;j++)
	   {
		   if(la.elem[j]>la.elem[j+1])
		   {
			   t=la.elem[j];
			   la.elem[j]=la.elem[j+1];
			   la.elem[j+1]=t;
		   }
	   }
   }
   ///对线性表lb按非递减排序
   for(i=0;i<lb.length-1;i++)
   {
	   for(j=0;j<lb.length-1-i;j++)
	   {
		   if(lb.elem[j]>la.elem[j+1])
		   {
			   t=lb.elem[j];
			   la.elem[j]=la.elem[j+1];
			   la.elem[j+1]=t;
		   }
	   }
   }
   //// 将la与lb合并为线性表lc
   i=0;
   j=0;
   while(i<la.length && j<lb.length)
   {
	   if(la.elem[i]<lb.elem[j])
	   {
		   lc.elem[k++]=la.elem[i++];
	   }
	   else  if(la.elem[i]==lb.elem[j])
	   {
		   lc.elem[k++]=la.elem[i++];
		   j++;
	   }
	   else 
	   {
		   lc.elem[k++]=lb.elem[j++];
	   }
   }
   while(i<la.length)
   {
	   lc.elem[k++]=la.elem[i++];
   }
   while(j<lb.length)
   {
	   lc.elem[k++]=lb.elem[j++];
   }
   lc.length=k;
   printf("合并之后的线性表顺序为：\n");
   for(i=0;i<lc.length;i++)
   {
	   printf(" %d ",lc.elem[i]);
   }
   printf("合并之后的线性表的长度为：%d \n",lc.length);
}
void meun()
{
	printf("\n\n");
   printf("*************************************\n");
	printf("		1---创建第一个顺序表和第二个顺序表\n");
	printf("		2---按值查找元素（第一个顺序表）\n");
	printf("		3---插入元素（第一个顺序表）\n");
	printf("		4---按位置删除元素（第一个顺序表）\n");
	printf("		5---合并两个顺序表\n");
	printf("		6---退出\n");
	printf("*************************************\n");
}
int _tmain(int argc, _TCHAR* argv[])
{
	SeqList seqlist,Lb;
	int i,k=0;
	ElemType x;
	int flage=0;   ///标志位用于控制创建两个表
	while(k!=6)
	{
	   meun();
	   printf("请选择相应操作:\n");
	   scanf("%d",&k);
	   getchar();
	   /////////
	   
	   switch(k)
	   {
	   case 1:
		   if(flage==1)
		   {
			   printf("\n 已经创建成功了两个表，是否重新创建两个表？（y or n）");
		       char choice;
			   scanf("%c",&choice);
			   getchar();
			   if(choice=='y' || choice=='Y')
			   {
			        seqlist=InitList_Seq();
		            printf("创建第一个顺序表，输入顺序表的元素，-1代表结束:\n");
					seqlist=CreatList_Seq(seqlist);
					printf("第一个顺序表的元素为：");
					for(i=0;i<seqlist.length;i++)
						{
							 printf(" %d ",seqlist.elem[i]);
						}
				   printf("\n 顺序表的长度为: %d\n",seqlist.length);
				   Lb=InitList_Seq();
				   printf("创建第二个顺序表，输入顺序表的元素，-1带表结束:\n");
				   Lb=CreatList_Seq(Lb);
				   printf("第二个顺序表的元素为：");
				   for(i=0;i<Lb.length;i++)
					   printf(" %d ",Lb.elem[i]);
				   printf("\n 顺序表的长度为：%d\n",Lb.length);
				   flage=1;
			   }
			  // else if(choice=='n' || choice=='N')
				 
		   }
		   if(flage==0){
		   seqlist=InitList_Seq();
		   printf("创建第一个顺序表，输入顺序表的元素，-1代表结束:\n");
		   seqlist=CreatList_Seq(seqlist);
		   printf("第一个顺序表的元素为：");
		   for(i=0;i<seqlist.length;i++)
		   {
			   printf(" %d ",seqlist.elem[i]);
		   }
		   printf("\n 顺序表的长度为: %d\n",seqlist.length);
		   Lb=InitList_Seq();
		   printf("创建第二个顺序表，输入顺序表的元素，-1带表结束:\n");
		   Lb=CreatList_Seq(Lb);
		   printf("第二个顺序表的元素为：");
		   for(i=0;i<Lb.length;i++)
			   printf(" %d ",Lb.elem[i]);
		   printf("\n 顺序表的长度为：%d\n",Lb.length);
		   flage=1;
		   }
		   break;
	   case 2:
		   printf("请输入要查找元素的值（第一个顺序表）:");
		   scanf("%d",&x);
		   i=LocateElem_Seq(seqlist,x);
		   if(i)
			   printf("在顺序表中的位置为：%d\n",i);
		   else
			   printf("没有找到");
		   break;
	   case 3:
		   printf("请输入插入元素位置（第一个顺序表）：");
		   scanf("%d",&i);
		   printf("请输入插入元素的值：");
		   scanf("%d",&x);
		   seqlist=ListInsert_Seq(seqlist,i,x);
		   printf("第一个顺序表元素为：");
		   for(i=0;i<seqlist.length;i++)
		   {
			   printf(" %d",seqlist.elem[i]);
		   }
		   printf("\n  表的长度为：%d\n",seqlist.length);
		   break;
	   case 4:
		   printf("请输入删除元素位置（第一个顺序表）\n");
		   scanf("%d",&i);
		   seqlist=ListDelete_Seq(seqlist,i);
		   printf("第一个顺序表元素为：");
		   for(i=0;i<seqlist.length;i++)
		   {
			   printf(" %d",seqlist.elem[i]);
		   }
		   printf("\n 表的长度为： %d\n",seqlist.length);
		   break;
	   case 5:
		   MergeList_Seq(seqlist,Lb);
		   break;
	   case 6:
		   exit(0);
	   }
	}
	return 0;
}
