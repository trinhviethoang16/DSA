#include<iostream>
using namespace std;

//Xoa node q nam sau node p trong danh sach lien ket don

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

void outputLinkedList(List list)
{
    for(Node *temp = list.pHead; temp != NULL; temp=temp->pNext)
    {
        cout << temp->data << " ";
    }
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

void deleteNode(List &list, Node *p)
{
    for(Node *temp = list.pHead; temp != NULL; temp=temp->pNext)
    {
        if(temp->data == p->data)
        {
            Node *k = temp->pNext;
            temp->pNext = k->pNext;
            delete k;
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
        cout << "===== MENU =====" << endl;
        cout << "1. Add node to the begin of linked list" << endl;
        cout << "2. Add node to the end of linked list" << endl;
        cout << "3. Show linked list" << endl;
        cout << "4. Delete node" << endl;
        cout << "0. Exit" << endl;
        cout << "=====  END  =====" << endl;
        
        cout << "\nYour selection: ";
        cin >> selection;

        if(selection == 0)
        {
            return;
        }
        else if(selection == 1)
        {
            int data;
            cout << "Enter new node value: ";
            cin >> data;
            Node *p = initializeNode(data);
            addNodeToTheBegin(list, p);
        }
        else if(selection == 2)
        {
            int data;
            cout << "Enter new node value: ";
            cin >> data;
            Node *p = initializeNode(data);
            addNodeToTheEnd(list, p);
        }
        else if(selection == 3)
        {
            outputLinkedList(list);
            system("pause");
        }
        else if(selection == 4)
        {
            int data;
            cout << "Enter node value in linked list: ";
            cin >> data;
            Node *p = initializeNode(data);
            deleteNode(list, p);
        }
        else
        {
            cout << "No matching selection. Please try again !" << endl;
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