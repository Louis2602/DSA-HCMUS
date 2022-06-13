#include <iostream>
using namespace std;

#define ll long long

void Comp_selectionSort(int a[], int n)
{
}
void Comp_insertionSort(int a[], int n)
{
}
// BUBBLE SORT
void Comp_bubbleSort(int a[], int n, ll &cnt_compare)
{
    for (int i = 1; ++cnt_compare && i < n; i++)
        for (int j = n - 1; ++cnt_compare && j >= i; j--)
            if (++cnt_compare && a[j] < a[j - 1])
                swap(a[j], a[j - 1]);
}
// HEAP SORT
void Comp_heapRebuild(int a[], int n, int i, ll &cnt_compare)
{
    int largest = i;   // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
    // If left child is larger than root
    if (++cnt_compare && l < n && ++cnt_compare && a[l] > a[largest])
        largest = l;
    // If right child is larger than largest so far
    if (++cnt_compare && r < n && ++cnt_compare && a[r] > a[largest])
        largest = r;
    // If largest is not root
    if (++cnt_compare && largest != i)
    {
        swap(a[i], a[largest]);
        Comp_heapRebuild(a, n, largest, cnt_compare);
    }
}
void Comp_heapSort(int a[], int n, ll &cnt_compare)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; ++cnt_compare && i >= 0; i--)
        Comp_heapRebuild(a, n, i, cnt_compare);
    for (int i = n - 1; ++cnt_compare && i > 0; i--)
    {
        swap(a[0], a[i]);
        Comp_heapRebuild(a, i, 0, cnt_compare);
    }
}
// MERGE SORT
void Comp_merge(int a[], int low, int high, int mid, ll &cnt_compare)
{
    int i, j, k;
    int *c = new int[1000000];
    i = low;
    k = low;
    j = mid + 1;
    while (++cnt_compare && i <= mid && ++cnt_compare && j <= high)
    {
        if (++cnt_compare && a[i] < a[j])
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
    while (++cnt_compare && i <= mid)
    {
        c[k] = a[i];
        k++;
        i++;
    }
    while (++cnt_compare && j <= high)
    {
        c[k] = a[j];
        k++;
        j++;
    }
    for (i = low; ++cnt_compare && i < k; i++)
        a[i] = c[i];
    delete[] c;
}
void Comp_mergeSort(int a[], int l, int r, ll &cnt_compare)
{
    if (++cnt_compare && l < r)
    {
        int m = (l + r) / 2;
        Comp_mergeSort(a, l, m, cnt_compare);
        Comp_mergeSort(a, m + 1, r, cnt_compare);
        Comp_merge(a, l, r, m, cnt_compare);
    }
}
// QUICK SORT
int Comp_partition(int a[], int l, int r, ll &cnt_compare)
{
    int first = l, last = r;
    int pivot = a[first];
    int last1 = first;
    int first_unknown = first + 1;
    while (++cnt_compare && first_unknown <= last)
    {
        if (++cnt_compare && a[first_unknown] < pivot)
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

void Comp_quickSort(int a[], int l, int r, ll &cnt_compare)
{
    if (++cnt_compare && l < r)
    {
        int p = Comp_partition(a, l, r, cnt_compare);
        Comp_quickSort(a, l, p - 1, cnt_compare);
        Comp_quickSort(a, p + 1, r, cnt_compare);
    }
}
void Comp_shakerSort(int a[], int n)
{
}
void Comp_shellSort(int a[], int n)
{
}
void Comp_CountingSort(int a[], int n)
{
}
void Comp_radixSort(int a[], int n)
{
}
void Comp_flashSort(int a[], int n)
{
}
