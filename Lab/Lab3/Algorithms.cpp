#include <iostream>
#include <fstream>
#include <chrono>
#include "DataGenerator.cpp"

using namespace std;
using namespace std::chrono;

void selectionSort(int a[], int n);
void insertionSort(int a[], int n);
void bubbleSort(int a[], int n, string params);
void heapSort(int a[], int n, string params);
void mergeSort(int a[], int n);
void quickSort(int a[], int low, int high, string params);
void shakerSort(int a[], int n);
void shellSort(int a[], int n);
void CountingSort(int a[], int n);
void radixSort(int a[], int n);
void flashSort(int a[], int n);
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
    while (!fi.eof())
    {
        fi >> a[i];
        i++;
    }
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
    int *array_input;
    int n;
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
        quickSort(array_input, 0, n - 1, output_params);
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
    // Tự viết code bubble sort
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
void heapRebuild(int a[], int n, int i)
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
void heapSort(int a[], int n, string params)
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

void mergeSort(int a[], int n)
{
}
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
void quickSort(int a[], int low, int high, string params)
{
    int n = high + 1;
    if (low < high)
    {
        int k = partition(a, low, high);
        quickSort(a, low, k - 1, params);
        quickSort(a, k + 1, high, params);
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