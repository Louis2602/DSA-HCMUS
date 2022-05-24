#include <iostream>
using namespace std;

int somesum(int n) {
    int sum = 0, i = 1, j = 0;
    while(i <= n) {
        j = n - 1;
        while(j <= i*i) {
            sum += i*j;
            j++;
        }
        i++;
    }
    return sum;
}

int main() {
    int n;
    cin >> n;
    int ans = somesum(n);
    cout << "Result: " << ans;
    return 0;
}
