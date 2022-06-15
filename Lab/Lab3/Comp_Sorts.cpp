#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define ll long long

void Comp_selectionSort(int a[], int n, ll &cnt_compare)
{
    for (int i = 0; ++cnt_compare && i < n - 1; i++)
    {
        int pos = i;
        for (int j = i + 1; ++cnt_compare && j < n; j++)
            if (++cnt_compare && a[j] < a[pos])
                pos = j;
        swap(a[i], a[pos]);
    }
}
void Comp_insertionSort(int a[], int n, ll &cnt_compare)
{
    for (int i = 1; ++cnt_compare && i < n; i++)
    {
        int key = a[i];
        int j = i - 1;

        while ((++cnt_compare && key < a[j]) && (++cnt_compare && j >= 0))
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}
// BUBBLE SORT
void Comp_bubbleSort(int a[], int n, ll &cnt_compare)
{
    for (int i = 0; ++cnt_compare && i < n - 1; i++)
        for (int j = 0; ++cnt_compare && j < n - i - 1; j++)
            if (++cnt_compare && a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
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
void Comp_shakerSort(int a[], int n, ll &cnt_compare)
{
    int left = 0, right = n - 1, k = 0;
    while (left < right && ++cnt_compare)
    {
        bool check = false;
        for (int i = left; ++cnt_compare && i < right; i++)
        {
            if (++cnt_compare && a[i] > a[i + 1])
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
        for (int i = right; ++cnt_compare && i > left; i--)
        {
            if (++cnt_compare && a[i] < a[i - 1])
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
void Comp_shellSort(int a[], int n, ll &cnt_compare)
{
    int interval = 0;
    for (interval = n / 2; ++cnt_compare && interval >= 1; interval /= 2)
    {
        for (int i = interval; ++cnt_compare && i < n; i++)
        {
            int tmp = a[i];
            int j = 0;
            for (j = i; ++cnt_compare && j >= interval && ++cnt_compare && a[j - interval] > tmp; j -= interval)
                a[j] = a[j - interval];
            a[j] = tmp;
        }
    }
}
void Comp_countingSort(int a[], int n, ll &cnt_compare)
{
    int max = *max_element(a, a + n);
    int min = *min_element(a, a + n);
    vector<int> count(max - min + 1);
    vector<int> res(n);
    for (int i = 0; ++cnt_compare && i < n; i++)
        count[a[i] - min]++;
    for (int i = 1; ++cnt_compare && i < count.size(); i++)
        count[i] += count[i - 1];
    for (int i = n - 1; ++cnt_compare && i >= 0; i--)
    {
        res[count[a[i] - min] - 1] = a[i];
        count[a[i] - min]--;
    }
    for (int i = 0; ++cnt_compare && i < n; i++)
        a[i] = res[i];
}
void Comp_radixSort(int a[], int n, ll &cnt_compare)
{
    int *b = new int[n];
    int m = a[0], exp = 1;

    // get max
    for (int i = 1; i < n; i++)
        if (a[i] > m)
            m = a[i];

    while (++cnt_compare && m / exp > 0)
    {
        int bucket[10] = {0};
        // Counting sort
        for (int i = 0; ++cnt_compare && i < n; i++)
            bucket[a[i] / exp % 10]++;
        for (int i = 1; ++cnt_compare && i < 10; i++)
            bucket[i] += bucket[i - 1];
        for (int i = n - 1; ++cnt_compare && i >= 0; i--)
            b[--bucket[a[i] / exp % 10]] = a[i];
        for (int i = 0; ++cnt_compare && i < n; i++)
            a[i] = b[i];
        exp *= 10;
    }
    delete[] b;
}

void Comp_selectionSortForFlashSort(vector<int> a, int n, ll &cnt_compare)
{
    int i, j, min_idx;

    for (i = 0; ++cnt_compare && i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; ++cnt_compare && j < n; j++)
            if (++cnt_compare && a[j] < a[min_idx])
                min_idx = j;

        int tmp = a[min_idx];
        a[min_idx] = a[i];
        a[i] = tmp;
    }
}
void Comp_flashSort(int a[], int n, ll &cnt_compare)
{
    int max, bucket = 10000, divider, i, j, k;
    vector<int> *B = new vector<int>[bucket];
    max = *max_element(a, a + n);
    divider = (float(max + 1) / bucket);
    for (i = 0; ++cnt_compare && i < n; i++)
    {
        j = a[i] / divider;
        B[j].push_back(a[i]);
    }

    for (i = 0; ++cnt_compare && i < bucket; i++)
        Comp_selectionSortForFlashSort(B[i], B[i].size(), cnt_compare);

    k = 0;
    for (i = 0; ++cnt_compare && i < bucket; i++)
        for (j = 0; ++cnt_compare && j < B[i].size(); j++)
            a[k++] = B[i][j];
}