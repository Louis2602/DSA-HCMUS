#include "DataGenerator.cpp"
#include "Sorts.h"

void executeCommand1(string, string, string);
void executeCommand2(string, string, string);
void executeCommand3(string, string, string);
void executeCommand4(string, string, string);
void executeCommand5(string, string, string);
void OutputParams(string output_params, double runtime);
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
    double runtime;
    if (algorithm == "bubble-sort")
    {
        auto start = high_resolution_clock::now();
        bubbleSort(array_input, n, output_params);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start) / 1e6;
        runtime = duration.count();
        OutputParams(output_params, runtime);
        writeFile("output.txt", array_input, n);
    }
    else if (algorithm == "heap-sort")
    {
        auto start = high_resolution_clock::now();
        heapSort(array_input, n, output_params);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start) / 1e6;
        runtime = duration.count();
        OutputParams(output_params, runtime);
        writeFile("output.txt", array_input, n);
    }
    else if (algorithm == "quick-sort")
    {
        auto start = high_resolution_clock::now();
        quickSort(array_input, 0, n - 1);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start) / 1e6;
        runtime = duration.count();
        OutputParams(output_params, runtime);
        writeFile("output.txt", array_input, n);
    }
    else if (algorithm == "merge-sort")
    {
        auto start = high_resolution_clock::now();
        mergeSort(array_input, 0, n - 1);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start) / 1e6;
        double runtime = duration.count();
        OutputParams(output_params, runtime);
        writeFile("output.txt", array_input, n);
    }
}

void OutputParams(string output_params, double runtime)
{
    if (output_params == "-time")
        cout << "Running time: " << runtime << " seconds" << '\n';
    else if (output_params == "-comp")
        cout << "Comparisons: " << '\n';
    else
    {
        cout << "Running time: " << runtime << " seconds" << '\n';
        cout << "Comparisons: " << '\n';
    }
}