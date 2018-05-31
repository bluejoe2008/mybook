// MessageMock.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "conio.h"
#include <iostream>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define MSG_KEY		0x1224
#define MSG_CHAR	0x1225
#define MSG_QUIT	0x0001
#define MSG_CLOSE	0x0002

//������Ϣ
struct _MSG
{
	int Message;
	int Parameter;
};

//��Ϣ����
CList<_MSG> _MsgQueue;

//��Ϣ������
typedef void (*MessageProc)(int Message, int Parameter);
MessageProc _MessageHandler;

//������Ϣ
void _PostMessage(int Message, int Parameter)
{
	_MSG NewMsg;
	NewMsg.Message = Message;
	NewMsg.Parameter = Parameter;

	_MsgQueue.AddTail(NewMsg);
}

//��ȡ��Ϣ�����е�����Ϣ
bool _GetMessage(_MSG * pMsg)
{
	while(_MsgQueue.IsEmpty());

	_MSG LastMsg = _MsgQueue.RemoveHead();
	*pMsg = LastMsg;

	if(pMsg->Message == MSG_QUIT)
		return false;		

	return true;
}

//ת����Ϣ
void _TranslateMessage(_MSG * pMsg)
{
	//x��Ϊϵͳ��
	if(pMsg->Message == MSG_KEY && pMsg->Parameter == 'x')
	{
		pMsg->Message = MSG_CLOSE;
		return;
	}

	//��������Ϣת�����ַ���Ϣ
	if(pMsg->Message == MSG_KEY)
	{
		pMsg->Message = MSG_CHAR;
	}
}

//�ַ���Ϣ
void _DispatchMessage(_MSG * pMsg)
{
	(*_MessageHandler)(pMsg->Message, pMsg->Parameter);
}

//��Ϣ��ѭ���������ȡ��Ϣ-->�ַ���Ϣ
void MessageLoop(MessageProc handler)
{
	_MessageHandler = handler;

	_MSG msg;
	while(_GetMessage(&msg))
	{
		_TranslateMessage(&msg);
		_DispatchMessage(&msg);
	}
}

//��MSG_CHAR����Ӧ
void OnChar(int charInput)
{
	if(charInput == 'q')
		_PostMessage(MSG_QUIT, 0);

	cout << "you typed " << (char)charInput << endl;
}

//��MSG_CLOSE����Ӧ
void OnClose(int charInput)
{
	_PostMessage(MSG_QUIT, 0);
}

void MyMessageProc(int Message, int Parameter)
{
	switch(Message)
	{
		case MSG_CHAR:
			OnChar(Parameter);
			break;

		case MSG_CLOSE:
			OnClose(Parameter);
			break;
	}
}

//��Ϣ������
UINT GatherMessages(LPVOID pParam)
{
	while(*((bool *)pParam))
	{
		if(_kbhit())
		{
			int ch = _getch();
			_PostMessage(MSG_KEY, ch);
		}
	}

	return 0;
}

int main(void)
{
	bool flag = true;

	//����Ϣ������
	AfxBeginThread(GatherMessages, &flag);
	//��ʼ��Ϣ����ѭ��
	MessageLoop(MyMessageProc);

	flag = false;

	AfxEndThread(0);
	return 0;
}