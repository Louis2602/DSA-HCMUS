#include <iostream>
using namespace std;

int squaresum_recursion(int n, int &cc, int &ca) {
    if(++cc && n < 1)
        return 0;
    else 
        return n*n + squaresum_recursion(n-1, cc, ++ca);
}

int main() {
    int n;
    cin >> n;
    int count_compare = 0, count_assign = 0;
    cout << squaresum_recursion(n, count_compare, count_assign);
    return 0;
}
