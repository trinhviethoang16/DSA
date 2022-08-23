#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *pNext;
};
typedef node Node;

struct list
{
    Node *pHead;
    Node *pTail;
};
typedef list List;

Node* initializeNode(int n)
{
    Node *p = new Node;
    if(p == NULL)
    {
        cout << "Khong du bo nho de cap phat !" << endl;
        return NULL;
    }
    p->data = n;
    p->pNext = NULL;
    return p;
}

void initializeList(List &list)
{
    list.pHead = NULL;
    list.pTail = NULL;
}

void addNodeToTheBegin(List &list, Node *p)
{
    if(list.pHead == NULL)
    {
        list.pHead = list.pTail = p;
    }
    else
    {
        p->pNext = list.pHead;
        list.pHead = p;
    }
}

void addNodeToTheEnd(List &list, Node *p)
{
    if(list.pHead == NULL)
    {
        list.pHead = list.pTail = p;
    }
    else
    {
        list.pTail->pNext = p;
        list.pTail = p;
    }
}

void outputLinkedList(List list)
{
    for(Node *temp = list.pHead; temp != NULL; temp = temp->pNext)
    {
        cout << temp->data << " ";
    }
}

void deleteNodeOnTheBegin(List &list)
{
    if(list.pHead == NULL)
    {
        cout << "There are no elements in linked list" << endl;
        return;
    }
    Node *p = list.pHead;
    list.pHead = list.pHead->pNext;
    delete p;
}

void deleteNodeOnTheEnd(List &list)
{
    if(list.pHead == NULL)
    {
        cout << "There are no elements in linked list" << endl;
        return;
    }
    
    if(list.pHead->pNext == NULL)
    {
        deleteNodeOnTheBegin(list);
        return;
    }

    for(Node *temp = list.pHead; temp != NULL; temp=temp->pNext)
    {
        if(temp->pNext == list.pTail)
        {
            delete list.pTail;
            temp->pNext = NULL;
            list.pTail = temp;
        }
    }
}

void freeMemory(List &list)
{
    Node *temp = NULL;
    while(list.pHead != NULL)
    {
        temp = list.pHead;
        list.pHead = list.pHead->pNext;
        delete temp;
    }
}

void Menu(List &list)
{
    int selection;
    while(true)
    {
        system("cls");
        cout << "\n===== MENU =====" << endl;
        cout << "1. Add node to linked list" << endl;
        cout << "2. Show all node on the linked list" << endl;
        cout << "3. Delete node on the begin " << endl;
        cout << "4. Delete node on the end" << endl;
        cout << "0. Exit" << endl;
        cout << "=====  END  =====" << endl;
        
        cout << "\nYour selection: ";
        cin >> selection;
        
        if(selection == 0)
        {
            cout << "...";
            return;
        }
        else if(selection == 1)
        {
            int n;
            cout << "Enter new node value: ";
            cin >> n;
            Node *p = initializeNode(n);
            addNodeToTheEnd(list, p);
        }
        else if(selection == 2)
        {
            outputLinkedList(list);
            system("pause");
        }
        else if(selection == 3)
        {
            deleteNodeOnTheBegin(list);
            system("pause");
        }
        else if(selection == 4)
        {
            deleteNodeOnTheEnd(list);
            system("pause");
        }
        else
        {
            cout << "No selection matching ! Please try again..." << endl;
            system("pause");
            break;
        }
    }
}

int main()
{
    List list;
    initializeList(list);
    Menu(list);
    freeMemory(list);
    return 0;
}