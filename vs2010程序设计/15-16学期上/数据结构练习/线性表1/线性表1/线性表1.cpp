// 线性表1.cpp : 定义控制台应用程序的入口点。
//
//顺序表的最大长度为100，编程实现顺序表的创建，查找，插入，删除，及合并算法。
#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100   ///定义顺序表的最大容量
typedef struct 
{
  int elem[MAXSIZE];
  int length;
}SeqList;

//顺序表的初始化
SeqList InitList_Seq()
{
   SeqList L;
   L.length=0;
   return L;
}

////顺序表的建立
SeqList CreateList_Seq(SeqList L)
{
  int x;
  scanf("%d",&x);
  while(x!=-1){
	  L.elem[L.length]=x;
	  L.length++;
	  scanf("%d",&x);
  }
  return  L;
}
///顺序表的插入
SeqList ListInsert_Seq(SeqList L,int i,int x){
	int j;
	if(L.length==MAXSIZE)
	{
	   printf("顺序表已满");
	}
	else if (i<1||i>L.length)
	{
	  printf("插入位置出错");
	}
	else
	{
		for(j=L.length;j>=i;j--)
		{
			L.elem[j]=L.elem[j-1];
		}
		L.elem[j-1]=x;
		L.length++;
		return L;
	}
}

///查找算法
int LocateElem_Seq(SeqList L,int x)
///在线性表L中找到元素值为x的数据元素，如果找到则返回该元素的位置，否则返回0
{
   int  i=0;
   while(i<=L.length&&L.elem[i]!=x){
     i++;
   }
   if(i<=L.length)   return i+1;
   else return 0;
}

//函数功能：合并算法
//已知线性表la与lb无序，先将他们排序，然后合并为一新表，并去掉重复的元素
SeqList MergeList_Seq(SeqList la,SeqList lb)
{
  int i,j,k;
  ///首先将la lb 分别非递减排序
  for(i=0;i<la.length-1;i++)
  {
	  for(j=0;j<la.length-i-1;j++)
	  {
		  if(la.elem[j]>la.elem[j+1])
		  {
			  k=la.elem[j];
			  la.elem[j]=la.elem[j+1];
			  la.elem[j+1]=k;
		  }
	  }
  }

  ////lb排序
    for(i=0;i<lb.length-1;i++)
  {
	  for(j=0;j<lb.length-i-1;j++)
	  {
		  if(lb.elem[j]>lb.elem[j+1])
		  {
			  k=lb.elem[j];
			  lb.elem[j]=lb.elem[j+1];
			  lb.elem[j+1]=k;
		  }
	  }
  }
	///合并la,lb两个表
	i=0;j=0;
	k=0;
	SeqList lc=InitList_Seq();
	while(i<la.length&&j<lb.length)
	{
		if(la.elem[i]<lb.elem[j])
		{
			lc.elem[k++]=la.elem[i++];   
		}
		else if(la.elem[i]=lb.elem[j])
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
	printf("合并之后的顺序表为\n");
	for(i=0;i<lc.length;i++)
		printf("%d ",&lc.elem[i]);
	printf("合并之后的表长度为：\n");
	printf("%d",&lc.length);
} 
///exchange 算法
//已知一线性表中含有A1.A2.A3。。。AN，b1.b2...bn,设计算法将线性表变为b1.b2.b3...bn,a1.a2.a3
void Exchange1(SeqList s,int m,int n)
{
	int k;
	int j;
	int w;
   for(k=1;k<=n;k++)
   {
	   w=s.elem[m+k-1];
	   for(j=m+k-1;j>=k;j--)
		   s.elem[j+1]=s.elem[j];
	   s.elem[k-1]=w;
   }
}
int _tmain(int argc, _TCHAR* argv[])
{
	SeqList seqlist,lb;
	int i,k;
	i=0;
	k=0;
	printf("*****************************\n");
	printf("1----创建第一个顺序表和第二个顺序表\n");
	printf("2----按值查找（第一个顺序表）\n");
	printf("3----插入元素（第一个顺序表）\n");
	printf("4----按位置删除元素（第一个元素）\n");
	printf("5----合并两个顺序表\n");
	printf("6----退出");
	while(k!=6)
	{
	   printf("请输入相关操作选项\n");
	   scanf("%d",&k);
	   switch(k)
	   {
	   case 1:

	   case 2:
	   case 3:
	   }
	}
	return 0;
}

