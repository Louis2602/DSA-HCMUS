#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void Algo_selectionSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int pos = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[pos])
                pos = j;
        swap(a[i], a[pos]);
    }
}
void Algo_insertionSort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;
        while (key < a[j] && j >= 0)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}
// BUBBLE SORT
void Algo_bubbleSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
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
    int left = 0, right = n - 1, k = 0;
    while (left < right)
    {
        bool check = false;
        for (int i = left; i < right; i++)
        {
            if (a[i] > a[i + 1])
            {
                check = true;
                swap(a[i], a[i + 1]);
                k = i;
            }
        }
        if (!check)
            return;
        right = k;
        check = false;
        for (int i = right; i > left; i--)
        {
            if (a[i] < a[i - 1])
            {
                check = true;
                swap(a[i], a[i - 1]);
                k = i;
            }
        }
        if (!check)
            return;
        left = k;
    }
}
void Algo_shellSort(int a[], int n)
{
    int interval = 0;
    for (interval = n / 2; interval >= 1; interval /= 2)
    {
        for (int i = interval; i < n; i++)
        {
            int tmp = a[i];
            int j = 0;
            for (j = i; j >= interval && a[j - interval] > tmp; j -= interval)
            {
                a[j] = a[j - interval];
            }
            a[j] = tmp;
        }
    }
}
void Algo_countingSort(int a[], int n)
{
    int max = *max_element(a, a + n);
    int min = *min_element(a, a + n);
    vector<int> count(max - min + 1);
    vector<int> res(n);
    for (int i = 0; i < n; i++)
    {
        count[a[i] - min]++;
    }
    for (int i = 1; i < count.size(); i++)
    {
        count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        res[count[a[i] - min] - 1] = a[i];
        count[a[i] - min]--;
    }
    for (int i = 0; i < n; i++)
    {
        a[i] = res[i];
    }
}
void Algo_radixSort(int a[], int n)
{
    int *b = new int[n];
    int m = a[0], exp = 1;

    // get max
    for (int i = 1; i < n; i++)
        if (a[i] > m)
            m = a[i];

    while (m / exp > 0)
    {
        int bucket[10] = {0};
        // Counting sort
        for (int i = 0; i < n; i++)
            bucket[a[i] / exp % 10]++;
        for (int i = 1; i < 10; i++)
            bucket[i] += bucket[i - 1];
        for (int i = n - 1; i >= 0; i--)
            b[--bucket[a[i] / exp % 10]] = a[i];
        for (int i = 0; i < n; i++)
            a[i] = b[i];
        exp *= 10;
    }
    delete[] b;
}
void Algo_selectionSortForFlashSort(vector<int> &a, int n)
{
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (a[j] < a[min_idx])
                min_idx = j;

        int tmp = a[min_idx];
        a[min_idx] = a[i];
        a[i] = tmp;
    }
}
void Algo_flashSort(int a[], int n)
{
    int max, bucket = 10000, divider, i, j, k;
    vector<int> *B = new vector<int>[bucket];
    max = *max_element(a, a + n);
    divider = (float(max + 1) / bucket);
    for (i = 0; i < n; i++)
    {
        j = a[i] / divider;
        B[j].push_back(a[i]);
    }

    for (i = 0; i < bucket; i++)
        Algo_selectionSortForFlashSort(B[i], B[i].size());

    k = 0;
    for (i = 0; i < bucket; i++)
        for (j = 0; j < B[i].size(); j++)
            a[k++] = B[i][j];
}
