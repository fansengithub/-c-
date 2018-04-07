// SeqList.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
///线性表的创建，查找，插入，删除，合并操作
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100     ///定义现行表存储的最大容量
#define  ElemTye int     ///定义顺序表存储的类型
///顺序存储结构线性表
typedef struct
{
   ElemTye  elem[MAXSIZE];     ///存放线性表的数组
   int length;                 ///线性表的长度
}SeqList;
///顺序表的初始化    sequence 顺序表   list 线性
SeqList InitList_Seq()         ///构造一个空的线性表
{
    SeqList    L;
    L.length=0;
    return L;
}

///顺序表的建立,并存入表中元素
SeqList  CreatList_Seq(SeqList L)
{
    ElemTye  x;
    scanf("%d",&x);
    while(x!=-1)
    {
      L.elem[L.length]=x;
      L.length++;
      scanf("%d",&x);
    }
    return L;
}

///顺序表的插入操作,向表L的i位置插入元素x
SeqList   ListInsert_Seq(SeqList L,int i,ElemTye x)
{
   int  j;
   if(L.length==MAXSIZE)                   ///进行合理性检查
    printf("线性表已经放满。");
   else if(i<1||i>L.length)
    printf("插入位置错误！");
   else
    {
        for(j=L.length;j>=i;j--)      ///顺序表的第i个元素，依次后移
        {
           L.elem[j]=L.elem[j-1];
        }
        L.elem[i-1]=x;
        L.length++;
    }
    return L;
}
///顺序表的查找操作--
//-查找给定线性表L中的给定值x，若找到，则返回元素所在为置，否则，返回0
int  LocateElem_Seq(SeqList L,ElemTu)
{
	int i=0;
	while(i<=L.length)
	return 0;
}
///打印线性表中元素
void  Show_SeqList(SeqList L)
{
    printf("当前表中元素为：\n");
    for(int i=0;i<L.length;i++)
    {
        printf(" %d",L.elem[i]);
    }
    printf("\n当前线性表的长度为： %d\n",L.length);
}
///打印菜单函数
void Menu()
{
     printf("\n******************************\n");
   printf("    1---创建一个线性表\n");
   printf("    2---插入元素\n");
   printf("    3---退出\n");
   printf("******************************\n");
}
/*
///c语言实参，形参，值传递验证
#include<stdio.h>
void fun(int x,int y)
{
   int tmp;
   tmp=x;
   x=y;
   y=tmp;
   printf("x = %d,y = %d\n",x,y);
}
int main()
{
   int a,b;
        ///!!!!!!!!!!!!!!!!!!
   printf("请输入一个整数 a!\n");
   scanf("%d",&a);
   printf("请输入一个整数 b!\n");
   scanf("%d",&b);
   printf("运行fun()之前：\n");
   printf("a = %d,b = %d\n",a,b);
   printf("运行fun()之后：\n");
   fun(a,b);
    printf("a = %d,b = %d",a,b);
   return 0;
}  */


int _tmain(int argc, _TCHAR* argv[])
{
	 SeqList seqlist;
   int k=0;
    int x,y;    ///插入元素将要用到。
    x=y=0;
   while(k!=3)
   {
     Menu();
     printf("请输入将要执行操作对应序号!\n");
     scanf("%d",&k);
     switch(k)
     {
       case 1:
       seqlist=InitList_Seq();
       printf("创建一个顺序表，输入顺序表中元素，-1代表输入结束：\n");
       seqlist=CreatList_Seq(seqlist);
       Show_SeqList(seqlist);
       break;
       case 2:
        printf("请输入将要插入元素的值！\n");
        scanf("%d",&x);
        printf("请输入将要插入的位置!\n");
        scanf("%d",&y);
        seqlist=ListInsert_Seq(seqlist,y,x);
        Show_SeqList(seqlist);
        break;
        case 3: exit(0);
     }
   }
   return 0;
	
}

