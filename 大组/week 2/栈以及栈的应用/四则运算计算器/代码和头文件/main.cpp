#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(void)
{
	stack<char> a;
	stack<int> b;
	string innn;
	string midd;
	char w[201]{ 0 }, num[101]{ 0 }; bool errorr = 0,state=0,state1=1,state2=0,state3=0;
	while (true)
	{
		while (!a.empty())
		{
			a.pop();
		}
		midd = { 0 };
		innn = { 0 };
		memset(w, 0, sizeof(w)); 
		memset(num, 0, sizeof(num));
		errorr = 0, state = 0, state1 = 1, state2 = 0, state3 = 0;
		cout << "Pls input your formula:(space and '=' is not allowed)" << endl;
		cin.getline(w, 200);
		/*if (w[0]=='\n')
		{
			cout << "pls enter a formula!" << endl;
			cout << "press to ENTER continue" << endl;
			cin.getline(w, 100);
			system("cls");continue;
		}*/
		innn += w;
		for (int i = 0; i < innn.length(); i++)
		{
			if (innn[i] >= '0' && innn[i] <= '9')
			{
				midd += innn[i];
				state = 1;
				state1 = 0;
				//sprintf_s(num, "%d", atoi(&innn[i]));
				//midd += num;
				//memset(num, 0, sizeof(num));
			}
			else if (innn[i] == '*' || innn[i] == '/')
			{
				if (state)
				{
					state = 0;
					midd += ' ';
				}
				if (state1)
				{
					errorr = 1;
					break;
				}
				state1 = 1;
				a.push(innn[i]);
			}
			else if (innn[i] == '(')
			{
				if (state)
				{
					state = 0;
					midd += ' ';
				}
				a.push(innn[i]);
			}
			else if (innn[i] == '+' || innn[i] == '-')
			{
				if (state)
				{
					state = 0;
					midd += ' ';
				}
				if (state1)
				{
					errorr = 1;
					break;
				}
				state1 = 1;
				if (a.empty()) a.push(innn[i]);
				else if (a.top() == '*' || a.top() == '/')
				{
					while (a.top() != '(')
					{
						midd += a.top();
						a.pop(); if (a.empty()) break;
					}
					a.push(innn[i]);
				}
				else
				{
					if (a.top() == '+' || a.top() == '-')
					{
						midd += a.top();
						a.pop();
					}
					a.push(innn[i]);
				}
			}
			else if (innn[i] == ')')
			{
				if (state)
				{
					state = 0;
					midd += ' ';
				}
				while (!a.empty())
				{
					if (a.top()=='(')
					{
						a.pop();
						state2 = 1;
						break;
					}
					midd += a.top();
					a.pop();
				}
				if (!state2)
				{
					errorr = 1;
				}
			}
			else if (innn[i] == ' ' || innn[i] == '\r' || innn[i] == '\n' || innn[i] == 0)
			{
			}
			else
			{
				errorr = 1;
			}
		}
		while (!a.empty())
		{
			if (a.top() != '+' && a.top() != '-' && a.top() != '*' && a.top() != '/')
			{
				errorr = 1;
				break;
			}
			midd += a.top();
			a.pop();
		}
		if (errorr)
		{
			//cin.getline(w, 100);
			cout << "Wrong Formula" << endl;
			cout << "press to ENTER continue" << endl;
			cin.getline(w, 100);
			system("cls");
			continue;
		}
		//cout << midd << endl;
		for (int i = 0; i < midd.length(); i++)
		{
			if (state3)
			{
				if (midd[i] >= '0' && midd[i] <= '9')
				{
					continue;
				}
				state3 = 0;
			}
			if (midd[i] >= '0' && midd[i] <= '9')
			{
				state3 = 1;
				b.push(atoi(&midd[i]));
			}
			else
			{
				int a1{ 0 }, a2{ 0 };
				switch (midd[i])
				{
				case'+':
					if (b.empty())
					{
						break;
					}

					a1 = b.top();
					b.pop();
					if (b.empty())
					{
						break;
					}

					a2 = b.top();
					b.pop();
					b.push(a1 + a2);
					break;
				case'-':
					if (b.empty())
					{
						break;
					}
					a1 = b.top();
					b.pop();
					if (b.empty())
					{
						break;
					}
					a2 = b.top();
					b.pop();
					b.push(a2 - a1);
					break;
				case'*':
					if (b.empty())
					{
						break;
					}
					a1 = b.top();
					b.pop();
					if (b.empty())
					{
						break;
					}
					a2 = b.top();
					b.pop();
					b.push(a2 * a1);
					break;
				case'/':
					if (b.empty())
					{
						break;
					}
					a1 = b.top();
					b.pop();
					if (b.empty())
					{
						break;
					}
					a2 = b.top();
					b.pop();
					b.push(a2 / a1);
					break;
				default:
					break;
				}
			}
		}
		if (!b.empty())
		{
			cout << b.top() << endl;
			b.pop();
		}
		else
		{
			cout << "Invalid formula!" << endl;
		}
		cout << "press to ENTER continue" << endl;
		cin.getline(w, 100);
		system("cls");
	}
	return 0;
}
