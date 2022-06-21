#include <iostream>
using namespace std;

int partition(int a[], int l, int r)
{
    int pivot = a[l];
    int last1 = l;
    int first_unknown = l + 1;
    while (first_unknown <= r)
    {
        if (a[first_unknown] < pivot)
        {
            swap(a[first_unknown], a[last1 + 1]);
            last1++;
        }
        first_unknown++;
    }
    swap(a[l], a[last1]);
    return last1;
}

void quickSort(int a[], int l, int r)
{
    if (l < r)
    {
        int p = partition(a, l, r);
        quickSort(a, l, p - 1);
        quickSort(a, p + 1, r);
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
    int a[] = {5, 2, 3, 4, 1, 6};
    int n = 6;
    quickSort(a, 0, n - 1);
    print(a, n);
    return 0;
}
