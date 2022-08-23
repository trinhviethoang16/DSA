#include<iostream>
using namespace std;

/*LIFO
- IsEmpty: Check if the stack is empty
- IsFull: Check if the stack is full ?
- Push: Add an element to the top of a stack
- Pop: Remove an element from the top of a stack
- Peek: Get the value of the top element without removing it */

struct node
{
    int data;
    struct node *pNext;
};
typedef node Node;

struct stack
{
    Node *pTop;
};
typedef stack Stack;

Node* initializeNode(int value)
{
    Node *p = new Node;
    if(p == NULL)
    {
        cout << "Not enough memory to allocate !" << endl;
        return NULL;
    }
    p->data = value;
    p->pNext = NULL;
    return p;
}

void initializeStack(Stack &stack)
{
    stack.pTop = NULL;
}

bool IsEmpty(Stack stack)
{
    if(stack.pTop == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Push(Stack &stack, Node *p)
{
    if(IsEmpty(stack) == true)
    {
        stack.pTop = p;
    }
    else
    {
        p->pNext = stack.pTop;
        stack.pTop = p;
    }
}

void Pop(Stack &stack)
{
    if(IsEmpty(stack) == true)
    {
        cout << "\nThere are no elements in the stack\n" << endl;
        return;
    }
    else
    {
        Node *temp = stack.pTop;
        stack.pTop = stack.pTop->pNext;
        delete temp;
    }
}

void Peek(Stack stack, int &value)
{
    if(IsEmpty(stack) == true)
    {
        cout << "\nThere are no elements in the stack\n" << endl;
        return;
    }
    else
    {
        value = stack.pTop->data;
    }
}

void showAllElementValue(Stack stack)
{
    if(IsEmpty(stack) == true)
    {
        cout << "\nThere are no elements in the stack\n" << endl;
        return;
    }

    while(IsEmpty(stack) == false)
    {
        cout << stack.pTop->data << " ";
        stack.pTop = stack.pTop->pNext;
    }
}

void freeMemory(Stack &stack)
{
    Node *temp = NULL;
    while(stack.pTop != NULL)
    {
        temp = stack.pTop;
        stack.pTop = stack.pTop->pNext;
        delete temp;
    }
}

void Menu(Stack &stack)
{
    int selection;
    while(true)
    {
        system("cls");
        cout << "\t\t===== MENU =====" << endl;
        cout << "\t1. Show all elements in stack" << endl;
        cout << "\t2. Add an element to the top of a stack" << endl;
        cout << "\t3. Remove an element from the top of a stack" << endl;
        cout << "\t4. Get the value of the top element" << endl;
        cout << "\t0. Exit" << endl;
        cout << "\t\t=====  END  =====" << endl;
        cout << "\n\nYour selection: ";
        cin >> selection;
        
        if(selection == 0)
        {
            cout << "\tSee ya" << endl;
            system("pause");
            return;
        }
        else if(selection == 1)
        {
            showAllElementValue(stack);
            system("pause");
        }
        else if(selection == 2)
        {
            int value;
            cout << "Enter new node value: ";
            cin >> value;
            Node *p = initializeNode(value);
            Push(stack, p);
        }
        else if(selection == 3)
        {
            Pop(stack);
            system("pause");
        }
        else if(selection == 4)
        {
            int temp;
            Peek(stack, temp);
            cout << "\nThe value of the top element is " << temp << endl << endl;
            system("pause");
        }
        else
        {
            cout << "\nThere no selection matching. Please try again !\n" << endl;
            system("pause");
        }
    }
}

int main()
{
    Stack stack;
    initializeStack(stack);
    Menu(stack);
    freeMemory(stack);
    return 0;
}