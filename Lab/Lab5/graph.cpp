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
}

vector<vector<int>> readG2()
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
    return G2;
}
void findDegree(vector<vector<int>> G) {
    int degree = 0;
    for(int i=0; i<G.size(); i++) {
        degree = 0;
        for(int j=0; j<G[i].size(); j++) {
            if(G[i][j] == 1)
                degree++;
        }
        cout << "The degree of vertex " << i << " is: " << degree << '\n';
    }
}
int numEdges(vector<vector<int>> G) {
    int degree = 0;
    for(int i=0; i<G.size(); i++)
        for(int j=0; j<G[i].size(); j++)
            if(G[i][j] == 1)
                degree++;
    return degree/2;
}
int numVertices(vector<vector<int>> G) {
    int vertices = 0;
    for(int i=0; i<G.size(); i++) {
        for(int j=0; j<G[i].size(); j++) {
            if(G[i][j] == 1) {
                vertices++;
                break;
            }
        }
    }
    return vertices;
}
void showIsolatedVertices(vector<vector<int>> G) {
    vector<bool> iV(G.size(), false);
    for(int i=0; i<G.size(); i++) {
        for(int j=0; j<G[i].size(); j++) {
            if(G[i][j] == 1) {
                iV[i] = true;
                break;
            }
        }
    }
    cout << "Isolated Vertices: ";
    for(int i=0; i<iV.size(); i++) {
        if(iV[i] == 0)
            cout << i << " ";
    }
    cout << '\n';
}
bool checkCompleteGraph(vector<vector<int>> G) {
    int nV = numVertices(G);
    int nE = numEdges(G);
    return nE == (nV*(nV-1))/2 ? true : false;
}
int main()
{
    vector<vector<int>> G2;
    // readG1();
    G2 = readG2();
    findDegree(G2);
    cout << "Number of edges: " << numEdges(G2) << '\n';
    cout << "Number of vertices: " << numVertices(G2) << '\n';
    showIsolatedVertices(G2);
    cout << "Complete Graph: " << checkCompleteGraph(G2) << '\n';
    return 0;
}
