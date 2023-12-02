#include<iostream>
//#include<>
using namespace std;

int searchFirstEntitty(int arr[],int size,int ind,int find)
{
    if(ind == size)
    {
        return -1;
    }
    if(arr[ind] == find)
    {
        return ind;
    }
    return searchFirstEntitty(arr,size,ind+1,find);
}
int searchLastEntitty(int arr[],int size,int ind,int find)
{
    if(ind == 0)
    {
        return -1;
    }
    if(arr[ind] == find)
    {
        return ind;
    }
    return searchLastEntitty(arr,size,ind-1,find);
}
int BinaryEntitty(int arr[],int size,int ind,int find)
{
    int left = ind;
    int right = size;
    if(left <= right)
    {
        int mid = left + (right-left)/2; 
    
    if(arr[mid] == find)
    {
        return mid;
    }
    else if(arr[mid] > find)
    {
        return BinaryEntitty(arr,mid - 1,ind,find);
    }
    else
    {
        return BinaryEntitty(arr,size,mid + 1,find);
    }
        
    }
    return -1;
}
int main()
{
    int arr[9] = {1,2,3,4,5,6,6,1,3};
    cout<< searchFirstEntitty(arr,9,0,1)<<endl<<searchLastEntitty(arr,9,8,1)<<endl;
     int arrt[6] = {1,2,3,4,5,6};
     cout<<BinaryEntitty(arrt,6,0,4);

}