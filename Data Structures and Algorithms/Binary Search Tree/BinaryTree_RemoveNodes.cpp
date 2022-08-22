#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *pLeft;
    struct node *pRight;
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
        else
        {
            cout << "\nCannot add an existing value in the binary tree ! " << endl;
            system("pause");
        }
    }
}

void findNode(Tree &X, Tree &Y)
{
    if(Y->pLeft != NULL)
    {
        findNode(X, Y->pLeft);
    }
    else
    {
        X->data = Y->data;
        X = Y;
        Y = Y->pRight;
    }
}

void deleteNodeInTree(Tree &tree, int value)
{
    if(tree == NULL)
    {
        cout << "\nThere no elements in binary tree" << endl;
        return;
    }
    else
    {
        if(value > tree->data)
        {
            deleteNodeInTree(tree->pRight, value);
        }
        else if(value < tree->data)
        {
            deleteNodeInTree(tree->pLeft, value);
        }
        else
        {
            Node *X = tree;
            
            if(tree->pLeft == NULL)
            {
                tree = tree->pRight;
            }
            else if(tree->pRight == NULL)
            {
                tree = tree->pLeft;
            }
            else
            {
                findNode(X, tree->pRight);
            }
            delete X;
        }
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

void Menu(Tree &tree)
{
    int selection;
    while(true)
    {
        system("cls");
        cout << "\t\t===== MENU =====" << endl;
        cout << "\t1. Show all elements in binary tree" << endl;
        cout << "\t2. Add new node value to binary tree" << endl;
        cout << "\t3. Remove node in binary tree" << endl;
        cout << "\t0. Exit" << endl;
        cout << "\t\t=====  END  =====" << endl;
        
        cout << "\n\nYour selection: ";
        cin >> selection;

        if(selection == 0)
        {
            cout << "\n\tSee ya\n" << endl;
            system("pause");
            return;
        }
        else if(selection == 1)
        {
            if(tree == NULL)
            {
                cout << "\nThere no elements in binary tree" << endl;
            }
            else {
                cout << "\nAll elements: ";
                NRL(tree);
            }
            system("pause");

        }
        else if(selection == 2)
        {
            int value;
            cout << "\nEnter new value: ";
            cin >> value;
            addNodeToTree(tree, value);
        }
        else if(selection == 3)
        {
            int value;
            cout << "\nEnter value need to delete: ";
            cin >> value;
            deleteNodeInTree(tree, value);
        }
        else
        {
            cout << "\nNo matching selection. Please try again !\n" << endl;
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