#include <iostream>
#include <fstream>
#include <chrono>
#include "DataGenerator.cpp"

using namespace std;
using namespace std::chrono;

void selectionSort(int *a, int n);
void insertionSort(int *a, int n);
void bubbleSort(int *a, int n, string params);
void heapSort(int *a, int n, string params);
void mergeSort(int *a, int l, int r);
void quickSort(int *a, int low, int high);
void shakerSort(int *a, int n);
void shellSort(int *a, int n);
void CountingSort(int *a, int n);
void radixSort(int *a, int n);
void flashSort(int *a, int n);
void executeCommand1(string, string, string);
void executeCommand2(string, string, string);
void executeCommand3(string, string, string);
void executeCommand4(string, string, string);
void executeCommand5(string, string, string);
void AlgorithmMode();
void ComparisionMode();
int main(int argc, char *argv[])
{
    string algorithm, input_file, input_size, input_order, output_params;
    // Algorithm Mode
    if (argc < 5)
        cout << "[ERROR]: COMMAND NOT FOUND!";
    if (string(argv[1]) == "-a")
    {
        // Command 1
        if (argc == 5)
        {
            algorithm = argv[2];
            input_file = argv[3];
            output_params = argv[4];
            executeCommand1(algorithm, input_file, output_params);
        }
        // Command 2
        else if (argc == 6)
        {
            algorithm = argv[2];
            input_size = argv[3];
            input_order = argv[4];
            output_params = argv[5];
        }
        // Command 3
        else if (argc == 5 && isdigit(atoi(argv[4])))
        {
            algorithm = argv[2];
            input_size = argv[3];
            output_params = argv[4];
        }
        else
        {
            cout << "[ERROR]: COMMAND NOT FOUND!";
            exit(1);
        }
    }
    // Comparison Mode
    string algorithm1, algorithm2;
    if (string(argv[1]) == "-c")
    {
        // Command 4
        if (argc == 5)
        {

            algorithm1 = argv[2];
            algorithm2 = argv[3];
            input_file = argv[4];
        }
        // Command 5
        else if (argc == 6)
        {
            algorithm1 = argv[2];
            algorithm2 = argv[3];
            input_size = argv[4];
            input_order = argv[5];
        }
        else
        {
            cout << "[ERROR]: COMMAND NOT FOUND!";
            exit(1);
        }
    }
    return 0;
}
void readFile(string input_file, int *&a, int &n)
{
    ifstream fi(input_file);
    int i = 0;
    fi >> n;
    a = new int[n];
    for (int i = 0; i < n; i++)
        fi >> a[i];
    fi.close();
}
void writeFile(string output_file, int *a, int n)
{
    ofstream fo(output_file);
    for (int i = 0; i < n; i++)
        fo << a[i] << " ";
    fo.close();
}
void executeCommand1(string algorithm, string input_file, string output_params)
{
    int *array_input, n;
    cout << "============================\n";
    cout << "|      ALGORITHM MODE      |\n";
    cout << "============================\n";
    cout << "Algorithm: " << algorithm << "\n";

    readFile(input_file, array_input, n);

    if (algorithm == "bubble-sort")
        bubbleSort(array_input, n, output_params);
    else if (algorithm == "heap-sort")
        heapSort(array_input, n, output_params);
    else if (algorithm == "quick-sort")
    {
        auto start = high_resolution_clock::now();
        quickSort(array_input, 0, n - 1);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start) / 1e6;
        if (output_params == "-time")
            cout << "Running time: " << duration.count() << " seconds" << '\n';
        else if (output_params == "-comp")
            cout << "Comparisons: " << '\n';
        else
        {
            cout << "Running time: " << duration.count() << " seconds" << '\n';
            cout << "Comparisons: " << '\n';
        }
        writeFile("output.txt", array_input, n);
    }
    else if (algorithm == "merge-sort")
    {
        auto start = high_resolution_clock::now();
        mergeSort(array_input, 0, n - 1);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start) / 1e6;
        if (output_params == "-time")
            cout << "Running time: " << duration.count() << " seconds" << '\n';
        else if (output_params == "-comp")
            cout << "Comparisons: " << '\n';
        else
        {
            cout << "Running time: " << duration.count() << " seconds" << '\n';
            cout << "Comparisons: " << '\n';
        }
        writeFile("output.txt", array_input, n);
    }
}
void AlgorithmMode()
{
}
void ComparisionMode()
{
}
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
    writeFile("output.txt", a, n);
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
    writeFile("output.txt", a, n);
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