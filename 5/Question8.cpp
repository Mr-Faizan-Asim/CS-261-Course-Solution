#include <iostream>
#include <vector>

using namespace std;
vector<int> tempVector;
//3
int sumMem(int n) {
    switch (n) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 3;
        default:
            if (tempVector[n] != 0) {
                return tempVector[n];
            }
            tempVector[n] = sumMem(n - 1) + sumMem(n - 2) +sumMem(n - 3);
            return tempVector[n];
    }
}
//1
int sum1(int index) {
    if (index == 1) {
        return 1;
    }
    if (index == 2) {
        return 2;
    }
    if (index == 3) {
        return 3;
    }
    return sum1(index - 1) + sum1(index - 2) + sum1(index - 3);
}
//2
int sumBottomUp(int index) {
    if (index <= 0) {
        return 0;
    }
    if (index == 1) {
        return 1;
    }
    if (index == 2) {
        return 2;
    }
    if (index == 3) {
        return 3;
    }

    vector<int> temp(index + 1);
    temp[1] = 1;
    temp[2] = 2;
    temp[3] = 3;

    for (int i = 4; i <= index; i++) {
        temp[i] = temp[i - 1] + temp[i - 2] + temp[i - 3];
    }

    return temp[index];
}

int main() {
    int index = 7;
    int d = 7; 

    tempVector.resize(d + 1, 0);
    tempVector[1] = 1;
    tempVector[2] = 2;
    tempVector[3] = 3;

    for (int i = 1; i <= index; i++) {
        cout << sum1(i) << ",";
    }
    cout<<endl;
    for (int i = 1; i <= index; i++) {
        cout << sumBottomUp(i) << ",";
    }
  
    cout<<endl;
    for (int i = 1; i <= d; i++) {
        cout << sumMem(i) << ",";
    }
}
