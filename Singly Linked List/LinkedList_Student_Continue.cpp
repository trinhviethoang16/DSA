#include<iostream>
#include<string>
#include<string.h>
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
    Node *pHead;
    Node *pTail;
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

void sort(Student &x, Student &y)
{
    Student temp;
    temp = x;
    x = y;
    y = temp;
}

void sortStudentByScore(List &list)
{
    for(Node *a = list.pHead; a != NULL; a=a->pNext)
    {
        for(Node *b = a->pNext; b != NULL; b=b->pNext){
            if(a->data.score > b->data.score)
            {
                sort(a->data, b->data);
            }
        }
    }
}

void writeToFileStudentData(ofstream &FileOut, Student st)
{
    FileOut << st.name << "," << st.id << "," << st.date.day << "/" << st.date.month << "/" << st.date.year << "," << st.score;
}

void writeFileStudentByScore(List list)
{
    ofstream FileOut;
    FileOut.open("D:\\Codes\\Data Structures and Algorithms\\Singly Linked List\\LinkedList_Student_Continue\\ScoreSort.txt", ios_base::out);
    sortStudentByScore(list);
    for(Node *temp = list.pHead; temp != NULL; temp=temp->pNext)
    {
        writeToFileStudentData(FileOut, temp->data);
        FileOut << endl;
    }
    FileOut.close();
}

void writeHighestScoreToFile(List list)
{
    float max = list.pHead->data.score;
    for(Node *temp = list.pHead->pNext; temp != NULL; temp=temp->pNext)
    {
        if(max < temp->data.score)
        {
            max = temp->data.score;
        }
    }

    ofstream FileOut;
    FileOut.open("D:\\Codes\\Data Structures and Algorithms\\Singly Linked List\\LinkedList_Student_Continue\\HighestScore.txt", ios_base::out);

    for(Node *temp = list.pHead; temp != NULL; temp=temp->pNext)
    {
        if(max == temp->data.score)
        {
            writeToFileStudentData(FileOut, temp->data);
            FileOut << endl;
        }
    }
    FileOut.close();
}

void findStudentScore(List list, float studentScore)
{
    for(Node *temp=list.pHead; temp != NULL; temp=temp->pNext)
    {
        if(studentScore == temp->data.score)
        {
            showStudent(temp->data);
            cout << endl;
        }
    }
}

string studentName(string name)
{
    int length = name.length();
    int i;
    for(i = length-1; i>=0; i--)
    {
        if(name[i] == ' ')
        {
            break;
        }
    }
    return name.substr(i + 1);
}

void findStudentName(List list, string name)
{
    for(Node *p = list.pHead; p != NULL; p = p->pNext)
    {
        string temp = studentName(p->data.name);
        if(strcmp(temp.c_str(), name.c_str()) == 0)
        {
            showStudent(p->data);
            cout << endl;
        }
    }
}

int main()
{
    List list;
    initializeList(list);
    ifstream FileIn;
    FileIn.open("D:\\Codes\\Data Structures and Algorithms\\Singly Linked List\\LinkedList_Student\\SinhVien.txt", ios_base::in);
    if(FileIn.fail())
    {
        cout << "Can't open file !" << endl;
        return 0;
    }
    readStudentList(FileIn, list);
    showStudentList(list);
    writeFileStudentByScore(list);
    writeHighestScoreToFile(list);

    float score;
    cout << "\n\nEnter student score you want to find: ";
    cin >> score;
    findStudentScore(list, score);
    fflush(stdin);
    string name;
    cout << "\n\nEnter student name you want to find: ";
    getline(cin, name);
    findStudentName(list, name);
    FileIn.close();
    freeMemory(list);
    return 0;
}