// My_client.cpp : �������̨Ӧ�ó������ڵ㡣
//ʵ�ֿͻ���

#include "stdafx.h"
#include<iostream>
#include<WINSOCK2.H>
#include<cstring>
#include<WS2tcpip.h>
#pragma comment(lib,"WS2_32.lib")
using namespace std;

#define DES_IP "127.0.0.1"
#define DES_PORT 5000


int _tmain(int argc, _TCHAR* argv[])
{
	SOCKET sock;
	char buf[1024];     ///���͵��ַ���
	char Ser_IP[100];
	char Ser_PORT[50];
	cout<<"�����������IP��ַ\n";
	cin>>Ser_IP;
	cout<<"����������Ķ˿ں�\n";
	cin>>Ser_PORT;
	getchar();
	SOCKADDR_IN ser_addr;   ///�������˵�ַ
	WSADATA wsaData;		///�ýṹ�����ڽ���Windows Socket �Ľṹ��Ϣ��
	struct in_addr s;
	WORD wVersionRequired;   // ����socket��̬���ӿ�(dll)
	wVersionRequired=MAKEWORD(2,2);     // ����2.2�汾��WinSock��
	if(WSAStartup(wVersionRequired, &wsaData)!=0)     // ����ֵΪ���ʱ���Ǳ�ʾ�ɹ�����WSAStartup
	{
	   cout<<WSAGetLastError()<<endl;
	   cout<<"��ʼ��ʧ��!\n";
	}
	///�����׽���
	sock=socket(AF_INET,SOCK_STREAM,0);

	inet_pton(AF_INET,DES_IP,(void *)&s);   //IP��ַת�������������ڽ�IP��ַ�ڡ����ʮ���ơ��͡�������������֮��ת��
	ser_addr.sin_addr.S_un.S_addr=s.S_un.S_addr;    //��������IP��ַ
	ser_addr.sin_port=htons(DES_PORT);   // ��DES_PORTת��Ϊ�����ֽ��򣬵��� htonl(long��)��htons(����)  
	ser_addr.sin_family=AF_INET;
	memset(ser_addr.sin_zero,0,8);
	//���Ӻ���
	if(connect(sock,(SOCKADDR *)&ser_addr,sizeof(SOCKADDR_IN))!=0)
	{
	    int nError=WSAGetLastError();
		cout<<"���ӷ�������ʧ��!\n";
		return 1;
	}
	else
	{
		cout<<"***************************************************************\n\n";
	  cout<<"���ӷ������ɹ������Է������ݣ����롰Q��ʱ�Ͽ���������ͻ��������ӣ�\n\n";
	  cout<<"***************************************************************\n\n";
	}
	while(1)
	{

	  int SentBytes;
	  int RecvBytes;
	 
	  char strRecv[1024]={0};
	  cout<<"���뽫Ҫ���͵����ݣ�\n";
	  cin>>buf;
	  if(strcmp(buf,"Q")==0)  break;
	  SentBytes=send(sock,buf,strlen(buf),0);
	  if(SentBytes==SOCKET_ERROR)
	  {
	     cout<<"����ʧ�ܣ������½������ӣ��ٴγ��ԣ�\n\n";
         break;
	  }
	  if((RecvBytes = recv(sock, strRecv, sizeof(strRecv), 0)) != SOCKET_ERROR)
		{
			strRecv[RecvBytes] = 0;
			cout << "���գ� " << strRecv << endl;
		}
	  else
	  {
	    cout<<WSAGetLastError()<<endl;
		cout<<"��������ʧ�ܣ������½������ӣ��ٴγ��ԣ�\n";

		break;
		Sleep(1000);
	  }
	}
	closesocket(sock);     ///�ر��׽��֣�����TCP�Ի���
	WSACleanup();
	getchar();
	return 0;
}

