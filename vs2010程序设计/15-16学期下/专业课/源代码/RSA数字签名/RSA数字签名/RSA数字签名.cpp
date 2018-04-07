// RSA����ǩ��.cpp : �������̨Ӧ�ó������ڵ㡣
//
// My_RSA.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
///    RSA����ǩ����RSA���ܽ��ܵ����� ��  ���ܽ����е�  e---d   ��ǩ����   e----d  ��λ
int gcd(int a,int b);
///�������ܣ�WITNESS�㷨��ʵ�֣��ж�һ�����Ƿ�Ϊ����
int  Witness(int a,int n)   ///�ж�N�Ƿ�Ϊ������a��С��n��ĳ������
{
  char bin[1000];
  int k=0;			///���ڼ�¼2���Ƶĳ���
  int temp=0;
  temp=n-1;
  itoa(temp,bin,2);    ///��temp--(n-1)ת��Ϊ2����
  strrev(bin);          ///��ת�ַ���
  k=strlen(bin);
  int d,i,x;
  d=i=x=0;
  d=1;
  for(i=(k-1);i>=0;i--)
  {
      x=d;
	  d=(d*d)%n;		//ʵ��mod����
	  if(d==1 && x!=1 && x!=(n-1))
	  {
	     return 1;
	  }
	  if(bin[i]=='1')				///ע�⣺bin��2���Ƶ�˳�� �� n-1==12 bin��Ϊ 0011----��1100
	  {
	    d=(d*a)%n;
	  }
  }
  if(d!=1)  return 1;
  return 0;
}
///�������ܣ�������չ��ŷ������㷨���������Կd----e����Ԫ
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
////�������ܣ�ʵ�ֿ���ȡģָ���㷨
/*
int Result_Mod(int a,int b,int n)
{
   int  c=0;
   int d=1;
   char bin[1000];
   int k=0;
   itoa(n,bin,2);       ///��Nת��Ϊ2����
   strrev(bin);          ///��ת�ַ���
   k=strlen(bin);            ////k��¼�ַ����ĳ���
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
////�������ܣ�ʵ�ֿ���ȡģָ���㷨
int  Result_Mod(int a,int b,int n)
{
  int ret=1;             ////ʵ��ԭ��   a*b%c <====>  ((a%c)*b)%c     ����   a*a*a*a%c ==  (((((a%c)*a)%c)*a%c)*a%c)
  while(b--)
  {
    ret=a*ret%n;
  }
      //printf("************** %d   ",ret);
  return ret;
}
////�������ܣ�������Կ
int  Creat_Key(int p,int q)
{
  int n,m;
  int i,e,j;
  n=p*q;
  m=(p-1)*(q-1);					
  for(i=2;i<n;i++)				///�ҵ���m���ص�e
  {
     j=gcd(i,m);
	 if(j==1)   return i;				///��j==1ʱ������i  m�����Լ����1����������
  }

}

///�������ܣ��������������Լ��
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
	printf("�����뽫Ҫת��Ϊ2���Ƶĳ�ʼ������\n");
	scanf("%d",&temp);
	itoa(temp,bin,2);
	printf("2����Ϊ��%s\n",bin);
	k=strlen(bin);
	printf("---%d",k);  */

	/*
	    // ����Ϊ char *str1 = "abcxyz";������������ʱ�����
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
	printf("�������һ����Ҫ�ж�������ֵ��\n");
	scanf("%d",&n);
	a=n-1;
	r=Witness(a,n);
	if(r==1) 
		{
			printf("%dһ������������\n",n);
	       
	    }
	else 
		{
			printf("%d������������\n",n);   
	         p=n;
	    }
	p=n;
	}while(r==1);

	do{
	printf("�������2����Ҫ�ж�������ֵ��\n");
	scanf("%d",&n);
	a=n-1;
	r=Witness(a,n);
	if(r==1) 
		{
			printf("%dһ������������\n",n);
	    }
	else 
		{
			printf("%d������������\n",n);   
	         q=n;
	    }
	q=n;
	}while(r==1);
	
	int e=Creat_Key(p,q);
	int m=(p-1)*(q-1);
	n=p*q;
	//int e=13;
	int x=0,y=0;
	int d=Euclid(e,m,x,y);        //// ������չ��ŷ������㷨���e����Ԫ
	printf("e=%d,d=%d",e,d);
	printf("\n\nRSAǩ����Ϊ��\n");
	for(int i=0;i<5;i++)
	{
	   int result=Result_Mod(array_0[i],d,n);
	   array_1[i]=result;
       printf("%d ",result);
	}
	printf("\n\nRSA���ܽ��Ϊ:\n");
	for(int i=0;i<5;i++)
	{
	     int result=Result_Mod(array_1[i],e,n);
		 printf("%d ",result);
	}
	return 0;
}

