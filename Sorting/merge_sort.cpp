// O(nlog2(n))
#include <iostream>
using namespace std;
void merge(int arr[], int low, int high, int mid)
{
    int i, j, k, c[50];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            c[k] = arr[i];
            k++;
            i++;
        }
        else
        {
            c[k] = arr[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        c[k] = arr[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        c[k] = arr[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)
        arr[i] = c[i];
}
void mergeSort(int a[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, r, m);
    }
}
void print(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << '\n';
}
int main()
{
    int a[] = {12, 11, 13, 5, 6, 3};
    int n = sizeof(a) / sizeof(a[0]);
    cout << "Before: ";
    print(a, n);
    cout << "After sorting: ";
    mergeSort(a, 0, n - 1);
    print(a, n);
    return 0;
}