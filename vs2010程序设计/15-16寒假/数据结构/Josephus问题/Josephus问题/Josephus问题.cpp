// Josephus问题.cpp : 定义控制台应用程序的入口点。
//约瑟夫环问题

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#define FALSE 0
#define TRUE  1
typedef int DataType;
//结构体声明
typedef struct SeqList
{
  int MAXNUM;				//顺序表中的最大元素个数
  int n;					//存放线性表中元素个数  n<=MAXNUM
  DataType * elem;			//elem[0],elem[1],elem[2],....elem[n-1]存放线性表中的元素
}* PSeqList;
//typedef struct SeqList  *  PSeqList;
///函数功能：创建新的顺序表
PSeqList  createNullList_seq(int m)
{
     PSeqList palist=(PSeqList)malloc(sizeof(struct SeqList));
	 if(palist!=NULL)
	 {
		 palist->elem=(DataType *)malloc(sizeof(DataType) * m);
		 if(palist->elem)
		 {
			 palist->MAXNUM=m;
			 palist->n=0;
			 return palist;
		 }
		 else
			 free(palist);
	 }
	 printf("Out of space!!\n");		//分配内存失败
	 return NULL;
}
///判断palist所指向的顺序表是否为空表

int IsNullList_seq(PSeqList palist)
{
	return (palist->n==0);
}
///求x在palist所指顺序表中的下标
int locate_seq(PSeqList palist,DataType x)
{
	int q;
	for(q=0;q<palist->n;q++)
	{
		if(palist->elem[q]==x)
			return q;
	}
	return -1;
}
//函数功能：在palist所指向的顺序表中，下标为p的元素之前插入x
int insertPre_seq(PSeqList palist,int p,DataType x)
{
	int q;
	if(palist->n>=palist->MAXNUM)		//溢出处理
	{
	   printf("Overflow!\n");
	   return 0;
	}
	if(IsNullList_seq(palist))			///如果palist指向空表,空顺序表插入
	{
		palist->elem[0]=x;				///插入元素x
		palist->n=1;					///元素个数修改为1
		return 1;    
	}
	if(p< 0||p>palist->n)				///如果不存在下标为p的元素!
	{
	   printf("No exit !\n");
	   return 0;
	}
	for(q=palist->n-1;q>=p;q--)			///在插入位置及之后的元素均后移一个位置
	{
		palist->elem[q+1]=palist->elem[q];
	}
	palist->elem[p]=x;					///插入元素
	palist->n=palist->n+1;				///元素个数加1
    return 1;
}
///函数功能：在palist所指顺序表中删除下标为p的元素
int deleteP_seq(PSeqList palist,int p)
{
  int q;
  if(p<0 ||p>palist->n-1)			//p的合法性判断
  {
    printf("Not exist!\n");
	return 0;
  }
  for(q=p;q<palist->n-1;q++)		//被删除元素之后的元素均向前移动一个位置
  {
	  palist->elem[q]=palist->elem[q+1];
  }
  palist->n=palist->n-1;
  return 1;
}
///约瑟夫环主函数的实现
void  josephus_seq(PSeqList palist,int  s,int m)
{
    int s1,i,w;
	s1=s-1;
	for(i=palist->n;i>0;i--)
	{
	  ///找出列的元素
		s1=(s1+m-1)%i;
		w=palist->elem[s1];			//求出下标为s1元素的值
		printf("Out element %d \n",w);		//打印出输出的元素
		deleteP_seq(palist,s1);				//删除输出的元素

	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	PSeqList jos_alist;
	int i;
	int  n,s,m;				///一共n个人，现从第s个人开始报数，数到第m个人出列,然后从下一个人从新开始报数，数到第m个人，又出列
	printf("\n  Please input the  values of n  (<100)\n");
	scanf("%d",&n);
	printf("\n Please input the values of s  \n");
	scanf("%d",&s);
	printf("\n Please input the values of m \n");
	scanf("%d",&m);
	jos_alist=createNullList_seq(n);			///创建空的顺序表
	if(jos_alist!=NULL)
	{
	   for(i=0;i<n;i++)						//线性表赋值
		   insertPre_seq(jos_alist,i,i+1);
	   josephus_seq(jos_alist,s,m);
	   free(jos_alist->elem);
	   free(jos_alist);
	}
	return 0;
}

