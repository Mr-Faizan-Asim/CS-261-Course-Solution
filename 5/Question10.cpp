#include<iostream>
#include<stack>
using namespace std;
void sort(stack<int> &org);
void insert(stack<int> &org,int top);
void show(stack<int> sta);
int main()
{
    stack<int> myStack;
    myStack.push(-3);
    myStack.push(14);
    myStack.push(18);
    myStack.push(-5);
    myStack.push(30);

    cout << "Input Stack:" << std::endl;
    show(myStack);
    sort(myStack);
    cout << "Sorted Stack:" << std::endl;
    show(myStack);

    return 0;
}
void sort(stack<int> &org)
{
    if(!org.empty())
    {
        int top = org.top();
        org.pop();    
        sort(org);
        insert(org,top);
    }
}

void insert(stack<int> &org,int top)
{
    if(org.empty() || org.top() < top)
    {
        org.push(top);
        return;
    }
    int topEle = org.top();
    org.pop();
    insert(org,top);
    org.push(topEle);
}

void show(stack<int> sta) {
    stack<int> temp =sta; 
    for(int i= 0 ; i <  5 ; i++)
    {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;
}