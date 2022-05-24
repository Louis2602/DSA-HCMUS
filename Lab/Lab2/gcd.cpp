#include <iostream>
using namespace std;

int gcd_fast_euclide(int a, int b) {
    if(b == 0)
        return a;
    return gcd_fast_euclide(b, a % b);
}

int gcd_normal(int a, int b) {
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
    cout << gcd_fast_euclide(a, b);
    cout << "\nSlow: ";
    cout << gcd_normal(a, b);
    return 0;
}
