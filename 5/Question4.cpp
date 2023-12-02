#include<iostream>
#include<math.h>
using namespace std;

int Power(int x,int y, int M)
{
    if(y == 0)
    {
        return 1%M;
    }
    return (x * Power(x,y-1,M))% M;
}
int PowerByLog(int x,int y,int M)
{
    int res = 0;
    if(y == 0)
    {
        return 1%M;
    }
    if(y%2 == 0)
    {
        int hlf = PowerByLog(x,y/2,M);
        res = (hlf*hlf)%M;
    }
    else{
        int hlf = PowerByLog(x,(y-1)/2,M);
        res = ((hlf*hlf)%M * (x % M )) % M;
    }
    return (res+M)%M;
}
int main()
{
    cout<<Power(2,3,3)<<endl<<PowerByLog(2,3,3);

}
