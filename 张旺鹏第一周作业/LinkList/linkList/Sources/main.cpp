#include <iostream>
#include <graphics.h>
#include <Windows.h>
#include "linkedlist.h"
#include "screen.h"

using namespace std;
int main1()//ȫ����������
{
	linkedlist a;
	a.run();
	a.~linkedlist();
	return 0;
}
//ͼ�λ���������
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	initgraph(1200, 750);
	screen a;
	a.run();
	while (1) {}
	
	return 0;
}