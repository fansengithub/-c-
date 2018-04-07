// 信息安全实验2.1.cpp : 定义控制台应用程序的入口点。
//
///实验功能描述：实现----使用密钥的单链代替加密    sunlime text
#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 26
#define M 10
///函数功能：判断K中第i个字符之前有没有与它相同的字符     
int Is_First(int i,char K_alphabet[N])   
{ 
	char a=K_alphabet[i];
	int j=0;
	while(j<i)
	{
		if(K_alphabet[j]==a)
		{
			return 0;
		}
		j++;
	}
	return 1;
}
///函数功能：判断a在P中是否出现过
int Is_First_1(char a,char P_alphabet[N])
{
	int i=0;
	for(i=0;i<N;i++)
	{
		if(P_alphabet[i]=='\0')
			break;
		else
		{
			if(P_alphabet[i]==a)
				return 0;
		}
	}
	return 1;
}
///函数功能：去除密钥空间字符串中的重复元素
int  Remove_Duplicate(char K_alphabet[N],char middle[N])
{
	int i;
	int j;						////一个一个遍历数组中元素，如果是第一个出现，添加到另一个数组中
	j=0;
	char a;
	for(i=0;i<N;i++)
	{
		a=K_alphabet[i];
		if(Is_First(i,K_alphabet))			  ///当a时第一个出现的字符时
		{
			middle[j]=a;
			j++;
		}
	}
	j=j-2;        //middle数组中最后两个不是字母，所以-2
	return j;				///返回middle的长度
}
////函数功能:将明文空间中元素复制到密文空间中
void Calphabet_To_Palphabet(char C_alphabet[N],char P_alphabet[N],int j)
{
	int i;
	char a;
	for(i=0;i<N;i++)
	{
		a=C_alphabet[i];
		if(Is_First_1(a,P_alphabet))		//当a是在P中第一次出现时,将a放入P（密文空间）中
		{
			P_alphabet[j]=a;
			j++;
		}
	}
}
///函数功能：完成加密操作，，，，由明文得出密文
void Encryption(char message[M],char ciphertext[M],char C_alphabet[N],char P_alphabet[N])
{
	int i;
	int j;
	int k=strlen(message);
	j=0;
	char a;
	// char b;
	for(i=0;i<M;i++)
	{
		if(i>=k)  return;
		a=message[i];				    ///获取明文的一个字母
		while(C_alphabet[j]!=a)         ///在明文空间中找到相应字母，记录下标
		{
			j++;
		}
		ciphertext[i]=P_alphabet[j];     ////在密文中记录相应的字母
		j=0;
	}
}
///函数功能：解密操作，，，由密文得到明文
void Decrypt(char message[M],char ciphertext[M],char C_alphabet[N],char P_alphabet[N])
{
	int i;
	int j;
	j=0;
	char a;
	int k=strlen(ciphertext);
	for(i=0;i<M;i++)
	{
		if(i>=k)  return;
		a=ciphertext[i];			///获取密文的第i个字母
		while(P_alphabet[j]!=a)         ///在密文空间中找到相应字母，记录下标
		{
			j++;
		}
		message[i]=C_alphabet[j];
		j=0;
	}

}
///函数功能：菜单函数
void menu()
{
	printf("\t\t**************************\n");
	printf("\t\t\t 1  加密\n");
	printf("\t\t\t 2  解密\n");
	printf("\t\t\t 3  退出\n");
	printf("\t\t**************************\n");
}
int _tmain(int argc, _TCHAR* argv[])
{
	int i;
	int j;
	int k;
	int choice;
	char a;
	int t=0;
	char P_alphabet[N];     //密文空间字母表定义    [ˈælfəˌbɛt, -bɪt]
	char C_alphabet[27]="abcdefghijklmnopqrstuvwxyz";       ////明文空间字母表定义及初始化
	char K_alphabet[N];			///密钥空间定义
	char middle[N];
	char middle_1[N];

	printf("请输入密钥！\n");
	scanf("%s",K_alphabet);			///输入密钥
	j=Remove_Duplicate(K_alphabet,middle);     ///j代表middle数组的长度-----除去密钥中的重复数字
	for(i=0;i<j;i++)
	{
		P_alphabet[i]=middle[i];				///将密钥空间中无重复的元素赋值到密文空间中
	}
	Calphabet_To_Palphabet(C_alphabet,P_alphabet,j);		///将明文空间中元素，输入到密文空间
	printf("输入密钥后，得到的明文空间是：\n");
	puts(C_alphabet);
	printf("输入密钥后，得到的密文文空间是：\n");
	 for(t=0;t<26;t++)
	 {
	   printf("%c",P_alphabet[t]);
	 }
	 printf("\n\n\n");
	//printf("输入密钥后，得到的密文文空间是：\n");
	//puts(P_alphabet);
	menu();
	printf("请选择相应操作！\n");
	scanf("%d",&choice);
	while(choice!=3)
	{
		if(choice==1)
		{
			char message[M];      ///明文数组
			char ciphertext[M];    ///密文数组   ['saɪfəˌtekst]
			printf("请输入明文！\n");
			scanf("%s",message);
			k=strlen(message);
			Encryption(message,ciphertext,C_alphabet,P_alphabet);
			printf("经加密得到的密文是：\n");
			//printf("%s",ciphertext);
			for(int i=0;i<k;i++)
			{
				printf("%c",ciphertext[i]);
			}
			printf("\n");
		}
		else if(choice==2)
		{
			char message[M];      ///明文数组
			char ciphertext[M];    ///密文数组   ['saɪfəˌtekst]
			printf("请输入密文！\n");
			scanf("%s",ciphertext);
			k=strlen(ciphertext);
			Decrypt(message,ciphertext,C_alphabet,P_alphabet);
			printf("经解密得到的明文是：\n");
			for(int i=0;i<k;i++)
			{
				printf("%c",message[i]);
			}
			printf("\n");
		}
		else
		{
			printf("------输入错误,请重新输入!\n");
		}
		menu();
		printf("请选择相应操作！\n");
		scanf("%d",&choice);
	}
	return 0;
}

