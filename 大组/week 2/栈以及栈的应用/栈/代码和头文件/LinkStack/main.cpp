#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "LinkStack.h" 

using namespace std;

int main(void)
{
	LinkStack *a= (LinkStack * )malloc(sizeof(LinkStack));
	int data;
	char w[101] = { 0 };
	while (1)
	{

		cout <<
			"-------------------------------------------------------------------\n"
			"|  a:init        b:isEmpty       c:getTopdata      d:clearStack   |\n"
			"|  e:GetLength   f:pushStack     g:popStack        h:destroyStack |\n"
			"-------------------------------------------------------------------\n";
		for (int i = 0; i < 101; i++)
			{
				w[i] = 0;
			}

		cin.getline(w,100);
		if (w[1] != 0)
		{
			cout << "Invalid input" << endl;
			cout << "press to ENTER continue" << endl;
			cin.getline(w, 100);
			system("cls");
			continue;
		}
		switch (w[0])
		{
		case'a':
			if (initLStack(a)==SUCCESS)
			{
				cout << "OK!" << endl;
			}
			else
			{
				cout << "You have inited it!" << endl;
			}
			break;
		case'b':
			if (isEmptyLStack(a))
			{
				cout << "Not empty!" << endl;
			}
			else
			{
				cout << "Empty!" << endl;
			}
			break;
		case'c':
			if (getTopLStack(a, &data))
			{
				cout << "top's data is " << data << endl;
			}
			else
			{
				cout << "ERROR!" << endl;
			}
			break;
		case'd':
			if (clearLStack(a))
			{
				cout << "Cleared!" << endl;
			}
			else
			{
				cout << "It cant be cleared!" << endl;
			}
			break;
		case'e':
			if (LStackLength(a, &data))
			{
				cout << "length is " << data << endl;
			}
			else
			{
				cout << "ERROR!" << endl;
			}
			break;
		case'f':
			cout << "input your data" << endl;
			scanf_s("%d", &data);
			if (cin.get()!='\r')
			{
				cin.getline(w, 100);
				cout << "Invalid input!" << endl;
				break;
			}
			if (pushLStack(a, data))
			{
				cout << "Push ok!" << endl;
			}
			else
			{
				cout << "ERROR!" << endl;
				cout << "I think you should init it!" << endl;
			}
			cin.getline(w, 100);
			break;
		case'g':
			if (popLStack(a, &data))
			{
				cout << "Pushed data is " << data << endl;
			}
			else
			{
				cout << "ERROR!" << endl;
				cout << "I think it is empty!" << endl;
			}
			break;	
		case'h':
			cout << "BYE!" << endl;
			destroyLStack(a);
			break;
		default:
			cout << "Invalid input" << endl;
			break;
		}	
		cout << "press to ENTER continue" << endl;
		cin.getline(w,100);
		system("cls");
	}
	return 0;
}

