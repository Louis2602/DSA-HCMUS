#include <iostream>
#include <fstream>

using namespace std;

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
void print(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << '\n';
}
int main()
{
    int *a, n;
    ifstream fi("input.txt");
    ofstream fo("output.txt");
    fi >> n;
    a = new int[n];
    for(int i=0; i<n; i++)
        fi >> a[i];
    cout << n;
    //cout << "Before: ";
    //print(a, n);
    //cout << "After sorting: ";
    quickSort(a, 0, n - 1);
    for(int i=0; i<n; i++)
        fo << a[i] << " ";
    fi.close();
    fo.close();
        
    //print(a, n);
    return 0;
}
