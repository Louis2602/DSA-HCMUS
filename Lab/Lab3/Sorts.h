#pragma once
#include <string>
#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

void selectionSort(int a[], int n)
{
}
void insertionSort(int a[], int n)
{
}
void bubbleSort(int a[], int n, string params)
{
    auto start = high_resolution_clock::now();
    for (int i = 1; i < n; i++)
        for (int j = n - 1; j >= i; j--)
            if (a[j] < a[j - 1])
                swap(a[j], a[j - 1]);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start) / 1e6;
    if (params == "-time")
        cout << "Running time: " << duration.count() << " seconds" << '\n';
    else if (params == "-comp")
        cout << "Comparisons: " << '\n';
    else
    {
        cout << "Running time: " << duration.count() << " seconds" << '\n';
        cout << "Comparisons: " << '\n';
    }
}
// HEAP SORT
void heapRebuild(int *a, int n, int i)
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
        heapRebuild(a, n, largest);
    }
}
void heapSort(int *a, int n, string params)
{
    auto start = high_resolution_clock::now();
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapRebuild(a, n, i);
    for (int i = n - 1; i > 0; i--)
    {
        swap(a[0], a[i]);
        heapRebuild(a, i, 0);
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start) / 1e6;
    if (params == "-time")
        cout << "Running time: " << duration.count() << " seconds" << '\n';
    else if (params == "-comp")
        cout << "Comparisons: " << '\n';
    else
    {
        cout << "Running time: " << duration.count() << " seconds" << '\n';
        cout << "Comparisons: " << '\n';
    }
}
// MERGE SORT
void merge(int *a, int low, int high, int mid)
{
    int i, j, k;
    int *c = new int[high + 1];
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
}
void mergeSort(int *a, int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, r, m);
    }
}
// QUICK SORT
int partition(int *a, int l, int r)
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
void quickSort(int *a, int low, int high)
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