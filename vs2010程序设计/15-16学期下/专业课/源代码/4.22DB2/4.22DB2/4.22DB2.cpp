// 4.22DB2.cpp : 定义控制台应用程序的入口点。
//
// homework.cpp : 定义控制台应用程序的入口点。
//


#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 50
#define N1 10
char   key2[19][10]={"create","table","drop","alter","insert","into","delete","from","updata","select","grant","revoke","index","view","user","int","char","values","add"};
//char  * key1[5]={"creat table","drop table","altrer table","insert into","delect from"};
///结构体声明
typedef struct Lnode
{
	char table[10][10];   ///用于存放每一个记录---字符串
	int rows;         ////用于记录当前当前2维数组用了几行
	struct Lnode * next;        ///指向下一个节点
}Lnode;

 Lnode * L;     ///定义第一个节点
 ////函数功能：展示表中所有数据
 void Show_Table()
 {
    Lnode *p;
	printf("****************----------------\n");
	printf("已有表:");
	for(int i=0;i<3;i++)
	{
		
		for(int j=0;L->table[i][j]!='\0';j++)      ///打印表明，和表的属性名
		{
			printf("%c",L->table[i][j]);
		}
		printf("\t\t");
		if(i==0)  printf("\n----------------------------------\n\t");
	}
 }
///函数功能：实现 creat table功能
void  Create_Table(char world1[N1][10],char word2[N1][10],int word_1,int word_2)
{
	
	L=(Lnode *)malloc(sizeof(Lnode));       ///头结点申请
	L->rows=0;
	 for(int i=0;i<word_2;i++)
	 {
		 strcpy(L->table[i],word2[i]);      ///将  stu ID Name 都放在第一个节点中
		 L->rows++;      ////矩阵行数+1
	 }
	 L->next=NULL;
	 Show_Table();
}
////函数功能：实现  drop table  (删除新建表的功能)
void Drop_Table()
{
  L=NULL;        ///将链表置空
}
///函数功能：实现 alter table ..add .int age  (向表中添加属性时)
void Alter_Table(char word2[N1][10],int word_2)
{
	
	L->rows++;
	strcpy(L->table[L->rows],word2[1]);
	Show_Table();
}
/////函数功能：完成数据库的操作
void  Function3()
{
	char  word1[N1][10]={""};
	char  word2[N1][10]={""};
	int word_two=0;    ///用于控制word2[]数组
	int   word_one=0;      ////    用于控制  word1[]数组
	char ch;
	char yes_no='y';     //
	int finish=0;
	char  action[N];
	char  get[N1];
	//char  get1[N1];
	//int  count=1;      ///用来和  name1 na me2 name3 配合使用
//	printf("请输入数据库操作！（以 ; 结尾）\n");
//	gets(action);
	int i=0;
	//int use=0;
	int j=0;
	int sum=0;
	int run=-1;
	int k=0;
	
	while(yes_no=='y')
	{
	   printf("请输入操作命令！\n");
	   gets(action);
	   i=0;
	   word_one=word_two=0;
	ch=action[i];
	while(ch==' ')          /////过滤掉操作语句的空格
	{
		i++;
		ch=action[i];
	}
	while(ch!=';')
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

			finish=0;
			for(k=0;k<18;k++)           /////和关键词数组中元素比较，找到匹配字符串
			{
				if(strcmp(get,key2[k])==0)
				{
					//strcpy(get1,get);       ////用get1暂时保存get中的内容。
					finish=1;          ///标记该字符串时关键词
					//word1[word_one]=get1;
					strcpy(word1[word_one],get);     ////将get数组中的内容放到word字符串数组中
					word_one++;   
					break;
				}
			}
			if(finish==0)       ////当字符串不是关键词时,放在第二个数组中c
			{
			  strcpy(word2[word_two],get);
			  word_two++;
			 
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
			printf("分解符：  ");
			printf("(3,%c)\n",ch);
			i++;
			ch=action[i];
		}
		//	length--;   
	}

	printf("数组1中的内容：\n");
	for(int i=0;i<=word_one;i++)
	{
	  puts(word1[i]);
	  printf("  ");
	}
	printf("数组2中的内容：\n");
	for(int i=0;i<word_two;i++)
	{
	  puts(word2[i]);
	  printf("  ");
	}
	if(strcmp(word1[0],"create")==0 &&strcmp(word1[1],"table")==0)    ////当是creat table 时，执行 creat_table函数
	{
	   Create_Table(word1,word2,word_one,word_two);
	}
	if(strcmp(word1[0],"drop")==0 && strcmp(word1[1],"table")==0)      ///当输入命令是 drop table 时，执行 drop_table函数
	{
	    Drop_Table();
	}

	if(strcmp(word1[0],"alter")==0 && strcmp(word1[1],"table")==0 && strcmp(word1[2],"add")==0)   ///当输入命令是  alter table stu add int age (表中添加属性时)
	{
		printf("添加属性！\n");
	   Alter_Table(word2,word_two);
	}
	for(int i=0;i<10;i++)       ///  每一次循环之后，将 word 数组置空
	{
	    strcpy(word1[i],"");
         strcpy(word2[i],"");
	}
	//strcpy(word1[1],"");
	printf("\n是否继续？（y or n）\n");
	scanf("%c",&yes_no);
	getchar();
	}
	
	
}
int _tmain(int argc, _TCHAR* argv[])
{
    Function3();
	return 0;
}


