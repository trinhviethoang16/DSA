#include<iostream>
using namespace std;

//Them node p vao sau va truoc node q(q nam trong danh sach lien ket don cac so nguyen)
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

void addNodeAfterAnotherNode(List &list, Node *p)
{
    int n;
    cout << "Enter node value in linked list: ";
    cin >> n;
    Node *q = initializeNode(n);

    if(list.pHead->pNext == NULL && q->data == list.pHead->data)
    {
        addNodeToTheEnd(list, p);
    }
    else
    {
        for(Node *temp = list.pHead; temp != NULL; temp = temp->pNext)
        {
            if(q->data == temp->data)
            {
                Node *h = initializeNode(p->data);
                Node *k = temp->pNext;
                h->pNext = k;
                temp->pNext = h;
            }
        }
    }
}

void addNodeBeforeAnotherNode(List &list, Node *p)
{
    int n;
    cout << "Enter node value in linked list: ";
    cin >> n;
    Node *q = initializeNode(n);

    if(list.pHead->pNext == NULL && q->data == list.pHead->data)
    {
        addNodeToTheBegin(list, p);
    }
    else
    {
        Node *k = new Node;
        for(Node *temp = list.pHead; temp != NULL; temp=temp->pNext)
        {
            if(q->data == temp->data)
            {
                Node *h = initializeNode(p->data);
                h->pNext = temp;
                k->pNext = h;
            }
            k = temp;
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
        cout << "3. Add node after node in linked list" << endl;
        cout << "4. Add node before node in linked list" << endl;
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
            int n;
            cout << "Enter new node value: ";
            cin >> n;
            Node *p = initializeNode(n);
            addNodeAfterAnotherNode(list, p);
        }
        else if(selection == 4)
        {
            int n;
            cout << "Enter new node value: ";
            cin >> n;
            Node *p = initializeNode(n);
            addNodeBeforeAnotherNode(list , p);
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