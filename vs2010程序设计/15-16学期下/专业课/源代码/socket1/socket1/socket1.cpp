// socket1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
////////////////�������˴��� sever.cpp  
///һ����ʼ���׽���  
///���������׽���  
///������  
///�ġ�����  
///�塢����  
///��������  
///�ߡ���������  
////////////////////////////////////////////////////  

#include <iostream>  
#include <WINSOCK2.H> 
#include <WS2tcpip.h>
//#include <cstdlib>  
#pragma comment(lib,"WS2_32.lib")    //��ʾ���ӵ�WS2_32.lib��+
using namespace std;

#define SER_PORT 5000    //�������˶˿ڵ�ַ
#define SER_IP "127.0.0.1"    //��������IP��ַ

DWORD WINAPI ThreadProcessor(LPVOID lpParameter); //�������ݵ��̺߳���  
fd_set fdRead = { 0 };



int _tmain(int argc, _TCHAR* argv[])
{
	 //�����׽���  
	SOCKET sever;    
	SOCKET client;
	char buf[1024];
	//��ַ��Ϣ
	SOCKADDR_IN ser_addr;   
	SOCKADDR_IN cli_addr;   
	    
	struct in_addr s;
	char IP_s[20];

	int ret;   //���ڱ��溯������ֵ  
	WORD wVersionRequested;
	WSADATA wsaData;
	int cliAddrLen;
	//#define MAKEWORD(a, b)      ((WORD)(((BYTE)(((DWORD_PTR)(a)) & 0xff)) | ((WORD)((BYTE)(((DWORD_PTR)(b)) & 0xff))) << 8))
	wVersionRequested = MAKEWORD(2, 2);
	if (WSAStartup(wVersionRequested, &wsaData) != 0)
	{
		cout << "��ʼ��ʧ�ܣ�\n";
		return 1;
	}
	ser_addr.sin_family = AF_INET;       //#define AF_INET         2               // internetwork: UDP, TCP, etc.
	inet_pton(AF_INET, SER_IP, (void *)&s);
	ser_addr.sin_addr.S_un.S_addr = s.S_un.S_addr;
	//ser_addr.sin_addr.S_un.S_addr = inet_addr(SER_IP);
	ser_addr.sin_port = htons(SER_PORT);
	memset(ser_addr.sin_zero, 0, 8); //CHAR sin_zero[8]��SOCKADDR_IN��һ����Ա����
	///�����׽���  
	sever = socket(AF_INET, SOCK_STREAM, 0);//���캯��
	if (sever == INVALID_SOCKET)
	{
		cout << "�����׽���ʧ�ܣ�\n";
		return 1;
	}
	//��  
	if (bind(sever, (SOCKADDR *)&ser_addr, sizeof(SOCKADDR)) != 0)
	{
		cout << "��ʧ�ܣ�\n";
		return 1;
	}
	else
	{
		cout << "���������ѳɹ�����......\n\n";
	}

	while (1)   //�������˼��������µ�����  
	{
		//����  
		if (int i = listen(sever, 6) != 0)
		{
			cout << "����ʧ��: " << WSAGetLastError() << endl;
			return 1;
		}
		cliAddrLen = sizeof(SOCKADDR);//�ͻ��˵�ַ����
		//���ؿͻ����׽���   cli_addr Ϊ�ͻ��˵ĵ�ַ���˿���Ϣ  
		if ((client = accept(sever, (SOCKADDR *)&cli_addr, &cliAddrLen)) == INVALID_SOCKET)
		{
			cout << "�ͻ����Ѿ��Ͽ����ӣ�\n\n";
			break;
		}
		inet_ntop(AF_INET, (void *)&cli_addr.sin_addr, IP_s, 16);
		cout << IP_s << endl;
		cout << "Client Ip: " << IP_s << endl;
		cout << "Client Port: " << ntohs(cli_addr.sin_port) << endl;

		//      ULONG ul=1;  
		///�������ƣ�����selecѡ��Ͳ���Ҫ�ô˺�����  
		//      if (ret=ioctlsocket(client,FIONBIO,&ul) == SOCKET_ERROR)  
		//      {  
		//          cout << "Call ioctlsocket function fail !\n";  
		//          return 1;  
		//      }  

		FD_ZERO(&fdRead);  //��ռ���  
		FD_SET(client, &fdRead); //��client���뵽��ȡ������  

		bool bAvail = true;
		///��������  
		while (bAvail)
		{
			FD_SET(client, &fdRead); //��client���뵽��ȡ������  

			///���������пɶ����ݲŷ��أ���Ȼ��ϳ���  
			timeval t = { 0 };
			t.tv_usec = 10000 * 500;
			char sendBuf[1024];
			if ((ret = select(0, &fdRead, NULL, NULL, &t)) <= 0)  //��������  
			{
				continue;
			}
			if (ret>0)
			{
				if (FD_ISSET(client, &fdRead))  //client in fdRead  
				{
					int RecvBytes = 0;
					do   //ѭ����ȡ���ݣ�ֱ���������е����ݶ���  
					{
						//��������  
						RecvBytes = recv(client, buf, sizeof(buf), 0);
						if (RecvBytes == SOCKET_ERROR || RecvBytes == 0)
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
					//	Sleep(2 * 1000);
					} while (RecvBytes>0);
				}
			}
			FD_ZERO(&fdRead);
		}//while  
		closesocket(client);
	}//while  

	cout << "end\n";
	Sleep(5000);

	FD_CLR(client, &fdRead);
	closesocket(sever);
	WSACleanup();

	getchar();
	//return 0;
	return 0;
}
