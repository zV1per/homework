#include "binary_sort_tree.h"
#include <stdio.h>
#include <stack>
#include <queue>
#include <iostream>

bool isinit;

Status BST_init(BinarySortTreePtr tree)
{
	if (isinit)
	{
		return Status(0);
	}
	tree->root = nullptr;
	tree->nodenum = 0; 
	isinit = 1;
	return Status(1);
}

Status BST_insert(BinarySortTreePtr tree, ElemType value)
{
	if (!isinit)
	{
		return Status(0);
	}
	Node *toadd = new Node;
	toadd->left = nullptr;
	toadd->right = nullptr;
	toadd->value = value;
	if (!tree->nodenum)
	{
		tree->root = toadd;
		tree->nodenum++;
		return Status(1);
	}
	Node* current=tree->root;
	while (1)
	{
		if (value > current->value)
		{
			if (current->right==nullptr)
			{
				break;
			}
			current = current->right;
		}
		else if (value < current->value)
		{
			if (current->left == nullptr)
			{
				break;
			}
			current = current->left;
		}
		else
		{
			return Status(0);
		}
	}
	if (value > current->value)
	{

		current->right = toadd;
	}
	if (value < current->value)
	{
		current->left = toadd;
	}
	tree->nodenum++;
	return Status(1);
}

Status BST_delete(BinarySortTreePtr tree, ElemType value)
{	
	if (!isinit)
	{
		return Status(0);
	}
	if (!tree->nodenum)
	{
		return Status(0);
	}
	if (value == tree->root->value)
	{
		delete tree->root;
		tree->root = nullptr;
		tree->nodenum = 0;
		return Status(1);
	}
	Node* current = tree->root;
	Node* last = tree->root;
	while (1)
	{
		if (value > current->value)
		{
			if (current->right == nullptr)
			{
				break;
			}
			last = current;
			current = current->right;
		}
		else if (value < current->value)
		{
			if (current->left == nullptr)
			{
				break;
			}
			last = current;
			current = current->left;
		}
		else
		{
			if (current->right != nullptr)
			{
				Node* temp = current;
				current = current->right;
				while (current->left!=nullptr)
				{
					temp = current;
					current = current->left;
				}
				if (last->left != nullptr && last->left->value == value)
				{
					last->left->value = current->value;
				}
				if (last->right != nullptr && last->right->value == value)
				{
					last->right->value = current->value;
				}
				delete temp->left;
				temp->left = nullptr;
				tree->nodenum--;
			}
			else if (current->left != nullptr)
			{
				Node* temp = current;
				current = current->left;
				while (current->right != nullptr)
				{
					temp = current;
					current = current->right;
				}
				if (last->left != nullptr && last->left->value == value)
				{
					last->left->value = current->value;
				}
				if (last->right != nullptr && last->right->value == value)
				{
					last->right->value = current->value;
				}
				delete temp->right;
				temp->right = nullptr;
				tree->nodenum--;
			}
			else
			{
				if (last->left != nullptr && last->left->value == value)
				{
					delete last->left;
					last->left = nullptr;
					tree->nodenum--;
				}
				if (last->right != nullptr && last->right->value == value)
				{
					delete last->right;
					last->right = nullptr;
					tree->nodenum--;
				}
			}
			return Status(1);
		}
	}
	return Status(0);
}

Status BST_search(BinarySortTreePtr tree, ElemType value)
{
	if (!isinit)
	{
		return Status(0);
	}
	if (!tree->nodenum)
	{
		return Status(0);
	}
	Node* current = tree->root;
	while (1)
	{
		if (value > current->value)
		{
			if (current->right == nullptr)
			{
				break;
			}
			current = current->right;
		}
		else if (value < current->value)
		{
			if (current->left == nullptr)
			{
				break;
			}
			current = current->left;
		}
		else
		{
			return Status(1);
		}
	}
	return Status(0);
}

Status BST_preorderI(BinarySortTreePtr tree)
{
	if (!isinit)
	{
		return Status(0);
	}
	preorder(tree->root);
	return Status(1);
}

Status BST_preorderR(BinarySortTreePtr tree)
{
	if (tree == NULL)
		return Status(0);;
	Node * p = tree->root;
	std::stack<NodePtr>s;
	while (p != NULL || !s.empty())
	{
		while (p != NULL)
		{
			s.push(p);
			printf("%d ", p->value);
			p = p->left;
		}
		if (!s.empty())
		{
			p = s.top();
			s.pop();
			p = p->right;
		}
	}
	return Status(1);
}

Status BST_inorderI(BinarySortTreePtr tree)
{
	if (!isinit)
	{
		return Status(0);
	}
	inorder(tree->root);
	return Status(1);
}

Status BST_inorderR(BinarySortTreePtr tree)
{
	if (tree == NULL)
		return Status(0);;
	Node* p = tree->root;
	std::stack<NodePtr>s;

	while (p != NULL || !s.empty())
	{
		while (p != NULL)
		{
			s.push(p);
			
			p = p->left;
		}
		if (!s.empty())
		{
			p = s.top();
			printf("%d ", p->value);
			s.pop();
			p = p->right;
		}
	}
	return Status(1);
}

Status BST_postorderI(BinarySortTreePtr tree)
{
	if (!isinit)
	{
		return Status(0);
	}
	postorder(tree->root);
	return Status(1);
}

Status BST_postorderR(BinarySortTreePtr tree)
{

	if (tree == NULL)
		return Status(0);
	std::stack<NodePtr>s;
	NodePtr cur = tree->root, pre = NULL;
	s.push(tree->root);
	while (!s.empty())
	{
		cur = s.top();
		if ((cur->left == NULL && cur->right == NULL) ||
			((pre == cur->left || pre == cur->right) && pre != NULL))
		{
			printf("%d ", cur->value);
			s.pop();
			pre = cur;
		}
		else
		{
			if (cur->right != NULL)
				s.push(cur->right);
			if (cur->left != NULL)
				s.push(cur->left);
		}
	}
	return Status(1);
}

Status BST_levelOrder(BinarySortTreePtr tree)
{
	if (tree==nullptr||tree->root == nullptr) {
		return Status(0);
	}
	std::queue<Node*> q;
	q.push(tree->root);
	while (!q.empty()) {
		Node* node = q.front();
		q.pop();
		printf("%d ", node->value);
		if (node->left != nullptr) {
			q.push(node->left);
		}
		if (node->right != nullptr) {
			q.push(node->right);
		}
	}
	return  Status(1);
}

void preorder(Node *p)
{
	if (p == nullptr)return;
	printf("%d ", p->value);
	preorder(p->left);
	preorder(p->right);
}

void inorder(Node* p)
{
	if (p == nullptr)return;
	inorder(p->left);
	printf("%d ", p->value);
	inorder(p->right);
}

void postorder(Node* p)
{
	if (p == nullptr)return;
	postorder(p->left);
	postorder(p->right);
	printf("%d ", p->value);
}
