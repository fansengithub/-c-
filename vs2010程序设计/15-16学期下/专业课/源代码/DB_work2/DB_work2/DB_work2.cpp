
#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 50
#define N1 10
char  * key2[18]={"create","table","drop","alter","insert","into","delete","from","updata","select","grant","revoke","index","view","user","int","char","values"};
char  * key1[5]={"creat table","drop table","altrer table","insert into","delect from"};
/////函数功能：完成数据库的操作
void  Function3()
{
	
	char ch;
	char  action[N]="";
	char  get[N1];
	printf("请输入数据库操作！\n");
	gets(action);
	int word1=-1;     ///记录操作语句的第一个关键词，
	int word2=-1;    ////记录操作语句的第二个关键词
	int i=0;
	int use=0;
	int j=0;
	int first=-1;
	int sum=0;
	int run=-1;
	int k=0;
	printf("***********************\n");
	int position;
	ch=action[i];
	while(ch==' ')          /////过滤掉操作语句的空格
	{
		i++;
		ch=action[i];
	}
	while(ch!='#')
	{
		while(ch==' ')          /////过滤掉操作语句的空格
		{
			i++;
			ch=action[i];
		}

		if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))     //可能是关键字或者变量名
		{
			j=0;
			while((ch>='0'&&ch<='9')||(ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))
			{
				get[j++]=ch;
				i++;
				ch=action[i];
			}
			get[j++]='\0';      ////单词末尾赋值

			for(k=0;k<18;k++)           /////和关键词数组中元素比较，找到匹配字符串
			{
				if(strcmp(get,key2[k])==0)
				{
					position=k;      ////记录下关键字的位置

					break;
				}
			}

		}
		else if(ch>='0'&&ch<='9')     ////当时数字时
		{
			sum=0;
			while(ch>='0'&&ch<='9')
			{
				sum=sum*10+ch-'0';       ////将由数字组成的字符串转化为10进制
				i++;
				ch=action[i];
			}
			printf("(4,%d)\n",sum);
			sum=0;
		}
		else           ///当ch为分界符时
		{
			printf("(3,%c)\n",ch);
			i++;
			ch=action[i];
		}
		//	length--;
	}
	if(ch=='#')
	{
		printf("(-1,%c)\n",ch);

	} 
}
int _tmain(int argc, _TCHAR* argv[])
{
    
	return 0;
}