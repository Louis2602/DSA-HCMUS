#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct Examinee
{
    string id;
    float grade[11];
};

Examinee readExaminee(string line_info)
{
    stringstream ss(line_info);
    string tmp;
    Examinee e;
    getline(ss, e.id, ','); // read id
    getline(ss, tmp, ',');  // read name
    for (int i = 0; i < 11; i++)
    {
        getline(ss, tmp, ',');
        if (tmp == "")
            e.grade[i] = 0;
        else
            e.grade[i] = stof(tmp);
    }
    return e;
}
vector<Examinee> readExamineeList(string fname)
{
    fstream fs(fname, ios::in);
    vector<Examinee> ve;
    Examinee t;
    string tmp;
    getline(fs, tmp); // skip intro line
    while (!fs.eof())
    {
        getline(fs, tmp);
        t = readExaminee(tmp);
        ve.push_back(t);
    }
    fs.close();
    return ve;
}
int main()
{
    Examinee e = readExaminee("BD1200001,,4.0,5.0,,1,,4.25,7.0,7.75,,,2.0,N1,BinhDinh");
    cout << e.id << '\n';
    for (int i = 0; i < 11; i++)
        cout << e.grade[i] << '\t';
    // vector<Examinee> ve = readExamineeList("data.txt");
    // for (int i = 0; i < ve.size(); i++)
    // {
    //     for (int j = 0; j < 11; j++)
    //     {
    //         cout << ve[i].grade[j] << '\t';
    //     }
    //     cout << '\n';
    // }

    return 0;
}
