// homework.cpp : �������̨Ӧ�ó������ڵ㡣
//


#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 50
#define N1 10
char   key2[18][10]={"create","table","drop","alter","insert","into","delete","from","updata","select","grant","revoke","index","view","user","int","char","values"};
//char  * key1[5]={"creat table","drop table","altrer table","insert into","delect from"};
///�ṹ������
typedef struct Lnode
{
	char table[10][10];   ///���ڴ��ÿһ����¼---�ַ���
	struct Lnode * next;        ///ָ����һ���ڵ�
}Lnode;

 Lnode * L;     ///�����һ���ڵ�
 ////�������ܣ�չʾ������������
 void Show_Table()
 {
    Lnode *p;
	printf("----------------------------\n");
	for(int i=0;i<3;i++)
	{
		puts(L->table[i]);
	}
 }
///�������ܣ�ʵ�� creat table����
void  Create_Table(char world1[N1][10],char word2[N1][10],int word_1,int word_2)
{
	
	L=(Lnode *)malloc(sizeof(Lnode));       ///ͷ�������
	   
	 for(int i=0;i<word_2;i++)
	 {
		 strcpy(L->table[i],word2[i]);      ///��  stu ID Name �����ڵ�һ���ڵ���
	 }
	 L->next=NULL;
	 Show_Table();
}
/////�������ܣ�������ݿ�Ĳ���
void  Function3()
{
	char  word1[N1][10]={""};
	char  word2[N1][10]={""};
	int word_two=0;    ///���ڿ���word2[]����
	int   word_one=0;      ////    ���ڿ���  word1[]����
	char ch;
	int finish=0;
	char  action[N]="create table stu ( int ID ,char Name);";
	char  get[N1];
	char  get1[N1];
	//int  count=1;      ///������  name1 na me2 name3 ���ʹ��
//	printf("���������ݿ���������� ; ��β��\n");
//	gets(action);
	int i=0;
	//int use=0;
	int j=0;
	int sum=0;
	int run=-1;
	int k=0;
	ch=action[i];
	while(ch==' ')          /////���˵��������Ŀո�
	{
		i++;
		ch=action[i];
	}
	while(ch!=';')
	{
		while(ch==' ')          /////���˵��������Ŀո�
		{
			i++;
			ch=action[i];
		}

		if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))     //�����ǹؼ��ֻ��߱�����
		{
			j=0;
			while((ch>='0'&&ch<='9')||(ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))
			{
				get[j++]=ch;
				i++;
				ch=action[i];
			}
			get[j++]='\0';      ////����ĩβ��ֵ

			finish=0;
			for(k=0;k<18;k++)           /////�͹ؼ���������Ԫ�رȽϣ��ҵ�ƥ���ַ���
			{
				if(strcmp(get,key2[k])==0)
				{
					strcpy(get1,get);       ////��get1��ʱ����get�е����ݡ�
					finish=1;          ///��Ǹ��ַ���ʱ�ؼ���
					//word1[word_one]=get1;
					strcpy(word1[word_one],get);     ////��get�����е����ݷŵ�word�ַ���������
					word_one++;   
					break;
				}
			}
			if(finish==0)       ////���ַ������ǹؼ���ʱ,���ڵڶ���������c
			{
			  strcpy(word2[word_two],get);
			  word_two++;
			 
			}
		}
		else if(ch>='0'&&ch<='9')     ////��ʱ����ʱ
		{
			sum=0;
			while(ch>='0'&&ch<='9')
			{
				sum=sum*10+ch-'0';       ////����������ɵ��ַ���ת��Ϊ10����
				i++;
				ch=action[i];
			}
			printf("(4,%d)\n",sum);
			sum=0;
		}
		else           ///��chΪ�ֽ��ʱ
		{
			printf("(3,%c)\n",ch);
			i++;
			ch=action[i];
		}
		//	length--;
	}
	for(int i=0;i<=word_one;i++)
	{
	  puts(word1[i]);
	  printf("  ");
	}
	for(int i=0;i<word_two;i++)
	{
	  puts(word2[i]);
	  printf("  ");
	}
	if(strcmp(word1[0],"create")==0 &&strcmp(word1[1],"table")==0)    ////����creat table ʱ��ִ�� creat_table����
	{
	   Create_Table(word1,word2,word_one,word_two);
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
    Function3();
	return 0;
}

