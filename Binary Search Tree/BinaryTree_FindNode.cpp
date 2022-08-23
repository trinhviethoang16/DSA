#include<iostream>
using namespace std;

//Integer value
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

Tree findingNode(Tree tree, int value)
{
    if(tree == NULL)
    {
        return NULL;
    }
    else
    {
        if(value > tree->data)
        {
            findingNode(tree->pRight, value);
        }
        else if(value < tree->data)
        {
            findingNode(tree->pLeft, value);
        }
    }
    return tree;
}

void Menu(Tree &tree)
{
    int selection;
    while(true)
    {
        system("cls");
        cout << "\t===== MENU =====" << endl;
        cout << "1. Show all elements in binary tree" << endl;
        cout << "2. Add new value to binary tree" << endl;
        cout << "3. Find node in binary tree" << endl;
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
            cout << "\nAll elements by NLR: ";
            NLR(tree);
            system("pause");
        }
        else if(selection == 2)
        {
            int value;
            cout << "Enter new value: ";
            cin >> value;
            addNodeToTree(tree, value);
        }
        else if(selection == 3)
        {
            int value;
            cout << "Enter node value need to find: ";
            cin >> value;
            Node *p = findingNode(tree, value);
            if(p == NULL)
            {
                cout << "\nCould't find " << value << " in binary tree\n" << endl;
            }
            else
            {
                cout << "\nFind " << value << " in binary tree\n" << endl;
            }
            system("pause");
        }
        else
        {
            cout << "No matching selection. Pleasy try again !" << endl;
            system("pause");
        }
    }
}

int main()
{
    Tree tree;
    initializeTree(tree);
    Menu(tree);
    system("pause");
    return 0;
}