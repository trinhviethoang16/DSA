#include<iostream>
using namespace std;

int numberOfMember = 0;

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
    for(Node *temp = list.pHead; temp != NULL; temp=temp->pNext)
    {
        cout << temp->data << " ";
    }
}

void addNodeToAnyPosition(List &list, Node *p, int position)
{

    if(list.pHead == NULL || position == 1)
    {
        addNodeToTheBegin(list, p);
    }
    else if(position == numberOfMember+1)
    {
        addNodeToTheEnd(list, p);
    }
    else
    {
        int count = 0;
        Node *g = new Node;
        for(Node *k = list.pHead; k != NULL; k=k->pNext)
        {
            count++;
            if(count == position)
            {
                Node *h = initializeNode(p->data);
                h->pNext = k;
                g->pNext = h;
                break;
            }
            g = k;
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
        cout << "3. Add node to any position" << endl;
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
            numberOfMember++;
            int value;
            cout << "Enter new node value: ";
            cin >> value;
            Node *p = initializeNode(value);
            addNodeToTheEnd(list, p);
        }
        else if(selection == 2)
        {
            outputLinkedList(list);
            system("pause");
        }
        else if(selection == 3)
        {
            int value, position;
            cout << "Enter new node value: ";
            cin >> value;
            Node *p = initializeNode(value);

            do
            {
                cout << "\nEnter position of linked list: ";
                cin >> position;
                if(position<1 || position>numberOfMember+1)
                {
                    cout << "\nPosition must be in [1;" << numberOfMember+1  << "]: " << endl;
                }
            } while(position<1 || position>numberOfMember+1);
            addNodeToAnyPosition(list, p, position);
            numberOfMember++;
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