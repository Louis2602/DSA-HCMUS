#include <iostream>
using namespace std;

int partition(int a[], int l, int r)
{
    int first = l, last = r;
    int pivot = a[first];
    int last1 = first;
    int first_unknown = first + 1;
    while (first_unknown <= last)
    {
        if (a[first_unknown] < pivot)
        {
            swap(a[first_unknown], a[last1 + 1]);
            last1++;
            first_unknown++;
        }
        else
            first_unknown++;
    }
    swap(a[first], a[last1]);
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
