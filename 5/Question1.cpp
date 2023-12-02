#include<iostream>
#include<math.h>
using namespace std;
int SumNatural(int n);
int SumOdd(int n);
int SumTwoPower(int n);
int main()
{
    SumNatural(5);

}
// 1
int SumNatural(int n)
{
    if(n == 0)
    {
        return 0;
    }
    return n + SumNatural(n - 1);
}
// 2
int SumOdd(int n)
{
    if(n == 1)
    {
        return 1;
    }
    return n + SumOdd(n - 2);
}
// 3
int SumTwoPower(int n)
{
    if(n == 0)
    {
        return 1;
    }
    return pow(2,n) + SumTwoPower(n - 1);
}
// 4
int SumThreePower(int n)
{
    if(n == 0)
    {
        return 1;
    }
    return pow(3,n) + SumThreePower(n - 1);
}
// 5
int SumThreeDivide(int n)
{
    if(n == 0)
    {
        return 1;
    }
    return n + SumThreeDivide(n/3);
}
// 6
int SumTwoDivide(int n)
{
    if(n == 0)
    {
        return 1;
    }
    return n + SumTwoDivide(n/2);
}
