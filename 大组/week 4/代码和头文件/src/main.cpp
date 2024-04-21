#include <iostream>

#include "binary_sort_tree.h"

using namespace std;

int main()
{
	int choice = 0;
	int data = 0;
	char a[100]{ 0 };
	BinarySortTreePtr tree = new BinarySortTree;
	while (true)
	{
		cout << "1:init   2:insert    3:delete    4:search\n5:preorder   6:inorder    7:postorder 8:postorder" << endl;
		choice = getchar();
		switch (choice)
		{
		case '1':
			if (BST_init(tree))
			{
				cout << "SUCCESS" << endl;
			}
			else
			{
				cout << "ERROR" << endl;
			}
			break;
		case '2':
			cout << "enter your data" << endl;
			cin >> data;
			if (BST_insert(tree, data))
			{
				cout << "SUCCESS" << endl;
			}
			else
			{
				cout << "ERROR" << endl;
			}
			break;
		case '3':
			cout << "enter your data" << endl;
			cin >> data;
			if (BST_delete(tree, data))
			{
				cout << "SUCCESS" << endl;
			}
			else
			{
				cout << "ERROR" << endl;
			}
			break;
		case '4':
			cout << "enter your data" << endl;
			cin >> data;
			if (BST_search(tree, data))
			{
				cout << "SUCCESS" << endl;
			}
			else
			{
				cout << "ERROR" << endl;
			}
			break;
		case '5':
			BST_preorderI(tree);
			break;
		case '6':
			BST_inorderI(tree);
			break;
		case '7':
			BST_postorderI(tree);
			break;
		case '8':
			BST_levelOrder(tree);
			break;
		default:
			cout << "Pls input correct order!!!" << endl;
			break;
		}
		cout << "Press ENTER to continue" << endl;
		cin.getline(a, 100);
		cin.getline(a, 100);
		system("cls");
	}
	return 0;
}