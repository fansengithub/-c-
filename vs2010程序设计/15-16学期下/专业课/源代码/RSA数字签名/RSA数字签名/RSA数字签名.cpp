// RSA数字签名.cpp : 定义控制台应用程序的入口点。
//
// My_RSA.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
///    RSA数字签名与RSA加密解密的区别 ：  加密解密中的  e---d   与签名中   e----d  换位
int gcd(int a,int b);
///函数功能：WITNESS算法的实现，判断一个数是否为素数
int  Witness(int a,int n)   ///判断N是否为素数，a是小于n的某个整数
{
  char bin[1000];
  int k=0;			///用于记录2进制的长度
  int temp=0;
  temp=n-1;
  itoa(temp,bin,2);    ///将temp--(n-1)转化为2进制
  strrev(bin);          ///翻转字符串
  k=strlen(bin);
  int d,i,x;
  d=i=x=0;
  d=1;
  for(i=(k-1);i>=0;i--)
  {
      x=d;
	  d=(d*d)%n;		//实现mod功能
	  if(d==1 && x!=1 && x!=(n-1))
	  {
	     return 1;
	  }
	  if(bin[i]=='1')				///注意：bin中2进制的顺序 当 n-1==12 bin中为 0011----非1100
	  {
	    d=(d*a)%n;
	  }
  }
  if(d!=1)  return 1;
  return 0;
}
///函数功能：利用扩展的欧几里得算法计算解密密钥d----e的逆元
int  Euclid(int a,int b,int &x,int &y)
{
   if(b==0)
   {
      x=1;
	  y=0;
   }
   else
   {
     int x1;
	 int y1;
	 int d=Euclid(b,a%b,x1,y1);
	 x=y1;
	 y=x1-a/b*y1;
	 return x;
   }
}
////函数功能：实现快速取模指数算法
/*
int Result_Mod(int a,int b,int n)
{
   int  c=0;
   int d=1;
   char bin[1000];
   int k=0;
   itoa(n,bin,2);       ///将N转化为2进制
   strrev(bin);          ///翻转字符串
   k=strlen(bin);            ////k记录字符串的长度
   for(int i=k;i<=0;i--)
   {
     c=2*c;
	 d=(d*d)%n;
	 if(bin[i]==1)
	 {
	    c=c+1;
		d=(d*a)%n;
	 }
   }
    printf("************** %d   ",d);
   return d;
  
}    */
////函数功能：实现快速取模指数算法
int  Result_Mod(int a,int b,int n)
{
  int ret=1;             ////实现原理：   a*b%c <====>  ((a%c)*b)%c     所以   a*a*a*a%c ==  (((((a%c)*a)%c)*a%c)*a%c)
  while(b--)
  {
    ret=a*ret%n;
  }
      //printf("************** %d   ",ret);
  return ret;
}
////函数功能：产生密钥
int  Creat_Key(int p,int q)
{
  int n,m;
  int i,e,j;
  n=p*q;
  m=(p-1)*(q-1);					
  for(i=2;i<n;i++)				///找到与m互素的e
  {
     j=gcd(i,m);
	 if(j==1)   return i;				///当j==1时，代表i  m的最大公约数是1，，，互素
  }

}

///函数功能：求两个数的最大公约数
int gcd(int a,int b)
{
   if(a==0)
   {
     return b;
   }
   else
   {
     return gcd(b % a,a);
   }
}
int _tmain(int argc, _TCHAR* argv[])
{
	/*
	int temp;
	int k=0;
	char bin[1000];
	printf("请输入将要转换为2进制的初始整数！\n");
	scanf("%d",&temp);
	itoa(temp,bin,2);
	printf("2进制为：%s\n",bin);
	k=strlen(bin);
	printf("---%d",k);  */

	/*
	    // 若改为 char *str1 = "abcxyz";，程序在运行时会崩溃
    char str1[] = "abcxyzw";
	printf("The origin string of str1 is: %s\n", str1);
     strrev(str1);
    
    printf("The reverse string of str1 is: %s\n", str1);  */

	int a,n,r;
	int p,q;
	p=q=0;
	a=n=r=0;
	int array_0[5]={10,12,15,9,20};
	int array_1[5];
	do{
	printf("请输入第一个将要判断整数的值：\n");
	scanf("%d",&n);
	a=n-1;
	r=Witness(a,n);
	if(r==1) 
		{
			printf("%d一定不是素数！\n",n);
	       
	    }
	else 
		{
			printf("%d可能是素数！\n",n);   
	         p=n;
	    }
	p=n;
	}while(r==1);

	do{
	printf("请输入第2个将要判断整数的值：\n");
	scanf("%d",&n);
	a=n-1;
	r=Witness(a,n);
	if(r==1) 
		{
			printf("%d一定不是素数！\n",n);
	    }
	else 
		{
			printf("%d可能是素数！\n",n);   
	         q=n;
	    }
	q=n;
	}while(r==1);
	
	int e=Creat_Key(p,q);
	int m=(p-1)*(q-1);
	n=p*q;
	//int e=13;
	int x=0,y=0;
	int d=Euclid(e,m,x,y);        //// 利用扩展的欧几里得算法求解e的逆元
	printf("e=%d,d=%d",e,d);
	printf("\n\nRSA签名后为：\n");
	for(int i=0;i<5;i++)
	{
	   int result=Result_Mod(array_0[i],d,n);
	   array_1[i]=result;
       printf("%d ",result);
	}
	printf("\n\nRSA解密结果为:\n");
	for(int i=0;i<5;i++)
	{
	     int result=Result_Mod(array_1[i],e,n);
		 printf("%d ",result);
	}
	return 0;
}

