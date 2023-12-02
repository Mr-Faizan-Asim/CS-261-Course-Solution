#include<iostream>
using namespace std;


using namespace std;
// Node
class Node{
public:
    string name;
    int roll;
    int marks;
    Node* prev;
    Node* next;
public:
    Node(string name,int roll,int marks)
    {
        this->marks = marks;
        this->name = name;
        this->roll = roll;
        prev = nullptr;
        next = nullptr; 
    }
};
// Double Link List
class doubleLinkList{
    Node* head;
    Node* tail;
public:
    doubleLinkList()
    {
        head = nullptr;
    }
    // insert
    bool insertBegin(string name,int roll, int marks)
    {
        Node* nextNode = new  Node(name,roll,marks);
        if(head == nullptr)
        {
            nextNode->next =  head;
            head = nextNode;
            tail = nextNode;
            
        }
        else{
            nextNode->next =  head;
            head->prev = nextNode;
            head = nextNode;
             
        }
    }
    // insert end
    bool insertEnd(string name,int roll, int marks)
    {
        Node* nextNode = new  Node(name,roll,marks);
        if(head == nullptr)
        {
            nextNode->next =  head;
            head = nextNode;
            tail = nextNode;
        }
        else
        {
            tail->next = nextNode;
            nextNode->prev = tail;
            tail = nextNode;
            
        }

    }
    // Display
    void displayBegin()
    {
        Node* temp = this->head;
        while(temp != nullptr)
        {
            cout<<temp->name + " and " << temp->marks << endl;
            temp = temp->next;
        }
    }

    void displayLast()
    {
        Node* temp = this->tail;
        while(temp != nullptr)
        {
            cout<<temp->name + " and " << temp->marks << endl;
            temp = temp->prev;
        }
    }
    // Search
    bool Search(int roll)
    {
        Node* temp = this->tail;
        while(temp != nullptr)
        {
            if(temp->roll == roll)
            {
                cout<<temp->name + " and " << temp->marks << endl;
                break;
            }
            temp = temp->prev;
        }
    }
    // Delete
    bool Delete(int roll)
    {
        Node* temp = this->head;
        while(temp != nullptr)
        {
            if(temp->roll == roll)
            {
                Node* t = temp->prev;
                t->next = temp->next;
                Node* t2 = temp->next;
                t2->prev = temp->prev;
                
                break;
            }
            temp = temp->next;
        }
    }
    // Update
    // Search
    bool UpdateMarks(int roll, int marks)
    {
        Node* temp = this->tail;
        while(temp != nullptr)
        {
            if(temp->roll == roll)
            {
                temp->marks = marks;
                cout<<"Updated";
                break;
            }
            temp = temp->prev;
        }
    }

};