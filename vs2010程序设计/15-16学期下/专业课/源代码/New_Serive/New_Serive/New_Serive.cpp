// New_Serive.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdio.h>
#include <winsock2.h>
#include<string.h>
#define N 10
#pragma comment(lib,"ws2_32.lib")

///����RIP �ṹ��
typedef struct RIP{
	char  aim[N];       ////Ŀ������---
	int   dis;            //����
	char jump[N];      //��һ��
	char  host_add[N];          ///��ű���·�ɵ�ַ
	// RIP * next;   ///�γ�����ṹ
}RIP;
int main(int argc, char* argv[])
{

	//����·�ɱ��ʼ��
	int count_s=0;      ///���ڼ�¼--����ڵ����
	char address[N]="R4";     ///��ű���·�ɵ�ַ

	RIP s[N];
	RIP  t[N];      ///���ڽ���socket�������Ľṹ��
	int count1=0;        ///  ���socket�������ṹ�������±�
	strcpy(s[0].aim,"Net1");
	s[0].dis=3;
	//strcpy(s[0].dis,"6");
	strcpy(s[0].host_add,address);
	strcpy(s[0].jump,"R1");
	count_s++;

	strcpy(s[1].aim,"Net2");
	strcpy(s[1].host_add,address);
	s[1].dis=4;
	//strcpy(s[1].dis,"3");
	//L->dis=3;
	strcpy(s[1].jump,"R2");
	count_s++;

	strcpy(s[2].aim,"Net3");
	s[2].dis=1;
	//strcpy(s[2].dis,"55");
	strcpy(s[2].jump,"R7");
	strcpy(s[2].host_add,address);
	count_s++;



	/*
	RIP * L=(RIP *)malloc(sizeof(RIP));       ////��һ���ڵ�
	count++;
	strcpy(L->aim,"net1");
	strcpy(L->host_add,address);
	strcpy(L->dis,"3");
	//L->dis=3;
	strcpy(L->jump,"a");
	L->next=NULL;

	RIP * p=(RIP *)malloc(sizeof(RIP));
	count++;
	strcpy(p->aim,"net2");
	strcpy(p->host_add,address);
	strcpy(p->dis,"4");
	//p->dis=2;
	strcpy(p->jump,"b");
	p->next=NULL;

	RIP * q;
	q=L; 
	while(q->next!=NULL)            ///�յ���������һ���ڵ�
	{
	q=q->next;
	}
	q->next=p;


	p=(RIP *)malloc(sizeof(RIP));
	count++;
	strcpy(p->aim,"net3");
	strcpy(p->host_add,address);
	strcpy(p->dis,"2");
	//p->dis=2;
	strcpy(p->jump,"c");
	p->next=NULL;

	q=L; 
	while(q->next!=NULL)            ///�յ���������һ���ڵ�
	{
	q=q->next;
	}
	q->next=p;

	*/
	//��ʼ��WSA,����socket�汾 Ϊ��2��2��
	WORD sockVersion = MAKEWORD(2,2);
	WSADATA  wsaData;
	if(WSAStartup(sockVersion, &wsaData)!=0)
	{
		return 0;
	}

	//�����׽���
	SOCKET slisten = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);  //ϵͳ����socket �����ֱ���TCP����IPV4����ʧ�׽��� ��һ��������ָ����ַ��(TCP/IPֻ����AF_INET��Ҳ��д��PF_INET)  
	// �ڶ�����ѡ���׽��ֵ�����(��ʽ�׽���)�����������ض���ַ�������Э�飨0Ϊ�Զ���
	if(slisten == INVALID_SOCKET)
	{
		printf("socket error !");
		return 0;
	}

	//��IP�Ͷ˿�
	sockaddr_in sin;
	sin.sin_family = AF_INET;
	sin.sin_port = htons(520);

	//sin.sin_addr.S_un.S_addr = INADDR_ANY; 
	sin.sin_addr.S_un.S_addr=inet_addr("127.0.0.1");
	printf("----------------------\n");
	//puts(inet_ntoa(S_asin_addr));
	//ipAddr.S_un.S_addr = inet_addr("127.0.0.1");
	// �׽���sockSrv�뱾�ص�ַ���� 
	if(bind(slisten, (LPSOCKADDR)&sin, sizeof(sin)) == SOCKET_ERROR)
	{
		printf("bind error !");
	}

	// ���׽�������Ϊ����ģʽ���������󣩣� listen()֪ͨTCP������׼���ý�������  
	//��ʼ����
	if(listen(slisten, 5) == SOCKET_ERROR)
	{
		printf("listen error !");
		return 0;
	}

	//ѭ����������
	SOCKET sClient;
	sockaddr_in remoteAddr;
	int nAddrlen = sizeof(remoteAddr);
	char revData[255]; 
	int flage=1;
	while (flage==1)
	{
		// accept()���������ӣ��ȴ��ͻ�������  
		printf("�ȴ�����...\n");
		sClient = accept(slisten, (SOCKADDR *)&remoteAddr, &nAddrlen);

		printf("���ܵ�һ�����ӷ��������IP��ַΪ��%s \t\t", inet_ntoa(remoteAddr.sin_addr));
		if(strcmp(inet_ntoa(remoteAddr.sin_addr),"127.0.0.1")!=0)
		{
			printf("IP��ַ����������������ӣ�\n");
			//return 0;
		}
		printf("�����Ķ˿ڵ�ַΪ��%d   \n", ntohs(sin.sin_port));
		if(sClient == INVALID_SOCKET)
		{
			printf("accept error !");
			continue;
		}

		//while(true)
		//{
			///****************************************************
			//RIP * L;
			//	RIP *q;
			/*
			printf("����·�ɵ�ַΪ��    %s\n",L->host_add);
			printf("��··�ɱ�Ϊ��\n");
			printf("Ŀ������		����		��һ��\n");
			q=L;
			while(q!=NULL)
			{
			printf("%s        \t\t%s \t\t%s\n",q->aim,q->dis,q->jump);
			q=q->next;
			}   */
			//��������
			// recv(), ���׽����Ͻ�������

			/*
			int ret = recv(sClient, revData, 255, 0);        
			if(ret > 0)
			{
			revData[ret] = 0x00;
			printf("���յ��ͻ��˷��͵�����Ϊ��\n");
			printf(revData);
			printf("\n");
			}   */

			printf("����·�ɱ�\n");
			printf("����·�ɵ�ַΪ R4  \n");
			printf("-----------------------------------------\n");
			printf("Ŀ������\t\t����\t\t��һ��\n");
			printf("-----------------------------------------\n");
			for(int i=0;i<count_s;i++)
			{
				printf("%s\t\t\t%d\t\t%s\n",s[i].aim,s[i].dis,s[i].jump);
			}
			printf("-----------------------------------------\n\n\n");
			char buffer[100]="\0";
			//	RIP recvRIP;
			recv(sClient,buffer,sizeof(buffer),0);
			memcpy(&t[count1],buffer,sizeof(buffer));
			//printf("socketͨ���յ���·�ɱ�Ϊ��\n");
			//printf("·�ɵ�ַΪ  %s\n",t[count1].host_add);
			//printf("------------------------------------------\n");
			//printf("Ŀ������\t\t����\t\t��һ��\n");
			//printf("%s\t\t\t%d\t\t%s\n",t[count1].aim,t[count1].dis,t[count1].jump);
			//	printf("%s   %s   %s   %s\n",recvRIP.aim,recvRIP.dis,recvRIP.jump,recvRIP.host_add);
			//	recvRIP.dis++;                  
			//	strcpy(recvRIP.jump,add_2);
			t[count1].dis++;                             ////�����յ���·�ɱ����Ԥ����
			strcpy(t[count1].jump,t[count1].host_add);
			count1++;


			char buffer1[100]="\0";
			recv(sClient,buffer1,sizeof(buffer1),0);
			memcpy(&t[count1],buffer1,sizeof(buffer1));
			//printf("%s\t\t\t%d\t\t%s\n",t[count1].aim,t[count1].dis,t[count1].jump);
			t[count1].dis++;
			strcpy(t[count1].jump,t[count1].host_add);
			count1++;


			char buffer2[100]="\0";
			recv(sClient,buffer2,sizeof(buffer2),0);
			memcpy(&t[count1],buffer2,sizeof(buffer2));
			//printf("%s\t\t\t%d\t\t%s\n",t[count1].aim,t[count1].dis,t[count1].jump);
			t[count1].dis++;
			strcpy(t[count1].jump,t[count1].host_add);
			count1++;
			//printf("-----------------------------------------\n\n\n");


			printf("\n�յ���·�ɱ�Ԥ�����Ϊ��\n");
			printf("-----------------------------------------\n");
			printf("Ŀ������\t\t����\t\t��һ��\n");
			printf("-----------------------------------------\n");
			for(int i=0;i<count1;i++)
			{
				printf("%s\t\t\t%d\t\t%s\n",t[i].aim,t[i].dis,t[i].jump);
			}
			printf("-----------------------------------------\n\n\n");

			for(int j=0;j<count1;j++)       ///�����յ���·�ɱ�
			{
				int flage=0;
				for(int i=0;i<count_s;i++)            ////��������·�ɱ�
				{
					if(strcmp(s[i].aim,t[j].aim)==0)				///������·�ɱ�������Nʱ��
					{
						flage=1;
						if(strcmp(s[i].jump,t[j].jump)==0)            ////����һ���� Xʱ�����滻ԭ·�ɱ�ľ���
						{
							s[i].dis=t[j].dis;
						}
						else if(t[j].dis<s[i].dis)                 ///���յ���Ŀ�еľ���dС�ڱ��еľ���ʱ������.
						{
							s[i].dis=t[j].dis;
							strcpy(s[i].jump,t[j].jump);
						}
					}
					else if(i==(count_s-1) && flage==0)       ////�����������б���·�ɱ��û�з��� ����Nʱ������ӵ�����·�ɱ�
					{
						strcpy(s[count_s].aim,t[j].aim);
						strcpy(s[count_s].host_add,address);
						s[count_s].dis=t[j].dis;
						strcpy(s[count_s].jump,t[j].jump);
						count_s++;
						break;     ///������ǰѭ��
					}
				}
			}

			printf("���º�ı���·�ɱ�\n");
			printf("����·�ɵ�ַΪ R4  \n");
			printf("-----------------------------------------\n");
			printf("Ŀ������\t\t����\t\t��һ��\n");
			printf("-----------------------------------------\n");
			for(int i=0;i<count_s;i++)
			{
				printf("%s\t\t\t%d\t\t%s\n",s[i].aim,s[i].dis,s[i].jump);
			}
			printf("-----------------------------------------\n\n\n");


			printf("**********************************");

			// send(), ���׽����Ϸ�������  
			//��������

			/*
			RIP L;
			memcpy(L.aim,"net1",sizeof("net1"));
			memcpy(L.dis,"4",sizeof("4"));
			memcpy(L.jump,"a",sizeof("a"));
			memcpy(L.host_add,"w",sizeof("w"));
			L.next=NULL;  */
			//memcpy(L.next,"",sizeof(""));   
			//	printf("%s   %s   %s   %s",L.aim,L.dis,L.jump,L.host_add);  

			// char * sendData = "��ã�TCP�ͻ��ˣ�\n";
			//printf("���ͽṹ�壡��\n");
			printf("----------------��������·�ɱ�-----------------\n");
			send(sClient,(char *)&s[0],sizeof(RIP),0);
			Sleep(1000);
			send(sClient,(char *)&s[1],sizeof(RIP),0);
			Sleep(1000);
			send(sClient,(char *)&s[2],sizeof(RIP),0);
			Sleep(1000);
			/*char message[100];
			printf("�����뽫Ҫ���͵����ݣ�\n");
			scanf("%s",message);
			send(sClient, message, strlen(message), 0);  */
		//}
	}

	closesocket(sClient);
	closesocket(slisten);
	WSACleanup();
	return 0;
}



