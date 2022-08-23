#include<iostream>
using namespace std;

/*FIFO
- IsEmpty: Check if the queue is empty
- IsFull: Check if the queue is full ?
- Push: Add an element to the end of a queue
- Pop: Remove an element from the begin of a queue
- Peek: Get the value of the begin element without removing it */

struct node
{
    int data;
    struct node *pNext;
};
typedef node Node;

struct queue
{
    Node *pHead;
    Node *pTail;
};
typedef queue Queue;

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

void initializeQueue(Queue &queue)
{
    queue.pHead = NULL;
    queue.pTail = NULL;
}

bool IsEmpty(Queue queue)
{
    if(queue.pHead == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Push(Queue &queue, Node *p)
{
    if(IsEmpty(queue) == true)
    {
        queue.pHead = queue.pTail = p;
    }
    else
    {
        queue.pTail->pNext = p;
        queue.pTail = p;
    }
}

void Pop(Queue &queue)
{
    if(IsEmpty(queue) == true)
    {
        cout << "\nThere are no elements in the queue\n" << endl;
        return;
    }
    else
    {
        Node *temp = queue.pHead;
        queue.pHead = queue.pHead->pNext;
        delete temp;
    }
}

void Peek(Queue queue, int &value)
{
    if(IsEmpty(queue) == true)
    {
        cout << "\nThere are no elements in the list\n" << endl;
        return;
    }
    else
    {
        value = queue.pHead->data;
    }
}

void showAllElementValue(Queue queue)
{
    if(IsEmpty(queue) == true)
    {
        cout << "\nThere are no elements in the list\n" << endl;
        return;
    }

    for(Node *temp = queue.pHead; temp != NULL; temp=temp->pNext)
    {
        cout << temp->data << " ";
    }
}

void freeMemory(Queue &queue)
{
    Node *temp = NULL;
    while(queue.pHead != NULL)
    {
        temp = queue.pHead;
        queue.pHead = queue.pHead->pNext;
        delete temp;
    }
}

void Menu(Queue &queue)
{
    int selection;
    while(true)
    {
        system("cls");
        cout << "\t\t===== MENU =====" << endl;
        cout << "\t1. Show all elements in queue" << endl;
        cout << "\t2. Add an element to the end of a queue" << endl;
        cout << "\t3. Remove an element from the begin of a queue" << endl;
        cout << "\t4. Get the value of the begin element" << endl;
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
            showAllElementValue(queue);
            system("pause");
        }
        else if(selection == 2)
        {
            int value;
            cout << "Enter new node value: ";
            cin >> value;
            Node *p = initializeNode(value);
            Push(queue, p);
        }
        else if(selection == 3)
        {
            Pop(queue);
            system("pause");
        }
        else if(selection == 4)
        {
            int temp;
            Peek(queue, temp);
            cout << "\nThe value of the begin element is " << temp << endl << endl;
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
    Queue queue;
    initializeQueue(queue);
    Menu(queue);
    freeMemory(queue);
    return 0;
}