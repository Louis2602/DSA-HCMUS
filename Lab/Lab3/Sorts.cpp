#pragma once
#include <string>
#include <sstream>
#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

template <class T>
void selectionSort(int a[], int n)
{
}
void insertionSort(int a[], int n)
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
void Comp_bubbleSort(int a[], int n, int &cnt_compare)
{
    for (int i = 1; ++cnt_compare && i < n; i++)
        for (int j = n - 1; ++cnt_compare && j >= i; j--)
            if (++cnt_compare && a[j] < a[j - 1])
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
void Comp_heapRebuild(int a[], int n, int i, int &cnt_compare)
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
void Comp_heapSort(int a[], int n, int &cnt_compare)
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
void Comp_merge(int a[], int low, int high, int mid, int &cnt_compare)
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
void Comp_mergeSort(int a[], int l, int r, int &cnt_compare)
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

void shakerSort(int a[], int n)
{
}
void shellSort(int a[], int n)
{
}
void CountingSort(int a[], int n)
{
}
void radixSort(int a[], int n)
{
}
void flashSort(int a[], int n)
{
}
