#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

int main()
{
    srand(time(0));
    int a[100];
    ofstream fo("data.txt");
    for (int i = 0; i < 50; i++)
    {
        a[i] = rand() % 200;
        fo << a[i] << " ";
    }
    fo.close();
    return 0;
}