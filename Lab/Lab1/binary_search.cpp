#include <iostream>
using namespace std;

int search(int a[], int n, int k) {
    int l = 0, r = n - 1;
    while(l <= r) {
        int m = l + (r - l) / 2;
        if(a[m] == k)
            return m;
        if(a[m] > k) 
            r = m - 1;
        else l = m + 1;
    }
    return -1;
}

int main() {
    int a[] = {1, 3, 4, 5, 7, 9, 11, 15};
    int n = 8;
    int k = 2;
    cout << search(a, n, k);
    return 0;
}
