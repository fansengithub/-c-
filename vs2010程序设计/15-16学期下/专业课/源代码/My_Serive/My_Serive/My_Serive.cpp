// My_Serive.cpp : �������̨Ӧ�ó������ڵ㡣
//����������ʵ��

#include "stdafx.h"
#include<iostream>
#include<WINSOCK2.H>
#include<WS2tcpip.h>
#pragma comment(lib,"WS2_32.lib")    //��ʾ���ӵ�WS2_32.lib��
using namespace std;

#define SER_PORT 5000    ///�������˶˿ڵ�ַ
#define SER_IP  "127.0.0.1"     ///��������IP��ַ

DWORD WINAPI ThreadProcessor(LPVOID lpParameter); //�������ݵ��̺߳���  
fd_set fdRead = { 0 };
int _tmain(int argc, _TCHAR* argv[])
{
	SOCKET sever;              ///�׽���
	SOCKET client;
	char buf[1024];
	///��ַ��Ϣ
	SOCKADDR_IN ser_addr;
	SOCKADDR_IN cli_addr;

	struct in_addr s;
	char IP_s[20];

	int ret;      ///���ڱ��溯���ķ���ֵ
	WORD wVersionRequested;
	WSADATA wsaData;				//�ýṹ�����ڽ���Windows Socket �Ľṹ��Ϣ��
	int cliAddrLen;
	wVersionRequested=MAKEWORD(2,2);             ///// ����2.2�汾��WinSock�� 
	if(WSAStartup(wVersionRequested,&wsaData) !=0)       // ����ֵΪ���ʱ���Ǳ�ʾ�ɹ�����WSAStartup
	{
	   cout<<"��ʼ��ʧ�ܣ�\n";
		   return 1;
	}
	ser_addr.sin_family=AF_INET;
	inet_pton(AF_INET,SER_IP,(void *)&s);
	ser_addr.sin_addr.S_un.S_addr=s.S_un.S_addr;
	ser_addr.sin_port=htons(SER_PORT);      //�������ʮ���ơ� ��> ��������������     ��һ������af�ǵ�ַ�أ��ڶ�������*src����Դ��ַ������������* dst����ת��������ݡ�
	memset(ser_addr.sin_zero,0,8);
	///�����׽���
	sever=socket(AF_INET,SOCK_STREAM,0);
	if(sever==INVALID_SOCKET)
	{
	  cout<<"�����׽���ʧ�ܣ�����������!\n";
	  return 1;
	}
	///��
	if(bind(sever,(SOCKADDR *)&ser_addr,sizeof(SOCKADDR))!=0)
	{
	  cout<<"��ʧ�ܣ�����������!";
	  return 1;
	}
	else
	{
	   cout<<"���������������ɹ�����ʹ�ã�";

	}
	///���������ϵ�ѭ�����������ͻ��˵�����
	while(1)
	{
	  ///������������׼��
		if(int i=listen(sever,6)!=0)
		{
		  cout<<"listen()����ʧ�ܣ�\n";
		 return 1;
		}
		cliAddrLen=sizeof(SOCKADDR);     //�ͻ��˵ĵ�ַ����
		/// ���ؿͻ����׽��֣�  cli_addr Ϊ�ͻ��˵ĵ�ַ���˿���Ϣ
		if ((client = accept(sever, (SOCKADDR *)&cli_addr, &cliAddrLen)) == INVALID_SOCKET)
		{
			cout << "�ͻ����Ѿ��Ͽ����ӣ�\n\n";
			break;
		}
		inet_ntop(AF_INET,(void *)&cli_addr.sin_addr,IP_s,16);
		cout<<IP_s<<endl;
		cout<<"*****************************\n";
		cout<<"Client IP:  "<<IP_s<<endl;
		cout<<"\n Client Port:  "<<ntohs(cli_addr.sin_port)<<endl;
		cout<<"*****************************\n";
		//FD_ZERO(&fdRead);
		//FD_SET(client,&fdRead);

		bool bAvail=true;
		///��������
		while(bAvail)
		{
		 //  FD_SET(client,&fdRead);       //��client���뵽��ȡ������ 
		//   timeval t={0};         ///�����������пɶ����ݲŷ��أ���Ȼ��ϳ���  
		  // t.tv_usec=1000*500;
		   char sendBuf[1024];
					int RecvBytes = 0;
					do   //ѭ����ȡ���ݣ�ֱ���������е����ݶ���  
					{
						//��������  
						RecvBytes = recv(client, buf, sizeof(buf), 0);
						if (RecvBytes == SOCKET_ERROR || RecvBytes == 0)    ///RecvBytes ����������ݵĳ���
						{
							cout << "���ݽ���ʧ�ܻ�ͻ����Ѿ��Ͽ���\n";
							bAvail = false;
							break;
						}
						buf[RecvBytes] = 0; //�����ݴ����Ͻ�����  
						//��ӡ�յ�����  
						cout << "�յ�" << RecvBytes << " bytes ����:  "
							<< buf << endl;
						cout << "���ͣ� ";
						cin.getline(sendBuf, 1024);
						///��ͻ��˷�������  
						if (send(client, sendBuf, strlen(sendBuf), 0) == -1)
							return -1;
					} while (RecvBytes>0);
			
			//FD_ZERO(&fdRead);
		}
		closesocket(client);
	}


	cout << "end\n";
	//Sleep(5000);

	//FD_CLR(client, &fdRead);
	closesocket(sever);
	WSACleanup();
     getchar();
	return 0;
}

