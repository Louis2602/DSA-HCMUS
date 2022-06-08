#include <iostream>
#include <string>
using namespace std;

void bubbleSort(int a[], int n);
void AlgorithmMode(int algoMode)
{
    cout << '\n';
    cout << "===============================\n";
    cout << "|        ALGORITHM MODE       |\n";
    cout << "===============================\n";
    cout << "|1. Selection Sort            |\n";
    cout << "|2. Insertion Sort            |\n";
    cout << "|3. Bubble Sort               |\n";
    cout << "|4. Shaker Sort               |\n";
    cout << "|5. Shell Sort                |\n";
    cout << "|6. Heap Sort                 |\n";
    cout << "|7. Merge Sort                |\n";
    cout << "|8. Quick Sort                |\n";
    cout << "|9. Counting Sort             |\n";
    cout << "|10. Radix Sort               |\n";
    cout << "|11. Flash Sort               |\n";
    cout << "===============================\n";
    cout << "Choose your algorithm: ";
    cin >> algoMode;
    int a[] = {5, 3, 4, 2, 6, 1};
    int n = 5;
    switch (algoMode)
    {
    case 1:
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
int main()
{
    int option, algoMode;
    string input_file, input_order;
    cout << "===============================\n";
    cout << "|       SORTING PROGRAM       |\n";
    cout << "===============================\n";
    cout << "|1. Sorting Algorithm         |\n";
    cout << "|2. Input file                |\n";
    cout << "|3. Input size                |\n";
    cout << "|4. Input order               |\n";
    cout << "|0. Exit                      |\n";
    cout << "===============================\n";
    int input_size;
    cout << "Option: ";
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
        cout << "Exit successful!\n";
        exit(1);
        break;
    }

    return 0;
}
void bubbleSort(int a[], int n)
{
    for (int i = 1; i < n; i++)
        for (int j = n - 1; j >= i; j--)
            if (a[j] < a[j - 1])
                swap(a[j], a[j - 1]);
    cout << "OUTPUT: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}