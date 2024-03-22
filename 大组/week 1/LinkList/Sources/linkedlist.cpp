#include "linkedlist.h"
#include <iostream>
using namespace std;

bool linkedlist::Isempty(void)
{
	if (head==nullptr)
	{
		return true;
	}
	return false;
}

bool linkedlist::Clearlist(void)
{
	PIONT* current = head;
	PIONT* previous ;
	for (int i = 0; i < length-1; i++)
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

int linkedlist::Getdata(int num)
{
	if (num>length||num<=0)
	{
		cout << "error" << endl;
		return 0;
	}
	PIONT* current = head;
	for (int i = 0; i < num-1; i++)
	{
		current = current->next;
	
	}
	return current->data;
}

int linkedlist::Searchdata(int num)
{
	if (length==0)
	{
		cout << "empty" << endl;
		return 0;
	}
	int last=0;
	PIONT* current = head;
	int i;
	for (i = 0; i < length-1; i++)
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

bool linkedlist::Addpiont(int data, int num)
{
	if (num>length||num<0)
	{
		return false;
	}
	PIONT* a = new(PIONT);
	a->data = data;
	a->next = nullptr;
	if (num==0)
	{
		a->next = head;
		head = a;
	}
	else
	{
		PIONT* current = head;
		for (int i = 0; i < num-1; i++)
		{
			current = current->next;
		}
		a->next = current->next;
		current->next = a;
	}
	length++;
	return true;
}

bool linkedlist::Deletepiont(int num)
{
	if (num > length || num <= 0)
	{
		return false;
	}
	PIONT* current = head;
	PIONT* todelete;
	if (1==num)
	{
		todelete = current;
		head = current->next;
		delete todelete;
	}
	else
	{
		for (int i = 0; i < num-2; i++)
		{
			current = current->next;
		}
		if (current->next->next ==nullptr)
		{
			delete current->next;
			current->next = nullptr;
		}
		else
		{
			todelete = current->next;
			current->next = current->next->next;
			delete todelete;
		}
	}
	length--;
	return true;
}

void linkedlist::Traverselist(void)
{
	if (head==nullptr)
	{
		cout << "empty!" << endl;
		return;
	}
	PIONT* current = head;
	cout << "#" << 1 << ":" << current->data << endl;
	for (int i = 1; i < length; i++)
	{
		current = current->next;
		cout << "#" << i+1 << ":" << current->data << endl;
	}
	return;
}

int linkedlist::Getlength(void) const
{
	return length;
}

int linkedlist::Getmidpiont(void)
{
	if (head==nullptr)
	{
		return 0;
	}
	if (length%2==1)
	{
		return length / 2 + 1;
	}
	return length / 2;
}

bool linkedlist::Iscircle(void)
{
	if (head==nullptr||head->next==nullptr||head->next->next==nullptr)
	{
		return false;
	}
	PIONT *slow = head, *fast = head;
	fast = fast->next; fast = fast->next;
	slow = slow->next;
	while (slow!=fast)
	{
		if (fast == nullptr||fast->next == nullptr || head->next->next == nullptr)
		{
			return false;
		}
		fast = fast->next; fast = fast->next;
		slow = slow->next;
	}
	return true;
}

bool linkedlist::Invert(void)
{
	if (head==nullptr)
	{
		return false;
	}
	PIONT* a = head;
	PIONT* p1, * p2;
	if ((a != nullptr) && (a->next != nullptr)) {
		p1 = head;
		p2 = head->next->next;
		head = head->next;
		head->next = p1;
		head->next->next = p2;
		a = p1;
		while ((a->next != nullptr) && (a->next->next != nullptr))
		{
			p1 = a->next;
			p2 = a->next->next->next;
			a->next = a->next->next;
			a->next->next = p1;
			a->next->next->next = p2;
			a = a->next->next;
		}
	}
	return true;
}

bool linkedlist::Upsidedown(void)
{
	if (head==nullptr)
	{
		return false;
	}
	if (head->next==nullptr)
	{
		return true;
	}
	
	PIONT* i = head->next, * pre = head;
	PIONT* nex = head->next->next;
	while (i->next != nullptr)
	{
		nex = i->next;
		i->next = pre;
		pre = i;
		i = nex;
	}
	i->next = pre;
	head->next = nullptr;
	head = i;
	return true;
}

void linkedlist::Upsidedown_Recursion(PIONT* ptr)
{
	if (ptr->next==nullptr)
	{
		head->next=nullptr;
		head = ptr;
		return;
	}
	PIONT* nx = ptr->next;
	Upsidedown_Recursion(nx);
	nx->next = ptr;
}

void linkedlist::run(void)
{
	int choice;
	int num, data;
	cout << "1 to add   ""2 to delete   ""3 to Isempty   ""4 to clear\n""5 to search   "
		"6 to getdata   ""7 to getlength   ""8 to traverse\n""9 to getmid   "
		"10 to Iscircle   ""11 to Inverse   ""12 to µÝ¹é   "
		"13 to ·ÇµÝ¹é   \n""0 callhelp" << endl;
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
			if (Getmidpiont())
			{
				cout << Getmidpiont()<<endl;
			}
			else
			{
				cout << "Empty" << endl;
			}
			break;
		case 10:
			if (Iscircle())
			{
				cout << "IScircle" << endl;
			}
			else
			{
				cout << "ISNTcircle" << endl;
			}
			break;
		case 11:
			if (Invert())
			{
				cout << "Success" << endl;
			}
			else
			{
				cout << "Error" << endl;
			}
			break;
		case 12:
			Upsidedown_Recursion(head);
			cout << "Success!" << endl;
			break;
		case 13:
			Upsidedown();
			cout << "Success!" << endl;
			break;
		default:
			cout << "1 to add   ""2 to delete   ""3 to Isempty   ""4 to clear\n""5 to search   "
				"6 to getdata   ""7 to getlength   ""8 to traverse\n""9 to getmid   "
				"10 to Iscircle   ""11 to Inverse   ""12 to µÝ¹é   "
				"13 to ·ÇµÝ¹é   \n""0 callhelp" << endl;
			break;
		}
	}
}