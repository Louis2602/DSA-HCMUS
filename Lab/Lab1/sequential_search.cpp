#include <iostream>
using namespace std;

int search(int a[], int n, int k) {
    for(int i=0; i<n; i++) {
        if(a[i] == k)
            return i;
    }
    return -1;
}

int main() {
    int a[] = {1,2,3,45,5,4,10};
    int n = 7;
    int k;
    cout << "Nhap mot so can tim: ";
    cin >> k;
    cout << search(a, n, k);
    return 0;
}
