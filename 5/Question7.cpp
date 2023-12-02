#include<iostream>
#include<vector>
using namespace std;


int simpleFib(int ind){
    if(ind==0||ind==1)
    {
        return (ind);
    }
    return simpleFib(ind-1)+simpleFib(ind-2);
}
int fast(vector<int> &temp,int ind)
{
    if(temp[ind]!=-1)
    {
         return temp[ind];
    }
    return temp[ind]=fast(temp,ind-1)+fast(temp,ind-2);
}
int secondFib(int ind)
{
    vector<int> temp(ind+1,{-1});
    temp[0]=0;
    temp[1]=1;
    return fast(temp,ind);
}

int thirdFib(int ind) {
    if (ind <= 1) {
        return ind;
    }
    vector<int> temp(ind + 1);
    temp[0] = 0;
    temp[1] = 1;
    for (int i = 2; i <= ind; ++i) {
        temp[i] = temp[i - 1] + temp[i - 2];
    }
    for(int i=0;i<=ind;i++)
    {
        cout<<temp[i]<<" ";
    }
   
}
