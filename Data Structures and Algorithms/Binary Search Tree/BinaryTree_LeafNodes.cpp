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

void nodeHasNoLeaves(Tree tree)
{
    if(tree != NULL)
    {
        if(tree->pLeft == NULL && tree->pRight == NULL)
        {
            cout << tree->data << " ";
        }
        nodeHasNoLeaves(tree->pLeft);
        nodeHasNoLeaves(tree->pRight);
    }
}

void nodeHas1Leaf(Tree tree)
{
    if(tree != NULL)
    {
        if((tree->pLeft != NULL && tree->pRight == NULL) || (tree->pLeft == NULL && tree->pRight != NULL))
        {
            cout << tree->data << " ";
        }
        nodeHas1Leaf(tree->pLeft);
        nodeHas1Leaf(tree->pRight);
    }
}

void nodeHas2Leaves(Tree tree)
{
    if(tree != NULL)
    {
        if(tree->pLeft != NULL && tree->pRight != NULL)
        {
            cout << tree->data << " ";
        }
        nodeHas2Leaves(tree->pLeft);
        nodeHas2Leaves(tree->pRight);
    }
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
        cout << "\t3. Show all node has no leaves" << endl;
        cout << "\t4. Show all node has 1 leaf" << endl;
        cout << "\t5. Show all node has 2 leaves" << endl;
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
            cout << "\nNode has no leaves is ";
            nodeHasNoLeaves(tree);
            cout << endl;
            system("pause");
        }
        else if(selection == 4)
        {
            cout << "\nNode has 1 leaf is ";
            nodeHas1Leaf(tree);
            cout << endl;
            system("pause");
        }
        else if(selection == 5)
        {
            cout << "\nNode has 2 leaves is ";
            nodeHas2Leaves(tree);
            cout << endl;
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