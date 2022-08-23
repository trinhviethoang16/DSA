#include<iostream>
using namespace std;

//Xoa node tai vi tri bat ki trong danh sach lien ket don

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

void outputList(List list)
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

void deleteNodeInTheBegin(List &list)
{
    if(list.pHead == NULL)
    {
        cout << "\nThere are no more elements in the list\n" << endl;
        system("pause");
        return;
    }
    Node *temp = list.pHead;
    list.pHead = list.pHead->pNext;
    delete temp;
}

void deleteNodeInTheEnd(List &list)
{
    if(list.pHead == NULL)
    {
        cout << "\nThere are no more elements in the list\n" << endl;
        system("pause");
        return;
    }
    else if(list.pHead->pNext == NULL)
    {
        deleteNodeInTheBegin(list);
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

void deleteNodeToAnyPosition(List &list, int value)
{
    if(list.pHead == NULL)
    {
        cout << "\nThere are no more elements in the list\n" << endl;
        system("pause");
        return;
    }
    else if(list.pHead->data == value)
    {
        deleteNodeInTheBegin(list);
        return;
    }
    else if(list.pTail->data == value)
    {
        deleteNodeInTheEnd(list);
        return;
    }

    Node *temp = new Node;
    for(Node *k = list.pHead; k != NULL; k=k->pNext)
    {
        if(k->data == value)
        {
            temp->pNext = k->pNext;
            delete k;
            return;
        }
        temp = k;
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
        cout << "1. Show all node in linked list" << endl;
        cout << "2. Add node to the begin of list" << endl;
        cout << "3. Add node to the end of list" << endl;
        cout << "4. Delete node in the begin of list" << endl;
        cout << "5. Delete node in the end of list" << endl;
        cout << "6. Delete node to any position" << endl;
        cout << "0. Exit" << endl;
        cout << "=====  END  =====" << endl;

        cout << "\nYour selection: ";
        cin >> selection;

        if(selection == 0)
        {
            cout << "........" << endl;
            return;
        }
        else if(selection == 1)
        {
            outputList(list);
            system("pause");
        }
        else if(selection == 2)
        {
            int data;
            cout << "Enter new node value: ";
            cin >> data;
            Node *p = initializeNode(data);
            addNodeToTheBegin(list, p);
        }
        else if(selection == 3)
        {
            int data;
            cout << "Enter new node value: ";
            cin >> data;
            Node *p = initializeNode(data);
            addNodeToTheEnd(list, p);
        }
        else if(selection == 4)
        {
            deleteNodeInTheBegin(list);
        }
        else if(selection == 5)
        {
            deleteNodeInTheEnd(list);   
        }
        else if(selection == 6)
        {
            int value;
            cout << "Enter node value on linked list to delete: ";
            cin >> value;
            deleteNodeToAnyPosition(list, value);
            
        }
        else
        {
            cout << "There no selection matching... Please try again !" << endl;
            system("pause");
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