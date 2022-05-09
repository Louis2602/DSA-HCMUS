#include <iostream>
using namespace std;

int partition(int a[], int l, int r)
{
    int pivot = a[l];
    int i = l + 1;
    int j = r;
    while (i <= j)
    {
        while (i <= j && a[i] < pivot)
            i++;
        while (i <= j && a[j] > pivot)
            j--;
        if (i < j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    swap(a[l], a[j]);
    return j;
}
void quickSort(int a[], int low, int high)
{
    if (low < high)
    {
        int k = partition(a, low, high);
        quickSort(a, low, k - 1);
        quickSort(a, k + 1, high);
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
    quickSort(a, 0, n - 1);
    print(a, n);
    return 0;
}