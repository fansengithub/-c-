#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<windows.h>   ///用于时间计算
#define N 100
#define N1 20
#define M 24
char   key2[M][10]={"create","table","drop","alter","insert","into","delete","from","update","select","grant","revoke","index","view","user","int","char","values","add","where","set","on","and","by"};
//char  * key1[5]={"creat table","drop table","altrer table","insert into","delect from"};

void Write_To_File(char word1[N1][10],char word2[N1][10],int word_1,int word_2);
///索引结构体声明
typedef struct Index_Node
{
	char key[10];    ///存放具体的ID ，如 123
	int aim;       ///存放所在行数  入 3
	struct Index_Node * next;
}Index_Node;
///文件记录结构体声明
typedef struct Lnode
{
	char table[10][10];   ///二维数组用于存放每一个记录---字符串
	int rows;         ////用于记录当前当前2维数组用了几行
	struct Lnode * next;        ///指向下一个节点
}Lnode;
typedef struct User
{
	char name[10];    ///用于存放每一个用户名
	char password[10];    ///用于存放用户名对应的密码
	char power[10];      ///记录用户的权限
	struct User * next;
}User;
///User 链表的第一个节点，存放管理员相关信息
User * u0;

///定义数据字典
int index=1;
char data_diction[N][N];    ///定义数据字典
Lnode * l1, *l2, *l3;
Lnode  * Table_Array[N1]={l1,l2,l3};   ///存放链表的头结点
Index_Node * i1, *i2,*i3;
Index_Node * Index_Array[N1]={i1,i2,i3};
int Index_Count=3;  //用于遍历Index_Array[]数组
//Table_Array[];
int  Table_Count=0;     ///用于遍历Table_Array[]数组
//Lnode * L;     ///定义第一个节点
////函数功能：数据字典的初始化
void Init_dd()
{
	for(int i=0;i<N;i++)
	{
		strcpy(data_diction[i],"");
	}
	//  strcpy(data_diction[0],"关系名：   ");      ///矩阵第一行，，存放汉字：
	// strcpy(data_diction[2],"属性名：   "); 
}
////函数功能：展示表中所有数据
void Show_Table(char word1[N1][10],char word2[N1][10],int word_1,int word_2)
{
	for(int i=0;i<Table_Count;i++)
	{
		if(Table_Array[i]==NULL)    ////当第一个表删除时，直接跳到下一个文件
			continue;    
		char temp[N1]="";
		//if(L==NULL)   printf("当前数据库为空！");  return ;
		Lnode *p;
		p=Table_Array[i];
		//printf("****************----------------\n");
		printf("已有表:");
		//strcpy(temp,p->table[0]);      ///用temp 临时存放 关系名  stu
		puts(p->table[0]);
		printf("\n----------------------------------------\n");
		//strcpy(p->table[0],"");
		p=p->next;
		while(p!=NULL)
		{
			for(int i=0;i<p->rows;i++)
			{	printf("\t");
			for(int j=0;p->table[i][j]!='\0';j++)      ///打印表明，和表的属性名
			{
				printf("%c",p->table[i][j]);
			}
			printf("\t");
			//if(i==0)  printf("\n----------------------------------\n\t");
			}
			p=p->next;
			printf("\n");
		}
	}
	//strcpy(L->table[0],temp);     ///每次打印关系之后，将关系名恢复，下次用.
}
///函数功能：实现 creat table功能
void  Create_Table(char word1[N1][10],char word2[N1][10],int word_1,int word_2)
{

	Lnode * L;     ///定义第一个节点

	L=(Lnode *)malloc(sizeof(Lnode));       ///头结点申请
	for(int i=0;i<10;i++)
	{
		strcpy(L->table[i],"");
	}
	L->rows=1;
	L->next=NULL;
	strcpy(L->table[0],word2[0]);          ///将关系名放在头结点中
	Table_Array[Table_Count]=L;
	Table_Count++;

	strcpy(data_diction[0],"table_name： ");      ///矩阵第一行，，存放汉字：
	strcpy(data_diction[2],"property： "); 
	strcpy(data_diction[1],word2[0]);    ///将关系名写入数据文件
	strcpy(data_diction[3],"    ");

	Lnode * p=(Lnode *)malloc(sizeof(Lnode));    ///申请第二个节点放  ID  Name

	//Table_Array[Table_Count]=L;
	//printf("%d",Table_Array[0]->rows);
	for(int i=0;i<10;i++)                ///初始化节点 
	{
		strcpy(p->table[i],"");
	}
	p->rows=0;
	p->next=NULL;

	for(int i=0;i<(word_2-1);i++)
	{
		strcpy(p->table[i],word2[(i+1)]);      ///将   ID Name 都放在第2个节点中
		p->rows++;      ////矩阵行数+1
	}
	index=4;                ////数据字典下标从4开始
	for(int i=0;i<(word_2-1);i++)
	{
		strcpy(data_diction[(index++)],word1[(2+i)]);
		strcpy(data_diction[(index++)],word2[(1+i)]);
	}

	L->next=p;
	Show_Table(word1,word2,word_1,word_2);
	/// Write_To_File();
	//printf("******");
}
////函数功能：实现  drop table  (删除新建表的功能)
void Drop_Table(char word1[N1][10],char word2[N1][10],int word_1,int word_2)
{
	char close[N1]="";
	///找到将要删除表
	int i=0;
	for( i=0;i<Table_Count;i++)
	{
		if(strcmp(Table_Array[i]->table[0],word2[0])==0)
			break;
	}
	FILE * fp;
	FILE  * fp1;
	if(i==0)  ///删除第一个表
	{
		if((fp=fopen("E:\\db1.txt","w"))==NULL)         ////对文件清空
		{
			printf("打开文件失败！\n");
			exit(0);
		}
		fprintf(fp,"%s",close);         ////向文件中写入空白符
		fclose(fp);

		if((fp1=fopen("E:\\db11.txt","w"))==NULL)         ////对数据字典进行清空
		{
			printf("打开文件失败！\n");
			exit(0);
		}
		fprintf(fp1,"%s",close);      ///向数据字典文件中写入空格符
		fclose(fp1);
	}
	if(i==1)     ///删除第二个表
	{
		if((fp=fopen("E:\\db2.txt","w"))==NULL)         ////对文件清空
		{
			printf("打开文件失败！\n");
			exit(0);
		}
		fprintf(fp,"%s",close);
		fclose(fp);

		if((fp1=fopen("E:\\db22.txt","w"))==NULL)         ////对数据字典进行清空
		{
			printf("打开文件失败！\n");
			exit(0);
		}
		fprintf(fp1,"%s",close);  
		fclose(fp1);
	}
	if(i==2)   
	{
		if((fp=fopen("E:\\db3.txt","w"))==NULL)         ////对文件清空
		{
			printf("打开文件失败！\n");
			exit(0);
		}
		fprintf(fp,"%s",close);
		fclose(fp);

		if((fp1=fopen("E:\\db33.txt","w"))==NULL)         ////对数据字典进行清空
		{
			printf("打开文件失败！\n");
			exit(0);
		}
		fprintf(fp1,"%s",close);  
		fclose(fp1);
	}
	Lnode * q;
	Lnode *  p=Table_Array[i];
	Table_Array[i]=NULL;      ////将指针数组中的对应项制空
	while(p->next!=NULL)
	{
		q=p->next;
		free(p);
		p=q;
	}
	free(p);
	//L=NULL;        ///将链表置空
	Show_Table(word1,word2,word_1,word_2);
}
///函数功能：实现 alter table ..add .int age  (向表中添加属性时)
void Add_Table(char word1[N1][10],char word2[N1][10],int word_1,int word_2)
{
	///首次找到将要操作的表
	int i=0;
	for( i=0;i<Table_Count;i++)
	{
		if(strcmp(Table_Array[i]->table[0],word2[0])==0)
			break;
	}

	Lnode *  p=Table_Array[i]->next;   ////找到链表的第二个节点，，添加属性名

	//L->rows;
	strcpy(p->table[p->rows],word2[1]);
	p->rows++;       ///先复制到 table 的 row行，然后加1，，，数组下标从0开始

	strcpy(data_diction[(index++)],word1[3]);         ///修改数据字典
	strcpy(data_diction[(index++)],word2[1]);

	Show_Table(word1,word2,word_1,word_2);
	/*
	printf("数据字典：\n");       ///打印输出数据字典的内容：
	for(int i=0;i<N;i++)
	{
	puts(data_diction[i]);
	}   */
}
///函数功能：在关系中删除列元素(删除属性)
void Drop_Column(char word1[N1][10],char word2[N1][10],int word_1,int word_2)
{
	///首次找到将要操作的表
	int i=0;
	for( i=0;i<Table_Count;i++)
	{
		if(strcmp(Table_Array[i]->table[0],word2[0])==0)
			break;
	}

	Lnode *  p=Table_Array[i]->next;   ////找到链表的第二个节点，，添加属性名
	i=0;
	int k=0;
	for(i=0;i<(p->rows-1);i++)
	{
		if(strcmp(p->table[i],word2[1])==0)     ///找到 Age 对应的行号
		{
			//strcpy(p->table[i],"");
			break;
		}

	}
	while(p!=NULL)
	{
		for(int j=0;j<p->rows;j++)
		{
			if(j==i)  strcpy(p->table[j],"");
		}
		p=p->next;
	}
	////修改数据字典 
	for( k=3;k<index;k++)
	{
		if(strcmp(data_diction[k],word2[1])==0)    ///在数据字典中找到 Age 对应的下标
			break;
	}
	strcpy(data_diction[k],"");      ///在数据字典中删除  Age
	index--;
	strcpy(data_diction[(k-1)],"");   ////在数据字典中删除  Age  的类型
	index--;
	/*
	L->rows--;
	strcpy(L->table[L->rows],"");        ////将这一行清空
	*/
	Show_Table(word1,word2,word_1,word_2);   
}
///函数功能：在关系中添加元组
void Insert_Into(char word1[N1][10],char word2[N1][10],int word_1,int word_2)
{
	Lnode * p=(Lnode *)malloc(sizeof(Lnode));     ///申请一个新的结构体，，将元组内容放入其中
	p->rows=0;
	p->next=NULL;
	for(int i=1;i<word_2;i++)
	{
		strcpy(p->table[(i-1)],word2[i]);
		p->rows++;
	}
	///首次找到将要操作的表
	int i=0;
	for( i=0;i<Table_Count;i++)
	{
		if(strcmp(Table_Array[i]->table[0],word2[0])==0)
			break;
	}

	Lnode *  q=Table_Array[i];   ////找到链表的第二个节点，，
	//	Lnode *q=L;
	while(q->next!=NULL)
	{
		q=q->next;    ///找到链表的末节点
	}
	q->next=p;
	Show_Table(word1,word2,word_1,word_2);
}
//函数功能：在关系中删除一个元组
void Delect_Row(char word1[N1][10],char word2[N1][10],int word_1,int word_2)
{
	///首先确定 ID 对应的下标   i
	int i=0;
	for( i=0;i<Table_Count;i++)
	{
		if(strcmp(Table_Array[i]->table[0],word2[0])==0)
			break;
	}

	Lnode *  p=Table_Array[i]->next;   ////找到链表的第二个节点，，
	//Lnode * p=L->next;
	i=0;
	for( i=0;i<p->rows;i++)
	{
		if(strcmp(p->table[i],word2[1])==0)    
		{
			break;
		}
	}
	Lnode * r;
	r=p->next;
	while(r!=NULL)
	{
		if(strcmp(r->table[i],word2[2])==0)       ///找到对应条件的元组
		{
			p->next=r->next;         ///在链表中删除该节点

		}
		p=r;
		r=r->next;
	}
	Show_Table(word1,word2,word_1,word_2);
}
///函数功能：更新关系中的数据
void Update_Set(char word1[N1][10],char word2[N1][10],int word_1,int word_2)
{
	///首先确定 ID 对应的下标   i
	///首先确定 ID 对应的下标   i
	int i=0;
	for( i=0;i<Table_Count;i++)
	{
		if(strcmp(Table_Array[i]->table[0],word2[0])==0)
			break;
	}

	Lnode *  p=Table_Array[i]->next;   ////找到链表的第二个节点，，
	//Lnode * p=L->next;
	i=0;
	for( i=0;i<p->rows;i++)
	{
		if(strcmp(p->table[i],word2[3])==0)    
		{
			break;
		}
	}
	int j=0;
	for(j=0;j<p->rows;j++)
	{
		if(strcmp(p->table[j],word2[1])==0)     ///找到Age对应的下标    
		{
			break;
		}
	}
	Lnode * r;
	r=p->next;
	while(r!=NULL)
	{
		if(strcmp(r->table[i],word2[4])==0)    ///找到  ID=123
		{
			strcpy(r->table[j],word2[2]);      ///把  ID 对应节点的  Age  修改为20

			//r->table[j]
		}
		r=r->next;
	}
	Show_Table(word1,word2,word_1,word_2);
}
////函数功能：显示表中所有内容
void Select_From(char word1[N1][10],char word2[N1][10],int word_1,int word_2)
{
	///首先确定 ID 对应的下标   i
	int i=0;
	for( i=0;i<Table_Count;i++)
	{
		if(strcmp(Table_Array[i]->table[0],word2[1])==0)
			break;
	}
	Lnode *  p=Table_Array[i];   ////找到链表的第1个节点，，
	printf("\n----------------------------------------\n");
	puts(p->table[0]);
	printf("\n----------------------------------------\n");
	//strcpy(p->table[0],"");
	p=p->next;
	while(p!=NULL)
	{
		for(int i=0;i<p->rows;i++)
		{	printf("\t");
		for(int j=0;p->table[i][j]!='\0';j++)      ///打印表明，和表的属性名
		{
			printf("%c",p->table[i][j]);
		}
		printf("\t");
		//if(i==0)  printf("\n----------------------------------\n\t");
		}
		p=p->next;
		printf("\n");
	}
	//Show_Table(word1,word2,word_1,word_2);
}
///函数功能：单关系的投影操作
void Show_Column(char word1[N1][10],char word2[N1][10],int word_1,int word_2)
{
	int i=0;
	int t=0;  ///用于记录Name属性对应的下标
	for( i=0;i<Table_Count;i++)
	{
		if(strcmp(Table_Array[i]->table[0],word2[1])==0)
			break;
	}
	Lnode * p=Table_Array[i];     ///找到链表的第一个节点
	printf("\n投影操作：\n");
	puts(p->table[0]);    //打印表名

	p=p->next;
	for(t=0;t<p->rows;t++)
	{
		if(strcmp(word2[0],p->table[t])==0)
			break;
	}
	printf("%s",p->table[t]);
	printf("\n-----------\n");
	p=p->next;
	while(p!=NULL)
	{
		printf("%s\n",p->table[t]);
		p=p->next;
	}
}
///函数功能：实现单关系的选择操作
void Single_Select(char word1[N1][10],char word2[N1][10],int word_1,int word_2)
{
	SYSTEMTIME t1,t2;			 //用于计算时间
	int time;
	GetSystemTime(&t1);
	printf("%d:%d\n",t1.wSecond,t1.wMilliseconds);			//打印开始前的时间
	int i=0;
	int t=0;  ///用于记录Name属性对应的下标
	for( i=0;i<Table_Count;i++)
	{
		if(strcmp(Table_Array[i]->table[0],word2[1])==0)
			break;
	}
	Lnode * p=Table_Array[i];     ///找到链表的第一个节点
	puts(p->table[0]);    //打印表名
	printf("--------\n");

	p=p->next;
	for(t=0;t<p->rows;t++)
	{
		if(strcmp(word2[2],p->table[t])==0)
			break;
	}
	p=p->next;
	while(p!=NULL)
	{
		if(strcmp(word2[3],">")==0)   ///当选择关系为  > 时
		{
			if(strcmp(p->table[t],word2[4])>0)    
				{
					for(int i=0;i<p->rows;i++)
					{
					  printf("%s\t",p->table[i]);
					}
					printf("\n");
			     }
		}
		if(strcmp(word2[3],"=")==0)   ///当选择关系为  =时
		{
			if(strcmp(p->table[t],word2[4])==0)   
			{
			        for(int i=0;i<p->rows;i++)
					{
					  printf("%s\t",p->table[i]);
					}
					printf("\n");
			}
		}
		if(strcmp(word2[3],"<")==0)   ///当选择关系为  < 时
		{
			if(strcmp(p->table[t],word2[4])<0)  
			{
				   for(int i=0;i<p->rows;i++)
					{
					  printf("%s\t",p->table[i]);
					}
					printf("\n");
			}
		}

		p=p->next;
	}
	GetSystemTime(&t2);
	printf("%d:%d\n",t2.wSecond,t2.wMilliseconds);					///打印执行之后的时间
	time=(t2.wSecond - t1.wSecond)*1000+t2.wMilliseconds-t1.wMilliseconds;				///求出总共用时
	printf("总共用时：  %d    微秒\n",time);
}
///函数功能：利用索引完成双表的连接
void Connct_By_Index(char word1[N1][10],char word2[N1][10],int word_1,int word_2)
{
    SYSTEMTIME t1,t2;			 //用于计算时间
	int time;
	GetSystemTime(&t1);
	printf("%d:%d\n",t1.wSecond,t1.wMilliseconds);			//打印开始前的时间
    int i=0;
	int j=0;
	int index1=0;  ///用于记录索引下标
	int index2=0;
	int t=0;  ///用于记录Name属性对应的下标
	for( i=0;i<Table_Count;i++)
	{
		if(strcmp(Table_Array[i]->table[0],word2[1])==0)
			break;
	}
	Lnode * p=Table_Array[i];     ///找到链表的第一个节点,,,,第一个文件
	//puts(p->table[0]);    //打印表名

	for( j=0;j<Table_Count;j++)
	{
		if(strcmp(Table_Array[j]->table[0],word2[2])==0)
			break;
	}
	Lnode * q=Table_Array[j];     ///找到链表的第一个节点，，，，第二个文件
	//puts(q->table[0]);    //打印表名

	for(index1=0;index1<3;index1++)    ////在索引头结点数组中找到S_Id对应项
	{
		if(strcmp(word2[4],Index_Array[index1]->key)==0)
			break; 
	}
	Index_Node * node1=Index_Array[index1];
	node1=node1->next;                    ///用node1记录第一个索引文件

	for(index2=0;index2<3;index2++)    ////在索引头结点数组中找到S_Id对应项
	{
		if(strcmp(word2[7],Index_Array[index2]->key)==0)
			break; 
	}
	Index_Node * node2=Index_Array[index2];
	node2=node2->next;                    ///用node1记录第一个索引文件
}
///函数功能：实现双表连接
void Double_Connct(char word1[N1][10],char word2[N1][10],int word_1,int word_2)
{
	int i=0;
	int j=0;
	int t1=0;   ///记录stu中name属性的下标
	int t2=0;    //记录teachet中name属性的下标
	for( i=0;i<Table_Count;i++)
	{
		if(strcmp(Table_Array[i]->table[0],word2[1])==0)
			break;
	}
	Lnode * p=Table_Array[i];     ///找到stu 文件链表的第一个节点
	for( j=0;j<Table_Count;j++)
	{
		if(strcmp(Table_Array[j]->table[0],word2[2])==0)
			break;
	}
	Lnode * q=Table_Array[j];     ///找到teacher 文件链表的第一个节点

	p=p->next;              ////找到stu 中Name对应的下标
	for(t1=0;t1<p->rows;t1++) 
	{
		if(strcmp(word2[(word_2-1)],p->table[t1])==0)
			break;
	}

	q=q->next;    ////找到teach中Name对应的下标
	for(t2=0;t2<q->rows;t2++)
	{
		if(strcmp(word2[(word_2-1)],q->table[t2])==0)
			break;
	}

	p=p->next;   ///找到stu文件链表的第三个节点
	q=q->next;
	Lnode * x=q;   //暂存作用
	while(p!=NULL)     ///两层循环嵌套，外层遍历stu链表，，内层循环遍历teach链表
	{
		q=x;
		while(q!=NULL)
		{
			if(strcmp(p->table[t1],q->table[t2])==0)     ///当找到两个链表中有相等项时
			{
				strcpy(p->table[p->rows],"yes");      //将链表中二维数组中一项改为 yes,做个标记
				strcpy(q->table[q->rows],"yes");
			}
			q=q->next;
		}
		p=p->next;
	}

	p=Table_Array[i];     ///指向链表的第一个节点
	q=Table_Array[j];
	///开始打印标记的项
	puts(p->table[0]);       ///打印第一个链表
	printf("\n----------------------------------------\n");
	p=p->next->next;

	while(p!=NULL)
	{
		if(strcmp(p->table[p->rows],"yes")==0)    ///当有标记时,才打印出来
		{
			for(int i=0;i<p->rows;i++)
			{	printf("\t");
			for(int j=0;p->table[i][j]!='\0';j++)      ///打印表明，和表的属性名
			{
				printf("%c",p->table[i][j]);
			}
			printf("\t");
			//if(i==0)  printf("\n----------------------------------\n\t");
			}
			strcpy(p->table[p->rows],"");     ///使用结束之后，清楚标记
		}
		p=p->next;
		printf("\n");
	}

	puts(q->table[0]);      ///打印第二个链表
	printf("\n----------------------------------------\n");
	q=q->next->next;

	while(q!=NULL)
	{
		if(strcmp(q->table[q->rows],"yes")==0)    ///当有标记时,才打印出来
		{
			for(int i=0;i<q->rows;i++)
			{	printf("\t");
			for(int j=0;q->table[i][j]!='\0';j++)      ///打印表明，和表的属性名
			{
				printf("%c",q->table[i][j]);
			}
			printf("\t");
			//if(i==0)  printf("\n----------------------------------\n\t");
			}
			strcpy(q->table[q->rows],"");     ///使用结束之后，清楚标记
		}
		q=q->next;
		printf("\n");
	}
}
///函数功能：实现双表的投影和连接
void Double_Shadow_Connct(char word1[N1][10],char word2[N1][10],int word_1,int word_2)
{
	int i=0;
	int j=0;
	int y1=0;    //记录stu中Id对应的下标
	int y2=0;
	int t1=0;   ///记录stu中name属性的下标
	int t2=0;    //记录teachet中name属性的下标
	for( i=0;i<Table_Count;i++)
	{
		if(strcmp(Table_Array[i]->table[0],word2[1])==0)
			break;
	}
	Lnode * p=Table_Array[i];     ///找到stu 文件链表的第一个节点
	for( j=0;j<Table_Count;j++)
	{
		if(strcmp(Table_Array[j]->table[0],word2[2])==0)
			break;
	}
	Lnode * q=Table_Array[j];     ///找到teacher 文件链表的第一个节点

	p=p->next;              ////找到stu 中Name对应的下标
	for(t1=0;t1<p->rows;t1++) 
	{
		if(strcmp(word2[(word_2-1)],p->table[t1])==0)
			break;
	}
	for(y1=0;y1<p->rows;y1++)  ///找到stu中 Id 对应的下标
	{
		if(strcmp(word2[0],p->table[y1])==0)
			break;
	}

	q=q->next;    ////找到teach中Name对应的下标
	for(t2=0;t2<q->rows;t2++)
	{
		if(strcmp(word2[(word_2-1)],q->table[t2])==0)
			break;
	}
	for(y2=0;y2<q->rows;y2++)  ///找到teacher中 Id 对应的下标
	{
		if(strcmp(word2[0],q->table[y2])==0)
			break;
	}

	p=p->next;   ///找到stu文件链表的第三个节点
	q=q->next;
	Lnode * x=q;   //暂存作用
	while(p!=NULL)     ///两层循环嵌套，外层遍历stu链表，，内层循环遍历teach链表
	{
		q=x;
		while(q!=NULL)
		{
			if(strcmp(p->table[t1],q->table[t2])==0)     ///当找到两个链表中有相等项时
			{
				strcpy(p->table[p->rows],"yes");      //将链表中二维数组中一项改为 yes,做个标记
				strcpy(q->table[q->rows],"yes");
			}
			q=q->next;
		}
		p=p->next;
	}

	p=Table_Array[i];     ///指向链表的第一个节点
	q=Table_Array[j];
	///开始打印标记的项
	puts(p->table[0]);       ///打印第一个链表
	printf("-------------------\n");
	p=p->next->next;

	while(p!=NULL)
	{
		if(strcmp(p->table[p->rows],"yes")==0)    ///当有标记时,才打印出来
		{
			printf("%s\n",p->table[y1]);
			strcpy(p->table[p->rows],"");     ///使用结束之后，清楚标记
		}
		p=p->next;
		//	printf("\n");
	}
	printf("\n");
	puts(q->table[0]);      ///打印第二个链表
	printf("-------------------\n");
	q=q->next->next;

	while(q!=NULL)
	{
		if(strcmp(q->table[q->rows],"yes")==0)    ///当有标记时,才打印出来
		{
			printf("%s\n",q->table[y2]);
			strcpy(q->table[q->rows],"");     ///使用结束之后，清楚标记
		}
		q=q->next;
		//	printf("\n");
	}
}
///函数功能：实现多表的选择，投影和连接
void Many_Sel_Sha_Cont(char word1[N1][10],char word2[N1][10],int word_1,int word_2)
{  

	int t1=0;   ///记录c中c_name属性的下标
	int t2=0;    ///记录c中c_Id 属性的下标
	int t3=0;    ///记录sc中c_Id 属性的下标
	int t4=0;    ///记录sc中s_Id 属性的下标
	int t5=0;
	int t6=0;
	int i=0;
	for( i=0;i<Table_Count;i++)
	{
		if(strcmp(Table_Array[i]->table[0],word2[2])==0)
			break;
	}
	Lnode * p=Table_Array[i];     ///找到c 文件链表的第一个节点

	p=p->next;              ////找到c 中c_name 对应的下标
	for(t1=0;t1<p->rows;t1++) 
	{
		if(strcmp(word2[3],p->table[t1])==0)
			break;
	}
	for(t2=0;t2<p->rows;t2++)     ///记录c中c_Id 属性的下标
	{
		if(strcmp(word2[7],p->table[t2])==0)
			break;
	}

	for( i=0;i<Table_Count;i++)
	{
		if(strcmp(Table_Array[i]->table[0],word2[9])==0)
			break;
	}
	Lnode * q=Table_Array[i];     ///找到sc文件链表的第一个节点
	q=q->next;
	for(t3=0;t3<q->rows;t3++)    ///记录sc中c_Id 属性的下标
	{
		if(strcmp(word2[10],q->table[t3])==0)
			break;
	}
	for(t4=0;t4<q->rows;t4++)    ///记录sc中s_Id 属性的下标
	{
		if(strcmp(word2[12],q->table[t4])==0)
			break;
	}
	q=q->next;
	Lnode * q1=q;    ///记录下当前链表的第三个节点

	for( i=0;i<Table_Count;i++)
	{
		if(strcmp(Table_Array[i]->table[0],word2[14])==0)
			break;
	}
	Lnode * r=Table_Array[i];     ///找到s文件链表的第一个节点
	Lnode * r1=r;    ///记录下当前链表的第1个节点
	r=r->next;
	for(t5=0;t5<r->rows;t5++)    ///记录s中s_Id 属性的下标
	{
		if(strcmp(word2[15],r->table[t5])==0)
			break;
	}
	for(t6=0;t6<r->rows;t6++)    ///记录s中s_Name 属性的下标
	{
		if(strcmp(word2[0],r->table[t6])==0)
			break;
	}
	r=r->next;


	p=p->next;
	Lnode * p1=p;    ///记录下当前链表的第三个节点
	while(p!=NULL)
	{
		if(strcmp(p->table[t1],word2[5])==0)   //当找到满足第一个条件时( c_name= math )，做个标记
		{
			strcpy(p->table[p->rows],"yes"); 
			// break;
		}
		p=p->next;
	}

	p=p1;
	while(p!=NULL)     ///两层循环进行连接操作，外层遍历 c 表，内层遍历 sc 表
	{
		if(strcmp(p->table[p->rows],"yes")==0)     ///当找到做过标记的项时
		{
			while(q!=NULL)
			{
				if(strcmp(p->table[t2],q->table[t3])==0)  ///当连接条件相同时
				{
					strcpy(q->table[q->rows],"yes");
				}
				q=q->next;
			}
			strcpy(p->table[p->rows],"");    ///使用结束之后，清楚标记
		}
		p=p->next;
	}

	q=q1;
	while(q!=NULL)    ///两层循环进行连接操作，外层遍历 sc表，内层遍历 s 表
	{
		if(strcmp(q->table[q->rows],"yes")==0)    ///当找到做过标记的项时
		{
			while(r!=NULL)
			{
				if(strcmp(q->table[t4],r->table[t5])==0)  ///当连接条件相同时
				{
					strcpy(r->table[r->rows],"yes");
				}
				r=r->next;
			}
			strcpy(q->table[q->rows],"");    ///使用结束之后，清楚标记
		}
		q=q->next;
	}

	r=r1;
	printf("\n");
	puts(r->table[0]);      ///打印表名
	printf("-------------------\n");
	r=r->next->next;
	while(r!=NULL)
	{
		if(strcmp(r->table[r->rows],"yes")==0)
		{
			printf("%s\n",r->table[t6]);
			strcpy(r->table[r->rows],"");    ///使用结束之后，清楚标记
		}
		r=r->next;
	}
}
//函数功能：实现双表的选择连接
void Double_Select_Connt(char word1[N1][10],char word2[N1][10],int word_1,int word_2)
{
	///先进行双表连接操作
	int i=0;
	int j=0;
	int t1=0;   ///记录stu中name属性的下标
	int t2=0;    //记录teacher中name属性的下标
	int y1=0;    ///记录stu中ID属性的下标
	int y2=0;	 //记录teacher中ID属性的下标
	for( i=0;i<Table_Count;i++)
	{
		if(strcmp(Table_Array[i]->table[0],word2[1])==0)
			break;
	}
	Lnode * p=Table_Array[i];     ///找到stu 文件链表的第一个节点
	for( j=0;j<Table_Count;j++)
	{
		if(strcmp(Table_Array[j]->table[0],word2[2])==0)
			break;
	}
	Lnode * q=Table_Array[j];     ///找到teacher 文件链表的第一个节点

	p=p->next;              ////找到stu 中Name对应的下标
	for(t1=0;t1<p->rows;t1++) 
	{
		if(strcmp(word2[(word_2-1)],p->table[t1])==0)
			break;
	}
	for(y1=0;y1<p->rows;y1++)    ////找到stu 中ID对应的下标
	{
		if(strcmp(word2[3],p->table[y1])==0)
			break;
	}

	q=q->next;    ////找到teach中Name对应的下标
	for(t2=0;t2<q->rows;t2++)
	{
		if(strcmp(word2[(word_2-1)],q->table[t2])==0)
			break;
	}
	for(y2=0;y2<p->rows;y2++)    ////找到teacher 中ID对应的下标
	{
		if(strcmp(word2[3],p->table[y2])==0)
			break;
	}

	p=p->next;   ///找到stu文件链表的第三个节点
	q=q->next;
	Lnode * x=q;   //暂存作用
	while(p!=NULL)     ///两层循环嵌套，外层遍历stu链表，，内层循环遍历teach链表
	{
		q=x;
		while(q!=NULL)
		{
			if(strcmp(p->table[t1],q->table[t2])==0 )     ///当找到两个链表中有相等项时---条件1判断
			{
				if(strcmp(word2[4],">")==0)   ///当选择关系为  > ,,,条件2判断
				{
					if(strcmp(p->table[y1],word2[5])>0 && strcmp(q->table[y2],word2[5])>0)
					{
						strcpy(p->table[p->rows],"yes");      //将链表中二维数组中一项改为 yes,做个标记
						strcpy(q->table[q->rows],"yes");
					}
				}
				if(strcmp(word2[4],"=")==0)   ///当选择关系为  =时
				{
					if(strcmp(p->table[y1],word2[5])==0 && strcmp(q->table[y2],word2[5])==0)    
					{
						strcpy(p->table[p->rows],"yes");      //将链表中二维数组中一项改为 yes,做个标记
						strcpy(q->table[q->rows],"yes");
					}
				}
				if(strcmp(word2[3],"<")==0)   ///当选择关系为  < 时
				{
					if(strcmp(p->table[y1],word2[5])<0 && strcmp(q->table[y2],word2[5])<0)
					{
						strcpy(p->table[p->rows],"yes");      //将链表中二维数组中一项改为 yes,做个标记
						strcpy(q->table[q->rows],"yes");
					}
				}
			}
			q=q->next;
		}
		p=p->next;
	}


	p=Table_Array[i];     ///指向链表的第一个节点
	q=Table_Array[j];
	///开始打印标记的项
	puts(p->table[0]);       ///打印第一个链表
	printf("\n----------------------------------------\n");
	p=p->next->next;

	while(p!=NULL)
	{
		if(strcmp(p->table[p->rows],"yes")==0)    ///当有标记时,才打印出来
		{
			for(int i=0;i<p->rows;i++)
			{	printf("\t");
			for(int j=0;p->table[i][j]!='\0';j++)      ///打印表明，和表的属性名
			{
				printf("%c",p->table[i][j]);
			}
			printf("\t");
			//if(i==0)  printf("\n----------------------------------\n\t");
			}
			strcpy(p->table[p->rows],"");     ///使用结束之后，清楚标记
		}
		p=p->next;
		printf("\n");
	}

	puts(q->table[0]);      ///打印第二个链表
	printf("\n----------------------------------------\n");
	q=q->next->next;

	while(q!=NULL)
	{
		if(strcmp(q->table[q->rows],"yes")==0)    ///当有标记时,才打印出来
		{
			for(int i=0;i<q->rows;i++)
			{	printf("\t");
			for(int j=0;q->table[i][j]!='\0';j++)      ///打印表明，和表的属性名
			{
				printf("%c",q->table[i][j]);
			}
			printf("\t");
			//if(i==0)  printf("\n----------------------------------\n\t");
			}
			strcpy(q->table[q->rows],"");     ///使用结束之后，清楚标记
		}
		q=q->next;
		printf("\n");
	}
}
///函数功能；实现单关系的选择和投影操作
void  Single_Sele_Shadow(char word1[N1][10],char word2[N1][10],int word_1,int word_2)
{
	int i=0;
	int t=0;  ///用于记录Name属性对应的下标
	int  k=0;  ///用于记录Id属性对应的下标
	for( i=0;i<Table_Count;i++)     ///找到多个数据库文件中的一个
	{
		if(strcmp(Table_Array[i]->table[0],word2[1])==0)
			break;
	}
	Lnode * p=Table_Array[i];     ///找到链表的第一个节点
	puts(p->table[0]);    //打印表名
	printf("--------\n");

	p=p->next;     ///跳转到第二个节点
	for(t=0;t<p->rows;t++)      ///找到Name属性对应的下标
	{
		if(strcmp(word2[0],p->table[t])==0)
			break;
	}
	for(k=0;k<p->rows;k++)      ///找到Id属性对应的下标
	{
		if(strcmp(word2[2],p->table[k])==0)
			break;
	}
	p=p->next;    ///跳转到第三个节点
	while(p!=NULL)
	{
		if(strcmp(word2[3],">")==0)   ///当选择关系为  > 时
		{
			if(strcmp(p->table[k],word2[4])>0)    printf("%s\n",p->table[t]);
		}
		if(strcmp(word2[3],"=")==0)   ///当选择关系为  =时
		{
			if(strcmp(p->table[k],word2[4])==0)    printf("%s\n",p->table[t]);
		}
		if(strcmp(word2[3],"<")==0)   ///当选择关系为  < 时
		{
			if(strcmp(p->table[k],word2[4])<0)    printf("%s\n",p->table[t]);
		}

		p=p->next;
	}
}
///函数功能：将数据库表写入文件中
void Write_To_File(char word1[N1][10],char word2[N1][10],int word_1,int word_2)
{
	///首先确定 ID 对应的下标   i
	int i=0;
	for( i=0;i<Table_Count;i++)
	{
		Lnode *  p=Table_Array[i];   ////找到链表的第i个节点，，
		//Lnode * p=L;
		FILE * fp;
		FILE * fp1;
		char c='\t';
		char a='\n';
		char ch[40]="-----------------------------";
		//数据库表的文件
		if(i==0)    ////当第一个表时
		{
			if((fp=fopen("E:\\db1.txt","w"))==NULL)
			{
				printf("打开文件失败！\n");
				exit(0);
			}
			while(p!=NULL)
			{
				for(int i=0;i<p->rows;i++)
				{
					if(strcmp(p->table[i],"")==0)
						continue;
					fprintf(fp,"%s%c%c",p->table[i],c,c);
					if(i==(p->rows-1))  fprintf(fp,"%c",a);    ///每一条记录写入完成后，换行
					if(p->rows==1)     ////文件中表名的下一行，加上  --------------- 换行
						fprintf(fp,"%s%c",ch,a);
				}

				p=p->next;
			}
			fclose(fp);
			////数据库数据字典文件
			char ch1[40]="file of data dictionary";
			char ch2[10]="      ";
			if((fp1=fopen("E:\\db11.txt","w"))==NULL)
			{
				printf("打开文件失败！\n");
				exit(0);
			}
			fprintf(fp,"%s%c%s%c",ch1,a,ch,a);     ///打印开头提示信息
			for(int i=0;i<index;i++)
			{
				fprintf(fp,"%s%s",data_diction[i],ch2);
				if(i%2==1)  fprintf(fp,"%c",a);
			}
		}
		if(i==1)  ///当为第2个表时
		{
			if((fp=fopen("E:\\db2.txt","w"))==NULL)
			{
				printf("打开文件失败！\n");
				exit(0);
			}
			while(p!=NULL)
			{
				for(int i=0;i<p->rows;i++)
				{
					if(strcmp(p->table[i],"")==0)
						continue;
					fprintf(fp,"%s%c%c",p->table[i],c,c);
					if(i==(p->rows-1))  fprintf(fp,"%c",a);
					if(p->rows==1)     ////文件中表名的下一行，加上  --------------- 换行
						fprintf(fp,"%s%c",ch,a);
				}

				p=p->next;
			}
			fclose(fp);
			////数据库数据字典文件
			char ch1[40]="file fo data dictionary";
			char ch2[10]="      ";
			if((fp1=fopen("E:\\db22.txt","w"))==NULL)
			{
				printf("打开文件失败！\n");
				exit(0);
			}
			fprintf(fp,"%s%c%s%c",ch1,a,ch,a);     ///打印开头提示信息
			for(int i=0;i<index;i++)
			{
				fprintf(fp,"%s%s",data_diction[i],ch2);
				if(i%2==1)  fprintf(fp,"%c",a);
			}
		}
		if(i==2)
		{
			if((fp=fopen("E:\\db3.txt","w"))==NULL)
			{
				printf("打开文件失败！\n");
				exit(0);
			}
			while(p!=NULL)
			{
				for(int i=0;i<p->rows;i++)
				{
					if(strcmp(p->table[i],"")==0)
						continue;
					fprintf(fp,"%s%c%c",p->table[i],c,c);
					if(i==(p->rows-1))  fprintf(fp,"%c",a);
					if(p->rows==1)     ////文件中表名的下一行，加上  --------------- 换行
						fprintf(fp,"%s%c",ch,a);
				}

				p=p->next;
			}
			fclose(fp);
			////数据库数据字典文件
			char ch1[40]="file fo data dictionary";
			char ch2[10]="      ";
			if((fp1=fopen("E:\\db33.txt","w"))==NULL)
			{
				printf("打开文件失败！\n");
				exit(0);
			}
			fprintf(fp,"%s%c%s%c",ch1,a,ch,a);     ///打印开头提示信息
			for(int i=0;i<index;i++)
			{
				fprintf(fp,"%s%s",data_diction[i],ch2);
				if(i%2==1)  fprintf(fp,"%c",a);
			}
		}
	}


}
///函数功能：利用索引完成选择
void Select_By_Index(char word1[N1][10],char word2[N1][10],int word_1,int word_2)
{
	SYSTEMTIME t1,t2;			 //用于计算时间
	int time;
	GetSystemTime(&t1);
	printf("%d:%d\n",t1.wSecond,t1.wMilliseconds);			//打印开始前的时间
    int i=0;
	int index=0;  ///用于记录索引下标
	int t=0;  ///用于记录Name属性对应的下标
	for( i=0;i<Table_Count;i++)
	{
		if(strcmp(Table_Array[i]->table[0],word2[1])==0)
			break;
	}
	Lnode * p=Table_Array[i];     ///找到链表的第一个节点
	puts(p->table[0]);    //打印表名
	printf("--------\n");

	p=p->next;
	p=p->next;   //为第三个结点
	Lnode * q=p;  //保存当前p的值
	for(index=0;index<3;index++)    ////在索引头结点数组中找到S_Id对应项
	{
		if(strcmp(word2[2],Index_Array[index]->key)==0)
			break; 
	}
	Index_Node * node=Index_Array[index];
	node=node->next;  
	
	if(strcmp(word2[3],">")==0)    ////当用索引完成大于选择时
	{
		while(node!=NULL)
	  {
		if(strcmp(node->key,word2[4])>0)    ///如果找到满足要求的记录，则打印
		{
			int temp=node->aim;    ///保存索引文件中的数据项
			while(temp>1)
			{
			    p=p->next;
			    temp--;
			}
             for(int i=0;i<p->rows;i++)
			 {
			   printf("%s\t",p->table[i]);
			 }
			 p=q;  ///指向链表的第一个数据结点
			 printf("\n");
		}
		node=node->next;
		}
	} 
	else if(strcmp(word2[3],"=")==0)
	{
		while(node!=NULL)
	  {
	    if(strcmp(node->key,word2[4])==0)    ///如果找到满足要求的记录，则打印
		{
			int temp=node->aim;    ///保存索引文件中的数据项
			while(temp>1)
			{
			    p=p->next;
			    temp--;
			}
             for(int i=0;i<p->rows;i++)
			 {
			   printf("%s\t",p->table[i]);
			 }
			 p=q;  ///指向链表的第一个数据结点
			 printf("\n");
		}
	     node=node->next;
		}
	}
	else if(strcmp(word2[3],"<")==0)
	{
		while(node!=NULL)
	  {
	    if(strcmp(node->key,word2[4])<0)    ///如果找到满足要求的记录，则打印
		{
			int temp=node->aim;    ///保存索引文件中的数据项
			while(temp>1)
			{
			    p=p->next;
			    temp--;
			}
             for(int i=0;i<p->rows;i++)
			 {
			   printf("%s\t",p->table[i]);
			 }
			 p=q;  ///指向链表的第一个数据结点
			 printf("\n");
		 }
	     node=node->next;
		}
	}
	GetSystemTime(&t2);
	printf("%d:%d\n",t2.wSecond,t2.wMilliseconds);					///打印执行之后的时间
	time=(t2.wSecond - t1.wSecond)*1000+t2.wMilliseconds-t1.wMilliseconds;				///求出总共用时
	printf("总共用时：  %d    微秒\n",time);
	printf("**************************************\n");
	printf("当不用索引进行选择时！\n");
	
	Single_Select(word1,word2,word_1,word_2);
}
///函数功能：删除索引*******************************************
void Drop_Index(char word1[N1][10],char word2[N1][10],int word_1,int word_2)
{
    //首先找到将要创建索引的表*********************************************************************************
	int i=0;
	int k=0;
	int t=1;   ///用于记录索引中的行号
	for( i=0;i<Table_Count;i++)
	{
		if(strcmp(Table_Array[i]->table[0],word2[1])==0)
			break;
	}
	////将创建的索引写入文件中
	char ch[40]="";
	FILE * fp;
	if(i==0)     ///第一个表时
	{
		if((fp=fopen("E:\\db_index_1.txt","w"))==NULL)
		{
			printf("打开文件失败！\n");
			exit(0);
		}
		fprintf(fp,"%s",ch);
		fclose(fp);
	}
	else if (i==1)    ///第二个表时
	{
		if((fp=fopen("E:\\db_index_2.txt","w"))==NULL)
		{
			printf("打开文件失败！\n");
			exit(0);
		}
		fprintf(fp,"%s",ch);
		fclose(fp);
	}
	else if (i==2)
	{
		if((fp=fopen("E:\\db_index_3.txt","w"))==NULL)
		{
			printf("打开文件失败！\n");
			exit(0);
		}
		fprintf(fp,"%s",ch);
		fclose(fp);
	}
}

////函数功能：为关系的主属性创建索引
void Create_Index_1(char word1[N1][10],char word2[N1][10],int word_1,int word_2)
{   //首先找到将要创建索引的表
	int i=0;
	int k=0;
	int t=1;   ///用于记录索引中的行号
	for( i=0;i<Table_Count;i++)
	{
		if(strcmp(Table_Array[i]->table[0],word2[1])==0)
			break;
	}

	Lnode *  p=Table_Array[i]->next;   ////找到链表的第二个节点，，
	for(k=0;k<p->rows;k++)    ///找到索引项对应的行号
	{
		if(strcmp(p->table[k],word2[0])==0)
			break;
	}
	Index_Node * head;
	head=(Index_Node *)malloc(sizeof(Index_Node));
	strcpy(head->key,word2[0]);     ///对头结点的初始化
	head->aim=-1;
	head->next=NULL;
	Index_Node * a;
	a=head;

	if(p->next!=NULL)     ///找到数据库链表的第三个节点
	{
		p=p->next;
	}
	while(p!=NULL)
	{
		Index_Node * b=(Index_Node *)malloc(sizeof(Index_Node));
		strcpy(b->key,p->table[k]);
		b->aim=t;
		t++;

		b->next=NULL;
		a->next=b;
		a=b;              ////把新申请的索引节点连接到链表的末尾
		p=p->next;
	}

	////将创建的索引写入文件中
	char ch[40]="-----------------------------";
	FILE * fp;
	if(i==0)     ///第一个表时
	{
		
		if((fp=fopen("E:\\db_index_1.txt","w"))==NULL)
		{
			printf("打开文件失败！\n");
			exit(0);
		}
		a=head;
		Index_Array[0]=a;
		while(a!=NULL)
		{
			fprintf(fp,"%s\t%d\n",a->key,a->aim);
			if(a==head)   fprintf(fp,"%s\n",ch);    ////第一行的后面加上  ------------------ 和换行
			a=a->next;
		}
		fclose(fp);
	}
	else if (i==1)    ///第二个表时
	{
		if((fp=fopen("E:\\db_index_2.txt","w"))==NULL)
		{
			printf("打开文件失败！\n");
			exit(0);
		}
		a=head;
		Index_Array[1]=a;
		while(a!=NULL)
		{
			fprintf(fp,"%s\t%d\n",a->key,a->aim);
			if(a==head)   fprintf(fp,"%s\n",ch);    ////第一行的后面加上  ------------------ 和换行
			a=a->next;
		}
		fclose(fp);
	}
	else if (i==2)   ///第三个表时
	{
		if((fp=fopen("E:\\db_index_3.txt","w"))==NULL)
		{
			printf("打开文件失败！\n");
			exit(0);
		}
		a=head;

		while(a!=NULL)
		{
			fprintf(fp,"%s\t%d\n",a->key,a->aim);
			if(a==head)   fprintf(fp,"%s\n",ch);    ////第一行的后面加上  ------------------ 和换行
			a=a->next;
		}
		fclose(fp);
	}
}
/*
///函数功能：完成删除索引的操作
void Drop_Index(char word1[N1][10],char word2[N1][10],int word_1,int word_2)
{
	////找到将要删除索引的位置
	int i=0;
	for( i=0;i<Index_Count;i++)
	{
		if(strcmp(Index_Array[i]->key,word2[1])==0)
			break;
	}
	Index_Node * q;
	Index_Node * p=Index_Array[i];
	while(p->next!=NULL)
	{
		q=p->next;
		free(p);
		p=q;
	}
	free(p);


	for( i=0;i<Table_Count;i++)
	{
		if(strcmp(Table_Array[i]->table[0],word2[1])==0)
			break;
	}
	////将创建的索引写入文件中
	char ch[40]="";
	FILE * fp;
	if(i==0)     ///第一个表时
	{
		if((fp=fopen("E:\\db_index_1.txt","w"))==NULL)
		{
			printf("打开文件失败！\n");
			exit(0);
		}
		fprintf(fp,"%s",ch);
		fclose(fp);
	}
	else if (i==1)    ///第二个表时
	{
		if((fp=fopen("E:\\db_index_2.txt","w"))==NULL)
		{
			printf("打开文件失败！\n");
			exit(0);
		}
		fprintf(fp,"%s",ch);
		fclose(fp);
	}
	else if (i==2)
	{
		if((fp=fopen("E:\\db_index_3.txt","w"))==NULL)
		{
			printf("打开文件失败！\n");
			exit(0);
		}
		fprintf(fp,"%s",ch);
		fclose(fp);
	}
}  
 */
///函数功能：将用户信息写入文件中
void Write_User_File()
{
	char array0[10]="Name";
	char array1[10]="Password";
	char array2[10]="Power";
	char t='\t';
	User * p=u0;   ///链表头结点
	FILE * fp;
	if((fp=fopen("E:\\user.txt","w"))==NULL)
	{
		printf("打开文件失败！\n");
		exit(0);
	}
	while(p!=NULL)
	{
		  if(p==u0)     ///第一行写入 Name  Password   Power 提示信息
		  {
		    fprintf(fp,"%s%c%c%s%c%c%s\n",array0,t,t,array1,t,t,array2);
		  }
		  fprintf(fp,"%s%c%c%s%c%c%c%s\n",p->name,t,t,p->password,t,t,t,p->power);    ///向文件中写入用户名，密码，权限
		p=p->next;
	}
	fclose(fp);
}
///函数功能：完成各类用户的创建
void Create_User()
{
	char y_n;
	char  name[10];
	char password[10];
	char power[10];
	///User 链表的第一个节点，存放管理员相关信息
	u0=(User *)malloc(sizeof(User));
	strcpy(u0->name,"admtor");
	strcpy(u0->password,"");
	strcpy(u0->power,"w");
	u0->next=NULL;
	printf("\n--------------------------------------------------------------------------\n");
	printf("用户权限说明：w--写，可以修改,查询数据库中的内容，r--读，只能查询数据库中的内容。\n");
	printf("--------------------------------------------------------------------------\n");
	printf("\n已经创建管理员（admtor），其权限为w,请输入管理管理员密码！\n");
	gets(password);
	strcpy(u0->password,password);
	printf("是否创建一般用户?(y or n)\n");
	scanf("%c",&y_n);
	User * p=u0;       ///指向当前链表的最后一个节点
	while(y_n=='y')    ///当创建用户时
	{

		printf("请输入用户名！\n");
		//gets(name);
		scanf("%s",name);
		getchar();
		printf("请输入密码!\n");
		// gets(password);
		scanf("%s",password);
		getchar();
		printf("请输入将要创建用户的权限!(w or r)\n");
		// gets(power);
		scanf("%s",power);
		getchar();
		User * u=(User *)malloc(sizeof(User));
		strcpy(u->name,name);
		strcpy(u->password,password);
		strcpy(u->power,power);
		u->next=NULL;
		p->next=u;
		p=u;
		printf("是否创建一般用户?(y or n)\n");
		scanf("%c",&y_n);
		getchar();
	}
	 Write_User_File();     ///将用户信息写入文件中
	system("cls");    ///清屏函数，清空屏幕
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
	char change='n';    ///是否切换用户的标记
	int finish=0;
	char  action[N];
	char  get[N1];
	char  name[10];     ///登录时用到的用户名，，密码数组
	char password[10];
	int i=0;
	//int use=0;
	int j=0;
	int sum=0;
	int run=-1;
	int k=0;
	char right[10];

AGAIN:	printf("请输入用户名！\n");
	//gets(name);
	scanf("%s",name);
	getchar();
	printf("请输入密码！\n");
	//gets(password);
	scanf("%s",password);
	getchar();
	User * login;
	login=u0;   ///头结点

	while(login!=NULL)
	{
		if(strcmp(login->name,name)==0)   ///当用户名相等时，判断密码是否相等
		{
			if(strcmp(login->password,password)==0)
			{
				printf("登录成功！\n");
				strcpy(right,login->power);   ///获取该用户的权限
				break;
			}
			else
			{
				printf("用户名，密码不符。登录失败！\n");
				goto AGAIN;
			}
		}
		login=login->next;
	}

	while(yes_no=='y')
	{
		int run=0;       ////用来表示数据库已经执行一遍
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

			if((ch>='0' && ch<='9')||(ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')||(ch=='*')||(ch=='>')||(ch=='=')||ch=='<' ||(ch=='_'))     //可能是关键字或者变量名
			{
				j=0;
				while((ch>='0'&&ch<='9')||(ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')||(ch=='*')||(ch=='>')||(ch=='=')||ch=='<'||(ch=='_'))
				{
					get[j++]=ch;
					i++;
					ch=action[i];
				}
				get[j++]='\0';      ////单词末尾赋值

				finish=0;
				for(k=0;k<M;k++)           /////和关键词数组中元素比较，找到匹配字符串
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
			/*
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
			}   */
			else           ///当ch为分界符时
			{
				//printf("分解符：  ");  
				//printf("(3,%c)\n",ch);
				i++;
				ch=action[i];
			}  
			//	length--;   
		}
		/*
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
		}  */
		if(strcmp(word1[0],"create")==0 &&strcmp(word1[1],"table")==0)    ////当是creat table 时，执行 creat_table函数
		{
			if(strcmp(right,"r")==0)
			{
				printf("当前用户权限不够！\n");
				goto  NEXT;
			}
			Create_Table(word1,word2,word_one,word_two);
			Write_To_File(word1,word2,word_one,word_two);
			run=1;
		}
		if(strcmp(word1[0],"drop")==0 && strcmp(word1[1],"table")==0)      ///当输入命令是 drop table 时，执行 drop_table函数
		{
			if(strcmp(right,"r")==0)
			{
				printf("当前用户权限不够！\n");
				goto  NEXT;
			}
			run=1;
			Drop_Table(word1,word2,word_one,word_two);
			Write_To_File(word1,word2,word_one,word_two);
		}

		if(strcmp(word1[0],"alter")==0 && strcmp(word1[1],"table")==0 && strcmp(word1[2],"add")==0)   ///当输入命令是  alter table stu add int age (关系中添加属性时)
		{
			if(strcmp(right,"r")==0)
			{
				printf("当前用户权限不够！\n");
				goto  NEXT;
			}
			run=1;
			printf("添加属性！\n");
			Add_Table(word1,word2,word_one,word_two);
			Write_To_File(word1,word2,word_one,word_two);

		}
		if(strcmp(word1[0],"alter")==0 && strcmp(word1[1],"table")==0 && strcmp(word1[2],"drop")==0)   ///当输入命令是  alter table stu add int age (关系中删除属性时)
		{
			if(strcmp(right,"r")==0)
			{
				printf("当前用户权限不够！\n");
				goto  NEXT;
			}
			run=1;
			printf("删除属性！\n");
			Drop_Column(word1,word2,word_one,word_two);
			Write_To_File(word1,word2,word_one,word_two);
		}
		if(strcmp(word1[0],"insert")==0 && strcmp(word1[1],"into")==0 && strcmp(word1[2],"values")==0)   ////当输入命令是向关系中添加元组时
		{
			if(strcmp(right,"r")==0)
			{
				printf("当前用户权限不够！\n");
				goto  NEXT;
			}
			run=1;
			printf("添加元组！\n");
			Insert_Into(word1,word2,word_one,word_two);
			Write_To_File(word1,word2,word_one,word_two);
		}
		if(strcmp(word1[0],"delete")==0 && strcmp(word1[1],"from")==0 && strcmp(word1[2],"where")==0)   ////当输入命令是在关系中删除元组时
		{
			if(strcmp(right,"r")==0)
			{
				printf("当前用户权限不够！\n");
				goto  NEXT;
			}
			run=1;
			printf("删除元组！\n");
			Delect_Row(word1,word2,word_one,word_two);
			Write_To_File(word1,word2,word_one,word_two);
		}
		if(strcmp(word1[0],"update")==0 && strcmp(word1[1],"set")==0 && strcmp(word1[2],"where")==0)     /////当输入命令是更新数据库时
		{
			if(strcmp(right,"r")==0)
			{
				printf("当前用户权限不够！\n");
				goto  NEXT;
			}
			run=1;
			printf("更新数据元素！\n");
			Update_Set(word1,word2,word_one,word_two);
			Write_To_File(word1,word2,word_one,word_two);
		}
		if(strcmp(word1[0],"select")==0 && strcmp(word1[1],"from")==0 && strcmp(word2[0],"*")==0 && word_one==2 && word_two==2)     ///当输入命令是  显示所有表内容时
		{
			run=1;
			printf("显示一个表的内容！\n");
			Select_From(word1,word2,word_one,word_two);
			//Write_To_File(word1,word2,word_one,word_two);
		}
		///
		if(strcmp(word1[0],"select")==0 && strcmp(word1[1],"from")==0 && strcmp(word1[2],"where")==0 && strcmp(word1[3],"by")==0)
		{
		  run=1;
		  printf("利用索引完成选择!\n");
		  Select_By_Index(word1,word2,word_one,word_two);
		}
		if(strcmp(word1[0],"select")==0 && strcmp(word1[1],"from")==0 && strcmp(word1[2],"where")==0 && strcmp(word2[0],"*")==0 && word_two==5)///最后一个条件对第二个数组d第一个为* 
		{
		   run=1;
			printf("单表选择！\n");
			Single_Select(word1,word2,word_one,word_two);
		}
		else if(strcmp(word1[0],"select")==0 && strcmp(word1[1],"from")==0 && strcmp(word1[2],"where")==0 && word_two==5)    ///最后一个条件对第二个数组大小进行限制
		{
			run=1;
			printf("实现单关系的选择和投影!\n");
			Single_Sele_Shadow(word1,word2,word_one,word_two);
		}
		else if(strcmp(word1[0],"select")==0 && strcmp(word1[1],"from")==0 && strcmp(word1[2],"where")==0 && strcmp(word1[3],"by")==0 && word_two>8)
		{
		  run=1;
		  printf("利用索引属性完成连接操作!\n");
		  Connct_By_Index(word1,word2,word_one,word_two);
		}
		else if(strcmp(word1[0],"select")==0 && strcmp(word1[1],"from")==0 && strcmp(word1[2],"where")==0 && strcmp(word2[0],"*")==0 && word_two==8)
		{ 
			run=1;
			printf("实现双表的连接!\n");
			Double_Connct(word1,word2,word_one,word_two);
		}
		else if(word_two==8)
		{
			run=1;
			printf("实现双表的投影和连接!\n");
			Double_Shadow_Connct(word1,word2,word_one,word_two);
		}
		else if(strcmp(word1[0],"select")==0 && strcmp(word1[1],"from")==0 && strcmp(word1[2],"where")==0 && strcmp(word1[3],"and")==0 && strcmp(word1[4],"and")==0)
		{
			run=1;
			printf("3个表的选择，连接和投影！\n");
			Many_Sel_Sha_Cont(word1,word2,word_one,word_two); 
		}
		else if(word_two==11)
		{
			run=1;
			printf("实现双表的选择连接！\n");
			Double_Select_Connt(word1,word2,word_one,word_two);
		}
		else if(strcmp(word1[0],"select")==0 && strcmp(word1[1],"from")==0 && word_two==2)   ///最后一个条件对第二个数组大小进行限制
		{
			run=1;
			printf("实现一个表中的投影操作！\n");
			Show_Column(word1,word2,word_one,word_two);
		}
		if(strcmp(word1[0],"create")==0 && strcmp(word1[1],"index")==0 && strcmp(word1[2],"on")==0)
		{
			if(strcmp(right,"r")==0)
			{
				printf("当前用户权限不够！\n");
				goto  NEXT;
			}
			run=1;
			printf("创建索引！\n");
			Create_Index_1(word1,word2,word_one,word_two);

		}
		if(strcmp(word1[0],"drop")==0 && strcmp(word1[1],"index")==0 && strcmp(word1[2],"on")==0)
		{
		    if(strcmp(right,"r")==0)
			{
				printf("当前用户权限不够！\n");
				goto  NEXT;
			}
			run=1;
			printf("删除索引！\n");
			Drop_Index(word1,word2,word_one,word_two);
		}
		if(run==0)   ///代表输入语句发生错误
		{
			printf("输入语法错误，请检查并重新输入!!!\n");
		}
		for(int i=0;i<10;i++)       ///  每一次循环之后，将 word 数组置空
		{
			strcpy(word1[i],"");
			strcpy(word2[i],"");        ///也可以调用memset（）函数
		}
		//strcpy(word1[1],"");
NEXT: printf("\n是否继续？（y or n）\n");
		scanf(" %c",&yes_no);
		getchar();

		printf("是否切换当前用户?(y or n)\n");
		scanf(" %c",&change);
		getchar();
		if(change=='y')   ///将要切换用户时,跳转
		{
			goto  AGAIN;
		}
		if(yes_no!='y' &&  yes_no!='n')  
		{
			printf("\n输入格式错误---请输入 y / n !\n");
			scanf("  %c",&yes_no);
			getchar();
			printf("%c",yes_no);
			printf("--------");
		}
	}


}
int _tmain(int argc, _TCHAR* argv[])
{
	void Init_dd();   ///初始化数据字典
	Create_User();     
	Function3();           ///执行操作命令
	return 0;
}






