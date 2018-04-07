// socket.cpp : �������̨Ӧ�ó������ڵ㡣
//�ͻ��˴���

#include "stdafx.h"
#include <iostream>  
#include <WINSOCK2.H>  
#include <cstring>  
#include <WS2tcpip.h>
#pragma comment(lib,"WS2_32.lib")  
using namespace std;

#define DES_IP "127.0.0.1"  
#define DES_PORT 5000  

int _tmain(int argc, _TCHAR* argv[])
{
	SOCKET sock;
	char buf[1024]; //���͵��ִ�  
	SOCKADDR_IN ser_addr;//�������˵�ַ
	WSADATA wsaData;       // ��ṹ�����ڽ���Wjndows Socket�Ľṹ��Ϣ�� 
	struct in_addr s;
	WORD wVersionRequired;
	wVersionRequired = MAKEWORD(2, 2);         // ����2.2�汾��WinSock��
	if (WSAStartup(wVersionRequired, &wsaData) != 0)      // ����ֵΪ���ʱ���Ǳ�ʾ�ɹ�����WSAStartup 
	{
		cout << WSAGetLastError() << endl;
		cout << "��ʼ��ʧ�ܣ�\n";
		//  return 1;  
	}

	//if (sock = WSASocket(AF_INET,SOCK_STREAM,IPPROTO_IP,NULL,0,1))  
	// �����׽���  
	// SOCKET socket(int af, int type, int protocol);  
    // ��һ��������ָ����ַ��(TCP/IPֻ����AF_INET��Ҳ��д��PF_INET)  
    // �ڶ�����ѡ���׽��ֵ�����(��ʽ�׽���)�����������ض���ַ�������Э�飨0Ϊ�Զ���  
	sock = socket(AF_INET, SOCK_STREAM, 0);
	//  if (sock = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP)==INVALID_SOCKET)  
	//  {  
	//      cout << "�����׽���ʧ�ܣ�\n\n";  
	//      return 1;  
	//      }  

	inet_pton(AF_INET, DES_IP, (void *)&s);
	ser_addr.sin_addr.S_un.S_addr = s.S_un.S_addr;		///��������IP��ַ
	//ser_addr.sin_addr.S_un.S_addr = inet_addr(DES_IP);
	ser_addr.sin_port = htons(DES_PORT);   // ��DES_PORTת��Ϊ�����ֽ��򣬵��� htonl(long��)��htons(����)  
	ser_addr.sin_family = AF_INET;
	memset(ser_addr.sin_zero, 0, 8);
	//����  
	if (connect(sock, (SOCKADDR *)&ser_addr, sizeof(SOCKADDR_IN)) != 0)
	{
		int nError = WSAGetLastError();
		cout << "���ӷ�������ʧ��\n";
		return 1;
	}
	else
	{
		cout << "�ɹ����ӷ����������Կ�ʼ�������ݣ�����\"exit\"ʱ�Ͽ�����\n\n";
	}
	//��������  
	do
	{
		int SentBytes;
		int RecvBytes;
		char strRecv[1024] = { 0 };
		cout << "���ͣ�";
		cin >> buf;
		if (strcmp(buf, "exit") == 0) break;
		SentBytes = send(sock, buf, strlen(buf), 0);
		if (SentBytes == SOCKET_ERROR)   ///����ʧ��  
		{
			cout<< "��������ʧ�ܣ�\n\n";
			break;
		}
		//      else //���ͳɹ�  
		//      {  
		//          cout << buf <<endl;  
		//      }  
		if ((RecvBytes = recv(sock, strRecv, sizeof(strRecv), 0)) != SOCKET_ERROR)
		{
			strRecv[RecvBytes] = 0;
			cout << "���գ� " << strRecv << endl;
		}
		else
		{
			cout << WSAGetLastError() << endl;
			cout << "��������ʧ�ܣ�\n";
		}
		Sleep(1000);
	} while (1);
	closesocket(sock);
	WSACleanup();

	getchar();
	return 0;
}



