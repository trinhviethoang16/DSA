#include<iostream>
using namespace std;

//Integer data
struct node
{
    int data;
    struct node *pLeft;
    struct node *pRight;
};
typedef node Node;
typedef node* Tree;

void initializeTree(Tree &tree)
{
    tree = NULL;
}

void addNodeToTree(Tree &tree, int value)
{
    if(tree == NULL)
    {
        Node *p = new Node;
        p->data = value;
        p->pLeft = NULL;
        p->pRight = NULL;
        tree = p;
    }
    else
    {
        if(value > tree->data)
        {
            addNodeToTree(tree->pRight, value);
        }
        else if(value < tree->data)
        {
            addNodeToTree(tree->pLeft, value);
        }
        else
        {
            cout << "\nCannot add an existing value in the binary tree ! " << endl;
            system("pause");
        }
    }
}

void NLR(Tree tree)
{
    if(tree != NULL)
    {
        cout << tree->data << " ";
        NLR(tree->pLeft);
        NLR(tree->pRight);
    }
}

void NRL(Tree tree)
{
    if(tree != NULL)
    {
        cout << tree->data << " ";
        NRL(tree->pRight);
        NRL(tree->pLeft);
    }
}

void LRN(Tree tree)
{
    if(tree != NULL)
    {
        LRN(tree->pLeft);
        LRN(tree->pRight);
        cout << tree->data << " ";
    }
}

void LNR(Tree tree)
{
    if(tree != NULL)
    {
        LNR(tree->pLeft);
        cout << tree->data << " ";
        LNR(tree->pRight);
    }
}

void RLN(Tree tree)
{
    if(tree != NULL)
    {
        RLN(tree->pRight);
        RLN(tree->pLeft);
        cout << tree->data << " ";
    }
}

void RNL(Tree tree)
{
    if(tree != NULL)
    {
        RNL(tree->pRight);
        cout << tree->data << " ";
        RNL(tree->pLeft);
    }
}

bool checkPrimes(int value)
{
	if (value<2)
	{
		return false;
	}
	else
	{
		if (value==2)
		{
			return true;
		}
		else
		{
			if (value%2==0)
			{
				return false;
			}
			else
			{
				for (int i=2; i<value; i++)
				{
					if (value%i==0)
					{
						return false;
					}
				}
			}
		}
	}
	return true;
}

void countingPrimesInTree(Tree tree, int &countNumber)
{
    if(tree != NULL)
    {
        if(checkPrimes(tree->data) == true)
        {
            countNumber++;
        }
        countingPrimesInTree(tree->pRight, countNumber);
        countingPrimesInTree(tree->pLeft, countNumber);
    }
}

void Menu(Tree &tree)
{
    int selection;
    while(true)
    {
        system("cls");
        cout << "\t===== MENU =====" << endl;
        cout << "1. Add new value to binary tree" << endl;
        cout << "2. Show NLR" << endl;
        cout << "3. Show NRL" << endl;
        cout << "4. Show LRN" << endl;
        cout << "5. Show LNR" << endl;
        cout << "6. Show RLN" << endl;
        cout << "7. Show RNL" << endl;
        cout << "8. Counting primes number in binary tree" << endl;
        cout << "0. Exit" << endl;
        cout << "\t=====  END  =====" << endl;

        cout << "\n\nYour selection: ";
        cin >> selection;

        if(selection == 0)
        {
            cout << "\tSee ya" << endl;
            return;
        }
        else if(selection == 1)
        {
            int value;
            cout << "Enter new value: ";
            cin >> value;
            addNodeToTree(tree, value);
        }
        else if(selection == 2)
        {
            cout << "\nAll elements by NLR: ";
            NLR(tree);
            system("pause");
        }
        else if(selection == 3)
        {
            cout << "\nAll elements by NRL: ";
            NRL(tree);
            system("pause");
        }
        else if(selection == 4)
        {
            cout << "\nAll elements by LRN: ";
            LRN(tree);
            system("pause");
        }
        else if(selection == 5)
        {
            cout << "\nAll elements by LNR: ";
            LNR(tree);
            system("pause");
        }
        else if(selection == 6)
        {
            cout << "\nAll elements by RLN: ";
            RLN(tree);
            system("pause");
        }
        else if(selection == 7)
        {
            cout << "\nAll elements by RNL: ";
            RNL(tree);
            system("pause");
        }
        else if(selection == 8)
        {
            int count = 0;
            countingPrimesInTree(tree, count);
            cout << "\nNumber of primes: " << count << endl;
            system("pause");
        }
        else
        {
            cout << "\nNo matching selection. Pleasy try again !\n" << endl;
            system("pause");
        }
    }
}

int main()
{
    Tree tree;
    initializeTree(tree);
    Menu(tree);
    return 0;
}