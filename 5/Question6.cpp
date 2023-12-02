#include <iostream>
using namespace std;


void divMod(int x,int y,int &ans,int &rem)
{
    if(rem < y)
    {
        return;
    }
    rem = rem - y;
    ans++;
    return divMod(x,y,ans,rem);

}
void divModLog(int A, int B, int &qu, int &rem) {
    if (A < B) {
        qu = 0;
        rem = A;
    } else {
        int multiple = 1;
        int tempB = B;

        while (A >= (tempB << 1)) {
            tempB <<= 1;
            multiple <<= 1;
        }

        divModLog(A - tempB, B, qu, rem);
        qu += multiple;
    }
}

int main() {
    int A = 20;
    int B = 4;
    int quotient = 0, remainder = A;

    // task 1
    divMod(A, B, quotient , remainder);

    cout << "A / B = " << quotient << endl << "A % B = " << remainder <<endl;
    // task 2
    int a = 20;
    int b = 4;
    int qu = 0, rem = a;

    divModLog(a, b, qu , rem);

    cout << "A / B = " << qu << endl << "A % B = " << rem<<endl;
    

}
