// Playfair���ܽ���ʵ��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N  100
int    Remove_Duplicate(char K_alphabet[N],char middle[N]);

void Show_Matrix(char Matrix[5][5] );
////�������ܣ��û��������Ļ�����
void Input(char input[N])
{
	int i=0;
	int j=0;
   //printf("��������Կ�����Ļ������ģ�(����Сд��ĸ)\n");

   again: scanf("%s",input);
   j=strlen(input);
   for(i=0;i<j;i++)
   {
      if(input[i]<97||input[i]>122)				///����Ϸ��Լ��
	  {
	     printf("�������Ļ����������зǷ��ַ������������룡������Сд��ĸ��\n");
		 goto again;			//������Ƿ��ַ�ʱ������������룬�������룡
	  }
   }
}
///�������ܣ������������Կ������Ӧ����ĸ����
void Creat_Matrix(char secret_key[],char Matrix[5][5])
{
	char middle[N];
	int i=0;
	int j=0;
	int k=0;
	int t=0;
	int count=0;
	int flage=0;
	int compare=97;
//	int length;  
	int  row=0;
	int column=0;
	      
	char Alphabet[27]="abcdefghijklmnopqrstuvwxyz";       ////��ĸ�������ڴ洢26����ĸ
	char Alp_Middle[27];					//���ڼ�¼Alpha�г�ȥ�ظ�Ԫ�ص���ĸ
	char a;
	int flage_1=1;
	int  length=0;
    length=Remove_Duplicate(secret_key,middle);		///��ȥ��Կ�е��ظ���ĸ
  //  length=strlen(middle);     ///��¼�����鳤��
	
	
	for(j=0;j<5;j++)			///���ά���鸳ֵ
    {
	  for(k=0;k<5;k++)
		{
		    if(middle[i]!='j')     ////i��j����ͬһ������λ���У�����Ҫ���⴦��
			{
			  Matrix[j][k]=middle[i];
			  i++;
			}
			else
			{
			 i++;
			 continue;				///��������ѭ��
			}
			if(i==length)				///��middle�����е�Ԫ�ر������ ��������ѭ��
			{
			  
			  row=j;                     ////��row,column�ֱ��¼�¾�����Ԫ�صľ���λ��
			  column=k;
			  break;					//��ʱ��j  k  �ֱ�����ά�����У����һ��Ԫ�ص�λ��
			}
	    }
	      if(i==length)				///��middle�����е�Ԫ�ر������ ��������ѭ��
			{
				
			  row=j;
			  column=k;
			   break;
			}
	 }
	//   �������
	/*        
	for(j=0;j<5;j++)				///�ھ������ҵ�Ԫ�ذ���ĸ��˳�������ֵ�Ԫ��
	{
	  for(k=0;k<5;k++)
	  {
		  flage=Matrix[j][k];
		  if(flage>compare)  compare=flage;      ///ͨ��ascII�Ƚ���ĸ�Ⱥ�˳��
		  if(count==(length-1))  break;				///��middle�����е�Ԫ�ر����������ѭ��
	     count++;
	  }
	     if(count==(length-1))  break;				///��middle�����е�Ԫ�ر����������ѭ��
	}   */
	for(j=0;j<27;j++)				///��Alphabet����middle�г��ֵ���ĸ��ȥ�������浽Alp_Middle��
	{
	   a=Alphabet[j];
	   for(k=0;k<length;k++)
	   {
	     if(a==middle[k])
			 flage_1=2;         ///�����
	   }
	   if(flage_1==1)				///���aû����middle�г��֣����浽Alp_Middle��
	   {
	      Alp_Middle[t++]=a;
	   }
	   flage_1=1;
	}
	///��row ,column����������ж�
	if(column==4)     ////�����������ĩβʱ��ת�Ƶ���һ��
	{
	     row++;
		 column=0;
	}
	else
	{
	   column++;            ///ֱ��ת��������һ��Ԫ��   
	}
	for(j=row,i=0;j<5;j++)     ///��������Alp_Middle�е�Ԫ��
	{
		if(j!=row) column=0;			///ʹk���0--4��ѭ��
	  for(k=column;k<5;k++)
	  {
		  if(Alp_Middle[i]=='j')     ////��Ϊi��j���ھ���ͬһλ���С���Ϊjʱ��������һԪ��
			  i++;
	       Matrix[j][k]=Alp_Middle[i++];
		  // if(k==4)  k=-1;				///ʹk���0--4��ѭ��
	  }
	}
	 Show_Matrix( Matrix );
}
///�������ܣ��ж�K�е�i���ַ�֮ǰ��û��������ͬ���ַ�     
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
///�������ܣ�ȥ����Կ�ռ��ַ����е��ظ�Ԫ��
int    Remove_Duplicate(char K_alphabet[N],char middle[N])
{
	int i;
	int j;
	j=0;
	char a;
	int k=strlen(K_alphabet);
	for(i=0;i<k;i++)
	{
		a=K_alphabet[i];
		if(Is_First(i,K_alphabet))			///��aʱ��һ�����ֵ��ַ�ʱ
		{
			middle[j]=a;
			j++;
		}
	}
	//length=j;
	//j=j-2;       //middle�������������������ĸ������-2
	//return j;				///����middle�ĳ���
	return  j;
}
///�������ܣ���ӡ����
void Show_Matrix(char Matrix[5][5] )
{
  int i=0;
  int j=0;
  printf("�����е�Ԫ��Ϊ: \n");
  for(i=0;i<5;i++)
  {
    for(j=0;j<5;j++)
	{
	   printf("%c  ",Matrix[i][j]);
	}
	printf("\n");
  }
}
///�������ܣ�������c�е�i��λ�����Ԫ��'z'
int  Add_Char(char clear_message[N],int i)
{
     int j=0;
	 int k=0;
	 int length=0;
	 int  temp=0;
	 length=strlen(clear_message);
	 k=length;
	 length++;
	 for(j=(k-1);j>=(i-1);j--)
	 {
	   clear_message[j+1]=clear_message[j];    ///һ��һ�����
	 }
	 clear_message[i]='z';
	return length;
}
///�������ܣ�������ĵľ���ʵ��
void Encryption_2(char clear_message[N],char  encrypted_message[N],char Matrix[5][5],int length)
{
	char first;
	char second;
   // int length=0;
	 int i=0;
	 int j=0;
	 int k=0;
	 int temp=0;
//	 int   flage=0;
	 int x1,x2,y1,y2;
	 x1=x2=y1=y2=0;       ///x y �ֱ��¼����������Ԫ�ض�Ӧ���±�
	//length=strlen(clear_message);
	for(i=0;i<length;i=i+2)                 ////�������������ַ��������ַ�����
	{
	 
	  first=clear_message[i];
	  second=clear_message[(i+1)];
	  for(j=0;j<5;j++)						////�ھ������ҵ���Ӧ�������ַ�������¼�¸��Ե��±�
	  {
	     for(k=0;k<5;k++)
		 {
		    if(first==Matrix[j][k])   
			{
			   x1=j;
			   y1=k;
			   
			}
			if(second==Matrix[j][k])
			{
			  x2=j;
			  y2=k;
			 
			}
			//if(flage==1)    break;       //���ҵ���ӦԪ��ʱ��ֱ������ѭ��
		 }
		    ///if(flage==1)    break;
	  }
	  
	  if(x1==x2&&y1!=y2)      ///������Ԫ��ͬ�в�ͬ��ʱ
	  {
	    y1++;     ///�ұߵ�Ԫ����Ϊ����Ԫ��
		y2++;
		if(y2==5)  y2=0;     ////����0��Ԫ����Ϊ4����һ��Ԫ��
		if(y1==5)  y1=0;
	  }
	  if(y1==y2&&x1!=x2)      ///������Ԫ��ͬ�в�ͬ��ʱ
	  {
	    x1++;                  
		x2++;
		if(x1==5)  x1=0;          ////����0��Ԫ����Ϊ4����һ��Ԫ��
		if(x2==5)  x2=0;
	  }
	  if(x1!=x2&&y1!=y2)            ////������Ԫ�ز�ͬ�У���ͬ��ʱ
	  {   
			   temp=y1;				///y1  y2  ����λ��
			   y1=y2;
			   y2=temp;
	  }
	  encrypted_message[i]=Matrix[x1][y1];
	  encrypted_message[(i+1)]=Matrix[x2][y2];
	}
	
	printf("����ԭ��������ĸ����ǵ���������ʱ���ַ����������� 'z';\n");
	printf("          ������������ظ���ĸ���м��'z';\n\n\n");
	printf("�������ܲ����󣬵õ��������ǣ�\n");
	
	//length=strlen(encrypted_message);
   //puts(encrypted_message);
   for(i=0;i<length;i++)
   {
     printf("%c",encrypted_message[i]);
   }
   printf("\n");
}
////�����ܣ�ʵ�ּ��ܹ���
void Encryption_1(char clear_message[N],char  encrypted_message[N],char Matrix[5][5])
{
	int length=0;
	int i=0;
					///���ܹ����У��õ������ַ�
	length=strlen(clear_message);
	for(i=0;i<(length-1);i++)			///����������Ƿ����ظ�Ԫ�أ�������ظ�Ԫ�أ��м����w
	{
	   if(clear_message[i]==clear_message[i+1])      
		{   
			length=Add_Char(clear_message,(i+1));
	   }
	}
	if(length%2!=0)      ///�ж��ַ����ĳ���Ϊ����������ĩβ��  z  Ƶ�ʷ����У�z��ʹ��Ƶ����С
	{
	  i=length;
	  clear_message[i]='z';                                    //////???????????????????????????????????????????
	  length++;
	}
	Encryption_2(clear_message,encrypted_message,Matrix,length);
}
///�������ܣ�ʵ�ֽ��ܹ���
void Decryption(char clear_message[N],char encrypted_message[N],char Matrix[5][5])
{
    char first;
	char second;
    int length=0;
	 int i=0;
	 int j=0;
	 int k=0;
	 int temp=0;
//	 int   flage=0;
	 int x1,x2,y1,y2;
	 x1=x2=y1=y2=0;       ///x y �ֱ��¼����������Ԫ�ض�Ӧ���±�
	length=strlen(encrypted_message);
	for(i=0;i<length;i=i+2)                 ////�������������ַ��������ַ�����
	{
	 
	  first=encrypted_message[i];
	  second=encrypted_message[(i+1)];
	  for(j=0;j<5;j++)						////�ھ������ҵ���Ӧ�������ַ�������¼�¸��Ե��±�
	  {
	     for(k=0;k<5;k++)
		 {
		    if(first==Matrix[j][k])   
			{
			   x1=j;
			   y1=k;
			   
			}
			if(second==Matrix[j][k])
			{
			  x2=j;
			  y2=k;
			 
			}
			//if(flage==1)    break;       //���ҵ���ӦԪ��ʱ��ֱ������ѭ��
		 }
		    ///if(flage==1)    break;
	  }
	  
	  if(x1==x2&&y1!=y2)      ///������Ԫ��ͬ�в�ͬ��ʱ
	  {
		  y1--;
		  y2--;
		  if(y1==-1)  y1=4;
		  if(y2==-1)   y2=4;
	  }
	  if(y1==y2&&x1!=x2)      ///������Ԫ��ͬ�в�ͬ��ʱ
	  {
		 x1--;
		 x2--;
		 if(x1==-1)  x1=4;
		 if(x2==-1)  x2=4;
	  }
	  if(x1!=x2&&y1!=y2)            ////������Ԫ�ز�ͬ�У���ͬ��ʱ
	  {   
			   temp=y1;				///y1  y2  ����λ��
			   y1=y2;
			   y2=temp;
	  }
	  clear_message[i]=Matrix[x1][y1];
	  clear_message[(i+1)]=Matrix[x2][y2];
	}
	printf("�������ܲ����󣬵õ��������ǣ�\n");
	//length=strlen(encrypted_message);
   //puts(encrypted_message);
   for(i=0;i<length;i++)
   {
	   if((i==(length-1))&&clear_message[i]=='z')       ////���������ַ���Ӧ�жϣ�
		   break;
     printf("%c",clear_message[i]);
   }
   printf("\n");
}
/// �������ܣ�ʵ�ֲ˵�չʾ
void menu()
{
  printf("\t\t\t*************************\n");
  printf("\t\t\t    1   Playfair ����\n");
  printf("\t\t\t    2   Playfair ����\n");
  printf("\t\t\t    3   �˳�\n");
  printf("\t\t\t*************************\n");
}
int _tmain(int argc, _TCHAR* argv[])
{
	int choice;
	char key[N];						///��Կ
	char clear_message_0[N];          ///����
	char  encrypted_message_0[N];			//����       0 �����ģ����ģ����ڼ���
	char clear_message_1[N];
    char encrypted_message_1[N];				//1 �����ģ��������ڽ���
	char Matrix[5][5];						///�������ľ���
	printf("��������Կ��������Сд��ĸ����\n");
	Input(key);				  ///������Կ
	Creat_Matrix(key,Matrix);				///�������
	
	//Input(encrypted_message);    ///��������
	menu();
	printf("������ѡ��!\n");
	scanf("%d",&choice);
    while(choice!=3)
	{
	   if(choice==1)         ///���ܹ���
	   {
		 printf("���������ģ�������Сд��ĸ����\n");
	     Input(clear_message_0);      ////��������
	     Encryption_1(clear_message_0,encrypted_message_0,Matrix);

	   }
	   else if(choice==2)			///���ܹ���
	   {
	    printf("���������ģ�������Сд��ĸ����\n");
		Input(encrypted_message_1);
		Decryption(clear_message_1,encrypted_message_1,Matrix);
	   }
	   else
	   {
	      printf("����������������룡\n");
	   }
	 menu();
	printf("������ѡ��!\n");
	scanf("%d",&choice);
	}
	return 0;
}

