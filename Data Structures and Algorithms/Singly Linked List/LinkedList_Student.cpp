#include<iostream>
#include<string.h>
#include<string>
#include<fstream>
using namespace std;

struct date
{
    int day;
    int month;
    int year;
};
typedef date Date;

struct student
{
    string name;
    string id;
    Date date;
    float score;
};
typedef student Student;

struct node
{
    Student data;
    struct node *pNext;
};
typedef node Node;

struct list
{
    Node *pHead = NULL;
    Node *pTail = NULL;
};
typedef list List;

Node* initializeNode(Student &st)
{
    Node *temp = new Node;
    if(temp == NULL)
    {
        cout << "Not enough memory to allocate !" << endl;
        return NULL;
    }
    temp->data = st;
    temp->pNext = NULL;
    return temp;
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

void readDateData(ifstream &FileIn, Date &date)
{
    FileIn >> date.day;
    char a;
    FileIn >> a;
    FileIn >> date.month;
    char b;
    FileIn >> b;
    FileIn >> date.year;
}

void readStudentData(ifstream &FileIn, Student &st)
{
    getline(FileIn, st.name, ',');
    getline(FileIn, st.id, ',');
    readDateData(FileIn, st.date);
    char a;
    FileIn >> a;
    FileIn >> st.score;
    string temp;
    getline(FileIn, temp);
}

void readStudentList(ifstream &FileIn, List &list)
{
    int count = 1;
    while(!FileIn.eof())
    {
        Student st;
        readStudentData(FileIn, st);
        Node *temp = initializeNode(st);
        addNodeToTheEnd(list, temp);
    }
}

void showStudent(Student st)
{
    cout << "Student name: " << st.name << endl;
    cout << "Student ID: " << st.id << endl;
    cout << "Date: " << st.date.day << "/" << st.date.month << "/" << st.date.year << endl;
    cout << "Score: " << st.score;
}

void showStudentList(List list)
{
    int count = 1;
    for(Node *temp = list.pHead; temp != NULL; temp = temp->pNext)
    {
        cout << "\n\n\t STUDENT " << count++ << endl;
        showStudent(temp->data);
    }
}

int main()
{
    List list;
    initializeList(list);
    ifstream FileIn;
    FileIn.open("D:\\Codes\\Data Structures and Algorithms\\Singly Linked List\\LinkedList_Student\\SinhVien.txt", ios::in);
    if(FileIn.fail())
    {
        cout << "Can't open file !" << endl;
        return 0;
    }
    readStudentList(FileIn, list);
    showStudentList(list);
    FileIn.close();
    freeMemory(list);
    return 0;
}