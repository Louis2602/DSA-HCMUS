#include <iostream>
using namespace std;

int gcd_1(int a, int b) {
    if(b == 0)
        return a;
    return gcd_1(b, a % b);
}

int gcd_2(int a, int b) {
    if(a == 0 || b == 0)
        return a + b;
    while(a != b) {
        if(a > b)
            a-=b;
        else
            b-=a;
    }
    return a;
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << "Fast: ";
    cout << gcd_2(a, b);
    cout << "\nSlow: ";
    cout << gcd_1(a, b);
    return 0;
}
