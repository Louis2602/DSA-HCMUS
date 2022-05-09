#include <iostream>

using namespace std;

void radixSort(int a[], int n)
{
    int *b = new int[n];
    int m = a[0], exp = 1;

    // get max
    for (int i = 1; i < n; i++)
        if (a[i] > m)
            m = a[i];

    while (m / exp > 0)
    {
        int bucket[10] = {0};
        // Counting sort
        for (int i = 0; i < n; i++)
            bucket[a[i] / exp % 10]++;
        for (int i = 1; i < 10; i++)
            bucket[i] += bucket[i - 1];
        for (int i = n - 1; i >= 0; i--)
            b[--bucket[a[i] / exp % 10]] = a[i];
        for (int i = 0; i < n; i++)
            a[i] = b[i];
        exp *= 10;
    }
    delete[] b;
}
void print(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << '\n';
}
int main()
{
    int a[] = {170, 45, 75, 99, 802, 24, 2, 66};
    int n = sizeof(a) / sizeof(a[0]);
    cout << "Before: ";
    print(a, n);
    cout << "After sorting: ";
    radixSort(a, n);
    print(a, n);
    return 0;
}