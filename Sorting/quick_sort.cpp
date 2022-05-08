#include <iostream>
using namespace std;

int partition(int a[], int low, int high)
{
    int pivot = a[high];
    int left = low;
    int right = high - 1;
    while (1)
    {
        while (left <= right && a[left] < pivot)
            left++;
        while (right >= left && a[right] > pivot)
            right--;
        if (left >= right)
            break;
        swap(a[left], a[right]);
        left++;
        right--;
    }
    swap(a[left], a[high]);
    return left;
}
void quickSort(int a[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(a, low, high);
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
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