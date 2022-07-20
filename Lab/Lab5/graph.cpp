#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <string>
#include <sstream>

using namespace std;

void readG1()
{
    cout << "Adjacency Matrix -> List\n";
    fstream fs("graph1.txt", ios::in);
    int n;
    fs >> n;
    list<int> *G1 = new list<int>[n];
    int v;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fs >> v;
            if (v)
            {
                G1[i].push_back(j);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << "| " << i << " | ";
        for (auto j : G1[i])
        {
            cout << "-> | " << j << " | ";
        }
        cout << endl;
    }
    fs.close();
}

void readG2()
{
    cout << "Adjacency List -> Matrix\n";
    fstream fs("graph2.txt", ios::in);
    int n;
    fs >> n;
    fs.ignore();
    vector<vector<int>> G2(n, vector<int>(n, 0));
    int v;
    string s;
    for (int i = 0; i < n; i++)
    {
        getline(fs, s);
        stringstream ss(s);
        if (s.size())
        {
            while (!ss.eof())
            {
                ss >> v;
                G2[i][v] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << G2[i][j] << " ";
        cout << '\n';
    }
    fs.close();
}

int main()
{
    readG1();
    readG2();
    return 0;
}
