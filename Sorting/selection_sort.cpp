#include <iostream>
using namespace std;

void selection_sort(int a[], int n)
{
    int minIndex;
    for (int i = 0; i < n - 1; i++)
    {
        minIndex = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[minIndex])
                minIndex = j;
        swap(a[minIndex], a[i]);
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
    int a[] = {6, 3, 5, 2, 8, 1};
    int n = sizeof(a) / sizeof(a[0]);
    selection_sort(a, n);
    print(a, n);
    return 0;
}