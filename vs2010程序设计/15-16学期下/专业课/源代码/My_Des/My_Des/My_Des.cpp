// My_Des.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
#define  N 64
///�������ܣ�����64λ����
void  Input(int clear_message[N])
{
	int i=0;
  printf("����64λ���ģ�\n");							////���ȼ��裬���������е�Ԫ��Ϊ      0---63
  for(i=0;i<N;i++)
  {
    clear_message[i]=i;
	printf("%d  ",clear_message[i]);
  }
  
}
///�������ܣ�����64λ��Կ
void  Input_Key(int clear_message[N])
{
  int i=0;
  printf("����64λ��Կ��\n");							////���ȼ��裬���������е�Ԫ��Ϊ      0---63
  for(i=100;i<(100+N);i++)
  {
    clear_message[i]=i;
	printf("%d  ",clear_message[i]);
  }
  
}
///�������ܣ�ʵ�ֳ�ʼIP�û�
void IP_Exchange(int  clear_message[N],int  IP_result[N])
{
	int i=0;
	int j=0;
	int k=0;
	int IP_Table[64] = {												/////�û���Ķ����ʼ��
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
///�������ܣ�ʵ��ѭ�����ƹ���
void Loop_Move(int C0[28],int move)
{
	int i=0;
	int j=0;
    if(move==1)       ////ѭ������1λ
	{
	  i=C0[0];
	  while(j<27)
	  {
		 C0[j]=C0[(j+1)];
	    j++;
	  }
	  C0[27]=i;
	}
	else if(move==2)			////ѭ������2λ
	{
	  i=C0[0];
	  while(j<27)
	  {
		 C0[j]=C0[(j+1)];
	    j++;
	  }
	  C0[27]=i;
	                                ///����ѭ������1λ
	  i=C0[0];
	  while(j<27)
	  {
		 C0[j]=C0[(j+1)];
	    j++;
	  }
	  C0[27]=i;
	}
}
///�������ܣ�ʵ����Կ������
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
	for(i=0;i<N;i++)					/////�û�ѡ��1��ʵ��
	{
	  for(j=0;j<56;j++)
	  {
	     if(i==PC1_Table[j])
		 {
		    if(j<28)   C0[j]=key[i];
			else       D0[(j-28)]=key[i];		  ///�ֱ�����C0���D0��
		 }
	  }
	}
	switch(t)
	{
	case 1:       ////����ѭ�����Ʊ�ȷ����λ��
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
		printf("�˻��任����16�֣�\n");
	}
	Loop_Move(C0,move);
	Loop_Move(D0,move);        ////c  d   �ֱ����ѭ������


}
///�������ܣ�ʵ��F�任
void F_Exchange(int right[32])
{
   
}
*/
int _tmain(int argc, _TCHAR* argv[])
{   
	
   int clear_message[N];
   int IP_result[N];
   int key[N];
   Input_Key(key);              ///������Կ
   Input(clear_message);						///��������
   IP_Exchange(clear_message,IP_result);
   

	int a=3;
	int b=5;
	printf("%d",b<<2);
	return 0;
	
}

