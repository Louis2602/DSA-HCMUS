#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Examinee
{
    string id;
    float math, literature, physic, chemistry, biology, history, geography, civic_education, natural_science,
        social_science, foreign_language;
};

void readFile(char *filename, Examinee e[], int n)
{
    fstream fs(filename, ios::in);
    string tmp;
    getline(fs, tmp);
    int i = 0;
    char c;
    for (int i = 0; i < n; i++)
    {
        getline(fs, e[i].id, ',');
        getline(fs, tmp, ',');
        fs >> e[i].math;
        fs >> e[i].literature;
        fs >> e[i].physic;
        fs >> e[i].chemistry;
        fs >> e[i].biology;
        fs >> e[i].history;
        fs >> e[i].geography;
        fs >> e[i].civic_education;
        fs >> e[i].natural_science;
        fs >> e[i].social_science;
        fs >> e[i].foreign_language;
        getline(fs, tmp, ',');
        getline(fs, tmp);
    }
}

int readLines(char *filename)
{
    fstream fs(filename, ios::in);
    string s;
    int n = 0;
    while (!fs.eof())
    {
        getline(fs, s);
        n++;
    }
    return n;
}
Examinee readExaminee(string line_info)
{
}
int main()
{
    char filename[] = "data.txt";
    int n = readLines(filename);
    Examinee *e = new Examinee[n];
    readFile(filename, e, n);
    return 0;
}