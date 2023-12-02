#include<iostream>
#include<vector>
using namespace std;
void vectorPrinter(vector<int> &d)
{
    
    for(int n : d)
    {
        cout<<n<<",";
    }
    if(d.size() == 0)
    {
        cout<<"0";
    }
    else
    {
    cout<<endl;
    }
}
int Subarray(vector<int> &temp,int start,int end,vector<int> &ans)
{
    if(start > end)
    {
        vectorPrinter(ans);
        return 0;
    }
    ans.push_back(temp[start]);
    Subarray(temp,start+1,end,ans);
    ans.pop_back();
    Subarray(temp,start+1,end,ans);
    
}


int main()
{
    vector<int> x = {1,2,3};
    vector<int> ans;
    Subarray(x,0,2,ans);

}
