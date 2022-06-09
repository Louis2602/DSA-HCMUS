#include <iostream>
#include "DataGenerator.cpp"
#include <string>
using namespace std;

void selectionSort(int a[], int n);
void insertionSort(int a[], int n);
void bubbleSort(int a[], int n);
void heapSort(int a[], int n);
void mergeSort(int a[], int n);
void quickSort(int a[], int n);
void shakerSort(int a[], int n);
void shellSort(int a[], int n);
void CountingSort(int a[], int n);
void radixSort(int a[], int n);
void flashSort(int a[], int n);
void readCommands(string cmd);
void AlgorithmMode();
void ComparisionMode();
int main(int argc, char *argv[])
{
    string algorithm, input_file, input_order, output_params;
    int input_size;
    // Algorithm Mode
    if (argc < 5)
        cout << "[ERROR]: NO COMMAND FOUND!";
    // Command 1
    if (string(argv[1]) == "-a")
    {
        if (argc == 5)
        {
            algorithm = argv[2];
            input_file = argv[3];
            output_params = argv[4];
        }
        // Command 2
        else if (argc == 6)
        {
            algorithm = argv[2];
            input_size = atoi(argv[3]);
            input_order = argv[4];
            output_params = argv[5];
        }
        // Command 3
        else if (argc == 5 && isdigit(atoi(argv[4])))
        {
            algorithm = argv[2];
            input_size = atoi(argv[3]);
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
            input_size = atoi(argv[4]);
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
void readCommands(string cmd)
{
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
void bubbleSort(int a[], int n)
{
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