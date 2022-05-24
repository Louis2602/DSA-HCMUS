#include <iostream>
using namespace std;

int squaresum_recursion(int n) {
    if (n < 1)
        return 0;
    return n*n + squaresum_recursion(n - 1);
}


int main() {
    int n;
    cout << "Nhap n: ";
    cin >> n;
    int res = squaresum_recursion(n);
    cout << "Result = " << res;
    return 0;
}
