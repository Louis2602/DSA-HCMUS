#include <iostream>
using namespace std;

int countMostCommon(int a[], int n) {
    int cnt[10] = {0};
    for(int i=0; i<n; i++) {
        cnt[a[i]]++;
    }
    int max = cnt[0];
    int index = 0;
    for(int i=0; i<n; i++) {
        if(cnt[i] > max) {
            max = cnt[i];
            index = i;
        }
    }
    return max > n / 2 ? index : -1;
}

int main() {
    int a[] = {1,1,3,1,1,5,1,2,1};
    int n = sizeof(a) / sizeof(a[0]);
    if(countMostCommon(a, n) == -1)
        cout << "NO";
    else cout << countMostCommon(a, n);
    return 0;
}
