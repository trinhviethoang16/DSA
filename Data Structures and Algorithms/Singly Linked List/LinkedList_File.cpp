#include<iostream>
#include<fstream>
using namespace std;

struct node
{
    int data;
    struct node *pNext;
};
typedef node Node;

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

void addNodeToTheBegin(Node *&pHead, Node *p)
{
    if(pHead == NULL)
    {
        pHead = p;
    }
    else
    {
        p->pNext = pHead;
        pHead = p;
    }
}

void addNodeToTheEnd(Node *&pHead, Node *p)
{
    if(pHead == NULL)
    {
        pHead = p;
    }
    else
    {
        for(Node *temp = pHead; ; temp=temp->pNext)
        {
            if(temp->pNext == NULL)
            {
                temp->pNext = p;
                break;
            }
        }
    }
}

void outputAllElements(Node *pHead)
{
    if(pHead == NULL)
    {
        cout << "\nThere are no elements in the stack\n" << endl;
        return;
    }
    cout << "\n\tALL ELEMENTS" << endl;
    for(Node *temp = pHead; temp != NULL; temp=temp->pNext)
    {
        cout << temp->data << " ";
    }
}

void freeMemory(Node *&pHead)
{
    Node *temp = NULL;
    while(pHead != NULL)
    {
        temp = pHead;
        pHead = pHead->pNext;
        delete temp;
    }
}

void Permutation(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

void sortElementsIncrease(Node *&pHead)
{
    for(Node *a = pHead; a != NULL; a=a->pNext)
    {
        for(Node *b = a->pNext; b != NULL; b=b->pNext)
        {
            if(a->data < b->data)
            {
                Permutation(a->data, b->data);
            }
        }
    }
}

void sortElementsDecrease(Node *&pHead)
{
    for(Node *a = pHead; a != NULL; a=a->pNext)
    {
        for(Node *b = a->pNext; b != NULL; b=b->pNext)
        {
            if(a->data > b->data)
            {
                Permutation(a->data, b->data);
            }
        }
    }
}

void writeToFileIncrease(Node *pHead, ofstream &FileOut, int number)
{
    sortElementsIncrease(pHead);
    FileOut << number << endl;
    for(Node *temp = pHead; temp != NULL; temp=temp->pNext)
    {
        FileOut << temp->data << " ";
    }
}

void writeToFileDecrease(Node *pHead, ofstream &FileOut, int number)
{
    sortElementsDecrease(pHead);
    FileOut << number << endl;
    for(Node *temp = pHead; temp != NULL; temp=temp->pNext)
    {
        FileOut << temp->data << " ";
    }
}

void writeMaxMinNumber(Node *pHead, ofstream &FileOut)
{
    int max = pHead->data;
    for(Node *temp = pHead->pNext; temp != NULL; temp=temp->pNext)
    {
        if(max < temp->data)
        {
            max = temp->data;
        }
    }
    FileOut.open("D:\\Codes\\Data Structures and Algorithms\\Singly Linked List\\LinkedList_File\\MaxMin.txt", ios_base::app);
    FileOut << "Max number in the linked list: " << max << endl;
    FileOut.close();

    int min = pHead->data;
    for(Node *temp = pHead->pNext; temp != NULL; temp=temp->pNext)
    {
        if(min > temp->data)
        {
            min = temp->data;
        }
    }
    FileOut.open("D:\\Codes\\Data Structures and Algorithms\\Singly Linked List\\LinkedList_File\\MaxMin.txt", ios_base::app);
    FileOut << "Min number in the linked list: " << min << endl;;
    FileOut.close();
}

int main()
{
    Node *pHead = NULL;
    ifstream FileIn;
    ofstream FileOut;
    FileIn.open("D:\\Codes\\Data Structures and Algorithms\\Singly Linked List\\LinkedList_File\\Number.txt", ios_base::in);
    int elements;
    FileIn >> elements;
    
    for(int i=0; i<elements; i++)
    {
        int value;
        FileIn >> value;
        Node *temp = initializeNode(value);
        addNodeToTheEnd(pHead, temp);
    }
    
    outputAllElements(pHead);
    FileOut.open("D:\\Codes\\Data Structures and Algorithms\\Singly Linked List\\LinkedList_File\\SapXepTangDan.txt", ios_base::out);
    writeToFileIncrease(pHead, FileOut, elements);
    FileOut.close();

    FileOut.open("D:\\Codes\\Data Structures and Algorithms\\Singly Linked List\\LinkedList_File\\SapXepGiamDan.txt", ios_base::out);
    writeToFileDecrease(pHead, FileOut, elements);
    FileOut.close();

    writeMaxMinNumber(pHead, FileOut);

    FileIn.close();
    freeMemory(pHead);
    return 0;
}