

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 50
#define N1 10
#define M 21
char   key2[M][10]={"create","table","drop","alter","insert","into","delete","from","update","select","grant","revoke","index","view","user","int","char","values","add","where","set"};
//char  * key1[5]={"creat table","drop table","altrer table","insert into","delect from"};
void Write_To_File();
///�����ṹ������
typedef struct Index_Node
{
	char key[10];    ///��ž����ID ���� 123
	int next;       ///�����������  �� 3
}Index_Node;
///�ṹ������
typedef struct Lnode
{
	char table[10][10];   ///��ά�������ڴ��ÿһ����¼---�ַ���
	int rows;         ////���ڼ�¼��ǰ��ǰ2ά�������˼���
	struct Lnode * next;        ///ָ����һ���ڵ�
}Lnode;
///���������ֵ�
int index=1;
char data_diction[N][N];
Lnode * L;     ///�����һ���ڵ�
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
void Show_Table()
{
	char temp[N1]="";
	//if(L==NULL)   printf("��ǰ���ݿ�Ϊ�գ�");  return ;
	Lnode *p;
	p=L;
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
	//strcpy(L->table[0],temp);     ///ÿ�δ�ӡ��ϵ֮�󣬽���ϵ���ָ����´���.
}
///�������ܣ�ʵ�� creat table����
void  Create_Table(char word1[N1][10],char word2[N1][10],int word_1,int word_2)
{
	
	L=(Lnode *)malloc(sizeof(Lnode));       ///ͷ�������
	for(int i=0;i<10;i++)
	{
		strcpy(L->table[i],"");
	}
	L->rows=1;
	strcpy(L->table[0],word2[0]);          ///����ϵ������ͷ�����

	strcpy(data_diction[0],"table_name�� ");      ///�����һ�У�����ź��֣�
   strcpy(data_diction[2],"property�� "); 
	strcpy(data_diction[1],word2[0]);    ///����ϵ��д�������ļ�
	strcpy(data_diction[3],"    ");

	Lnode * p=(Lnode *)malloc(sizeof(Lnode));    ///����ڶ����ڵ��  ID  Name
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
	Show_Table();
	/// Write_To_File();
	//printf("******");
}
////�������ܣ�ʵ��  drop table  (ɾ���½���Ĺ���)
void Drop_Table()
{
	L=NULL;        ///�������ÿ�
	Show_Table();
}
///�������ܣ�ʵ�� alter table ..add .int age  (������������ʱ)
void Add_Table(char word1[N1][10],char word2[N1][10],int word_1,int word_2)
{
	Lnode *  p=L->next;   ////�ҵ�����ĵڶ����ڵ㣬�����������


	//L->rows;
	strcpy(p->table[p->rows],word2[1]);
	p->rows++;       ///�ȸ��Ƶ� table �� row�У�Ȼ���1�����������±��0��ʼ

	strcpy(data_diction[(index++)],word1[3]);         ///�޸������ֵ�
	strcpy(data_diction[(index++)],word2[1]);
	
	Show_Table();
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
	Lnode * p=L->next;
	int i=0;
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
	Show_Table();   
}
///�������ܣ��ڹ�ϵ�����Ԫ��
void Insert_Into(char word2[N1][10],int word_2)
{
	Lnode * p=(Lnode *)malloc(sizeof(Lnode));     ///����һ���µĽṹ�壬����Ԫ�����ݷ�������
	p->rows=0;
	p->next=NULL;
	for(int i=1;i<word_2;i++)
	{
		strcpy(p->table[(i-1)],word2[i]);
		p->rows++;
	}
	Lnode *q=L;
	while(q->next!=NULL)
	{
		q=q->next;    ///�ҵ������ĩ�ڵ�
	}
	q->next=p;
	Show_Table();
}
//�������ܣ��ڹ�ϵ��ɾ��һ��Ԫ��
void Delect_Row(char word2[N1][10],int woerd_2)
{
	///����ȷ�� ID ��Ӧ���±�   i
	Lnode * p=L->next;
	int i=0;
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
	Show_Table();
}
///�������ܣ����¹�ϵ�е�����
void Update_Set(char word2[N1][10],int woerd_2)
{
	///����ȷ�� ID ��Ӧ���±�   i
	Lnode * p=L->next;
	int i=0;
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
	Show_Table();
}
////�������ܣ���ʾ������������
void Select_From()
{
	Show_Table();
}
///�������ܣ������ݿ�����ļ���
void Write_To_File()
{
	Lnode * p=L;
	FILE * fp;
	FILE * fp1;
	char c='\t';
	char a='\n';
	char ch[40]="-----------------------------";
	//���ݿ����ļ�
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
	if((fp1=fopen("E:\\db3.txt","w"))==NULL)
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
////�������ܣ�Ϊ��ϵ�������Դ�������


/*
void Creat_Index_1()
{   ///����������ʱ��������
	Lnode * p=L;
	int count=0;    ///���ڼ�¼��ǰ����ĳ���
	while(p!=NULL)
	{
		p=p->next;
		count++;
	}
	Index_Node array[count];
	p=p->next->next;    ////�ҵ������еĵ�һ���ݼ�¼
	while(p!=NULL)
	{
	   
	}
}

*/
/////�������ܣ�������ݿ�Ĳ���
void  Function3()
{
	char  word1[N1][10]={""};
	char  word2[N1][10]={""};
	int word_two=0;    ///���ڿ���word2[]����
	int   word_one=0;      ////    ���ڿ���  word1[]����
	char ch;
	char yes_no='y';     //
	int finish=0;
	char  action[N];
	char  get[N1];
	//char  get1[N1];
	//int  count=1;      ///������  name1 na me2 name3 ���ʹ��
	//	printf("���������ݿ���������� ; ��β��\n");
	//	gets(action);
	int i=0;
	//int use=0;
	int j=0;
	int sum=0;
	int run=-1;
	int k=0;

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

			if((ch>='0' && ch<='9')||(ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z') ||(ch=='*'))     //�����ǹؼ��ֻ��߱�����
			{
				j=0;
				while((ch>='0'&&ch<='9')||(ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')||(ch=='*'))
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
			Create_Table(word1,word2,word_one,word_two);
			Write_To_File();
			run=1;
		}
		if(strcmp(word1[0],"drop")==0 && strcmp(word1[1],"table")==0)      ///������������ drop table ʱ��ִ�� drop_table����
		{
			run=1;
			Drop_Table();
			Write_To_File();
		}

		if(strcmp(word1[0],"alter")==0 && strcmp(word1[1],"table")==0 && strcmp(word1[2],"add")==0)   ///������������  alter table stu add int age (��ϵ���������ʱ)
		{
			run=1;
			printf("������ԣ�\n");
			Add_Table(word1,word2,word_one,word_two);
			Write_To_File();
			
		}
		if(strcmp(word1[0],"alter")==0 && strcmp(word1[1],"table")==0 && strcmp(word1[2],"drop")==0)   ///������������  alter table stu add int age (��ϵ��ɾ������ʱ)
		{
			run=1;
			printf("ɾ�����ԣ�\n");
			Drop_Column(word1,word2,word_one,word_two);
			Write_To_File();
		}
		if(strcmp(word1[0],"insert")==0 && strcmp(word1[1],"into")==0 && strcmp(word1[2],"values")==0)   ////���������������ϵ�����Ԫ��ʱ
		{
			run=1;
			printf("���Ԫ�飡\n");
			Insert_Into(word2,word_two);
			Write_To_File();
		}
		if(strcmp(word1[0],"delete")==0 && strcmp(word1[1],"from")==0 && strcmp(word1[2],"where")==0)   ////�������������ڹ�ϵ��ɾ��Ԫ��ʱ
		{
			run=1;
			printf("ɾ��Ԫ�飡\n");
			Delect_Row(word2,word_two);
			Write_To_File();
		}
		if(strcmp(word1[0],"update")==0 && strcmp(word1[1],"set")==0 && strcmp(word1[2],"where")==0)     /////�����������Ǹ������ݿ�ʱ
		{
			run=1;
			printf("��������Ԫ�أ�\n");
			Update_Set(word2,word_two);
			Write_To_File();
		}
		if(strcmp(word1[0],"select")==0 && strcmp(word1[1],"from")==0 && strcmp(word2[0],"*")==0)     ///������������  ��ʾ���б�����ʱ
		{
			run=1;
			printf("��ʾ���б�����ݣ�\n");
			Select_From();
			Write_To_File();
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
		printf("\n�Ƿ��������y or n��\n");
		scanf(" %c",&yes_no);
		getchar();
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
	Function3();           ///ִ�в�������
	
	///д���ļ�
	/*
	char abc[10][10];
	char asd[10][10]={"####","*******"};
	char c='\n';
	for(int i=0;i<2;i++)
	{
	strcpy(abc[i],"qwe123--");
	}
	for(int i=2;i<10;i++)
	{
	strcpy(abc[i],"");
	}  
	FILE * fp;
	if((fp=fopen("E:\\db3.txt","w"))==NULL)
	{
	printf("���ļ�ʧ�ܣ�\n");
	exit(0);
	}
	printf("eeeeee");
	for(int i=0;i<10;i++)
	{
	if(strcmp(abc[i],"")==0)
	continue;
	fprintf(fp,"%s%c",abc[i],c);
	}
	for(int i=0;i<10;i++)
	{
	if(strcmp(asd[i],"")==0)
	continue;
	fprintf(fp,"%s%c",asd[i],c);
	}
	fclose(fp); 
	printf("tt12ttt+6");     */
	return 0;
}






