#include<iostream>
using namespace std;

//Nhap danh sach lien ket don cac so nguyen. Tim gia tri lon nhat trong danh sach
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

void initializeList(List &list)
{
    list.pHead = NULL;
    list.pTail = NULL;
}

Node* initializeNode(int n)
{
    Node *p = new Node;
    if(p == NULL)
    {
        cout << "Khong du bo nho de cap phat" << endl;
        return NULL;
    }
    p->data = n;
    p->pNext = NULL;
    return p;
}

void addNodeToBegin(List &list, Node *p)
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

void addNodeToEnd(List &list, Node *p)
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

void output(List list)
{
    for(Node *k = list.pHead; k != NULL; k = k->pNext)
    {
        cout << k->data << " ";
    }
}

int findHighestValue(List list)
{
    int max = list.pHead->data;
    for(Node *k = list.pHead->pNext; k != NULL; k = k->pNext)
    {
        if(max < k->data)
        {
            max = k->data;
        }
    }
    return max;
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

int main()
{
    List list;
    initializeList(list);
    int n, k;
    do
    {
        cout << "Nhap so luong node: ";
        cin >> n;
        if(n<=0)
        {
            cout << "So luong khong hop le ! Vui long nhap lai" << endl;
        }
    } while(n<=0);

    for(int i=1; i<=n; i++)
    {
        cout << "Nhap so nguyen phan tu thu " << i << " = ";
        cin >> k;
        Node *p = initializeNode(k);
        addNodeToBegin(list, p);
    }

    cout << "\n\tARRAY" << endl;
    output(list);

    cout << "\n\nHighest value in the array is " << findHighestValue(list);
    freeMemory(list);
    return 0;
}