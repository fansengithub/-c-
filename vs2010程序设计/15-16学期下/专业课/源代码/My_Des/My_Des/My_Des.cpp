// My_Des.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
#define  N 64
///函数功能：输入64位明文
void  Input(int clear_message[N])
{
	int i=0;
  printf("输入64位明文！\n");							////首先假设，明文数组中的元素为      0---63
  for(i=0;i<N;i++)
  {
    clear_message[i]=i;
	printf("%d  ",clear_message[i]);
  }
  
}
///函数功能：输入64位密钥
void  Input_Key(int clear_message[N])
{
  int i=0;
  printf("输入64位密钥！\n");							////首先假设，明文数组中的元素为      0---63
  for(i=100;i<(100+N);i++)
  {
    clear_message[i]=i;
	printf("%d  ",clear_message[i]);
  }
  
}
///函数功能：实现初始IP置换
void IP_Exchange(int  clear_message[N],int  IP_result[N])
{
	int i=0;
	int j=0;
	int k=0;
	int IP_Table[64] = {												/////置换表的定义初始化
	   58,50,42,34,26,18,10,2,60,52,44,36,28,20,12,4,
		62,54,46,38,30,22,14,6,64,56,48,40,32,24,16,8,
		57,49,41,33,25,17,9,1,59,51,43,35,27,19,11,3,
		61,53,45,37,29,21,13,5,63,55,47,39,31,23,15,7};
	//char  IP_result[N]; 
	for(i=0;i<N;i++)
	{
	   k=clear_message[i];
	   for(j=0;j<N;j++)
	   {
	     if(IP_Table[j]==(k+1))
		 {
		    IP_result[j]=k;
		 }
	   }
	}
}
///函数功能：实现循环左移功能
void Loop_Move(int C0[28],int move)
{
	int i=0;
	int j=0;
    if(move==1)       ////循环左移1位
	{
	  i=C0[0];
	  while(j<27)
	  {
		 C0[j]=C0[(j+1)];
	    j++;
	  }
	  C0[27]=i;
	}
	else if(move==2)			////循环左移2位
	{
	  i=C0[0];
	  while(j<27)
	  {
		 C0[j]=C0[(j+1)];
	    j++;
	  }
	  C0[27]=i;
	                                ///两个循环左移1位
	  i=C0[0];
	  while(j<27)
	  {
		 C0[j]=C0[(j+1)];
	    j++;
	  }
	  C0[27]=i;
	}
}
///函数功能：实现密钥的生成
void  Creat_Key(int key[N],int t)
{
	int PC1_Table[56] = {
	57,49,41,33,25,17,9,1,58,50,42,34,26,18,
		10,2,59,51,43,35,27,19,11,3,60,52,44,36,
		63,55,47,39,31,23,15,7,62,54,46,38,30,22,
		14,6,61,53,45,37,29,21,13,5,28,20,12,4};
	int i=0;
	int j=0;
	int move=0;
	int  C0[28];
	int D0[28];
	for(i=0;i<N;i++)					/////置换选择1的实现
	{
	  for(j=0;j<56;j++)
	  {
	     if(i==PC1_Table[j])
		 {
		    if(j<28)   C0[j]=key[i];
			else       D0[(j-28)]=key[i];		  ///分别生成C0表和D0表
		 }
	  }
	}
	switch(t)
	{
	case 1:       ////根据循环左移表，确定移位数
	case 2:
	case 9:
	case 16:
		move=1;
		break;
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
	case 8:
	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
		move=2;
		break;
	default:
		printf("乘积变换超过16轮！\n");
	}
	Loop_Move(C0,move);
	Loop_Move(D0,move);        ////c  d   分别进行循环左移


}
///函数功能：实现F变换
void F_Exchange(int right[32])
{
   
}
*/
int _tmain(int argc, _TCHAR* argv[])
{   
	
   int clear_message[N];
   int IP_result[N];
   int key[N];
   Input_Key(key);              ///输入密钥
   Input(clear_message);						///输入明文
   IP_Exchange(clear_message,IP_result);
   

	int a=3;
	int b=5;
	printf("%d",b<<2);
	return 0;
	
}

