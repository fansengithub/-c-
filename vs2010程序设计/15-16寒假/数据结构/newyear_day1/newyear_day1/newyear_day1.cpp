// newyear_day1.cpp : 定义控制台应用程序的入口点。
//
//编程实现：一个数组a中存放着两个线性顺序表，实现利用最少的辅助存储空间，将数组中的两个线性表置换
#include "stdafx.h"
#include<stdlib.h>
#include<stdio.h> 
#define MAXSIZE 100    ///定义顺序表的最大存储空间
#define ElemType  int    ///定义顺序表的存储类型，可以改变
typedef struct 
{
  ElemType  elem[MAXSIZE];    ///存放线性表的内容
  int   length;   //  线性表的长度
}SeqList;
///函数功能：线性表的初始化,即构造一个空的线性表
SeqList InitList_Seq()
{
	 SeqList L;
	 L.length=0;
	 return L;
}
///函数功能：顺序表的建立,给顺序表中的元素赋值
SeqList CreatList_Seq(SeqList L)
{
   ElemType x;
   scanf("%d",&x);
   while(x!=-1)
   {
	   L.elem[L.length]=x;
	   L.length++;
	   scanf("%d",&x);
   }
   return L;
}
///函数功能：用交换排序法将两类线性表交换   例如a1a2a3...amb1b2b3..bn
void  Exchange1(SeqList L,int m,int n)
{
   int i,j,w;
   for(i=1;i<=n;i++)
   {
	   w=L.elem[m+i];
	   for(j=m+i-1;j>=i-1;j--)
		   L.elem[j+1]=L.elem[j];
	   L.elem[i-1]=w;
   }
 

   printf("\n前插法之后线性表的元素为:\n");
   for(i=0;i<n;i++)
	   printf("%d ",L.elem[i]);
   for(i=n;i<L.length-1;i++)
	   printf("%d ",L.elem[i]);
   printf("\n第一个表的长度为%d\n",n);
   printf("\n第二个表的长度为%d\n",m);
}
///函数功能：是顺序表中的元素逆置
void invert(SeqList *s,int m,int n)
{
    int i,k,x;
	for(i=m;i<(n+1+m)/2;i++)
	{
		x=s->elem[i];
		s->elem[i]=s->elem[n+m-i];
		s->elem[n+m-i]=x;
	}
}
///函数功能：利用逆置方法实现第二种变换
void Exchange2(SeqList * s,int m,int n)
{ 
    int i;
	invert(s,0,n+m);
	invert(s,0,n-1);
	invert(s,n+1,n+m);
	printf("\n 逆置之后的线性表为\n");
	for(i=0;i<n;i++)
		printf("%d ",s->elem[i]);
	for(i=n+1;i<s->length;i++)
		printf("%d ",s->elem[i]);
	printf("\n第一个表的长度为：%d\n",n);
	printf("\n第二个表的长度为：%d\n",m);
}
int _tmain(int argc, _TCHAR* argv[])
{
	SeqList seqlist,*p;
	int i,k,h;
	ElemType x;
	seqlist=InitList_Seq();
	printf("已经创建一个顺序表，请输入表中元素:\n");
	seqlist=CreatList_Seq(seqlist);
	p=&seqlist;
	for(i=0;i<seqlist.length;i++)
	{
		if(seqlist.elem[i]==0)   ///第一个顺序表输入结束
			   k=i;
	}
	printf("\n第一个顺序表的元素为\n");
	for(i=0;i<k;i++)
	{
		printf("%d ",seqlist.elem[i]);
	}
	printf("\n第一个顺序表的长度为：%d",k);
	printf("\n第二个顺序表的元素为\n");
	for(i=k+1;i<seqlist.length;i++)
	{
		printf("%d",seqlist.elem[i]);
	}
	h=seqlist.length-k-1;
	printf("\n第二个顺序表的长度为：%d",h);



	Exchange1(seqlist,k,h);
	Exchange2(p,k,h);
	printf("\n------------------\n");
	for(i=0;i<seqlist.length;i++)
	{
		printf("%d ",seqlist.elem[i]);
	}
	printf("\n-ttttttttttttttttttttt-----------\n");
	for(i=0;i<p->length;i++)
	{
		printf("%d ",(*p).elem[i]);
	}
	return 0;
}

