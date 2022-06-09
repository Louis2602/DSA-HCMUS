#include <iostream>
#include "DataGenerator.cpp"
#include <string>
using namespace std;

void selectionSort(int a[], int n);
void bubbleSort(int a[], int n);
void AlgorithmMode(int algoMode);
void displayMenu();
int main()
{
    displayMenu();
    return 0;
}
void displayMenu()
{
    int option, algoMode;
    string input_file, input_order;
    cout << "\t\t===============================\n";
    cout << "\t\t|       SORTING PROGRAM       |\n";
    cout << "\t\t===============================\n";
    cout << "\t\t|1. Sorting Algorithm         |\n";
    cout << "\t\t|2. Input file                |\n";
    cout << "\t\t|3. Input size                |\n";
    cout << "\t\t|4. Input order               |\n";
    cout << "\t\t|0. Exit                      |\n";
    cout << "\t\t===============================\n";
    int input_size;
    cout << "\t\tOption: ";
    cin >> option;
    switch (option)
    {
    case 1:
        AlgorithmMode(algoMode);
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 0:
        cout << "\t\tExit successful!\n";
        exit(1);
        break;
    }
}
void AlgorithmMode(int algoMode)
{
    cout << '\n';
    cout << "\t\t================================\n";
    cout << "\t\t|        TNT-B        |\n";
    cout << "\t\t================================\n";
    cout << "\t\t|1.  Selection Sort            |\n";
    cout << "\t\t|2.  Insertion Sort            |\n";
    cout << "\t\t|3.  Bubble Sort               |\n";
    cout << "\t\t|4.  Shaker Sort               |\n";
    cout << "\t\t|5.  Shell Sort                |\n";
    cout << "\t\t|6.  Heap Sort                 |\n";
    cout << "\t\t|7.  Merge Sort                |\n";
    cout << "\t\t|8.  Quick Sort                |\n";
    cout << "\t\t|9.  Counting Sort             |\n";
    cout << "\t\t|10. Radix Sort                |\n";
    cout << "\t\t|11. Flash Sort                |\n";
    cout << "\t\t================================\n";
    cout << "\t\tChoose your algorithm: ";
    cin >> algoMode;
    int a[] = {5, 3, 4, 2, 6, 1};
    int n = 5;
    switch (algoMode)
    {
    case 1:
        selectionSort(a, n);
        break;
    case 2:
        break;
    case 3:
        bubbleSort(a, n);
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        break;
    case 7:
        break;
    case 8:
        break;
    case 9:
        break;
    case 10:
        break;
    case 11:
        break;
    }
}
void selectionSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i; 
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[min_idx])
                min_idx = j;
        swap(a[min_idx], a[i]);
    }
    cout << "\t\tOUTPUT: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}
void bubbleSort(int a[], int n)
{
    for (int i = 1; i < n; i++)
        for (int j = n - 1; j >= i; j--)
            if (a[j] < a[j - 1])
                swap(a[j], a[j - 1]);
    cout << "\t\tOUTPUT: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}
