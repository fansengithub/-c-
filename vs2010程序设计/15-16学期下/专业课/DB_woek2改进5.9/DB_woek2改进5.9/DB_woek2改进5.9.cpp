#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<windows.h>   ///����ʱ�����
#define N 100
#define N1 20
#define M 24
char   key2[M][10]={"create","table","drop","alter","insert","into","delete","from","update","select","grant","revoke","index","view","user","int","char","values","add","where","set","on","and","by"};
//char  * key1[5]={"creat table","drop table","altrer table","insert into","delect from"};

void Write_To_File(char word1[N1][10],char word2[N1][10],int word_1,int word_2);
///�����ṹ������
typedef struct Index_Node
{
	char key[10];    ///��ž����ID ���� 123
	int aim;       ///�����������  �� 3
	struct Index_Node * next;
}Index_Node;
///�ļ���¼�ṹ������
typedef struct Lnode
{
	char table[10][10];   ///��ά�������ڴ��ÿһ����¼---�ַ���
	int rows;         ////���ڼ�¼��ǰ��ǰ2ά�������˼���
	struct Lnode * next;        ///ָ����һ���ڵ�
}Lnode;
typedef struct User
{
	char name[10];    ///���ڴ��ÿһ���û���
	char password[10];    ///���ڴ���û�����Ӧ������
	char power[10];      ///��¼�û���Ȩ��
	struct User * next;
}User;
///User ����ĵ�һ���ڵ㣬��Ź���Ա�����Ϣ
User * u0;

///���������ֵ�
int index=1;
char data_diction[N][N];    ///���������ֵ�
Lnode * l1, *l2, *l3;
Lnode  * Table_Array[N1]={l1,l2,l3};   ///��������ͷ���
Index_Node * i1, *i2,*i3;
Index_Node * Index_Array[N1]={i1,i2,i3};
int Index_Count=3;  //���ڱ���Index_Array[]����
//Table_Array[];
int  Table_Count=0;     ///���ڱ���Table_Array[]����
//Lnode * L;     ///�����һ���ڵ�
////�������ܣ������ֵ�ĳ�ʼ��
void Init_dd()
{
	for(int i=0;i<N;i++)
	{
		strcpy(data_diction[i],"");
	}
	//  strcpy(data_diction[0],"��ϵ����   ");      ///�����һ�У�����ź��֣�
	// strcpy(data_diction[2],"��������   "); 
}
////�������ܣ�չʾ������������
void Show_Table(char word1[N1][10],char word2[N1][10],int word_1,int word_2)
{
	for(int i=0;i<Table_Count;i++)
	{
		if(Table_Array[i]==NULL)    ////����һ����ɾ��ʱ��ֱ��������һ���ļ�
			continue;    
		char temp[N1]="";
		//if(L==NULL)   printf("��ǰ���ݿ�Ϊ�գ�");  return ;
		Lnode *p;
		p=Table_Array[i];
		//printf("****************----------------\n");
		printf("���б�:");
		//strcpy(temp,p->table[0]);      ///��temp ��ʱ��� ��ϵ��  stu
		puts(p->table[0]);
		printf("\n----------------------------------------\n");
		//strcpy(p->table[0],"");
		p=p->next;
		while(p!=NULL)
		{
			for(int i=0;i<p->rows;i++)
			{	printf("\t");
			for(int j=0;p->table[i][j]!='\0';j++)      ///��ӡ�������ͱ��������
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
	//strcpy(L->table[0],temp);     ///ÿ�δ�ӡ��ϵ֮�󣬽���ϵ���ָ����´���.
}
///�������ܣ�ʵ�� creat table����
void  Create_Table(char word1[N1][10],char word2[N1][10],int word_1,int word_2)
{

	Lnode * L;     ///�����һ���ڵ�

	L=(Lnode *)malloc(sizeof(Lnode));       ///ͷ�������
	for(int i=0;i<10;i++)
	{
		strcpy(L->table[i],"");
	}
	L->rows=1;
	L->next=NULL;
	strcpy(L->table[0],word2[0]);          ///����ϵ������ͷ�����
	Table_Array[Table_Count]=L;
	Table_Count++;

	strcpy(data_diction[0],"table_name�� ");      ///�����һ�У�����ź��֣�
	strcpy(data_diction[2],"property�� "); 
	strcpy(data_diction[1],word2[0]);    ///����ϵ��д�������ļ�
	strcpy(data_diction[3],"    ");

	Lnode * p=(Lnode *)malloc(sizeof(Lnode));    ///����ڶ����ڵ��  ID  Name

	//Table_Array[Table_Count]=L;
	//printf("%d",Table_Array[0]->rows);
	for(int i=0;i<10;i++)                ///��ʼ���ڵ� 
	{
		strcpy(p->table[i],"");
	}
	p->rows=0;
	p->next=NULL;

	for(int i=0;i<(word_2-1);i++)
	{
		strcpy(p->table[i],word2[(i+1)]);      ///��   ID Name �����ڵ�2���ڵ���
		p->rows++;      ////��������+1
	}
	index=4;                ////�����ֵ��±��4��ʼ
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
////�������ܣ�ʵ��  drop table  (ɾ���½���Ĺ���)
void Drop_Table(char word1[N1][10],char word2[N1][10],int word_1,int word_2)
{
	char close[N1]="";
	///�ҵ���Ҫɾ����
	int i=0;
	for( i=0;i<Table_Count;i++)
	{
		if(strcmp(Table_Array[i]->table[0],word2[0])==0)
			break;
	}
	FILE * fp;
	FILE  * fp1;
	if(i==0)  ///ɾ����һ����
	{
		if((fp=fopen("E:\\db1.txt","w"))==NULL)         ////���ļ����
		{
			printf("���ļ�ʧ�ܣ�\n");
			exit(0);
		}
		fprintf(fp,"%s",close);         ////���ļ���д��հ׷�
		fclose(fp);

		if((fp1=fopen("E:\\db11.txt","w"))==NULL)         ////�������ֵ�������
		{
			printf("���ļ�ʧ�ܣ�\n");
			exit(0);
		}
		fprintf(fp1,"%s",close);      ///�������ֵ��ļ���д��ո��
		fclose(fp1);
	}
	if(i==1)     ///ɾ���ڶ�����
	{
		if((fp=fopen("E:\\db2.txt","w"))==NULL)         ////���ļ����
		{
			printf("���ļ�ʧ�ܣ�\n");
			exit(0);
		}
		fprintf(fp,"%s",close);
		fclose(fp);

		if((fp1=fopen("E:\\db22.txt","w"))==NULL)         ////�������ֵ�������
		{
			printf("���ļ�ʧ�ܣ�\n");
			exit(0);
		}
		fprintf(fp1,"%s",close);  
		fclose(fp1);
	}
	if(i==2)   
	{
		if((fp=fopen("E:\\db3.txt","w"))==NULL)         ////���ļ����
		{
			printf("���ļ�ʧ�ܣ�\n");
			exit(0);
		}
		fprintf(fp,"%s",close);
		fclose(fp);

		if((fp1=fopen("E:\\db33.txt","w"))==NULL)         ////�������ֵ�������
		{
			printf("���ļ�ʧ�ܣ�\n");
			exit(0);
		}
		fprintf(fp1,"%s",close);  
		fclose(fp1);
	}
	Lnode * q;
	Lnode *  p=Table_Array[i];
	Table_Array[i]=NULL;      ////��ָ�������еĶ�Ӧ���ƿ�
	while(p->next!=NULL)
	{
		q=p->next;
		free(p);
		p=q;
	}
	free(p);
	//L=NULL;        ///�������ÿ�
	Show_Table(word1,word2,word_1,word_2);
}
///�������ܣ�ʵ�� alter table ..add .int age  (������������ʱ)
void Add_Table(char word1[N1][10],char word2[N1][10],int word_1,int word_2)
{
	///�״��ҵ���Ҫ�����ı�
	int i=0;
	for( i=0;i<Table_Count;i++)
	{
		if(strcmp(Table_Array[i]->table[0],word2[0])==0)
			break;
	}

	Lnode *  p=Table_Array[i]->next;   ////�ҵ�����ĵڶ����ڵ㣬�����������

	//L->rows;
	strcpy(p->table[p->rows],word2[1]);
	p->rows++;       ///�ȸ��Ƶ� table �� row�У�Ȼ���1�����������±��0��ʼ

	strcpy(data_diction[(index++)],word1[3]);         ///�޸������ֵ�
	strcpy(data_diction[(index++)],word2[1]);

	Show_Table(word1,word2,word_1,word_2);
	/*
	printf("�����ֵ䣺\n");       ///��ӡ��������ֵ�����ݣ�
	for(int i=0;i<N;i++)
	{
	puts(data_diction[i]);
	}   */
}
///�������ܣ��ڹ�ϵ��ɾ����Ԫ��(ɾ������)
void Drop_Column(char word1[N1][10],char word2[N1][10],int word_1,int word_2)
{
	///�״��ҵ���Ҫ�����ı�
	int i=0;
	for( i=0;i<Table_Count;i++)
	{
		if(strcmp(Table_Array[i]->table[0],word2[0])==0)
			break;
	}

	Lnode *  p=Table_Array[i]->next;   ////�ҵ�����ĵڶ����ڵ㣬�����������
	i=0;
	int k=0;
	for(i=0;i<(p->rows-1);i++)
	{
		if(strcmp(p->table[i],word2[1])==0)     ///�ҵ� Age ��Ӧ���к�
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
	////�޸������ֵ� 
	for( k=3;k<index;k++)
	{
		if(strcmp(data_diction[k],word2[1])==0)    ///�������ֵ����ҵ� Age ��Ӧ���±�
			break;
	}
	strcpy(data_diction[k],"");      ///�������ֵ���ɾ��  Age
	index--;
	strcpy(data_diction[(k-1)],"");   ////�������ֵ���ɾ��  Age  ������
	index--;
	/*
	L->rows--;
	strcpy(L->table[L->rows],"");        ////����һ�����
	*/
	Show_Table(word1,word2,word_1,word_2);   
}
///�������ܣ��ڹ�ϵ�����Ԫ��
void Insert_Into(char word1[N1][10],char word2[N1][10],int word_1,int word_2)
{
	Lnode * p=(Lnode *)malloc(sizeof(Lnode));     ///����һ���µĽṹ�壬����Ԫ�����ݷ�������
	p->rows=0;
	p->next=NULL;
	for(int i=1;i<word_2;i++)
	{
		strcpy(p->table[(i-1)],word2[i]);
		p->rows++;
	}
	///�״��ҵ���Ҫ�����ı�
	int i=0;
	for( i=0;i<Table_Count;i++)
	{
		if(strcmp(Table_Array[i]->table[0],word2[0])==0)
			break;
	}

	Lnode *  q=Table_Array[i];   ////�ҵ�����ĵڶ����ڵ㣬��
	//	Lnode *q=L;
	while(q->next!=NULL)
	{
		q=q->next;    ///�ҵ������ĩ�ڵ�
	}
	q->next=p;
	Show_Table(word1,word2,word_1,word_2);
}
//�������ܣ��ڹ�ϵ��ɾ��һ��Ԫ��
void Delect_Row(char word1[N1][10],char word2[N1][10],int word_1,int word_2)
{
	///����ȷ�� ID ��Ӧ���±�   i
	int i=0;
	for( i=0;i<Table_Count;i++)
	{
		if(strcmp(Table_Array[i]->table[0],word2[0])==0)
			break;
	}

	Lnode *  p=Table_Array[i]->next;   ////�ҵ�����ĵڶ����ڵ㣬��
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
		if(strcmp(r->table[i],word2[2])==0)       ///�ҵ���Ӧ������Ԫ��
		{
			p->next=r->next;         ///��������ɾ���ýڵ�

		}
		p=r;
		r=r->next;
	}
	Show_Table(word1,word2,word_1,word_2);
}
///�������ܣ����¹�ϵ�е�����
void Update_Set(char word1[N1][10],char word2[N1][10],int word_1,int word_2)
{
	///����ȷ�� ID ��Ӧ���±�   i
	///����ȷ�� ID ��Ӧ���±�   i
	int i=0;
	for( i=0;i<Table_Count;i++)
	{
		if(strcmp(Table_Array[i]->table[0],word2[0])==0)
			break;
	}

	Lnode *  p=Table_Array[i]->next;   ////�ҵ�����ĵڶ����ڵ㣬��
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
		if(strcmp(p->table[j],word2[1])==0)     ///�ҵ�Age��Ӧ���±�    
		{
			break;
		}
	}
	Lnode * r;
	r=p->next;
	while(r!=NULL)
	{
		if(strcmp(r->table[i],word2[4])==0)    ///�ҵ�  ID=123
		{
			strcpy(r->table[j],word2[2]);      ///��  ID ��Ӧ�ڵ��  Age  �޸�Ϊ20

			//r->table[j]
		}
		r=r->next;
	}
	Show_Table(word1,word2,word_1,word_2);
}
////�������ܣ���ʾ������������
void Select_From(char word1[N1][10],char word2[N1][10],int word_1,int word_2)
{
	///����ȷ�� ID ��Ӧ���±�   i
	int i=0;
	for( i=0;i<Table_Count;i++)
	{
		if(strcmp(Table_Array[i]->table[0],word2[1])==0)
			break;
	}
	Lnode *  p=Table_Array[i];   ////�ҵ�����ĵ�1���ڵ㣬��
	printf("\n----------------------------------------\n");
	puts(p->table[0]);
	printf("\n----------------------------------------\n");
	//strcpy(p->table[0],"");
	p=p->next;
	while(p!=NULL)
	{
		for(int i=0;i<p->rows;i++)
		{	printf("\t");
		for(int j=0;p->table[i][j]!='\0';j++)      ///��ӡ�������ͱ��������
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
///�������ܣ�����ϵ��ͶӰ����
void Show_Column(char word1[N1][10],char word2[N1][10],int word_1,int word_2)
{
	int i=0;
	int t=0;  ///���ڼ�¼Name���Զ�Ӧ���±�
	for( i=0;i<Table_Count;i++)
	{
		if(strcmp(Table_Array[i]->table[0],word2[1])==0)
			break;
	}
	Lnode * p=Table_Array[i];     ///�ҵ�����ĵ�һ���ڵ�
	printf("\nͶӰ������\n");
	puts(p->table[0]);    //��ӡ����

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
///�������ܣ�ʵ�ֵ���ϵ��ѡ�����
void Single_Select(char word1[N1][10],char word2[N1][10],int word_1,int word_2)
{
	SYSTEMTIME t1,t2;			 //���ڼ���ʱ��
	int time;
	GetSystemTime(&t1);
	printf("%d:%d\n",t1.wSecond,t1.wMilliseconds);			//��ӡ��ʼǰ��ʱ��
	int i=0;
	int t=0;  ///���ڼ�¼Name���Զ�Ӧ���±�
	for( i=0;i<Table_Count;i++)
	{
		if(strcmp(Table_Array[i]->table[0],word2[1])==0)
			break;
	}
	Lnode * p=Table_Array[i];     ///�ҵ�����ĵ�һ���ڵ�
	puts(p->table[0]);    //��ӡ����
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
		if(strcmp(word2[3],">")==0)   ///��ѡ���ϵΪ  > ʱ
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
		if(strcmp(word2[3],"=")==0)   ///��ѡ���ϵΪ  =ʱ
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
		if(strcmp(word2[3],"<")==0)   ///��ѡ���ϵΪ  < ʱ
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
	printf("%d:%d\n",t2.wSecond,t2.wMilliseconds);					///��ӡִ��֮���ʱ��
	time=(t2.wSecond - t1.wSecond)*1000+t2.wMilliseconds-t1.wMilliseconds;				///����ܹ���ʱ
	printf("�ܹ���ʱ��  %d    ΢��\n",time);
}
///�������ܣ������������˫�������
void Connct_By_Index(char word1[N1][10],char word2[N1][10],int word_1,int word_2)
{
    SYSTEMTIME t1,t2;			 //���ڼ���ʱ��
	int time;
	GetSystemTime(&t1);
	printf("%d:%d\n",t1.wSecond,t1.wMilliseconds);			//��ӡ��ʼǰ��ʱ��
    int i=0;
	int j=0;
	int index1=0;  ///���ڼ�¼�����±�
	int index2=0;
	int t=0;  ///���ڼ�¼Name���Զ�Ӧ���±�
	for( i=0;i<Table_Count;i++)
	{
		if(strcmp(Table_Array[i]->table[0],word2[1])==0)
			break;
	}
	Lnode * p=Table_Array[i];     ///�ҵ�����ĵ�һ���ڵ�,,,,��һ���ļ�
	//puts(p->table[0]);    //��ӡ����

	for( j=0;j<Table_Count;j++)
	{
		if(strcmp(Table_Array[j]->table[0],word2[2])==0)
			break;
	}
	Lnode * q=Table_Array[j];     ///�ҵ�����ĵ�һ���ڵ㣬�������ڶ����ļ�
	//puts(q->table[0]);    //��ӡ����

	for(index1=0;index1<3;index1++)    ////������ͷ����������ҵ�S_Id��Ӧ��
	{
		if(strcmp(word2[4],Index_Array[index1]->key)==0)
			break; 
	}
	Index_Node * node1=Index_Array[index1];
	node1=node1->next;                    ///��node1��¼��һ�������ļ�

	for(index2=0;index2<3;index2++)    ////������ͷ����������ҵ�S_Id��Ӧ��
	{
		if(strcmp(word2[7],Index_Array[index2]->key)==0)
			break; 
	}
	Index_Node * node2=Index_Array[index2];
	node2=node2->next;                    ///��node1��¼��һ�������ļ�
}
///�������ܣ�ʵ��˫������
void Double_Connct(char word1[N1][10],char word2[N1][10],int word_1,int word_2)
{
	int i=0;
	int j=0;
	int t1=0;   ///��¼stu��name���Ե��±�
	int t2=0;    //��¼teachet��name���Ե��±�
	for( i=0;i<Table_Count;i++)
	{
		if(strcmp(Table_Array[i]->table[0],word2[1])==0)
			break;
	}
	Lnode * p=Table_Array[i];     ///�ҵ�stu �ļ�����ĵ�һ���ڵ�
	for( j=0;j<Table_Count;j++)
	{
		if(strcmp(Table_Array[j]->table[0],word2[2])==0)
			break;
	}
	Lnode * q=Table_Array[j];     ///�ҵ�teacher �ļ�����ĵ�һ���ڵ�

	p=p->next;              ////�ҵ�stu ��Name��Ӧ���±�
	for(t1=0;t1<p->rows;t1++) 
	{
		if(strcmp(word2[(word_2-1)],p->table[t1])==0)
			break;
	}

	q=q->next;    ////�ҵ�teach��Name��Ӧ���±�
	for(t2=0;t2<q->rows;t2++)
	{
		if(strcmp(word2[(word_2-1)],q->table[t2])==0)
			break;
	}

	p=p->next;   ///�ҵ�stu�ļ�����ĵ������ڵ�
	q=q->next;
	Lnode * x=q;   //�ݴ�����
	while(p!=NULL)     ///����ѭ��Ƕ�ף�������stu�������ڲ�ѭ������teach����
	{
		q=x;
		while(q!=NULL)
		{
			if(strcmp(p->table[t1],q->table[t2])==0)     ///���ҵ������������������ʱ
			{
				strcpy(p->table[p->rows],"yes");      //�������ж�ά������һ���Ϊ yes,�������
				strcpy(q->table[q->rows],"yes");
			}
			q=q->next;
		}
		p=p->next;
	}

	p=Table_Array[i];     ///ָ������ĵ�һ���ڵ�
	q=Table_Array[j];
	///��ʼ��ӡ��ǵ���
	puts(p->table[0]);       ///��ӡ��һ������
	printf("\n----------------------------------------\n");
	p=p->next->next;

	while(p!=NULL)
	{
		if(strcmp(p->table[p->rows],"yes")==0)    ///���б��ʱ,�Ŵ�ӡ����
		{
			for(int i=0;i<p->rows;i++)
			{	printf("\t");
			for(int j=0;p->table[i][j]!='\0';j++)      ///��ӡ�������ͱ��������
			{
				printf("%c",p->table[i][j]);
			}
			printf("\t");
			//if(i==0)  printf("\n----------------------------------\n\t");
			}
			strcpy(p->table[p->rows],"");     ///ʹ�ý���֮��������
		}
		p=p->next;
		printf("\n");
	}

	puts(q->table[0]);      ///��ӡ�ڶ�������
	printf("\n----------------------------------------\n");
	q=q->next->next;

	while(q!=NULL)
	{
		if(strcmp(q->table[q->rows],"yes")==0)    ///���б��ʱ,�Ŵ�ӡ����
		{
			for(int i=0;i<q->rows;i++)
			{	printf("\t");
			for(int j=0;q->table[i][j]!='\0';j++)      ///��ӡ�������ͱ��������
			{
				printf("%c",q->table[i][j]);
			}
			printf("\t");
			//if(i==0)  printf("\n----------------------------------\n\t");
			}
			strcpy(q->table[q->rows],"");     ///ʹ�ý���֮��������
		}
		q=q->next;
		printf("\n");
	}
}
///�������ܣ�ʵ��˫���ͶӰ������
void Double_Shadow_Connct(char word1[N1][10],char word2[N1][10],int word_1,int word_2)
{
	int i=0;
	int j=0;
	int y1=0;    //��¼stu��Id��Ӧ���±�
	int y2=0;
	int t1=0;   ///��¼stu��name���Ե��±�
	int t2=0;    //��¼teachet��name���Ե��±�
	for( i=0;i<Table_Count;i++)
	{
		if(strcmp(Table_Array[i]->table[0],word2[1])==0)
			break;
	}
	Lnode * p=Table_Array[i];     ///�ҵ�stu �ļ�����ĵ�һ���ڵ�
	for( j=0;j<Table_Count;j++)
	{
		if(strcmp(Table_Array[j]->table[0],word2[2])==0)
			break;
	}
	Lnode * q=Table_Array[j];     ///�ҵ�teacher �ļ�����ĵ�һ���ڵ�

	p=p->next;              ////�ҵ�stu ��Name��Ӧ���±�
	for(t1=0;t1<p->rows;t1++) 
	{
		if(strcmp(word2[(word_2-1)],p->table[t1])==0)
			break;
	}
	for(y1=0;y1<p->rows;y1++)  ///�ҵ�stu�� Id ��Ӧ���±�
	{
		if(strcmp(word2[0],p->table[y1])==0)
			break;
	}

	q=q->next;    ////�ҵ�teach��Name��Ӧ���±�
	for(t2=0;t2<q->rows;t2++)
	{
		if(strcmp(word2[(word_2-1)],q->table[t2])==0)
			break;
	}
	for(y2=0;y2<q->rows;y2++)  ///�ҵ�teacher�� Id ��Ӧ���±�
	{
		if(strcmp(word2[0],q->table[y2])==0)
			break;
	}

	p=p->next;   ///�ҵ�stu�ļ�����ĵ������ڵ�
	q=q->next;
	Lnode * x=q;   //�ݴ�����
	while(p!=NULL)     ///����ѭ��Ƕ�ף�������stu�������ڲ�ѭ������teach����
	{
		q=x;
		while(q!=NULL)
		{
			if(strcmp(p->table[t1],q->table[t2])==0)     ///���ҵ������������������ʱ
			{
				strcpy(p->table[p->rows],"yes");      //�������ж�ά������һ���Ϊ yes,�������
				strcpy(q->table[q->rows],"yes");
			}
			q=q->next;
		}
		p=p->next;
	}

	p=Table_Array[i];     ///ָ������ĵ�һ���ڵ�
	q=Table_Array[j];
	///��ʼ��ӡ��ǵ���
	puts(p->table[0]);       ///��ӡ��һ������
	printf("-------------------\n");
	p=p->next->next;

	while(p!=NULL)
	{
		if(strcmp(p->table[p->rows],"yes")==0)    ///���б��ʱ,�Ŵ�ӡ����
		{
			printf("%s\n",p->table[y1]);
			strcpy(p->table[p->rows],"");     ///ʹ�ý���֮��������
		}
		p=p->next;
		//	printf("\n");
	}
	printf("\n");
	puts(q->table[0]);      ///��ӡ�ڶ�������
	printf("-------------------\n");
	q=q->next->next;

	while(q!=NULL)
	{
		if(strcmp(q->table[q->rows],"yes")==0)    ///���б��ʱ,�Ŵ�ӡ����
		{
			printf("%s\n",q->table[y2]);
			strcpy(q->table[q->rows],"");     ///ʹ�ý���֮��������
		}
		q=q->next;
		//	printf("\n");
	}
}
///�������ܣ�ʵ�ֶ���ѡ��ͶӰ������
void Many_Sel_Sha_Cont(char word1[N1][10],char word2[N1][10],int word_1,int word_2)
{  

	int t1=0;   ///��¼c��c_name���Ե��±�
	int t2=0;    ///��¼c��c_Id ���Ե��±�
	int t3=0;    ///��¼sc��c_Id ���Ե��±�
	int t4=0;    ///��¼sc��s_Id ���Ե��±�
	int t5=0;
	int t6=0;
	int i=0;
	for( i=0;i<Table_Count;i++)
	{
		if(strcmp(Table_Array[i]->table[0],word2[2])==0)
			break;
	}
	Lnode * p=Table_Array[i];     ///�ҵ�c �ļ�����ĵ�һ���ڵ�

	p=p->next;              ////�ҵ�c ��c_name ��Ӧ���±�
	for(t1=0;t1<p->rows;t1++) 
	{
		if(strcmp(word2[3],p->table[t1])==0)
			break;
	}
	for(t2=0;t2<p->rows;t2++)     ///��¼c��c_Id ���Ե��±�
	{
		if(strcmp(word2[7],p->table[t2])==0)
			break;
	}

	for( i=0;i<Table_Count;i++)
	{
		if(strcmp(Table_Array[i]->table[0],word2[9])==0)
			break;
	}
	Lnode * q=Table_Array[i];     ///�ҵ�sc�ļ�����ĵ�һ���ڵ�
	q=q->next;
	for(t3=0;t3<q->rows;t3++)    ///��¼sc��c_Id ���Ե��±�
	{
		if(strcmp(word2[10],q->table[t3])==0)
			break;
	}
	for(t4=0;t4<q->rows;t4++)    ///��¼sc��s_Id ���Ե��±�
	{
		if(strcmp(word2[12],q->table[t4])==0)
			break;
	}
	q=q->next;
	Lnode * q1=q;    ///��¼�µ�ǰ����ĵ������ڵ�

	for( i=0;i<Table_Count;i++)
	{
		if(strcmp(Table_Array[i]->table[0],word2[14])==0)
			break;
	}
	Lnode * r=Table_Array[i];     ///�ҵ�s�ļ�����ĵ�һ���ڵ�
	Lnode * r1=r;    ///��¼�µ�ǰ����ĵ�1���ڵ�
	r=r->next;
	for(t5=0;t5<r->rows;t5++)    ///��¼s��s_Id ���Ե��±�
	{
		if(strcmp(word2[15],r->table[t5])==0)
			break;
	}
	for(t6=0;t6<r->rows;t6++)    ///��¼s��s_Name ���Ե��±�
	{
		if(strcmp(word2[0],r->table[t6])==0)
			break;
	}
	r=r->next;


	p=p->next;
	Lnode * p1=p;    ///��¼�µ�ǰ����ĵ������ڵ�
	while(p!=NULL)
	{
		if(strcmp(p->table[t1],word2[5])==0)   //���ҵ������һ������ʱ( c_name= math )���������
		{
			strcpy(p->table[p->rows],"yes"); 
			// break;
		}
		p=p->next;
	}

	p=p1;
	while(p!=NULL)     ///����ѭ���������Ӳ����������� c ���ڲ���� sc ��
	{
		if(strcmp(p->table[p->rows],"yes")==0)     ///���ҵ�������ǵ���ʱ
		{
			while(q!=NULL)
			{
				if(strcmp(p->table[t2],q->table[t3])==0)  ///������������ͬʱ
				{
					strcpy(q->table[q->rows],"yes");
				}
				q=q->next;
			}
			strcpy(p->table[p->rows],"");    ///ʹ�ý���֮��������
		}
		p=p->next;
	}

	q=q1;
	while(q!=NULL)    ///����ѭ���������Ӳ����������� sc���ڲ���� s ��
	{
		if(strcmp(q->table[q->rows],"yes")==0)    ///���ҵ�������ǵ���ʱ
		{
			while(r!=NULL)
			{
				if(strcmp(q->table[t4],r->table[t5])==0)  ///������������ͬʱ
				{
					strcpy(r->table[r->rows],"yes");
				}
				r=r->next;
			}
			strcpy(q->table[q->rows],"");    ///ʹ�ý���֮��������
		}
		q=q->next;
	}

	r=r1;
	printf("\n");
	puts(r->table[0]);      ///��ӡ����
	printf("-------------------\n");
	r=r->next->next;
	while(r!=NULL)
	{
		if(strcmp(r->table[r->rows],"yes")==0)
		{
			printf("%s\n",r->table[t6]);
			strcpy(r->table[r->rows],"");    ///ʹ�ý���֮��������
		}
		r=r->next;
	}
}
//�������ܣ�ʵ��˫���ѡ������
void Double_Select_Connt(char word1[N1][10],char word2[N1][10],int word_1,int word_2)
{
	///�Ƚ���˫�����Ӳ���
	int i=0;
	int j=0;
	int t1=0;   ///��¼stu��name���Ե��±�
	int t2=0;    //��¼teacher��name���Ե��±�
	int y1=0;    ///��¼stu��ID���Ե��±�
	int y2=0;	 //��¼teacher��ID���Ե��±�
	for( i=0;i<Table_Count;i++)
	{
		if(strcmp(Table_Array[i]->table[0],word2[1])==0)
			break;
	}
	Lnode * p=Table_Array[i];     ///�ҵ�stu �ļ�����ĵ�һ���ڵ�
	for( j=0;j<Table_Count;j++)
	{
		if(strcmp(Table_Array[j]->table[0],word2[2])==0)
			break;
	}
	Lnode * q=Table_Array[j];     ///�ҵ�teacher �ļ�����ĵ�һ���ڵ�

	p=p->next;              ////�ҵ�stu ��Name��Ӧ���±�
	for(t1=0;t1<p->rows;t1++) 
	{
		if(strcmp(word2[(word_2-1)],p->table[t1])==0)
			break;
	}
	for(y1=0;y1<p->rows;y1++)    ////�ҵ�stu ��ID��Ӧ���±�
	{
		if(strcmp(word2[3],p->table[y1])==0)
			break;
	}

	q=q->next;    ////�ҵ�teach��Name��Ӧ���±�
	for(t2=0;t2<q->rows;t2++)
	{
		if(strcmp(word2[(word_2-1)],q->table[t2])==0)
			break;
	}
	for(y2=0;y2<p->rows;y2++)    ////�ҵ�teacher ��ID��Ӧ���±�
	{
		if(strcmp(word2[3],p->table[y2])==0)
			break;
	}

	p=p->next;   ///�ҵ�stu�ļ�����ĵ������ڵ�
	q=q->next;
	Lnode * x=q;   //�ݴ�����
	while(p!=NULL)     ///����ѭ��Ƕ�ף�������stu�������ڲ�ѭ������teach����
	{
		q=x;
		while(q!=NULL)
		{
			if(strcmp(p->table[t1],q->table[t2])==0 )     ///���ҵ������������������ʱ---����1�ж�
			{
				if(strcmp(word2[4],">")==0)   ///��ѡ���ϵΪ  > ,,,����2�ж�
				{
					if(strcmp(p->table[y1],word2[5])>0 && strcmp(q->table[y2],word2[5])>0)
					{
						strcpy(p->table[p->rows],"yes");      //�������ж�ά������һ���Ϊ yes,�������
						strcpy(q->table[q->rows],"yes");
					}
				}
				if(strcmp(word2[4],"=")==0)   ///��ѡ���ϵΪ  =ʱ
				{
					if(strcmp(p->table[y1],word2[5])==0 && strcmp(q->table[y2],word2[5])==0)    
					{
						strcpy(p->table[p->rows],"yes");      //�������ж�ά������һ���Ϊ yes,�������
						strcpy(q->table[q->rows],"yes");
					}
				}
				if(strcmp(word2[3],"<")==0)   ///��ѡ���ϵΪ  < ʱ
				{
					if(strcmp(p->table[y1],word2[5])<0 && strcmp(q->table[y2],word2[5])<0)
					{
						strcpy(p->table[p->rows],"yes");      //�������ж�ά������һ���Ϊ yes,�������
						strcpy(q->table[q->rows],"yes");
					}
				}
			}
			q=q->next;
		}
		p=p->next;
	}


	p=Table_Array[i];     ///ָ������ĵ�һ���ڵ�
	q=Table_Array[j];
	///��ʼ��ӡ��ǵ���
	puts(p->table[0]);       ///��ӡ��һ������
	printf("\n----------------------------------------\n");
	p=p->next->next;

	while(p!=NULL)
	{
		if(strcmp(p->table[p->rows],"yes")==0)    ///���б��ʱ,�Ŵ�ӡ����
		{
			for(int i=0;i<p->rows;i++)
			{	printf("\t");
			for(int j=0;p->table[i][j]!='\0';j++)      ///��ӡ�������ͱ��������
			{
				printf("%c",p->table[i][j]);
			}
			printf("\t");
			//if(i==0)  printf("\n----------------------------------\n\t");
			}
			strcpy(p->table[p->rows],"");     ///ʹ�ý���֮��������
		}
		p=p->next;
		printf("\n");
	}

	puts(q->table[0]);      ///��ӡ�ڶ�������
	printf("\n----------------------------------------\n");
	q=q->next->next;

	while(q!=NULL)
	{
		if(strcmp(q->table[q->rows],"yes")==0)    ///���б��ʱ,�Ŵ�ӡ����
		{
			for(int i=0;i<q->rows;i++)
			{	printf("\t");
			for(int j=0;q->table[i][j]!='\0';j++)      ///��ӡ�������ͱ��������
			{
				printf("%c",q->table[i][j]);
			}
			printf("\t");
			//if(i==0)  printf("\n----------------------------------\n\t");
			}
			strcpy(q->table[q->rows],"");     ///ʹ�ý���֮��������
		}
		q=q->next;
		printf("\n");
	}
}
///�������ܣ�ʵ�ֵ���ϵ��ѡ���ͶӰ����
void  Single_Sele_Shadow(char word1[N1][10],char word2[N1][10],int word_1,int word_2)
{
	int i=0;
	int t=0;  ///���ڼ�¼Name���Զ�Ӧ���±�
	int  k=0;  ///���ڼ�¼Id���Զ�Ӧ���±�
	for( i=0;i<Table_Count;i++)     ///�ҵ�������ݿ��ļ��е�һ��
	{
		if(strcmp(Table_Array[i]->table[0],word2[1])==0)
			break;
	}
	Lnode * p=Table_Array[i];     ///�ҵ�����ĵ�һ���ڵ�
	puts(p->table[0]);    //��ӡ����
	printf("--------\n");

	p=p->next;     ///��ת���ڶ����ڵ�
	for(t=0;t<p->rows;t++)      ///�ҵ�Name���Զ�Ӧ���±�
	{
		if(strcmp(word2[0],p->table[t])==0)
			break;
	}
	for(k=0;k<p->rows;k++)      ///�ҵ�Id���Զ�Ӧ���±�
	{
		if(strcmp(word2[2],p->table[k])==0)
			break;
	}
	p=p->next;    ///��ת���������ڵ�
	while(p!=NULL)
	{
		if(strcmp(word2[3],">")==0)   ///��ѡ���ϵΪ  > ʱ
		{
			if(strcmp(p->table[k],word2[4])>0)    printf("%s\n",p->table[t]);
		}
		if(strcmp(word2[3],"=")==0)   ///��ѡ���ϵΪ  =ʱ
		{
			if(strcmp(p->table[k],word2[4])==0)    printf("%s\n",p->table[t]);
		}
		if(strcmp(word2[3],"<")==0)   ///��ѡ���ϵΪ  < ʱ
		{
			if(strcmp(p->table[k],word2[4])<0)    printf("%s\n",p->table[t]);
		}

		p=p->next;
	}
}
///�������ܣ������ݿ��д���ļ���
void Write_To_File(char word1[N1][10],char word2[N1][10],int word_1,int word_2)
{
	///����ȷ�� ID ��Ӧ���±�   i
	int i=0;
	for( i=0;i<Table_Count;i++)
	{
		Lnode *  p=Table_Array[i];   ////�ҵ�����ĵ�i���ڵ㣬��
		//Lnode * p=L;
		FILE * fp;
		FILE * fp1;
		char c='\t';
		char a='\n';
		char ch[40]="-----------------------------";
		//���ݿ����ļ�
		if(i==0)    ////����һ����ʱ
		{
			if((fp=fopen("E:\\db1.txt","w"))==NULL)
			{
				printf("���ļ�ʧ�ܣ�\n");
				exit(0);
			}
			while(p!=NULL)
			{
				for(int i=0;i<p->rows;i++)
				{
					if(strcmp(p->table[i],"")==0)
						continue;
					fprintf(fp,"%s%c%c",p->table[i],c,c);
					if(i==(p->rows-1))  fprintf(fp,"%c",a);    ///ÿһ����¼д����ɺ󣬻���
					if(p->rows==1)     ////�ļ��б�������һ�У�����  --------------- ����
						fprintf(fp,"%s%c",ch,a);
				}

				p=p->next;
			}
			fclose(fp);
			////���ݿ������ֵ��ļ�
			char ch1[40]="file of data dictionary";
			char ch2[10]="      ";
			if((fp1=fopen("E:\\db11.txt","w"))==NULL)
			{
				printf("���ļ�ʧ�ܣ�\n");
				exit(0);
			}
			fprintf(fp,"%s%c%s%c",ch1,a,ch,a);     ///��ӡ��ͷ��ʾ��Ϣ
			for(int i=0;i<index;i++)
			{
				fprintf(fp,"%s%s",data_diction[i],ch2);
				if(i%2==1)  fprintf(fp,"%c",a);
			}
		}
		if(i==1)  ///��Ϊ��2����ʱ
		{
			if((fp=fopen("E:\\db2.txt","w"))==NULL)
			{
				printf("���ļ�ʧ�ܣ�\n");
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
					if(p->rows==1)     ////�ļ��б�������һ�У�����  --------------- ����
						fprintf(fp,"%s%c",ch,a);
				}

				p=p->next;
			}
			fclose(fp);
			////���ݿ������ֵ��ļ�
			char ch1[40]="file fo data dictionary";
			char ch2[10]="      ";
			if((fp1=fopen("E:\\db22.txt","w"))==NULL)
			{
				printf("���ļ�ʧ�ܣ�\n");
				exit(0);
			}
			fprintf(fp,"%s%c%s%c",ch1,a,ch,a);     ///��ӡ��ͷ��ʾ��Ϣ
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
				printf("���ļ�ʧ�ܣ�\n");
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
					if(p->rows==1)     ////�ļ��б�������һ�У�����  --------------- ����
						fprintf(fp,"%s%c",ch,a);
				}

				p=p->next;
			}
			fclose(fp);
			////���ݿ������ֵ��ļ�
			char ch1[40]="file fo data dictionary";
			char ch2[10]="      ";
			if((fp1=fopen("E:\\db33.txt","w"))==NULL)
			{
				printf("���ļ�ʧ�ܣ�\n");
				exit(0);
			}
			fprintf(fp,"%s%c%s%c",ch1,a,ch,a);     ///��ӡ��ͷ��ʾ��Ϣ
			for(int i=0;i<index;i++)
			{
				fprintf(fp,"%s%s",data_diction[i],ch2);
				if(i%2==1)  fprintf(fp,"%c",a);
			}
		}
	}


}
///�������ܣ������������ѡ��
void Select_By_Index(char word1[N1][10],char word2[N1][10],int word_1,int word_2)
{
	SYSTEMTIME t1,t2;			 //���ڼ���ʱ��
	int time;
	GetSystemTime(&t1);
	printf("%d:%d\n",t1.wSecond,t1.wMilliseconds);			//��ӡ��ʼǰ��ʱ��
    int i=0;
	int index=0;  ///���ڼ�¼�����±�
	int t=0;  ///���ڼ�¼Name���Զ�Ӧ���±�
	for( i=0;i<Table_Count;i++)
	{
		if(strcmp(Table_Array[i]->table[0],word2[1])==0)
			break;
	}
	Lnode * p=Table_Array[i];     ///�ҵ�����ĵ�һ���ڵ�
	puts(p->table[0]);    //��ӡ����
	printf("--------\n");

	p=p->next;
	p=p->next;   //Ϊ���������
	Lnode * q=p;  //���浱ǰp��ֵ
	for(index=0;index<3;index++)    ////������ͷ����������ҵ�S_Id��Ӧ��
	{
		if(strcmp(word2[2],Index_Array[index]->key)==0)
			break; 
	}
	Index_Node * node=Index_Array[index];
	node=node->next;  
	
	if(strcmp(word2[3],">")==0)    ////����������ɴ���ѡ��ʱ
	{
		while(node!=NULL)
	  {
		if(strcmp(node->key,word2[4])>0)    ///����ҵ�����Ҫ��ļ�¼�����ӡ
		{
			int temp=node->aim;    ///���������ļ��е�������
			while(temp>1)
			{
			    p=p->next;
			    temp--;
			}
             for(int i=0;i<p->rows;i++)
			 {
			   printf("%s\t",p->table[i]);
			 }
			 p=q;  ///ָ������ĵ�һ�����ݽ��
			 printf("\n");
		}
		node=node->next;
		}
	} 
	else if(strcmp(word2[3],"=")==0)
	{
		while(node!=NULL)
	  {
	    if(strcmp(node->key,word2[4])==0)    ///����ҵ�����Ҫ��ļ�¼�����ӡ
		{
			int temp=node->aim;    ///���������ļ��е�������
			while(temp>1)
			{
			    p=p->next;
			    temp--;
			}
             for(int i=0;i<p->rows;i++)
			 {
			   printf("%s\t",p->table[i]);
			 }
			 p=q;  ///ָ������ĵ�һ�����ݽ��
			 printf("\n");
		}
	     node=node->next;
		}
	}
	else if(strcmp(word2[3],"<")==0)
	{
		while(node!=NULL)
	  {
	    if(strcmp(node->key,word2[4])<0)    ///����ҵ�����Ҫ��ļ�¼�����ӡ
		{
			int temp=node->aim;    ///���������ļ��е�������
			while(temp>1)
			{
			    p=p->next;
			    temp--;
			}
             for(int i=0;i<p->rows;i++)
			 {
			   printf("%s\t",p->table[i]);
			 }
			 p=q;  ///ָ������ĵ�һ�����ݽ��
			 printf("\n");
		 }
	     node=node->next;
		}
	}
	GetSystemTime(&t2);
	printf("%d:%d\n",t2.wSecond,t2.wMilliseconds);					///��ӡִ��֮���ʱ��
	time=(t2.wSecond - t1.wSecond)*1000+t2.wMilliseconds-t1.wMilliseconds;				///����ܹ���ʱ
	printf("�ܹ���ʱ��  %d    ΢��\n",time);
	printf("**************************************\n");
	printf("��������������ѡ��ʱ��\n");
	
	Single_Select(word1,word2,word_1,word_2);
}
///�������ܣ�ɾ������*******************************************
void Drop_Index(char word1[N1][10],char word2[N1][10],int word_1,int word_2)
{
    //�����ҵ���Ҫ���������ı�*********************************************************************************
	int i=0;
	int k=0;
	int t=1;   ///���ڼ�¼�����е��к�
	for( i=0;i<Table_Count;i++)
	{
		if(strcmp(Table_Array[i]->table[0],word2[1])==0)
			break;
	}
	////������������д���ļ���
	char ch[40]="";
	FILE * fp;
	if(i==0)     ///��һ����ʱ
	{
		if((fp=fopen("E:\\db_index_1.txt","w"))==NULL)
		{
			printf("���ļ�ʧ�ܣ�\n");
			exit(0);
		}
		fprintf(fp,"%s",ch);
		fclose(fp);
	}
	else if (i==1)    ///�ڶ�����ʱ
	{
		if((fp=fopen("E:\\db_index_2.txt","w"))==NULL)
		{
			printf("���ļ�ʧ�ܣ�\n");
			exit(0);
		}
		fprintf(fp,"%s",ch);
		fclose(fp);
	}
	else if (i==2)
	{
		if((fp=fopen("E:\\db_index_3.txt","w"))==NULL)
		{
			printf("���ļ�ʧ�ܣ�\n");
			exit(0);
		}
		fprintf(fp,"%s",ch);
		fclose(fp);
	}
}

////�������ܣ�Ϊ��ϵ�������Դ�������
void Create_Index_1(char word1[N1][10],char word2[N1][10],int word_1,int word_2)
{   //�����ҵ���Ҫ���������ı�
	int i=0;
	int k=0;
	int t=1;   ///���ڼ�¼�����е��к�
	for( i=0;i<Table_Count;i++)
	{
		if(strcmp(Table_Array[i]->table[0],word2[1])==0)
			break;
	}

	Lnode *  p=Table_Array[i]->next;   ////�ҵ�����ĵڶ����ڵ㣬��
	for(k=0;k<p->rows;k++)    ///�ҵ��������Ӧ���к�
	{
		if(strcmp(p->table[k],word2[0])==0)
			break;
	}
	Index_Node * head;
	head=(Index_Node *)malloc(sizeof(Index_Node));
	strcpy(head->key,word2[0]);     ///��ͷ���ĳ�ʼ��
	head->aim=-1;
	head->next=NULL;
	Index_Node * a;
	a=head;

	if(p->next!=NULL)     ///�ҵ����ݿ�����ĵ������ڵ�
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
		a=b;              ////��������������ڵ����ӵ������ĩβ
		p=p->next;
	}

	////������������д���ļ���
	char ch[40]="-----------------------------";
	FILE * fp;
	if(i==0)     ///��һ����ʱ
	{
		
		if((fp=fopen("E:\\db_index_1.txt","w"))==NULL)
		{
			printf("���ļ�ʧ�ܣ�\n");
			exit(0);
		}
		a=head;
		Index_Array[0]=a;
		while(a!=NULL)
		{
			fprintf(fp,"%s\t%d\n",a->key,a->aim);
			if(a==head)   fprintf(fp,"%s\n",ch);    ////��һ�еĺ������  ------------------ �ͻ���
			a=a->next;
		}
		fclose(fp);
	}
	else if (i==1)    ///�ڶ�����ʱ
	{
		if((fp=fopen("E:\\db_index_2.txt","w"))==NULL)
		{
			printf("���ļ�ʧ�ܣ�\n");
			exit(0);
		}
		a=head;
		Index_Array[1]=a;
		while(a!=NULL)
		{
			fprintf(fp,"%s\t%d\n",a->key,a->aim);
			if(a==head)   fprintf(fp,"%s\n",ch);    ////��һ�еĺ������  ------------------ �ͻ���
			a=a->next;
		}
		fclose(fp);
	}
	else if (i==2)   ///��������ʱ
	{
		if((fp=fopen("E:\\db_index_3.txt","w"))==NULL)
		{
			printf("���ļ�ʧ�ܣ�\n");
			exit(0);
		}
		a=head;

		while(a!=NULL)
		{
			fprintf(fp,"%s\t%d\n",a->key,a->aim);
			if(a==head)   fprintf(fp,"%s\n",ch);    ////��һ�еĺ������  ------------------ �ͻ���
			a=a->next;
		}
		fclose(fp);
	}
}
/*
///�������ܣ����ɾ�������Ĳ���
void Drop_Index(char word1[N1][10],char word2[N1][10],int word_1,int word_2)
{
	////�ҵ���Ҫɾ��������λ��
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
	////������������д���ļ���
	char ch[40]="";
	FILE * fp;
	if(i==0)     ///��һ����ʱ
	{
		if((fp=fopen("E:\\db_index_1.txt","w"))==NULL)
		{
			printf("���ļ�ʧ�ܣ�\n");
			exit(0);
		}
		fprintf(fp,"%s",ch);
		fclose(fp);
	}
	else if (i==1)    ///�ڶ�����ʱ
	{
		if((fp=fopen("E:\\db_index_2.txt","w"))==NULL)
		{
			printf("���ļ�ʧ�ܣ�\n");
			exit(0);
		}
		fprintf(fp,"%s",ch);
		fclose(fp);
	}
	else if (i==2)
	{
		if((fp=fopen("E:\\db_index_3.txt","w"))==NULL)
		{
			printf("���ļ�ʧ�ܣ�\n");
			exit(0);
		}
		fprintf(fp,"%s",ch);
		fclose(fp);
	}
}  
 */
///�������ܣ����û���Ϣд���ļ���
void Write_User_File()
{
	char array0[10]="Name";
	char array1[10]="Password";
	char array2[10]="Power";
	char t='\t';
	User * p=u0;   ///����ͷ���
	FILE * fp;
	if((fp=fopen("E:\\user.txt","w"))==NULL)
	{
		printf("���ļ�ʧ�ܣ�\n");
		exit(0);
	}
	while(p!=NULL)
	{
		  if(p==u0)     ///��һ��д�� Name  Password   Power ��ʾ��Ϣ
		  {
		    fprintf(fp,"%s%c%c%s%c%c%s\n",array0,t,t,array1,t,t,array2);
		  }
		  fprintf(fp,"%s%c%c%s%c%c%c%s\n",p->name,t,t,p->password,t,t,t,p->power);    ///���ļ���д���û��������룬Ȩ��
		p=p->next;
	}
	fclose(fp);
}
///�������ܣ���ɸ����û��Ĵ���
void Create_User()
{
	char y_n;
	char  name[10];
	char password[10];
	char power[10];
	///User ����ĵ�һ���ڵ㣬��Ź���Ա�����Ϣ
	u0=(User *)malloc(sizeof(User));
	strcpy(u0->name,"admtor");
	strcpy(u0->password,"");
	strcpy(u0->power,"w");
	u0->next=NULL;
	printf("\n--------------------------------------------------------------------------\n");
	printf("�û�Ȩ��˵����w--д�������޸�,��ѯ���ݿ��е����ݣ�r--����ֻ�ܲ�ѯ���ݿ��е����ݡ�\n");
	printf("--------------------------------------------------------------------------\n");
	printf("\n�Ѿ���������Ա��admtor������Ȩ��Ϊw,������������Ա���룡\n");
	gets(password);
	strcpy(u0->password,password);
	printf("�Ƿ񴴽�һ���û�?(y or n)\n");
	scanf("%c",&y_n);
	User * p=u0;       ///ָ��ǰ��������һ���ڵ�
	while(y_n=='y')    ///�������û�ʱ
	{

		printf("�������û�����\n");
		//gets(name);
		scanf("%s",name);
		getchar();
		printf("����������!\n");
		// gets(password);
		scanf("%s",password);
		getchar();
		printf("�����뽫Ҫ�����û���Ȩ��!(w or r)\n");
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
		printf("�Ƿ񴴽�һ���û�?(y or n)\n");
		scanf("%c",&y_n);
		getchar();
	}
	 Write_User_File();     ///���û���Ϣд���ļ���
	system("cls");    ///���������������Ļ
}
/////�������ܣ�������ݿ�Ĳ���
void  Function3()
{
	char  word1[N1][10]={""};
	char  word2[N1][10]={""};
	int word_two=0;    ///���ڿ���word2[]����
	int   word_one=0;      ////    ���ڿ���  word1[]����
	char ch;
	char yes_no='y';     //
	char change='n';    ///�Ƿ��л��û��ı��
	int finish=0;
	char  action[N];
	char  get[N1];
	char  name[10];     ///��¼ʱ�õ����û���������������
	char password[10];
	int i=0;
	//int use=0;
	int j=0;
	int sum=0;
	int run=-1;
	int k=0;
	char right[10];

AGAIN:	printf("�������û�����\n");
	//gets(name);
	scanf("%s",name);
	getchar();
	printf("���������룡\n");
	//gets(password);
	scanf("%s",password);
	getchar();
	User * login;
	login=u0;   ///ͷ���

	while(login!=NULL)
	{
		if(strcmp(login->name,name)==0)   ///���û������ʱ���ж������Ƿ����
		{
			if(strcmp(login->password,password)==0)
			{
				printf("��¼�ɹ���\n");
				strcpy(right,login->power);   ///��ȡ���û���Ȩ��
				break;
			}
			else
			{
				printf("�û��������벻������¼ʧ�ܣ�\n");
				goto AGAIN;
			}
		}
		login=login->next;
	}

	while(yes_no=='y')
	{
		int run=0;       ////������ʾ���ݿ��Ѿ�ִ��һ��
		printf("������������\n");
		gets(action);
		i=0;
		word_one=word_two=0;
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

			if((ch>='0' && ch<='9')||(ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')||(ch=='*')||(ch=='>')||(ch=='=')||ch=='<' ||(ch=='_'))     //�����ǹؼ��ֻ��߱�����
			{
				j=0;
				while((ch>='0'&&ch<='9')||(ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')||(ch=='*')||(ch=='>')||(ch=='=')||ch=='<'||(ch=='_'))
				{
					get[j++]=ch;
					i++;
					ch=action[i];
				}
				get[j++]='\0';      ////����ĩβ��ֵ

				finish=0;
				for(k=0;k<M;k++)           /////�͹ؼ���������Ԫ�رȽϣ��ҵ�ƥ���ַ���
				{
					if(strcmp(get,key2[k])==0)
					{
						//strcpy(get1,get);       ////��get1��ʱ����get�е����ݡ�
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
			/*
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
			}   */
			else           ///��chΪ�ֽ��ʱ
			{
				//printf("�ֽ����  ");  
				//printf("(3,%c)\n",ch);
				i++;
				ch=action[i];
			}  
			//	length--;   
		}
		/*
		printf("����1�е����ݣ�\n");
		for(int i=0;i<=word_one;i++)
		{
		puts(word1[i]);
		printf("  ");
		}
		printf("����2�е����ݣ�\n");
		for(int i=0;i<word_two;i++)
		{
		puts(word2[i]);
		printf("  ");
		}  */
		if(strcmp(word1[0],"create")==0 &&strcmp(word1[1],"table")==0)    ////����creat table ʱ��ִ�� creat_table����
		{
			if(strcmp(right,"r")==0)
			{
				printf("��ǰ�û�Ȩ�޲�����\n");
				goto  NEXT;
			}
			Create_Table(word1,word2,word_one,word_two);
			Write_To_File(word1,word2,word_one,word_two);
			run=1;
		}
		if(strcmp(word1[0],"drop")==0 && strcmp(word1[1],"table")==0)      ///������������ drop table ʱ��ִ�� drop_table����
		{
			if(strcmp(right,"r")==0)
			{
				printf("��ǰ�û�Ȩ�޲�����\n");
				goto  NEXT;
			}
			run=1;
			Drop_Table(word1,word2,word_one,word_two);
			Write_To_File(word1,word2,word_one,word_two);
		}

		if(strcmp(word1[0],"alter")==0 && strcmp(word1[1],"table")==0 && strcmp(word1[2],"add")==0)   ///������������  alter table stu add int age (��ϵ���������ʱ)
		{
			if(strcmp(right,"r")==0)
			{
				printf("��ǰ�û�Ȩ�޲�����\n");
				goto  NEXT;
			}
			run=1;
			printf("������ԣ�\n");
			Add_Table(word1,word2,word_one,word_two);
			Write_To_File(word1,word2,word_one,word_two);

		}
		if(strcmp(word1[0],"alter")==0 && strcmp(word1[1],"table")==0 && strcmp(word1[2],"drop")==0)   ///������������  alter table stu add int age (��ϵ��ɾ������ʱ)
		{
			if(strcmp(right,"r")==0)
			{
				printf("��ǰ�û�Ȩ�޲�����\n");
				goto  NEXT;
			}
			run=1;
			printf("ɾ�����ԣ�\n");
			Drop_Column(word1,word2,word_one,word_two);
			Write_To_File(word1,word2,word_one,word_two);
		}
		if(strcmp(word1[0],"insert")==0 && strcmp(word1[1],"into")==0 && strcmp(word1[2],"values")==0)   ////���������������ϵ�����Ԫ��ʱ
		{
			if(strcmp(right,"r")==0)
			{
				printf("��ǰ�û�Ȩ�޲�����\n");
				goto  NEXT;
			}
			run=1;
			printf("���Ԫ�飡\n");
			Insert_Into(word1,word2,word_one,word_two);
			Write_To_File(word1,word2,word_one,word_two);
		}
		if(strcmp(word1[0],"delete")==0 && strcmp(word1[1],"from")==0 && strcmp(word1[2],"where")==0)   ////�������������ڹ�ϵ��ɾ��Ԫ��ʱ
		{
			if(strcmp(right,"r")==0)
			{
				printf("��ǰ�û�Ȩ�޲�����\n");
				goto  NEXT;
			}
			run=1;
			printf("ɾ��Ԫ�飡\n");
			Delect_Row(word1,word2,word_one,word_two);
			Write_To_File(word1,word2,word_one,word_two);
		}
		if(strcmp(word1[0],"update")==0 && strcmp(word1[1],"set")==0 && strcmp(word1[2],"where")==0)     /////�����������Ǹ������ݿ�ʱ
		{
			if(strcmp(right,"r")==0)
			{
				printf("��ǰ�û�Ȩ�޲�����\n");
				goto  NEXT;
			}
			run=1;
			printf("��������Ԫ�أ�\n");
			Update_Set(word1,word2,word_one,word_two);
			Write_To_File(word1,word2,word_one,word_two);
		}
		if(strcmp(word1[0],"select")==0 && strcmp(word1[1],"from")==0 && strcmp(word2[0],"*")==0 && word_one==2 && word_two==2)     ///������������  ��ʾ���б�����ʱ
		{
			run=1;
			printf("��ʾһ��������ݣ�\n");
			Select_From(word1,word2,word_one,word_two);
			//Write_To_File(word1,word2,word_one,word_two);
		}
		///
		if(strcmp(word1[0],"select")==0 && strcmp(word1[1],"from")==0 && strcmp(word1[2],"where")==0 && strcmp(word1[3],"by")==0)
		{
		  run=1;
		  printf("�����������ѡ��!\n");
		  Select_By_Index(word1,word2,word_one,word_two);
		}
		if(strcmp(word1[0],"select")==0 && strcmp(word1[1],"from")==0 && strcmp(word1[2],"where")==0 && strcmp(word2[0],"*")==0 && word_two==5)///���һ�������Եڶ�������d��һ��Ϊ* 
		{
		   run=1;
			printf("����ѡ��\n");
			Single_Select(word1,word2,word_one,word_two);
		}
		else if(strcmp(word1[0],"select")==0 && strcmp(word1[1],"from")==0 && strcmp(word1[2],"where")==0 && word_two==5)    ///���һ�������Եڶ��������С��������
		{
			run=1;
			printf("ʵ�ֵ���ϵ��ѡ���ͶӰ!\n");
			Single_Sele_Shadow(word1,word2,word_one,word_two);
		}
		else if(strcmp(word1[0],"select")==0 && strcmp(word1[1],"from")==0 && strcmp(word1[2],"where")==0 && strcmp(word1[3],"by")==0 && word_two>8)
		{
		  run=1;
		  printf("������������������Ӳ���!\n");
		  Connct_By_Index(word1,word2,word_one,word_two);
		}
		else if(strcmp(word1[0],"select")==0 && strcmp(word1[1],"from")==0 && strcmp(word1[2],"where")==0 && strcmp(word2[0],"*")==0 && word_two==8)
		{ 
			run=1;
			printf("ʵ��˫�������!\n");
			Double_Connct(word1,word2,word_one,word_two);
		}
		else if(word_two==8)
		{
			run=1;
			printf("ʵ��˫���ͶӰ������!\n");
			Double_Shadow_Connct(word1,word2,word_one,word_two);
		}
		else if(strcmp(word1[0],"select")==0 && strcmp(word1[1],"from")==0 && strcmp(word1[2],"where")==0 && strcmp(word1[3],"and")==0 && strcmp(word1[4],"and")==0)
		{
			run=1;
			printf("3�����ѡ�����Ӻ�ͶӰ��\n");
			Many_Sel_Sha_Cont(word1,word2,word_one,word_two); 
		}
		else if(word_two==11)
		{
			run=1;
			printf("ʵ��˫���ѡ�����ӣ�\n");
			Double_Select_Connt(word1,word2,word_one,word_two);
		}
		else if(strcmp(word1[0],"select")==0 && strcmp(word1[1],"from")==0 && word_two==2)   ///���һ�������Եڶ��������С��������
		{
			run=1;
			printf("ʵ��һ�����е�ͶӰ������\n");
			Show_Column(word1,word2,word_one,word_two);
		}
		if(strcmp(word1[0],"create")==0 && strcmp(word1[1],"index")==0 && strcmp(word1[2],"on")==0)
		{
			if(strcmp(right,"r")==0)
			{
				printf("��ǰ�û�Ȩ�޲�����\n");
				goto  NEXT;
			}
			run=1;
			printf("����������\n");
			Create_Index_1(word1,word2,word_one,word_two);

		}
		if(strcmp(word1[0],"drop")==0 && strcmp(word1[1],"index")==0 && strcmp(word1[2],"on")==0)
		{
		    if(strcmp(right,"r")==0)
			{
				printf("��ǰ�û�Ȩ�޲�����\n");
				goto  NEXT;
			}
			run=1;
			printf("ɾ��������\n");
			Drop_Index(word1,word2,word_one,word_two);
		}
		if(run==0)   ///����������䷢������
		{
			printf("�����﷨�������鲢��������!!!\n");
		}
		for(int i=0;i<10;i++)       ///  ÿһ��ѭ��֮�󣬽� word �����ÿ�
		{
			strcpy(word1[i],"");
			strcpy(word2[i],"");        ///Ҳ���Ե���memset��������
		}
		//strcpy(word1[1],"");
NEXT: printf("\n�Ƿ��������y or n��\n");
		scanf(" %c",&yes_no);
		getchar();

		printf("�Ƿ��л���ǰ�û�?(y or n)\n");
		scanf(" %c",&change);
		getchar();
		if(change=='y')   ///��Ҫ�л��û�ʱ,��ת
		{
			goto  AGAIN;
		}
		if(yes_no!='y' &&  yes_no!='n')  
		{
			printf("\n�����ʽ����---������ y / n !\n");
			scanf("  %c",&yes_no);
			getchar();
			printf("%c",yes_no);
			printf("--------");
		}
	}


}
int _tmain(int argc, _TCHAR* argv[])
{
	void Init_dd();   ///��ʼ�������ֵ�
	Create_User();     
	Function3();           ///ִ�в�������
	return 0;
}






