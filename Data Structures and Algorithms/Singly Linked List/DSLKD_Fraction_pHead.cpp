#include<iostream>
using namespace std;

struct fraction
{
    int numerator;
    int denominator;
};
typedef fraction Fraction;

struct node
{
    Fraction data;
    struct node *pNext;    
};
typedef node Node;

Node* initializeNode(Fraction fr)
{
    Node *p = new Node;
    if(p == NULL)
    {
        cout << "Not enough memory to allocate !" << endl;
        return NULL;
    }
    p->data = fr;
    p->pNext = NULL;
    return p;
}

void inputFraction(Fraction &fr)
{
    cout << "\nInput numeration: ";
    cin >> fr.numerator;
    cout << "\nInput denominator: ";
    cin >> fr.denominator;
}

void outputFraction(Fraction fr)
{
    cout << "\t" << fr.numerator << "/" << fr.denominator << endl;
}

//Reduce
int greatestCommonDivisor(int x, int y)
{
    if(x<0)
    {
        x *= -1;
    }

    if(y<0)
    {
        y *= -1;
    }

    while(x!=y)
    {
        if(x>y)
        {
            x -= y;
        }
        else
        {
            y -= x;
        }
    }
    return x;
}

void reduceFration(Fraction &fr)
{
    int temp = greatestCommonDivisor(fr.numerator, fr.denominator);
    fr.numerator = fr.numerator/temp;
    fr.denominator = fr.denominator/temp;
}

void showAllFraction(Node *pHead)
{
    if(pHead == NULL)
    {
        cout << "\nThere are no elements in the stack\n" << endl;
        return;
    }
    cout << "\nALL FRACTION BEFORE REDUCE" << endl;
    for(Node *temp = pHead; temp != NULL; temp=temp->pNext)
    {
        outputFraction(temp->data);
        cout << endl;
    }
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
                // p->pNext = NULL;
                break;
            }
        }
    }
}

void deleteNodeInTheBegin(Node *&pHead)
{
    if(pHead == NULL)
    {
        cout << "\nThere are no elements in the list\n" << endl;
        return;
    }
    else
    {
        Node *temp = pHead;
        pHead = pHead->pNext;
        delete temp;
    }
}

void deleteNodeInTheEnd(Node *&pHead)
{
    if(pHead == NULL)
    {
        cout << "\nThere are no elements in the list\n" << endl;
        return;
    }
    else if(pHead->pNext == NULL)
    {
        Node *temp = pHead;
        pHead = NULL;
        delete temp;
        return;
    }
    else
    {
        for(Node *temp = pHead; ; temp=temp->pNext)
        {
            if(temp->pNext->pNext == NULL)
            {
                delete temp->pNext;
                temp->pNext = NULL;
                break;
            }
        }
    }
}

void addNodeBeforeNodeInTheList(Node *&pHead, Fraction fraction, Node *nodeInLinkedList)
{
    for(Node *temp = pHead; temp != NULL; temp=temp->pNext)
    {
        if(temp->data.denominator == nodeInLinkedList->data.denominator && temp->data.numerator == nodeInLinkedList->data.numerator)
        {
            Node *value = initializeNode(fraction);
            value->pNext = temp->pNext;
            temp->pNext = value;
        }
    }
}

void deleteNodeBeforeNodeInTheList(Node *&pHead, Node *nodeInLinkedList)
{
    if(pHead == NULL)
    {
        cout << "\nThere are no elements in the list\n" << endl;
        system("pause");
        return;
    }
    for(Node *temp = pHead; temp != NULL; temp=temp->pNext)
    {
        if(temp->pNext == NULL)
        {
            cout << "\nThere are no element before this node !\n" << endl;
            system("pause");
            return;
        }
        if(temp->data.denominator == nodeInLinkedList->data.denominator && temp->data.numerator == nodeInLinkedList->data.numerator)
        {
            Node *deleteNode = temp->pNext;
            temp->pNext = temp->pNext->pNext;
            delete deleteNode;
        }
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

void Menu(Node *&pHead)
{
    int selection;
    while(true)
    {
        system("cls");
        cout << "\t===== MENU =====" << endl;
        cout << "\t1. Show all fraction" << endl;
        cout << "\t2. Input new fraction" << endl;
        cout << "\t3. Delete node in the begin" << endl;
        cout << "\t4. Delete node in the end" << endl;
        cout << "\t5. Add node before node in the list" << endl;
        cout << "\t6. Delete node before node in the list" << endl;
        cout << "\t0. Exit" << endl;
        cout << "\t=====  END  =====" << endl;
        cout << "\n\nYour selection: ";
        cin >> selection;

        if(selection == 0)
        {
            cout << "\n\tSee ya" << endl;
            return;
        }
        else if(selection == 1)
        {
            showAllFraction(pHead);
            system("pause");
        }
        else if(selection == 2)
        {
            Fraction fr;
            inputFraction(fr);
            reduceFration(fr);
            Node *p = initializeNode(fr);
            addNodeToTheBegin(pHead, p);
        }
        else if(selection == 3)
        {
            deleteNodeInTheBegin(pHead);
            system("pause");
        }
        else if(selection == 4)
        {
            deleteNodeInTheEnd(pHead);
            system("pause");
        }
        else if(selection == 5)
        {
            Fraction fr;
            cout << "\n\tINPUT NEW NODE VALUE WANT TO ADD";
            inputFraction(fr);
            reduceFration(fr);

            Fraction valueInList; 
            cout << "\n\tINPUT NODE VALUE ALREADY EXIST IN THE LIST";
            inputFraction(valueInList);
            reduceFration(valueInList);
            Node *p = initializeNode(valueInList);
            addNodeBeforeNodeInTheList(pHead, fr, p);
        }
        else if(selection == 6)
        {
            Fraction fr;
            cout << "\n\tINPUT NODE VALUE ALREADY EXIST IN THE LIST";
            inputFraction(fr);
            reduceFration(fr);
            Node *p = initializeNode(fr);
            deleteNodeBeforeNodeInTheList(pHead, p);
        }
        else
        {
            cout << "No matching selection... Please try again !" << endl;
            system("pause");
        }
    }
}

int main()
{
    Node *pHead = NULL;
    Menu(pHead);
    freeMemory(pHead);
    return 0;
}