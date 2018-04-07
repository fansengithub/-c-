// ��ҳʽ�洢����3.0.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<string.h>
///ҳ��
struct PAGE_TABLE
{
	int Phy_Num;  /// ������
	int  Status;   ///״̬λ
};
//�����
struct Physical_Block
{
	int page_number;/// ҳ��
	int phy_addre;  ///�����ַ
};

void Print(PAGE_TABLE *P,Physical_Block *PB,int Page_Size, int Block_Size);

void Get_Address(char  Graph[][10],Physical_Block *  &p,int  Block_size)
{
	int i,j;  
	int count=0;
//	printf("�ҳ�λʾͼ��ǰ%d  ��0��Ӧ��λ��  \n",count1);
	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
		{
			if(Graph[i][j]==0)
			{ 
			   
				p[count].phy_addre=i*8+j+1;    ///��¼ i  , j��Ӧ�����λ��
				count++;
				if(count==(Block_size))
					return;
			}
		}
		//if(count==(Block_size-1)) break;
	}
  	return ;
}    
void Change_Graph(char  Graph[][10],Physical_Block *  &p,int  Physic_Block_Num)
{
	int i,j;
	int  count=1;
	for(i=0;i<8;i++)
	{
	   for(j=0;j<8;j++)
	   {
	       if(Graph[i][j]==0)
			{ 
			   Graph[i][j]=1;    ///��ջ������Ԫ��ʱ���޸Ķ�Ӧλʾͼ�е�����
			//	p[count].phy_addre=i*8+j+1;    ///��¼ i  , j��Ӧ�����λ��
				if(count==Physic_Block_Num)  return ;
			}
	   }
	}
  
}
///ҳ��ĳ�ʼ������
void  Page_Table_Boot(PAGE_TABLE * &P,int  Page_Size)
{    
	for(int i=0;i<Page_Size;i++)
	{
		P[i].Phy_Num=-1;     ///��������Ŀ��
		P[i].Status=0;      ///״̬λ�� 0
	}
}
///�������ܣ������ĳ�ʼ��
void  Phy_Block_Boot(char  Graph[][10],Physical_Block *  &p,int  Block_size)
{
    p=(Physical_Block *)malloc(Block_size*sizeof(Physical_Block));   ///���붯̬����
	for(int i=0;i<Block_size;i++)
	{
		p[i].page_number=-1;
		p[i].phy_addre=-1;
	}
	 Get_Address(Graph,p,Block_size);
}
///λʾͼ   ��ʼ��  ,Ѱ��n��������Ӧ�������ַ
void Creat_Position(char  Graph[][10])
{

	///*****************�����������Ϊλʾͼ���ݸ�ֵ
	int n,i,j;
	//	int k;  ///��¼ i  , j��Ӧ�����λ��
	
	int count=0;
	i=j=0;
	n=64;
	srand((int)time(0));
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			Graph[i][j]=rand()%2;
		}
	}
	//	printf("�������ڴ������Ĵ�С��\n");
	//	scanf("%d",&large1);
	//printf("�������ڴ滮�ֿ�Ĵ�С��\n");
	//	scanf("%d",&large2);
	//	i=large1/large2;
	//	k=(int )sqrt(i*1.0);
	printf("***********λʾͼ�Ĵ�СΪ8*8***************\n");
	printf("�����ڴ滮�ֵ�λʾͼΪ��\n");
	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
		{
			printf("%d    ",Graph[i][j]);
		}
		printf("\n");
	}
	//Creat_Process(large2, k, Graph);
//	printf("�����������ĸ���\n");
	//scanf("%d",&Physic_Block_Number);
	/*
	int * k=NULL;  ///��¼ i  , j��Ӧ�����λ��
	k=(int *)malloc(Physic_Block_Number*sizeof(int));
	printf("�ҳ�λʾͼ��ǰ%d  ��0��Ӧ��λ��  \n",Physic_Block_Number);
	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
		{
			if(Graph[i][j]==0)
			{ 
				k[count]=i*8+j+1;    ///��¼ i  , j��Ӧ�����λ��
				count++;
				if(count==(Physic_Block_Number-1)) break;
			}

		}
		if(count==(Physic_Block_Number-1)) break;
	}
	return k;   */
}

/*
///�������ܣ���λʾͼ�����ݽ����޸�  
int *  Change_Graph( char  Graph[][10],int Block_Num)
{
	int i,j;  /*
	k=0;
	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
		{
			if(Graph[i][j]==0)
			{ 
				k++;
				Graph[i][j]=1;
				if(k==count1)
				{
					return ;
				}
			}
		}
	}   
	//	printf("�����������ĸ���\n");
	//scanf("%d",&Physic_Block_Number);
	//int * k=NULL;  ///��¼ i  , j��Ӧ�����λ��
	int p=0;
//	int  k1;
	int * k =(int *)malloc(Block_Num*sizeof(int));  ///��̬�����������λʾͼ��Ӧ�ĵ�ַ
//	while(p< Physic_Block_Number)
//	{
//	   k[p]=0;
//	}
	int count=0;
//	printf("�ҳ�λʾͼ��ǰ%d  ��0��Ӧ��λ��  \n",count1);
	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
		{
			if(Graph[i][j]==0)
			{ 
			//	k=i*8+j+1;
			//  return k;
				k[count]=i*8+j+1;    ///��¼ i  , j��Ӧ�����λ��
				count++;
				if(count==Block_Num) break;
			}

		}
		if(count==Block_Num) break;
	}
  	return k;
}            */
///�������ܣ�ҳ��������û�
///  FIFO    LRU   �õ���ҳ����뺯��
void Page_In_1(char  Graph[][10],Physical_Block * PB,int Block_Size,PAGE_TABLE * p,int Page_Size,int Page_Num,int Physic_Block_Num )
{
   //	int count;
   //	int count1;
	int Temp=0;
	int Tag=0;
	///ɨ��ջ���ҳ�ջ�пյ�λ��tag,����Ϊ�գ�tagΪ-1
	for(Temp=0;Temp< Physic_Block_Num;Temp++)
	{
		if(PB[Temp].page_number==-1)
		{
			Tag=Temp;
		//	count=Temp;//��¼�����������ҳ�ŵĸ���
			break;
		}
	}
//	count1=Physic_Block_Num-count;
	if(Temp== Physic_Block_Num)
	{
		Tag=-1;
	}///��ջ��Ԫ����������Ҫ�ѵ�ǰĳ��ҳ��������ǰҳ�����ڴ�
	if(Tag==-1)
	{
		p[PB[0].page_number].Status=0;
		p[PB[0].page_number].Phy_Num=-1;
		///����ǰҳ������ڴ�
		///��ջ������Ԫ��ǰ��
		for(int i=1;i<Physic_Block_Num;i++)
		{
			PB[i-1].page_number=PB[i].page_number;
			p[PB[i].page_number].Phy_Num--;
		}
		PB[Physic_Block_Num-1].page_number=Page_Num;
		//�޸ĵ�ǰҳ���е�����
		p[Page_Num].Phy_Num=Physic_Block_Num-1;
		p[Page_Num].Status=1;
		return ;
	}
	else
	{
		PB[Temp].page_number=Page_Num;
		p[Page_Num].Phy_Num=Tag;                                                        ////////////////////////////////////////////////////////////////
		p[Page_Num].Status=1;
		///��λʾͼ�е����ݽ����޸�
		//Change_Graph(Graph,p,Block_Size);
		//PB[Temp].phy_addre=k;
		//  Change_Graph( Graph[10][10], count1);
		Change_Graph(Graph,PB,Physic_Block_Num);
	}
}
///�������ܣ�FIFO�û��㷨
int FIFO(char Graph[][10],Physical_Block *PB, int Block_Size,PAGE_TABLE *p,int Page_Size,int Page_Num,int & Find_Page,int Physic_Block_Num)
{
	///�鿴��ҳ�Ŷ�Ӧ��״̬λ��0���ڴ棬1�����ڴ�
	if(p[Page_Num].Status==0)
	{ 
		///�û����ߵ���
		Page_In_1( Graph, PB, Block_Size, p, Page_Size, Page_Num, Physic_Block_Num);
	}
	else 
	{
		Find_Page++;
	}
	return 0;
}
int LRU(char Graph[][10],Physical_Block *PB, int Block_Size,PAGE_TABLE *p,int Page_Size,int Page_Num,int & Find_Page,int Physic_Block_Num)
{

	///�鿴ҳ���ж�Ӧ��״̬λ   0 �������  1 ������
	if(p[Page_Num].Status==0)   ///ȱҳ���
	{
		//�û����ߵ���
		Page_In_1( Graph, PB, Block_Size, p, Page_Size, Page_Num, Physic_Block_Num);
	}
	else ///  ����
	{
		if((Physic_Block_Num-p[Page_Num].Phy_Num)>=2)  ////���е�ҳ�棬�������ջ�е�ǰ��λʱ������Ҫ�����ö�
		{
			int Temp=Page_Num;
			for(int i=p[Page_Num].Phy_Num;i<Physic_Block_Num-1;i++)
			{
				PB[i].page_number=PB[i+1].page_number;  ///�޸�ջ�е�����
				p[PB[i+1].page_number].Phy_Num--;     ///�޸�ҳ���е�����
			}
			PB[Physic_Block_Num-1].page_number=Temp;
			p[Page_Num].Phy_Num=Physic_Block_Num-1;
		}
		Find_Page++;
	}
	return 0;
}
////******************************************************
///OPT�㷨�õ���ҳ����룬��������
void  Page_In_2(char Graph[][10],Physical_Block *PB,int Block_Size/* Block_Num*/,PAGE_TABLE *p,int Page_Size,int Page_Num,int List_Num,int *List,int List_Size)
{
	int  Temp=0;
	int Tag=0;
	for(Temp=0;Temp<Block_Size;Temp++)
	{
		if(PB[Temp].page_number== -1)
		{
			Tag=Temp;
			break;
		}
	}
	if(Temp==Block_Size)
	{
		Tag=-1;
	}
	if(Tag==-1)
	{
		///�����������У��ҵ��ڴ���´γ��ֵ�λ��
		int * T=(int *)malloc(Block_Size*sizeof(int));
		for(int i=0;i<Block_Size;i++)
		{
			for(int j=List_Num;j<List_Size;j++)
			{
				if(PB[i].page_number== List[j])
				{
					T[i]=j;
					break;
				}
				T[i]=List_Size+1;
			}
		}
		///��������������
		int max=0;
		for(int i=0;i<Block_Size;i++)
		{
			if(T[max]<T[i])
			{
				max=i;
			}
		}
		///�滻���������Ӧ�Ŀ�
		p[PB[max].page_number].Phy_Num=-1;
		p[PB[max].page_number].Status=0;
		PB[max].page_number=Page_Num;
		p[Page_Num].Phy_Num=max;
		p[Page_Num].Status=1;
		free(T);
	}
	else
	{
		PB[Tag].page_number=Page_Num;
		p[Page_Num].Phy_Num=Tag;
		p[Page_Num].Status=1;
		///�޸�λʾͼ
		//int k=Change_Graph(Graph,p,Block_Size);;
	}
	return;
}
////         OPT  �õ���ҳ�����뺯��

///�������ܣ�OPT  �㷨��ʵ��
void  OPT(char Graph[][10],Physical_Block * PB,int Block_Size,PAGE_TABLE *p,int Page_Size,int &Find_Page,int *List,int List_Size )
{
	///�鿴λʾͼ Page_In_2(char Graph[10][10],Physical_Block *PB,int Block_Size,PAGE_TABLE *p,int Page_Size,int Page_Num,int List_Num,int *List,int List_Size)
   
	for(int i=0;i<List_Size;i++)
	{
		if(p[List[i]].Status==0)
		{
			Page_In_2(Graph,PB,Block_Size,p,Page_Size,List[i],i,List,List_Size);
			//printf("                              LRU\n");
		    //printf("�����ַ��  %d\n",((P1[Page1[Page_Num].Phy_Num].phy_addre)*Block_Size+ Page_in_Address));
	       // printf("���д�����   %d   �����ܴ�����   %d",Find_Page1,Visit_Page);
		    Print(p,PB,Page_Size, Block_Size);
		}
		else 
		{
			Find_Page++;
			printf("���У�\n");
		}

	}

}
///�������ܣ���ӡ����
void Print(PAGE_TABLE *P,Physical_Block *PB,int Page_Size, int Block_Size)
{
	printf("\n");
	printf("ҳ��     ״̬��     ������     ջ��״̬  \n");
	for(int i=0;i<Page_Size;i++)
	{
		if(P[i].Phy_Num != -1)     ///����ҳ�ţ��Ա�����
		{ 
			printf("%d         %d",i,P[i].Status);
		}
		else     ///// ����ҳ�ţ�δ������ʱ
		{
			printf("%d         %d",i/*,P[i].Phy_Num,*/,P[i].Status);
		}
		if(i<Block_Size)  ///�������飬 ��Ӧ��ջ
		{
			if(PB[Block_Size-i-1].page_number!=-1)   ////����飬��������ʱ
			{
				printf("       %d       %d\n",PB[Block_Size-1-i].phy_addre,PB[Block_Size-1-i].page_number);
			}
			else
			{
			  printf("       \n");
			}
		}
		else 
		{  printf("       \n");}
	}
}

////// �������У�OPT�㷨����Ҫ��
void Print_List(int * List,int List_Size)
{
    for(int i=0;i<List_Size;i++)
	{
	   printf("%d\n",List[i]);
	}
	return ;
}
int _tmain(int argc, _TCHAR* argv[])
{
	printf("*************�ڴ��Ĵ�СΪ64kB*******\n");
	printf("*************ҳ��Ĵ�СΪ6************\n");
	///-------------------------------------------------------------------------------------
	int Page_Size=6;
	///LRU ����ҳ��
	struct PAGE_TABLE * Page1=(PAGE_TABLE *)malloc(Page_Size*sizeof(PAGE_TABLE));
	//FIFO ����ҳ��
	struct PAGE_TABLE * Page2=(PAGE_TABLE *)malloc(Page_Size*sizeof(PAGE_TABLE));
	///����ҳ��ĳ�ʼ��
	Page_Table_Boot(Page1,Page_Size);
	Page_Table_Boot(Page2,Page_Size);
	////---------------------------------------------------------------------------------------
	printf("�����ڴ��(�����)�Ĵ�С��\n");
	int Block_Size;
	scanf_s("%d",&Block_Size);
	getchar();
	///+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	printf("�����ڴ�飨����飩�ĸ�����\n");
	int Block_Num;
	scanf_s("%d",&Block_Num);
	getchar();
	char  Graph[10][10];
	Creat_Position(Graph);
	Physical_Block  * P1;
	Physical_Block  * P2;
	Phy_Block_Boot(Graph,P1,Block_Num);
	for(int i=0;i<Block_Num;i++)
	{
		printf("�ڴ���Ӧ�������ַΪ��\n");
		printf("\n  %d      %d    \n",i, P1[i].phy_addre);
	}
	Phy_Block_Boot(Graph,P2,Block_Num);
	for(int i=0;i<Block_Num;i++)
	{
		printf("�ڴ���Ӧ�������ַΪ��\n");
		printf("\n  %d      %d    \n",i, P2[i].phy_addre);
	}
	
	///---------------------------------------------------------------------------------
	///λʾͼ

	////--------------------------------------------
	int Find_Page1=0;  //���д���
	int Find_Page2=0;
	int Visit_Page=0;   ///����ҳ���ܵĴ���
	////����ҳ�ŵ�����
	int List[20];
	for(int i=0;i<20;i++)
	{
	  List[i]=-1;
	}

	///*****************************+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	int Logic_Address=0;
	int Page_Num;    ///��ǰҳ��
	int Page_in_Address;     ////��ַת���е�ҳ�ڵ�ַ
	while(Logic_Address!=-1)
	{
		//Logic_Address=0;
		printf("�����߼���ַ��    \n");
		scanf_s("%x",&Logic_Address);
		getchar();
		if(Logic_Address== -1)  break;
		Page_Num=Logic_Address/(Block_Size*1024);  //ҳ��
		Page_in_Address=Logic_Address%(Block_Size*1024);  ///ҳ�ڵ�ַ
		//LRU
		 if (LRU(Graph,P1, Block_Size, Page1, Page_Size, Page_Num, Find_Page1,Block_Num) != -1)
		{
		     List[Visit_Page] = Page_Num;
		}  
		 else 
		 {
		    continue;
		 }
		 ////FIFO    
		if(FIFO(Graph,P2,Block_Size,Page2,Page_Size,Page_Num,Find_Page2,Block_Num)!=-1)
		{
		     Visit_Page++;
		}
		else
		{
			continue;
		}
		////�������ҳ����ջ
		printf("                              LRU\n");
		printf("�����ַ��  %x\n",((P1[Page1[Page_Num].Phy_Num].phy_addre)*Block_Size*1024+ Page_in_Address));
	    printf("���д�����   %d   �����ܴ�����   %d",Find_Page1,Visit_Page);
		Print(Page1,P1,Page_Size,Block_Num);
		printf("                              FIFO\n");
		printf("�����ַ��  %x\n",((P1[Page1[Page_Num].Phy_Num].phy_addre)*Block_Size*1024+ Page_in_Address));
	    printf("���д�����   %d   �����ܴ�����   %d",Find_Page1,Visit_Page);
		Print(Page1,P2,Page_Size,Block_Num);
	}
	float rate1,rate2;
	rate1=(float)Find_Page1/(float)Visit_Page;
	rate2=(float)Find_Page2/(float)Visit_Page;
	printf("LRU �����ʣ� %f\n",rate1);
	printf("FIFO �����ʣ� %f\n",rate2);
	printf("**************************--------------------------------************************\n");
	printf("���з�������Ϊ��\n");
	Print_List(List,Visit_Page);
	free(P1);
	Find_Page1=0;
	Phy_Block_Boot(Graph,P1,Block_Num);
	Page_Table_Boot(Page1,Page_Size);
    ////OPT�㷨ʵ��   OPT(char Graph[10][10],Physical_Block * PB,int Block_Size,PAGE_TABLE *p,int Page_Size,int &Find_Page,int *List,int List_Size )
	OPT(Graph,P1,Block_Num,Page1,Page_Size,Find_Page1,List,Visit_Page);
    printf(" \n ���д����� %d ,���ʴ����� %d",Find_Page1,Visit_Page);
	
	float rate=(float)Find_Page1/Visit_Page;
	printf("\n OPT  �����ʣ�%f",rate);
	free(P1);
	return 0;
}

