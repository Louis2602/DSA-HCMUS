// O(nlog2(n))
#include <iostream>

using namespace std;

void heapRebuild(int pos, int a[], int n)
{
    int k = pos;
    bool isHeap = false;
    while (!isHeap && 2 * k + 1 < n)
    {
        int j = 2 * k + 1; // first element
        // has enough 2 elements
        if (j < n - 1)
            if (a[j] < a[j + 1])
                j++; // position of the larger between A[2 * k + 1] and A[2 * k + 2]
        if (a[k] >= a[j])
            isHeap = true;
        else
        {
            swap(a[k], a[j]);
            k = j;
        }
    }
}
void heapConstruct(int a[], int n)
{
    int i = (n - 1) / 2;
    while (i >= 0)
    {
        heapRebuild(i, a, n);
        i--;
    }
}

void heapSort(int a[], int n)
{
    heapConstruct(a, n);
    int r = n - 1;
    while (r > 0)
    {
        swap(a[0], a[r]);
        heapRebuild(0, a, r);
        r--;
    }
}
void print(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << '\n';
}
int main()
{
    int a[] = {2, 9, 7, 6, 5, 8};
    int n = sizeof(a) / sizeof(a[0]);
    heapSort(a, n);
    print(a, n);
    return 0;
}