// 线性表置换.cpp : 定义控制台应用程序的入口点。
//
///  函数功能：已知数组中存放这两个线性表，设计一个算法，用尽可能少的辅助空间将数组中的两个线性表的位置互换，实现（a1,a2,a3,a4）,(b1,b2,b3,b4)-->(b1,b2,b3,b4),（a1,a2,a3,a4)
//
//两种算法   1---前插算法   2---逆置算法
#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100      ///定义顺序表的最大容量
#define ElemType  int     ///敌营顺序表的存储类型，可自行设置
typedef struct
{
   ElemType elem[MAXSIZE];    ///存放线性表的数组
   int length;   ///线性表的长度
}SeqList;

///顺序表的初始化
SeqList InitList_Seq()
{
  ///构造一个空的线性表，时间复杂度为0（1）
	SeqList L;
	L.length=0;
	return L;
}
///顺序表的建立
SeqList CreatList_Seq(SeqList L)
{
  ElemType x;
  scanf("%d",&x);
  while(x!= -1)
  {
	  L.elem[L.length]=x;
	  L.length++;
	  scanf("%d",&x);
  }
  return L;
}
////置换算法1：前插入算法，
void Exchange1(SeqList  s,int m,int n)
{
   int i,j,w;
   //首先用w保存一个元素，然后依次将前面的元素后移一位，最后插入w
   for(i=0;i<n;i++)
   {
	   w=s.elem[i+m+1];
	   for(j=m+i-1;j>=i;j--)
	   {
		   s.elem[j+1]=s.elem[j];
	   }
	   s.elem[i]=w;
   }
   printf("前插法之后的线性表元素为：\n");
   for(i=0;i<n;i++)
   {
	   printf(" %d",s.elem[i]);
   }
   for(i=n;i<s.length-1;i++)
   {
	   printf(" %d",s.elem[i]);
   }
   printf("\n 第一个顺序表的长度为： %d \n",n);
   printf("\n 第二个顺序表的长度为： %d\n",m);
}
void invert(SeqList * s,int m,int n)
{
    int i,k,x;
	for(i=m;i<(n+1+m)/2;i++)
	{
		x=s->elem[i];
		s->elem[i]=s->elem[n+m-i];
		s->elem[n+m-i]=x;
	}
}

///置换算法2：
void Exchange2(SeqList  *s,int m,int n)
{
   int i;
   invert(s,0,n+m);
   invert(s,0,n-1);
   invert(s,n+1,n+m);
   printf("\n 置换交换之后线性表元素为：");
     for(i=0;i<n;i++)
	 {
		 printf(" %d ",s->elem[i]);
	 }
	 for(i=n+1;i<s->length;i++)
		 printf(" %d ",s->elem[i]);
	 printf("\n第一个表的长度为：  %d\n",n);
	 printf("第二个表的长度为： %d\n",m);
}
int _tmain(int argc, _TCHAR* argv[])
{
	SeqList  seqlist, *p;
	int i,k,h;
	ElemType  x;
	seqlist=InitList_Seq();
	printf("创建一个顺序表，请输入顺序表的元素：  \n");
	seqlist=CreatList_Seq(seqlist);
	p=&seqlist;
	for(i=0;i<seqlist.length;i++)
	{
		if(seqlist.elem[i]==0)    ///当值为0时，代表第一个顺序表输入结束
			k=i;    ///用k记录数组中，第一个顺序表元素的个数
	}
	printf("第一个线性表元素为：\n");
	for(i=0;i<k;i++)
	{
		printf(" %d ",seqlist.elem[i]);
	}
	printf("\n表的长度为： %d\n",k);
	printf("第二个线性表元素为： \n");
	for(i=k+1;i<seqlist.length;i++)
		printf(" %d ",seqlist.elem[i]);
	h=seqlist.length-k-1;    ///代表第二个顺序表中元素个数
	printf("\n表的长度为为：%d\n ",h);
	Exchange1(seqlist,k,h);
	Exchange2(p,k,h);
	return 0;
}

