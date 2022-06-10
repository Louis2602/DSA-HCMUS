#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

int main()
{
    srand(time(0));
    int a[10000];
    ofstream fo("data.txt");
    for (int i = 0; i < 10000; i++)
    {
        a[i] = rand() % 20000;
        fo << a[i] << " ";
    }
    fo.close();
    return 0;
}