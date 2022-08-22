#include<iostream>
using namespace std;

/*Cconvert 10 -> 2-8-16 using stack */

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

void Pop(Stack &stack, int &value)
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
        value = temp->data;
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

void convert(Stack &stack, int radix, int decimal)
{
    while(decimal != 0)
    {
        int value = decimal%radix;
        Node *temp = initializeNode(value);
        Push(stack, temp);
        decimal /= radix;
    }
}

void showValue(Stack &stack)
{
    while(IsEmpty(stack) == false)
    {
        int temp;
        Pop(stack, temp);
        if(temp < 10)
        {
            cout << temp;
        }
        else if(temp == 10)
        {
            cout << "A";
        }
        else if(temp == 11)
        {
            cout << "B";
        }
        else if(temp == 12)
        {
            cout << "C";
        }
        else if(temp == 13)
        {
            cout << "D";
        }
        else if(temp == 14)
        {
            cout << "E";
        }
        else if(temp == 15)
        {
            cout << "F";
        }
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

int main()
{
    Stack stack;
    initializeStack(stack);
    int decimal, radix;
    cout << "\nEnter decimal number: ";
    cin >> decimal;
    do
    {
        cout << "Enter radix want to convert(2-8-16): ";
        cin >> radix;
        if(radix != 2 && radix != 8 && radix != 16)
        {
            cout << "Please enter the correct radix !" << endl;
        }
    }while(radix != 2 && radix != 8 && radix != 16);
    
    convert(stack, radix, decimal);
    cout << "Number before convert: ";
    showValue(stack);

    freeMemory(stack);
    return 0;
}