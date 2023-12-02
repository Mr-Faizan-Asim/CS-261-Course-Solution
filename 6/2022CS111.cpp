#include<iostream>
using namespace std;

// This is for Question 1 & 2
class Node{
    public:
    int data;
    Node* next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

class LinkedList{
private:
    Node* head;
    Node* tail;
    int count;
public:
    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
        count = 0;
    }
    // is empty
    bool isEmpty()
    {
        if(head == nullptr && tail == nullptr)
        {
            return true;
        }
        return false;
    }
    // front
    void insertAtFront(int value)
    {
        Node* nextNode = new  Node(value);
        if(head == nullptr)
        {
            nextNode->next =  head;
            head = nextNode;
            tail = nextNode;
            
        }
        else{
            nextNode->next =  head;
            head = nextNode;
        }
        count++;
    }
    // at tail
    bool insertAtTail(int data)
    {
        Node* nextNode = new  Node(data);
        if(head == nullptr)
        {
            nextNode->next =  head;
            head = nextNode;
            tail = nextNode;
        }
        else
        {
            tail->next = nextNode;
            tail = nextNode;
        }
        count++;
    }
    // at middle
    void insertAtMiddle(int val)
    {
         Node* nextNode = new  Node(val);
         Node* temp = head;
        
            for(int i = 0; i != count/2 -1 ; i++)
            {
                temp = temp->next;
            }
            Node* t = temp->next;
            temp->next = nextNode;
            nextNode->next = t;
            count++;
    }
    // insert After
    void insertAfter(int val,int key)
    {
         Node* nextNode = new  Node(key);
         Node* temp = head;
         while(temp->data != val)
         {
              temp = temp->next;
         }
            Node* t = temp->next;
            temp->next = nextNode;
            nextNode->next = t;
            count++;

    }
    // Insert before
     // insert After
    void insertBefore(int val,int key)
    {
         Node* nextNode = new  Node(key);
         Node* temp = head;
         Node* pre = temp;
         while(temp->data != val)
         {
              pre = temp;
              temp = temp->next;
         }
            Node* t = pre->next;
            pre->next = nextNode;
            nextNode->next = t;
            count++;

    }
    // toGet Front
    int ToGetFront()
    {
        if(!isEmpty())
            return head->data;
    }
    // to get last
    int ToGetEnd()
    {
        if(!isEmpty())
            return tail->data;
    }
    // search
    // insert After
    bool search(int val)
    {
         Node* temp = head;
         while(temp->next != nullptr)
         {
                if(temp->data == val)
                {
                    return true;
                }
         }
         return false;

    }
    // R Front
    int RemoveFront()
    {
        int d = head->data;
        head = head->next;
        count--;
        return d;
    }

    // R tail
    int RemoveTail()
    {
            Node* temp = head;   
            for(int i = 0; i != count - 2 ; i++)
            {
                temp = temp->next;
            }
            int d = tail->data;
            temp->next = nullptr;
            count--;
            return d;        
    }

    // Remove 
    void RemoveMiddle()
    {
            Node* temp = head;   
            for(int i = 0; i != count/2 -1 ; i++)
            {
                temp = temp->next;
            }
            Node* t = temp->next;
            temp->next = t->next;
            count--;

    }
    // display
    void display(){
        Node* current = head;
        while(current!= nullptr)
        {
            cout<<current->data<<"->";
            current = current->next;
        }
    }
};

// template <typename T>
// class Stack{
//     LinkedList
// }

class Stack{
    LinkedList S;
    public: 
        Stack()
        {

        }
        void push(int val)
        {
            S.insertAtFront(val);
        }
        int pop()
        {
            S.RemoveFront();
        }
        bool isEmpty()
        {
            return S.isEmpty();
        }
};

class Queue{
    LinkedList S;
    public: 
        Queue()
        {

        }
        void Enqueue(int val)
        {
            S.insertAtFront(val);
        }
        int Dequeue()
        {
            S.RemoveTail();
        }
        bool isEmpty()
        {
            return S.isEmpty();
        }
};

// This is for Question 3
class Nod{
public:
    string name;
    int roll;
    int marks;
    Nod* prev;
    Nod* next;
public:
    Nod(string name,int roll,int marks)
    {
        this->marks = marks;
        this->name = name;
        this->roll = roll;
        prev = nullptr;
        next = nullptr; 
    }
};
// Double Link List
class LinkList{
    Nod* head;
    Nod* tail;
public:
    LinkList()
    {
        head = nullptr;
    }
    // insert
    bool insertBegin(string name,int roll, int marks)
    {
        Nod* nextNode = new  Nod(name,roll,marks);
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
        Nod* nextNode = new  Nod(name,roll,marks);
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
        Nod* temp = this->head;
        while(temp != nullptr)
        {
            cout<<temp->name + " and " << temp->marks << endl;
            temp = temp->next;
        }
    }
    void reverseDisplay()
    {
        Nod* temp = this->tail;
        while(temp != nullptr)
        {
            cout<<temp->name + " and " << temp->marks << endl;
            temp = temp->prev;
        }
    }

    // Search
    bool Search(int roll)
    {
        Nod* temp = this->tail;
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
    // is Circular
    bool isCircular()
    {
        if(head->prev == tail && tail->next == head->prev )
        {
            return true;
        }
        return false;
    }
    // Reverse LinkList
    void ReverseLinkList()
    {
        LinkList l;
        Nod* temp = this->tail;
        while(temp != nullptr)
        {
            l.insertBegin(temp->name,temp->roll,temp->marks);
            temp = temp->prev;
        }
        this->head = l.head;
        this->tail = l.tail;
    }

};



int main() {
//Question 1
   LinkedList Li;
   Li.insertAtFront(5);
   Li.insertAtFront(6);
   Li.insertAtFront(7);
   Li.insertAtTail(8);
   Li.insertAtMiddle(3);
   Li.insertAfter(3,12);
   Li.insertBefore(8,4);
   Li.insertBefore(4,88);
   Li.insertBefore(3,99);
   Li.RemoveMiddle();
   Li.RemoveTail();

   Li.display();
// Question 2
// Question 3
    cout<<endl;
    LinkList op;
    op.insertBegin("ALi",1,2);
    op.insertBegin("bLi",2,22);
    op.insertBegin("cLi",3,222);
    op.insertBegin("dLi",4,2222);
    op.reverseDisplay();
    cout<<op.isCircular()<<endl;
    op.ReverseLinkList();
    op.displayBegin();

}