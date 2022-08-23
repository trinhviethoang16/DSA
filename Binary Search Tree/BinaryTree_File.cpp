#include<iostream>
#include<fstream>
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

void NRL(Tree tree)
{
    if(tree != NULL)
    {
        cout << tree->data << " ";
        NRL(tree->pRight);
        NRL(tree->pLeft);
    }
}

void readFile(Tree &tree, ifstream &FileIn)
{
    int numberOfElements;
    FileIn >> numberOfElements;
    
    for(int i=0; i<numberOfElements; i++)
    {
        int temp;
        FileIn >> temp;
        addNodeToTree(tree, temp);
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

void nodeHasOneLeaf(Tree tree)
{
    if(tree != NULL)
    {
        if((tree->pLeft != NULL && tree->pRight == NULL) || (tree->pLeft == NULL && tree->pRight != NULL))
        {
            cout << tree->data << " ";
        }
        nodeHasOneLeaf(tree->pLeft);
        nodeHasOneLeaf(tree->pRight);
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

int findHighestNodeValue(Tree tree)
{
    if(tree->pRight == NULL)
    {
        return tree->data;
    }
    return findHighestNodeValue(tree->pRight);
}

void Menu(Tree &tree)
{
    int selection;
    while(true)
    {
        system("cls");
        cout << "\t\t===== MENU =====" << endl;
        cout << "\t1. Show all elements in binary tree" << endl;
        cout << "\t2. Show all elements has one leaf" << endl;
        cout << "\t3. Show all elements has 2 leaves" << endl;
        cout << "\t4. Show all elements has no leaves" << endl;
        cout << "\t5. Show highest elements" << endl;
        cout << "\t0. Exit" << endl;
        cout << "\t\t=====  END  =====" << endl;
        
        cout << "\n\nYour selection: ";
        cin >> selection;

        if(selection == 0)
        {
            cout << "\t\nSee ya\n" << endl;
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
            if(tree == NULL)
            {
                cout << "\nThere no elements in binary tree" << endl;
            }
            else {
                cout << "\nAll elements has one leaf: ";
                nodeHasOneLeaf(tree);
            }
            system("pause");

        }
        else if(selection == 3)
        {
            if(tree == NULL)
            {
                cout << "\nThere no elements in binary tree" << endl;
            }
            else {
                cout << "\nAll elements has 2 leaves: ";
                nodeHas2Leaves(tree);
            }
            system("pause");

        }
        else if(selection == 4)
        {
            if(tree == NULL)
            {
                cout << "\nThere no elements in binary tree" << endl;
            }
            else {
                cout << "\nAll elements has no leaves: ";
                nodeHasNoLeaves(tree);
            }
            system("pause");
        }
        else if(selection == 5)
        {
            if(tree == NULL)
            {
                cout << "\nThere no elements in binary tree" << endl;
            }
            else {
                cout << "\nHighest value in binary tree is: " << findHighestNodeValue(tree) << endl << endl;
            }
            system("pause");
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
    ifstream FileIn;
    FileIn.open("D:\\Codes\\Data Structures and Algorithms\\Binary Search Tree\\BinaryTree_File\\Input.txt", ios_base::in);
    readFile(tree, FileIn);
    Menu(tree);
    FileIn.close();
    return 0;
}