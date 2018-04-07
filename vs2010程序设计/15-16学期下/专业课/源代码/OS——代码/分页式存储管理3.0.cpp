// 分页式存储管理3.0.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<string.h>
///页表
struct PAGE_TABLE
{
	int Phy_Num;  /// 物理块号
	int  Status;   ///状态位
};
//物理块
struct Physical_Block
{
	int page_number;/// 页号
	int phy_addre;  ///物理地址
};

void Print(PAGE_TABLE *P,Physical_Block *PB,int Page_Size, int Block_Size);

void Get_Address(char  Graph[][10],Physical_Block *  &p,int  Block_size)
{
	int i,j;  
	int count=0;
//	printf("找出位示图中前%d  个0对应的位置  \n",count1);
	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
		{
			if(Graph[i][j]==0)
			{ 
			   
				p[count].phy_addre=i*8+j+1;    ///记录 i  , j对应数组的位置
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
			   Graph[i][j]=1;    ///当栈中已有元素时，修改对应位示图中的内容
			//	p[count].phy_addre=i*8+j+1;    ///记录 i  , j对应数组的位置
				if(count==Physic_Block_Num)  return ;
			}
	   }
	}
  
}
///页表的初始化函数
void  Page_Table_Boot(PAGE_TABLE * &P,int  Page_Size)
{    
	for(int i=0;i<Page_Size;i++)
	{
		P[i].Phy_Num=-1;     ///存放物理块的块号
		P[i].Status=0;      ///状态位置 0
	}
}
///函数功能：物理块的初始化
void  Phy_Block_Boot(char  Graph[][10],Physical_Block *  &p,int  Block_size)
{
    p=(Physical_Block *)malloc(Block_size*sizeof(Physical_Block));   ///申请动态数组
	for(int i=0;i<Block_size;i++)
	{
		p[i].page_number=-1;
		p[i].phy_addre=-1;
	}
	 Get_Address(Graph,p,Block_size);
}
///位示图   初始化  ,寻找n个物理块对应的物理地址
void Creat_Position(char  Graph[][10])
{

	///*****************用随机数函数为位示图内容赋值
	int n,i,j;
	//	int k;  ///记录 i  , j对应数组的位置
	
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
	//	printf("请输入内存容量的大小！\n");
	//	scanf("%d",&large1);
	//printf("请输入内存划分块的大小！\n");
	//	scanf("%d",&large2);
	//	i=large1/large2;
	//	k=(int )sqrt(i*1.0);
	printf("***********位示图的大小为8*8***************\n");
	printf("根据内存划分的位示图为：\n");
	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
		{
			printf("%d    ",Graph[i][j]);
		}
		printf("\n");
	}
	//Creat_Process(large2, k, Graph);
//	printf("请输入物理块的个数\n");
	//scanf("%d",&Physic_Block_Number);
	/*
	int * k=NULL;  ///记录 i  , j对应数组的位置
	k=(int *)malloc(Physic_Block_Number*sizeof(int));
	printf("找出位示图中前%d  个0对应的位置  \n",Physic_Block_Number);
	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
		{
			if(Graph[i][j]==0)
			{ 
				k[count]=i*8+j+1;    ///记录 i  , j对应数组的位置
				count++;
				if(count==(Physic_Block_Number-1)) break;
			}

		}
		if(count==(Physic_Block_Number-1)) break;
	}
	return k;   */
}

/*
///函数功能：对位示图的内容进行修改  
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
	//	printf("请输入物理块的个数\n");
	//scanf("%d",&Physic_Block_Number);
	//int * k=NULL;  ///记录 i  , j对应数组的位置
	int p=0;
//	int  k1;
	int * k =(int *)malloc(Block_Num*sizeof(int));  ///动态数组用来存放位示图对应的地址
//	while(p< Physic_Block_Number)
//	{
//	   k[p]=0;
//	}
	int count=0;
//	printf("找出位示图中前%d  个0对应的位置  \n",count1);
	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
		{
			if(Graph[i][j]==0)
			{ 
			//	k=i*8+j+1;
			//  return k;
				k[count]=i*8+j+1;    ///记录 i  , j对应数组的位置
				count++;
				if(count==Block_Num) break;
			}

		}
		if(count==Block_Num) break;
	}
  	return k;
}            */
///函数功能：页面调入与置换
///  FIFO    LRU   用到的页面调入函数
void Page_In_1(char  Graph[][10],Physical_Block * PB,int Block_Size,PAGE_TABLE * p,int Page_Size,int Page_Num,int Physic_Block_Num )
{
   //	int count;
   //	int count1;
	int Temp=0;
	int Tag=0;
	///扫描栈，找出栈中空的位置tag,若不为空，tag为-1
	for(Temp=0;Temp< Physic_Block_Num;Temp++)
	{
		if(PB[Temp].page_number==-1)
		{
			Tag=Temp;
		//	count=Temp;//记录物理块中已有页号的个数
			break;
		}
	}
//	count1=Physic_Block_Num-count;
	if(Temp== Physic_Block_Num)
	{
		Tag=-1;
	}///当栈中元素已满，需要把当前某个页调出，当前页调入内存
	if(Tag==-1)
	{
		p[PB[0].page_number].Status=0;
		p[PB[0].page_number].Phy_Num=-1;
		///将当前页表调入内存
		///将栈中数据元素前移
		for(int i=1;i<Physic_Block_Num;i++)
		{
			PB[i-1].page_number=PB[i].page_number;
			p[PB[i].page_number].Phy_Num--;
		}
		PB[Physic_Block_Num-1].page_number=Page_Num;
		//修改当前页表中的内容
		p[Page_Num].Phy_Num=Physic_Block_Num-1;
		p[Page_Num].Status=1;
		return ;
	}
	else
	{
		PB[Temp].page_number=Page_Num;
		p[Page_Num].Phy_Num=Tag;                                                        ////////////////////////////////////////////////////////////////
		p[Page_Num].Status=1;
		///对位示图中的内容进行修改
		//Change_Graph(Graph,p,Block_Size);
		//PB[Temp].phy_addre=k;
		//  Change_Graph( Graph[10][10], count1);
		Change_Graph(Graph,PB,Physic_Block_Num);
	}
}
///函数功能：FIFO置换算法
int FIFO(char Graph[][10],Physical_Block *PB, int Block_Size,PAGE_TABLE *p,int Page_Size,int Page_Num,int & Find_Page,int Physic_Block_Num)
{
	///查看该页号对应的状态位，0在内存，1不在内存
	if(p[Page_Num].Status==0)
	{ 
		///置换或者调入
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

	///查看页表中对应的状态位   0 代表存在  1 不存在
	if(p[Page_Num].Status==0)   ///缺页情况
	{
		//置换或者调入
		Page_In_1( Graph, PB, Block_Size, p, Page_Size, Page_Num, Physic_Block_Num);
	}
	else ///  命中
	{
		if((Physic_Block_Num-p[Page_Num].Phy_Num)>=2)  ////命中的页面，是物理块栈中的前两位时，，需要将其置顶
		{
			int Temp=Page_Num;
			for(int i=p[Page_Num].Phy_Num;i<Physic_Block_Num-1;i++)
			{
				PB[i].page_number=PB[i+1].page_number;  ///修改栈中的内容
				p[PB[i+1].page_number].Phy_Num--;     ///修改页表中的内容
			}
			PB[Physic_Block_Num-1].page_number=Temp;
			p[Page_Num].Phy_Num=Physic_Block_Num-1;
		}
		Find_Page++;
	}
	return 0;
}
////******************************************************
///OPT算法用到的页表调入，换出函数
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
		///遍历整个序列，找到内存块下次出现的位置
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
		///求三个数中最大的
		int max=0;
		for(int i=0;i<Block_Size;i++)
		{
			if(T[max]<T[i])
			{
				max=i;
			}
		}
		///替换出最大数对应的块
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
		///修改位示图
		//int k=Change_Graph(Graph,p,Block_Size);;
	}
	return;
}
////         OPT  用到的页表输入函数

///函数功能：OPT  算法的实现
void  OPT(char Graph[][10],Physical_Block * PB,int Block_Size,PAGE_TABLE *p,int Page_Size,int &Find_Page,int *List,int List_Size )
{
	///查看位示图 Page_In_2(char Graph[10][10],Physical_Block *PB,int Block_Size,PAGE_TABLE *p,int Page_Size,int Page_Num,int List_Num,int *List,int List_Size)
   
	for(int i=0;i<List_Size;i++)
	{
		if(p[List[i]].Status==0)
		{
			Page_In_2(Graph,PB,Block_Size,p,Page_Size,List[i],i,List,List_Size);
			//printf("                              LRU\n");
		    //printf("物理地址：  %d\n",((P1[Page1[Page_Num].Phy_Num].phy_addre)*Block_Size+ Page_in_Address));
	       // printf("命中次数：   %d   访问总次数：   %d",Find_Page1,Visit_Page);
		    Print(p,PB,Page_Size, Block_Size);
		}
		else 
		{
			Find_Page++;
			printf("命中！\n");
		}

	}

}
///函数功能：打印函数
void Print(PAGE_TABLE *P,Physical_Block *PB,int Page_Size, int Block_Size)
{
	printf("\n");
	printf("页号     状态号     物理块号     栈的状态  \n");
	for(int i=0;i<Page_Size;i++)
	{
		if(P[i].Phy_Num != -1)     ///当该页号，以被利用
		{ 
			printf("%d         %d",i,P[i].Status);
		}
		else     ///// 当该页号，未被利用时
		{
			printf("%d         %d",i/*,P[i].Phy_Num,*/,P[i].Status);
		}
		if(i<Block_Size)  ///输出物理块， 对应的栈
		{
			if(PB[Block_Size-i-1].page_number!=-1)   ////物理块，中有内容时
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

////// 访问序列（OPT算法，需要）
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
	printf("*************内存块的大小为64kB*******\n");
	printf("*************页表的大小为6************\n");
	///-------------------------------------------------------------------------------------
	int Page_Size=6;
	///LRU 申请页表
	struct PAGE_TABLE * Page1=(PAGE_TABLE *)malloc(Page_Size*sizeof(PAGE_TABLE));
	//FIFO 申请页表
	struct PAGE_TABLE * Page2=(PAGE_TABLE *)malloc(Page_Size*sizeof(PAGE_TABLE));
	///两个页表的初始化
	Page_Table_Boot(Page1,Page_Size);
	Page_Table_Boot(Page2,Page_Size);
	////---------------------------------------------------------------------------------------
	printf("输入内存块(物理块)的大小！\n");
	int Block_Size;
	scanf_s("%d",&Block_Size);
	getchar();
	///+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	printf("输入内存块（物理块）的个数！\n");
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
		printf("内存块对应的物理地址为：\n");
		printf("\n  %d      %d    \n",i, P1[i].phy_addre);
	}
	Phy_Block_Boot(Graph,P2,Block_Num);
	for(int i=0;i<Block_Num;i++)
	{
		printf("内存块对应的物理地址为：\n");
		printf("\n  %d      %d    \n",i, P2[i].phy_addre);
	}
	
	///---------------------------------------------------------------------------------
	///位示图

	////--------------------------------------------
	int Find_Page1=0;  //命中次数
	int Find_Page2=0;
	int Visit_Page=0;   ///访问页表总的次数
	////访问页号的序列
	int List[20];
	for(int i=0;i<20;i++)
	{
	  List[i]=-1;
	}

	///*****************************+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	int Logic_Address=0;
	int Page_Num;    ///当前页号
	int Page_in_Address;     ////地址转换中的页内地址
	while(Logic_Address!=-1)
	{
		//Logic_Address=0;
		printf("输入逻辑地址！    \n");
		scanf_s("%x",&Logic_Address);
		getchar();
		if(Logic_Address== -1)  break;
		Page_Num=Logic_Address/(Block_Size*1024);  //页号
		Page_in_Address=Logic_Address%(Block_Size*1024);  ///页内地址
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
		////输出两个页表与栈
		printf("                              LRU\n");
		printf("物理地址：  %x\n",((P1[Page1[Page_Num].Phy_Num].phy_addre)*Block_Size*1024+ Page_in_Address));
	    printf("命中次数：   %d   访问总次数：   %d",Find_Page1,Visit_Page);
		Print(Page1,P1,Page_Size,Block_Num);
		printf("                              FIFO\n");
		printf("物理地址：  %x\n",((P1[Page1[Page_Num].Phy_Num].phy_addre)*Block_Size*1024+ Page_in_Address));
	    printf("命中次数：   %d   访问总次数：   %d",Find_Page1,Visit_Page);
		Print(Page1,P2,Page_Size,Block_Num);
	}
	float rate1,rate2;
	rate1=(float)Find_Page1/(float)Visit_Page;
	rate2=(float)Find_Page2/(float)Visit_Page;
	printf("LRU 命中率： %f\n",rate1);
	printf("FIFO 命中率： %f\n",rate2);
	printf("**************************--------------------------------************************\n");
	printf("所有访问序列为：\n");
	Print_List(List,Visit_Page);
	free(P1);
	Find_Page1=0;
	Phy_Block_Boot(Graph,P1,Block_Num);
	Page_Table_Boot(Page1,Page_Size);
    ////OPT算法实现   OPT(char Graph[10][10],Physical_Block * PB,int Block_Size,PAGE_TABLE *p,int Page_Size,int &Find_Page,int *List,int List_Size )
	OPT(Graph,P1,Block_Num,Page1,Page_Size,Find_Page1,List,Visit_Page);
    printf(" \n 命中次数： %d ,访问次数： %d",Find_Page1,Visit_Page);
	
	float rate=(float)Find_Page1/Visit_Page;
	printf("\n OPT  命中率：%f",rate);
	free(P1);
	return 0;
}

