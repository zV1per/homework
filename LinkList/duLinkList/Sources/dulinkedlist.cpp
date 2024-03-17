#include "dulinkedlist.h"
#include <iostream>
using namespace std;

bool dulinkedlist::Isempty(void)
{
	if (head == nullptr)
	{
		return true;
	}
	return false;
}

bool dulinkedlist::Clearlist(void)
{
	PIONT* current = head;
	PIONT* previous;
	for (int i = 0; i < length - 1; i++)
	{
		previous = current;
		current = current->next;
		delete previous;
	}
	delete current;
	head = nullptr;
	length = 0;
	return 1;
}

int dulinkedlist::Getdata(int num)
{
	if (num > length || num <= 0)
	{
		cout << "error" << endl;
		return 0;
	}
	PIONT* current = head;
	for (int i = 0; i < num - 1; i++)
	{
		current = current->next;

	}
	return current->data;
}

int dulinkedlist::Searchdata(int num)
{
	if (length == 0)
	{
		cout << "empty" << endl;
		return 0;
	}
	int last = 0;
	PIONT* current = head;
	int i;
	for (i = 0; i < length - 1; i++)
	{
		if (current->data == num)
		{
			cout << i + 1 << ' ' << endl;
			last = i + 1;
		}
		current = current->next;
	}
	if (current->data == num)
	{
		cout << i + 1 << ' ' << endl;
		last = i + 1;
	}
	return last;
}

bool dulinkedlist::Addpiont(int data, int num)
{
	if (num > length || num < 0)
	{
		return false;
	}
	PIONT* a = new(PIONT);
	a->data = data;
	a->next = nullptr;
	if (num == 0)
	{
		a->next = head;
		head = a;
	}
	else
	{
		PIONT* current = head;
		PIONT* previous = head;
		for (int i = 0; i < num - 1; i++)
		{
			previous = current;
			current = current->next;
		}
		a->prev = previous;
		a->next = current->next;
		current->next = a;
	}
	length++;
	return true;
}

bool dulinkedlist::Deletepiont(int num)
{
	if (num > length || num <= 0)
	{
		return false;
	}
	PIONT* current = head;
	PIONT* previous = head;
	PIONT* todelete;
	if (1 == num)
	{
		todelete = current;
		head = current->next;
		current->prev = head;
		delete todelete;
	}
	else
	{
		for (int i = 0; i < num - 2; i++)
		{
			current = current->next;
		}
		if (current->next->next == nullptr)
		{
			delete current->next;
			current->next = nullptr;
		}
		else
		{
			todelete = current->next;
			current->next = current->next->next;
			current->next->prev = todelete->prev;
			delete todelete;
		}
	}
	length--;
	return true;
}

void dulinkedlist::Traverselist(void)
{
	if (head == nullptr)
	{
		cout << "empty!" << endl;
		return;
	}
	PIONT* current = head;
	cout << "#" << 1 << ":" << current->data << endl;
	for (int i = 1; i < length; i++)
	{
		current = current->next;
		cout << "#" << i + 1 << ":" << current->data << endl;
	}
	return;
}

int dulinkedlist::Getlength(void) const
{
	return length;
}

void dulinkedlist::run(void)
{
	int choice;
	int num, data;
	cout << "1 to add   ""2 to delete   ""3 to Isempty   ""4 to clear\n""5 to search   "
		"6 to getdata   ""7 to getlength   ""8 to traverse\n""9 to quit" << endl;
	while (1)
	{
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "num: data:" << endl;
			cin >> num >> data;
			if (Addpiont(data, num))
			{
				cout << "Success!";
			}
			else
			{
				cout << "ERROR!";
			}
			break;
		case 2:
			cout << "num: " << endl;
			cin >> num;
			if (Deletepiont(num))
			{
				cout << "Success!";
			}
			else
			{
				cout << "ERROR!";
			}
			break;
		case 3:
			if (Isempty())
			{
				cout << "Empty!";
			}
			else
			{
				cout << "Not empty!";
			}
			break;
		case 4:
			if (Clearlist())
			{
				cout << "Success!";
			}
			else
			{
				cout << "ERROR!";
			}
			break;
		case 5:
			cout << "data: " << endl;
			cin >> data;
			if (Searchdata(data))
			{
				cout << "Finished!";
			}
			else
			{
				cout << "Notexist!";
			}
			break;
		case 6:
			cout << "num: " << endl;
			cin >> num;
			cout << Getdata(num) << endl;
			cout << "Finished!";
			break;
		case 7:
			cout << Getlength() << endl;
			cout << "Success!" << endl;
			break;
		case 8:
			Traverselist();
			cout << "Success!" << endl;
			break;
		case 9:

			return;
		default:
			cout << "1 to add   ""2 to delete   ""3 to Isempty   ""4 to clear\n""5 to search   "
				"6 to getdata   ""7 to getlength   ""8 to traverse\n""9 to quit   ""0 callhelp" << endl;
			break;
		}
	}
}
