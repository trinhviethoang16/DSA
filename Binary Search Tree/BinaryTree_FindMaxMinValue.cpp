#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *pRight;
    struct node *pLeft;
};
typedef node Node;
typedef Node* Tree;

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

int findMaxValue(Tree tree)
{
    if(tree->pRight == NULL)
    {
        return tree->data;
    }
    return findMaxValue(tree->pRight);
}

int findMinValue(Tree tree)
{
    if(tree->pLeft == NULL)
    {
        return tree->data;
    }
    return findMinValue(tree->pLeft);
}

void Menu(Tree &tree)
{
    int selection;
    while(true)
    {
        system("cls");
        cout << "\t\t===== MENU =====" << endl;
        cout << "\t1. Add node to binary tree" << endl;
        cout << "\t2. Show all elements by NLR" << endl;
        cout << "\t3. Max value" << endl;
        cout << "\t4. Min value" << endl;
        cout << "\t0. Exit" << endl;
        cout << "\t\t=====  END  =====" << endl;
        
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
            cout << "Enter new node value: ";
            cin >> value;
            addNodeToTree(tree, value);
        }
        else if(selection == 2)
        {
            NLR(tree);
            system("pause");
        }
        else if(selection == 3)
        {
            if(tree == NULL)
            {
                cout << "\nThere are no elements in binary tree\n" << endl;
                system("pause");
                break;
            }
            cout << "\nMax value in binary tree is " << findMaxValue(tree) << endl;
            system("pause");
        }
        else if(selection == 4)
        {
            if(tree == NULL)
            {
                cout << "\nThere are no elements in binary tree\n" << endl;
                system("pause");
                break;
            }
            cout << "\nMin value in binary tree is " << findMinValue(tree) << endl;
            system("pause");
        }
        else
        {
            cout << "\nNo selection matching. Please try again !\n" << endl;
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