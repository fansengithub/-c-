// New_Client.cpp : �������̨Ӧ�ó������ڵ㡣
//


#include "stdafx.h"
#include <WINSOCK2.H>
#include <STDIO.H>

#pragma  comment(lib,"ws2_32.lib")
#define N 10
///����RIP �ṹ��
typedef struct RIP{
	char  aim[N];       ////Ŀ������---
	int   dis;            //����
	char jump[N];      //��һ��
	char  host_add[N];          ///��ű���·�ɵ�ַ
  //  RIP * next;   ///�γ�����ṹ
}RIP;

int main(int argc, char* argv[])
{
	///����·�ɱ��ʼ��
	char add_2[10]="R6";
	int count=0;
	RIP c[N];                  ////�ṹ������
	RIP d[N];             ///���ڴ洢���յ��ĳ�ʼ·�ɱ�����������Ԥ����
	int count1=0;
	
	//RIP c3;
	strcpy(c[0].aim,"Net2");
	c[0].dis=3;
	//strcpy(c[0].dis,"2");
	strcpy(c[0].host_add,add_2);
	strcpy(c[0].jump,"R4");
	count++;

	strcpy(c[1].aim,"Net3");
	strcpy(c[1].host_add,add_2);
	c[1].dis=4;
	//strcpy(c[1].dis,"3");
	//L->dis=3;
	strcpy(c[1].jump,"R5");
	count++;

	//RIP c2;
	strcpy(c[2].aim,"Net8");
	strcpy(c[2].host_add,add_2);
	c[2].dis=4;
	//strcpy(c[2].dis,"4");
	strcpy(c[2].jump,"R8");
	count++;

	
	///��ʼ��WSA
	WORD sockVersion = MAKEWORD(2,2);
	WSADATA data; 
	if(WSAStartup(sockVersion, &data) != 0)
	{
		return 0;
	}
	SOCKET sclient = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(sclient == INVALID_SOCKET)
	{
		printf("invalid socket !");
		return 0;
	}
	sockaddr_in serAddr;
	serAddr.sin_family = AF_INET;
	serAddr.sin_port = htons(520);
	char adder_IP[100];
	printf("������Զ��������IP��ַ!\n");
	scanf("%s",adder_IP);
	serAddr.sin_addr.S_un.S_addr = inet_addr(adder_IP);    ////�����ʽ��IP��ַת��Ϊ������
	printf("************  ");
	printf("�˿ںţ�  %d",ntohs(serAddr.sin_port));
	printf("************  ");
	puts(adder_IP);
	// ���׽���sockClient��Զ����������
	if (connect(sclient, (sockaddr *)&serAddr, sizeof(serAddr)) == SOCKET_ERROR)
	{
		printf("))))))))))))))))\**************");
		printf("connect error !");
		closesocket(sclient);
		return 0;
	}
	//do{
		/*
		char message[100];
		printf("�����뷢�����ݣ�\n");
		scanf("%s",message);
		// char * sendData = "��ã�TCP����ˣ����ǿͻ���!\n  hello world\n";
		//printf("�����뽫Ҫ���͵����ݣ�\n");
		
		send(sclient, message, strlen(message), 0);  */
		printf("------------------���Ͷ˷���·�ɱ�---------------------------\n");
		send(sclient,(char *)&c[0],sizeof(RIP),0);
		Sleep(1000);
		send(sclient,(char *)&c[1],sizeof(RIP),0);
		Sleep(1000);
		send(sclient,(char *)&c[2],sizeof(RIP),0);
		Sleep(1000);



		printf("����·�ɱ�\n");
		printf("����·�ɵ�ַΪ R6  \n");
		printf("-----------------------------------------\n");
		printf("Ŀ������\t\t����\t\t��һ��\n");
		printf("-----------------------------------------\n");
		for(int i=0;i<count;i++)
		{
			printf("%s\t\t\t%d\t\t%s\n",c[i].aim,c[i].dis,c[i].jump);
		}
		printf("-----------------------------------------\n\n\n");
		char buffer[100]="\0";
	//	RIP recvRIP;
		recv(sclient,buffer,sizeof(buffer),0);
		memcpy(&d[count1],buffer,sizeof(buffer));
	//	printf("socketͨ���յ���·�ɱ�Ϊ��\n");
	//	printf("·�ɵ�ַΪ  %s\n",d[count1].host_add);
	 //   printf("------------------------------------------\n");
	//	printf("Ŀ������\t\t����\t\t��һ��\n");
	//	printf("%s\t\t\t%d\t\t%s\n",d[count1].aim,d[count1].dis,d[count1].jump);
	//	printf("%s   %s   %s   %s\n",recvRIP.aim,recvRIP.dis,recvRIP.jump,recvRIP.host_add);
	//	recvRIP.dis++;                  
	//	strcpy(recvRIP.jump,add_2);
		d[count1].dis++;                             ////�����յ���·�ɱ����Ԥ����
		strcpy(d[count1].jump,d[count1].host_add);
		count1++;


		char buffer1[100]="\0";
		recv(sclient,buffer1,sizeof(buffer1),0);
		memcpy(&d[count1],buffer1,sizeof(buffer1));
		//printf("%s\t\t\t%d\t\t%s\n",d[count1].aim,d[count1].dis,d[count1].jump);
		d[count1].dis++;
		strcpy(d[count1].jump,d[count1].host_add);
		count1++;

		
		char buffer2[100]="\0";
		recv(sclient,buffer2,sizeof(buffer2),0);
		memcpy(&d[count1],buffer2,sizeof(buffer2));
		//printf("%s\t\t\t%d\t\t%s\n",d[count1].aim,d[count1].dis,d[count1].jump);
		d[count1].dis++;
		strcpy(d[count1].jump,d[count1].host_add);
		count1++;
		//printf("-----------------------------------------\n\n\n");


		printf("\n�յ���·�ɱ�Ԥ�����Ϊ��\n");
		printf("-----------------------------------------\n");
		printf("Ŀ������\t\t����\t\t��һ��\n");
		printf("-----------------------------------------\n");
		for(int i=0;i<count1;i++)
		{
			printf("%s\t\t\t%d\t\t%s\n",d[i].aim,d[i].dis,d[i].jump);
		}
		printf("-----------------------------------------\n\n\n");
				
		for(int j=0;j<count1;j++)       ///�����յ���·�ɱ�
		{
			int flage=0;
		   for(int i=0;i<count;i++)            ////��������·�ɱ�
		   {
			   if(strcmp(c[i].aim,d[j].aim)==0)				///������·�ɱ�������Nʱ��
			   {
			      flage=1;
				  if(strcmp(c[i].jump,d[j].jump)==0)            ////����һ���� Xʱ�����滻ԭ·�ɱ�ľ���-----2
				  {
					  c[i].dis=d[j].dis;
				  }
				  else if(d[j].dis<c[i].dis)                 ///���յ���Ŀ�еľ���dС�ڱ��еľ���ʱ������.------3
				  {
					  c[i].dis=d[j].dis;
					  strcpy(c[i].jump,d[j].jump);
				  }
				  ///��4�������ʲôҲ����--------------------------4
			   }
 			   else if(i==(count-1) && flage==0)       ////�����������б���·�ɱ��û�з��� ����Nʱ������ӵ�����·�ɱ�----1
			   {
				   strcpy(c[count].aim,d[j].aim);
				   strcpy(c[count].host_add,add_2);
				   c[count].dis=d[j].dis;
				   strcpy(c[count].jump,d[j].jump);
	               count++;
				   break;     ///������ǰѭ��
			   }
		   }
		}

		printf("���º�ı���·�ɱ�\n");
		printf("����·�ɵ�ַΪ R6  \n");
		printf("-----------------------------------------\n");
		printf("Ŀ������\t\t����\t\t��һ��\n");
		printf("-----------------------------------------\n");
		for(int i=0;i<count;i++)
		{
			printf("%s\t\t\t%d\t\t%s\n",c[i].aim,c[i].dis,c[i].jump);
		}
		printf("-----------------------------------------\n\n\n");
		/*
		char recData[255];
		int ret = recv(sclient, recData, 255, 0);
		if(ret > 0)
		{
			recData[ret] = 0x00;
			printf("���յ����������͵�����Ϊ��\n");
			printf(recData);
			printf("\n");
		}
		 */
	//}while(1);

	closesocket(sclient);
	WSACleanup();
	getchar();
	return 0;
}



