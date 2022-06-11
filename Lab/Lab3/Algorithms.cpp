#include "DataGenerator.cpp"
#include "Sorts.cpp"

void executeCommand1(string, string, string);
void executeCommand2(string, int, string, string);
void executeCommand3(string, int, string);
void executeCommand4(string, string, string);
void executeCommand5(string, string, string);
void OutputParams(string, double);
void AlgorithmMode(string, int[], int, string, string, string, int);
int main(int argc, char *argv[])
{
    string algorithm, input_file, input_order, output_params, n;
    int input_size;
    // Algorithm Mode
    if (argc < 5)
        cout << "[ERROR]: COMMAND NOT FOUND!";
    if (string(argv[1]) == "-a")
    {
        // Command 1
        n = argv[3];
        stringstream ss(n);
        ss >> input_size;
        if (argc == 5 && isdigit(input_size))
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
            n = argv[3];
            stringstream ss(n);
            ss >> input_size;
            input_order = argv[4];
            output_params = argv[5];
            executeCommand2(algorithm, input_size, input_order, output_params);
        }
        // Command 3
        else if (argc == 5)
        {
            algorithm = argv[2];
            output_params = argv[4];
            executeCommand3(algorithm, input_size, output_params);
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
            n = argv[4];
            stringstream ss(n);
            ss >> input_size;
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
void readFile(string input_file, int *&array_input, int &n)
{
    ifstream fi(input_file);
    int i = 0;
    fi >> n;
    array_input = new int[n];
    for (int i = 0; i < n; i++)
        fi >> array_input[i];
    fi.close();
}
void writeFile(string output_file, int *a, int n)
{
    ofstream fo(output_file);
    fo << n << '\n';
    for (int i = 0; i < n; i++)
        fo << a[i] << " ";
    fo.close();
}
void executeCommand1(string algorithm, string input_file, string output_params)
{
    int *array_input, n;
    readFile(input_file, array_input, n);
    cout << "============================\n";
    cout << "|      ALGORITHM MODE      |\n";
    cout << "============================\n";
    cout << "Algorithm: " << algorithm << '\n';
    AlgorithmMode(algorithm, array_input, n, output_params, "", input_file, 1);
    delete[] array_input;
}
void executeCommand2(string algorithm, int input_size, string input_order, string output_params)
{
    int *array_input = new int[input_size];
    if (input_order == "-rand")
    {
        GenerateData(array_input, input_size, 0);
        writeFile("input.txt", array_input, input_size);
    }
    else if (input_order == "-sorted")
    {
        GenerateData(array_input, input_size, 1);
        writeFile("input.txt", array_input, input_size);
    }
    else if (input_order == "-rev")
    {
        GenerateData(array_input, input_size, 2);
        writeFile("input.txt", array_input, input_size);
    }
    else if (input_order == "-nsorted")
    {
        GenerateData(array_input, input_size, 3);
        writeFile("input.txt", array_input, input_size);
    }
    else
    {
        cout << "[ERROR]: INPUT ORDER WRONG (-rand, -sorted, -rev, -nsorted)!";
        exit(1);
    }
    readFile("input.txt", array_input, input_size);
    cout << "============================\n";
    cout << "|      ALGORITHM MODE      |\n";
    cout << "============================\n";
    cout << "Algorithm: " << algorithm << '\n';
    AlgorithmMode(algorithm, array_input, input_size, output_params, input_order, "input.txt", 2);
}

void executeCommand3(string algorithm, int input_size, string output_params)
{
    int *array_input = new int[input_size];

    // Random order data
    GenerateData(array_input, input_size, 0);
    writeFile("input_1.txt", array_input, input_size);
    // Nearly sorted data
    GenerateData(array_input, input_size, 3);
    writeFile("input_2.txt", array_input, input_size);
    // Sorted data
    GenerateData(array_input, input_size, 1);
    writeFile("input_3.txt", array_input, input_size);
    // Reversed data
    GenerateData(array_input, input_size, 2);
    writeFile("input_4.txt", array_input, input_size);

    cout << "============================\n";
    cout << "|      ALGORITHM MODE      |\n";
    cout << "============================\n";
    cout << "Algorithm: " << algorithm << '\n';
    cout << "Input size: " << input_size << '\n';

    readFile("input_1.txt", array_input, input_size);
    AlgorithmMode(algorithm, array_input, input_size, output_params, "-rand", "input_1.txt", 3);
    readFile("input_2.txt", array_input, input_size);
    AlgorithmMode(algorithm, array_input, input_size, output_params, "-nsorted", "input_2.txt", 3);
    readFile("input_3.txt", array_input, input_size);
    AlgorithmMode(algorithm, array_input, input_size, output_params, "-sorted", "input_3.txt", 3);
    readFile("input_4.txt", array_input, input_size);
    AlgorithmMode(algorithm, array_input, input_size, output_params, "-rev", "input_4.txt", 3);
}

void OutputParams(string output_params, double runtime)
{
    if (output_params == "-time")
        cout << "-----------------------------\nRunning time: " << runtime << " seconds" << '\n';
    else if (output_params == "-comp")
        cout << "Comparisons: " << '\n';
    else
    {
        cout << "-----------------------------\nRunning time: " << runtime << " seconds" << '\n';
        cout << "Comparisons: " << '\n';
    }
}
void AlgorithmMode(string algorithm, int array_input[], int n, string output_params, string input_order, string input_file, int cmd)
{
    if (input_order == "-rand")
        input_order = "Randomize";
    else if (input_order == "-sorted")
        input_order = "Sorted";
    else if (input_order == "-rev")
        input_order = "Reversed";
    else if (input_order == "-nsorted")
        input_order = "Nearly Sorted";

    switch (cmd)
    {
    case 1:
        cout << "Input file: " << input_file << '\n';
        cout << "Input size: " << n << '\n';
        break;
    case 2:
        cout << "Input size: " << n << '\n';
        cout << "Input order: " << input_order << '\n';
        break;
    case 3:
        cout << "\nInput order: " << input_order << '\n';
        break;
    case 4:
        break;
    case 5:
        break;
    }
    double runtime;
    if (algorithm == "bubble-sort")
    {
        auto start = high_resolution_clock::now();
        bubbleSort(array_input, n);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start) / 1e6;
        runtime = duration.count();
        OutputParams(output_params, runtime);
        writeFile("output.txt", array_input, n);
    }
    else if (algorithm == "heap-sort")
    {
        auto start = high_resolution_clock::now();
        heapSort(array_input, n);
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