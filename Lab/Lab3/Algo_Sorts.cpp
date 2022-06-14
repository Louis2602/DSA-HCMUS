#include <iostream>
using namespace std;

void Algo_selectionSort(int a[], int n)
{
}
void Algo_insertionSort(int a[], int n)
{
}
// BUBBLE SORT
void Algo_bubbleSort(int a[], int n)
{
    for (int i = 1; i < n; i++)
        for (int j = n - 1; j >= i; j--)
            if (a[j] < a[j - 1])
                swap(a[j], a[j - 1]);
}
// HEAP SORT
void Algo_heapRebuild(int a[], int n, int i)
{
    int largest = i;   // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
    // If left child is larger than root
    if (l < n && a[l] > a[largest])
        largest = l;
    // If right child is larger than largest so far
    if (r < n && a[r] > a[largest])
        largest = r;
    // If largest is not root
    if (largest != i)
    {
        swap(a[i], a[largest]);
        Algo_heapRebuild(a, n, largest);
    }
}
void Algo_heapSort(int a[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        Algo_heapRebuild(a, n, i);
    for (int i = n - 1; i > 0; i--)
    {
        swap(a[0], a[i]);
        Algo_heapRebuild(a, i, 0);
    }
}
// MERGE SORT
void Algo_merge(int a[], int low, int high, int mid)
{
    int i, j, k;
    int *c = new int[1000000];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            c[k] = a[i];
            k++;
            i++;
        }
        else
        {
            c[k] = a[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        c[k] = a[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        c[k] = a[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)
        a[i] = c[i];
    delete[] c;
}
void Algo_mergeSort(int a[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        Algo_mergeSort(a, l, m);
        Algo_mergeSort(a, m + 1, r);
        Algo_merge(a, l, r, m);
    }
}
// QUICK SORT
int Algo_partition(int a[], int l, int r)
{
    int mid = l + (r - l) / 2;
    if (a[l] > a[mid] && a[mid] > a[r])
        swap(a[l], a[mid]);
    else if (a[l] > a[r] && a[r] > a[mid])
        swap(a[l], a[r]);
    else if (a[mid] > a[l] && a[l] < a[r])
        swap(a[l], a[mid]);
    else if (a[r] > a[l] && a[l] > a[mid])
        swap(a[r], a[l]);

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

void Algo_quickSort(int a[], int l, int r)
{
    if (l < r)
    {
        int p = Algo_partition(a, l, r);
        Algo_quickSort(a, l, p - 1);
        Algo_quickSort(a, p + 1, r);
    }
}

void Algo_shakerSort(int a[], int n)
{
}
void Algo_shellSort(int a[], int n)
{
}
void Algo_CountingSort(int a[], int n)
{
}
void Algo_radixSort(int a[], int n)
{
}
void Algo_flashSort(int a[], int n)
{
}
