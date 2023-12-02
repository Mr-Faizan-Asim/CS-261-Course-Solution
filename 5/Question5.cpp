#include<iostream>
#include<math.h>
using namespace std;

int Add(int x, int y)
{
    if(y ==0 )
    {
        return 0;
    }
    return x + Add(x,y-1);
}
int MUL(int A,int B)
{
    return Add(A,B);
}

int MULTLOG2Y(int A, int B) {
    if (B == 0) {
        return 0;
    } else if (B % 2 == 0) {
        int half_product = MULTLOG2Y(A, B /2 );
        return Add(half_product, half_product);
    } else {
        int half_product = MULTLOG2Y(A, (B - 1)/2);
        return Add(half_product, Add(half_product, A));
    }
}


int main()
{
    cout<<Add(2,3) << endl << MUL(2,7)<<endl;
    cout<<MULTLOG2Y(2,3);
}
