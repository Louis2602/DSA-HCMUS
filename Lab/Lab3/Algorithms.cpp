#include <iostream>
#include <fstream>
#include "DataGenerator.cpp"
using namespace std;

void selectionSort(int a[], int n);
void insertionSort(int a[], int n);
void bubbleSort(int a[], int n, string params);
void heapSort(int a[], int n);
void mergeSort(int a[], int n);
void quickSort(int a[], int n);
void shakerSort(int a[], int n);
void shellSort(int a[], int n);
void CountingSort(int a[], int n);
void radixSort(int a[], int n);
void flashSort(int a[], int n);
void executeCommand1(string, string, string);
void executeCommand2();
void executeCommand3();
void executeCommand4();
void executeCommand5();
void AlgorithmMode();
void ComparisionMode();
int main(int argc, char *argv[])
{
    string algorithm, input_file, input_size, input_order, output_params;
    // Algorithm Mode
    if (argc < 5)
        cout << "[ERROR]: NO COMMAND FOUND!";
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
void executeCommand1(string algorithm, string input_file, string output_params)
{
    int *array_input;
    int n;
    readFile(input_file, array_input, n);
    if (algorithm == "bubble-sort")
        bubbleSort(array_input, n, output_params);
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
    if (params == "-asc")
    {
        for (int i = 1; i < n; i++)
            for (int j = n - 1; j >= i; j--)
                if (a[j] < a[j - 1])
                    swap(a[j], a[j - 1]);
    }
    if (params == "-des")
    {
        for (int i = 1; i < n; i++)
            for (int j = n - 1; j >= i; j--)
                if (a[j] > a[j - 1])
                    swap(a[j], a[j - 1]);
    }
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}
void heapSort(int a[], int n)
{
}
void mergeSort(int a[], int n)
{
}
void quickSort(int a[], int n)
{
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