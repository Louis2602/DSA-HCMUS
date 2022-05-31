#include <iostream>
#include <fstream>
#include <string>
#include <vector>

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
    int i = 0;
    string s;
    getline(fs, s);
    char c;
    for (int i = 0; i < n; i++)
    {
        getline(fs, e[i].id, ',');
        fs.ignore();
        getline(fs, s, ',');
        e[i].math = atof(s.c_str());
        getline(fs, s, ',');
        e[i].literature = atof(s.c_str());
        getline(fs, s, ',');
        e[i].physic = atof(s.c_str());
        getline(fs, s, ',');
        e[i].chemistry = atof(s.c_str());
        getline(fs, s, ',');
        e[i].biology = atof(s.c_str());
        getline(fs, s, ',');
        e[i].history = atof(s.c_str());
        getline(fs, s, ',');
        e[i].geography = atof(s.c_str());
        getline(fs, s, ',');
        e[i].civic_education = atof(s.c_str());
        getline(fs, s, ',');
        e[i].natural_science = atof(s.c_str());
        getline(fs, s, ',');
        e[i].social_science = atof(s.c_str());
        getline(fs, s, ',');
        e[i].foreign_language = atof(s.c_str());
        getline(fs, s, ',');
        getline(fs, s);
    }
    fs.close();
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
Examinee readExaminee(string line_info, Examinee *e)
{
    int k = stoi(line_info);
    return e[k];
}
void writeTotal(vector<Examinee> examinee_list, char *out_file_name, int n, Examinee *e)
{
    fstream fs(out_file_name, ios::out);
    int s = 0;
    float total_score;
    for (int i = 0; i < n - 1; i++)
    {
        total_score = e[i].math + e[i].literature + e[i].physic + e[i].chemistry + e[i].biology + e[i].history + e[i].geography + e[i].civic_education + e[i].social_science + e[i].foreign_language;
        fs << e[i].id << " " << total_score << endl;
    }
    fs.close();
}
int main()
{
    char filename[] = "data.txt";
    char out_file_name[] = "output.txt";
    int n = readLines(filename);
    Examinee *e = new Examinee[n];
    readFile(filename, e, n);
    // Examinee t;
    // t = readExaminee("3", n, e);
    vector<Examinee> examinee_list;
    writeTotal(examinee_list, out_file_name, n, e);
    return 0;
}
