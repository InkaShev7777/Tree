#include <iostream>
using namespace std;
struct Node
{
	int value;
	Node* left;
	Node* right;
};
Node* head = NULL;
void Add(int value,Node** tmp)
{
	if ((*tmp) == NULL)
	{
		(*tmp) = new Node;
		(*tmp)->value = value;
		(*tmp)->left = (*tmp)->right = NULL;
		return;
	}
	if (value > (*tmp)->value)
	{
		Add(value, &(*tmp)->right);
	}
	else
	{
		Add(value, &(*tmp)->left);
	}

}
void Print(Node* iter, int n)
{
	if (iter == NULL)
	{
		return;
	}
	else
	{
		Print(iter->left, ++n);
		for (int i = 0;i < n;++i)
		{
			cout << "  ";
		}
		cout << iter->value << "\n";
		n--;
	}
	Print(iter->right, ++n);
}
void Dell(Node* iter, int value)
{
	Node* tmp = NULL;
	if (iter->value == value)
	{
		cout << "UDalili koren!!\n";
		head = NULL;
		return;

	}
	if (iter == NULL)
	{
		return;
	}
	else
	{
		
		if (value > iter->value)
		{
			if (iter->right->value == value)
			{
				if (iter->right->right != NULL)
				{
					iter->right->right->left = iter->right->left;
					iter->right = iter->right->right;
					return;
				}
				else if (iter->right->left != NULL)
				{
					iter->right = iter->right->left;
				}
				else
				{
					iter->right = iter->right->left = iter->right->right;
				}
			}
			else if (iter->right->left->value == value)
			{
				iter->right->left = iter->right->left->right;
			}
			else
			{
				Dell(iter->right, value);
			}
			
		}
		else
		{
			if (iter->left->value == value)
			{
				if (iter->left->right != NULL)
				{
					iter->left->right->left = iter->left->left;
					iter->left = iter->left->right;
					return;
				}
				else if (iter->left->left != NULL)
				{
					iter->left = iter->left->right = iter->left->left;
				}
				else
				{
					iter->left = iter->left->left;
				}
			}
			else if(iter->left->right->value == value)
			{
				iter->left->right = iter->left->right->right;
			}
			else
			{
				Dell(iter->left, value);
			}
		}
		/*if (value > iter->value)
		{
			if (iter->right->value == value)
			{
				iter->right = iter->right->right;
			}
			else if (iter->right->left->value == value)
			{
				iter->left = iter->left->left;
			}
			else
			{
				Dell(iter->right, value);
				return;
			}
		}
		else
		{
			if (iter->left->value == value)
			{
				if (iter->left->left != NULL)
				{
					iter->left = iter->left->left;
				}
				else
				{
					iter->left = iter->left->right;
				}
				
			}
			else
			{
				Dell(iter->left, value);
				return;
			}
			
		}*/
	}
	//delete tmp;
}
int main()
{
	Add(44, &head);
	Add(29, &head);
	Add(30, &head);
	Add(62, &head);
	Add(60, &head);
	Add(70, &head);
	Add(21, &head);
	Add(31, &head);
	//Add(30, &head);
	/*Add(67, &head);
	Add(60, &head);*/

	//Add(4, &head);
	//Add(7, &head);
	Print(head, 0);
	int vibor;
	cout << "Vvedite: ";
	cin >> vibor;
	Dell(head, vibor);
	cout << "\n\n";
	Print(head, 0);
}

